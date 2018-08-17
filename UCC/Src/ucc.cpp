/*
*	This is a custom UCC.exe for Star Wars Republic Commando since the game shipped without one.
*	Everything compiles fine with Visual Studio .NET 2003 which is being used to achieve maximum compatibility
*	since it was also used to compile RC
*	The following settings are required in order to compile everything without errors:
*		- Character Set = Not Set	//Important as RC does not use unicode
*		- Struct Member Alignment = 4 Bytes	//Probably not necessary, but just in case...
*		- Calling Convention = __fastcall	//RC uses __fastcall as default calling convention
*/

#include "../../Core/Inc/Core.h"
#include "../../Core/Inc/FOutputDeviceFile.h"
#include "../../Core/Inc/FOutputDeviceWindowsError.h"
#include "../../Core/Inc/FFeedbackContextAnsi.h"
#include "../../Core/Inc/FConfigCacheIni.h"

void UServerCommandletMain(); //Defined in ServerCommandlet.cpp

//Output devices

FOutputDeviceFile Log;
FOutputDeviceWindowsError Error;
FFeedbackContextAnsi Warn;

void ShowBanner(){
	Warn.Log("=======================================");
	Warn.Log("ucc.exe for Star Wars Republic Commando");
	Warn.Log("made by Leon0628");
	Warn.Log("=======================================\n");
}

int main(int argc, char** argv){
	int ExitCode = EXIT_SUCCESS;

	GIsStarted = 1;

	try{
		GIsGuarded = 1;

		FString CmdLine;

		for(int i = 1; i < argc; i++)
			CmdLine += FString(argv[i]) + " ";

		appInit("SWRepublicCommando", *CmdLine, &Log, &Error, &Warn, FConfigCacheIni::Factory, 1);
		UObject::SetLanguage("int");

		if(argc > 1){
			//Initializing global state
			GIsUCC = GIsClient = GIsServer = GIsEditor = GIsScriptable = GLazyLoad = 1;

			FString ClassName = argv[1];
			TArray<FRegistryObjectInfo> List;

			UObject::GetRegistryObjects(List, UClass::StaticClass(), UCommandlet::StaticClass(), 0); //Loading list of commandlets declared in .int files

			for(int i = 0; i < List.Num(); i++){ //Looking Token up in list and autocompleting class name if found
				FString Str = List[i].Object;

				if(ClassName == Str || ClassName + "Commandlet" == Str){ //Checking against "PackageName.ClassName (+ Commandlet)"
					ClassName = List[i].Object;

					break;
				}

				while(Str.InStr(".") >= 0) //Removing package name so that only class name remains
					Str = Str.Mid(Str.InStr(".") + 1);

				if(ClassName == Str || ClassName + "Commandlet" == Str){ //Checking against "ClassName (+ Commandlet)" and adding "PackageName"
					ClassName = List[i].Object;

					break;
				}
			}

			DWORD LoadFlags = LOAD_NoWarn | LOAD_Quiet;

			if(ClassName == "Editor.MakeCommandlet")
				LoadFlags |= LOAD_DisallowFiles;

			UClass* Class = LoadClass<UCommandlet>(NULL, *ClassName, NULL, LoadFlags, NULL);

			if(!Class) //If class failed to load appending "Commandlet" and trying again
				Class = LoadClass<UCommandlet>(NULL, *(ClassName + "Commandlet"), NULL, LoadFlags, NULL);

			if(Class){
				UCommandlet* Commandlet = ConstructObject<UCommandlet>(Class);
				UCommandlet* Default = static_cast<UCommandlet*>(Class->GetDefaultObject());

				if(Default->ShowBanner)
					ShowBanner();

				Warn.Logf("Executing %s\n", Class->GetFullName());

				GIsClient = Default->IsClient;
				GIsEditor = Default->IsEditor;
				GIsServer = Default->IsServer;
				GLazyLoad = Default->LazyLoad;

				//Contains only the command-line options that are passed to the commandlet
				FString CommandletCmdLine;

				for(int i = 2; i < argc; i++)
					CommandletCmdLine += FString(argv[i]) + " ";

				Commandlet->InitExecution();
				Commandlet->ParseParms(*CommandletCmdLine);

				if(Default->LogToStdout){ //Redirecting commandlet output to console
					Warn.AuxOut = GLog;
					GLog = &Warn;
				}
				
				if(ClassName == "Engine.ServerCommandlet")
					UServerCommandletMain(); //The ServerCommandlet has a special Main function
				else
					Commandlet->Main(CommandletCmdLine);

				if(Default->ShowErrorCount)
					Warn.Logf("\n%s - %i error(s), %i warning(s)", Warn.ErrorCount == 0 ? "Success" : "Failure", Warn.ErrorCount, Warn.WarningCount);

				if(Default->LogToStdout){
					Warn.AuxOut = NULL;
					GLog = &Log;
				}
			}else{
				ShowBanner();
				Warn.Logf("Commandlet %s not found", argv[1]);
			}
		}else{
			ShowBanner();
			Warn.Log("Usage:");
			Warn.Log("    ucc CommandletName <parameters>");
		}

		//This prevents an infinite loop during garbage collection when there are compile errors with ucc make
		if(Warn.ErrorCount == 0)
			appPreExit();

		GIsGuarded = 0;
	}catch(...){
		GIsGuarded = 0;
		GLog = &Log;
		ExitCode = EXIT_FAILURE;
		Error.HandleError();
	}

	appExit();

	return ExitCode;
}