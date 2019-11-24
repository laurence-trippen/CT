/*===========================================================================
    C++ class definitions exported from UnrealScript.
    This is automatically generated by the tools.
    DO NOT modify this manually! Edit the corresponding .uc files instead!
===========================================================================*/

#ifndef MODMPGAME_NATIVE_DEFS
#define MODMPGAME_NATIVE_DEFS

#if SUPPORTS_PRAGMA_PACK
#pragma pack (push,4)
#endif

#ifndef MODMPGAME_API
#define MODMPGAME_API DLL_IMPORT
#endif



class MODMPGAME_API ABotSupport : public AActor
{
public:
    TArrayNoInit<FVector> NavPtFailLocations;
    TArrayNoInit<class AMPBot*> Bots;
    TArrayNoInit<class APlayerStart*> SpawnPoints;
    BITFIELD bImportedPaths:1 GCC_PACK(4);
    void execSpawnNavigationPoint(FFrame& Stack, void* Result);
    void execBuildPaths(FFrame& Stack, void* Result);
    void execClearPaths(FFrame& Stack, void* Result);
    DECLARE_CLASS(ABotSupport,AActor,0,ModMPGame)
	virtual void Spawned();
	virtual void Destroy();
	virtual UBOOL Tick(FLOAT DeltaTime, ELevelTick TickType);
	virtual void PostRender(class FLevelSceneNode* SceneNode, class FRenderInterface* RI);

	void SpawnNavigationPoint(UClass* NavPtClass, const FVector& Location, const FRotator& Rotation = FRotator(0, 0, 0));
	void ImportPaths();
	void BuildPaths();
	void ClearPaths();

	// Static because it needs to be accessed by UExportPathsCommandlet
	static void ExportPaths(ALevelInfo* LevelInfo);
    DECLARE_NATIVES(ABotSupport)
};



#if SUPPORTS_PRAGMA_PACK
#pragma pack (pop)
#endif

#if __STATIC_LINK

#define AUTO_INITIALIZE_REGISTRANTS_MODMPGAME \
	ABotSupport::StaticClass(); \

#endif // __STATIC_LINK

#endif // CORE_NATIVE_DEFS
