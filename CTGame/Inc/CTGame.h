/*===========================================================================
	C++ class definitions exported from UnrealScript.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .uc files instead!
===========================================================================*/

#ifndef CTGAME_NATIVE_DEFS
#define CTGAME_NATIVE_DEFS

#include "../../Gameplay/Inc/Gameplay.h"

#if SUPPORTS_PRAGMA_PACK
#pragma pack (push,4)
#endif

#ifndef CTGAME_API
#define CTGAME_API DLL_IMPORT
LINK_LIB(CTGame)
#endif

/*
*	ActivateDoor
*/

class CTGAME_API AActivateDoor : public AActivateItem{
public:
	class AActor* MatchingComponent;
	FActivationInfo DoorLockedState;
	FActivationInfo DoorUnlockedState;
	FActivationInfo DoorDamagedState;
	FLOAT DamagedDelay;

	DECLARE_CLASS(AActivateDoor,AActivateItem,0,CTGame)
	NO_DEFAULT_CONSTRUCTOR(AActivateDoor)
};

/*
*	ActivateTrap
*/

class CTGAME_API AActivateTrap : public AActivateItem{
public:
	FActivationInfo TrapDetected;
	FActivationInfo TrapDisarmed;
	FActivationInfo TrapSet;
	FActivationInfo TrapExplode;
	INT TeamIndex;
	FLOAT TriggerRadius;
	FLOAT NextCheckTime;
	class UStaticMesh* DetonationPreviewMesh;
	class AActor* DetonationPreviewActor;
	FName EventTargeted;
	FLOAT AlertTimeLimit;
	FLOAT LastNoDetectTime;
	class USound* AlertSound;
	BITFIELD bSetTrapReferences:1;
	void IncrementRadiusTrapReferences();
	void DecrementRadiusTrapReferences();

	DECLARE_CLASS(AActivateTrap,AActivateItem,0,CTGame)

	virtual INT AddMyMarker(AActor *S);
	virtual void PostNavListBuild();
};

/*
*	BactaDispenser
*/

class CTGAME_API ABactaDispenser : public AActivateItem{
public:
	FActivationInfo BactaStandby;
	FActivationInfo BactaActive;
	FActivationInfo BactaRecharging;
	FActivationInfo BactaDisabled;
	class ABactaDispenser* NextDispenser;
	FLOAT BactaRate;
	class UClass* DispenserEffectClass;
	class UClass* PawnEffectClass;
	class AEmitter* PawnEffect;
	void DepleteBacta();

	DECLARE_CLASS(ABactaDispenser,AActivateItem,0,CTGame)

	virtual ANavigationPoint* GetAnchor(){ return NavPts[0]; }
};

/*
*	HackTerminal
*/

class CTGAME_API AHackTerminal : public AActivateItem{
public:
	FActivationInfo DisabledState;
	FActivationInfo StandbyState;
	FActivationInfo HackedState;
	FActivationInfo ActiveState;
	class AActor* OptionalDesk;

	DECLARE_CLASS(AHackTerminal,AActivateItem,0,CTGame)
	NO_DEFAULT_CONSTRUCTOR(AHackTerminal)
};

/*
*	CTBot
*/

enum EStatePhase{
	SP_Inactive,
	SP_Activate,
	SP_Update,
	SP_Shutdown,
	SP_MAX
};

enum EBotGestureSuite{
	BGS_None,
	BGS_StateControlled,
	BGS_Auto,
	BGS_Incapacitated,
	BGS_MAX
};

#define UCONST_WoundedAccuracyFactor 1.0f
#define UCONST_AUTORUNDISTANCE 400.0

class CTGAME_API ACTBot : public AScriptedController{
public:
	INT MaxDodgeAngle;
	FLOAT MinDodgeTime;
	FLOAT MinGrenadeTime;
	FLOAT CoverBoredomTime;
	FLOAT GrenadeProbability;
	FLOAT MinBurstInterval;
	FLOAT NextBurstTime;
	FLOAT NextCoverSearchTime;
	FLOAT NextGrenadeTime;
	FLOAT NextDodgeTime;
	class ANavigationPoint* ReservedNode;
	class ULocalSituation* Situation;
	FLOAT NextDecisionTime;
	TArrayNoInit<class UStateObject*> States;
	class UGoalQueue* MainGoals;
	class UGoalQueue* ScriptedGoals;
	class UGoalQueue* SquadGoals;
	class UGoalQueue* ReflexGoals;
	class UGoalQueue* GestureGoals;
	class UStateObject* CurrentState;
	class UStateObject* NextState;
	FLOAT BestUtility;
	TArrayNoInit<class UStimulus*> StimuliReceived;
	FLOAT EnemyMemoryTime;
	FLOAT LastTimeEnemySeen;
	INT LastManeuver;
	INT ShotCounter;
	INT BurstCount;
	TArrayNoInit<class UStimulus*> UnprocessedStimuli;
	class UStimulus* StrongestStimulus;
	class UGOAL_WaitForEvent* WaitForEventGoal;
	class UGOAL_Shoot* CurrentShootGoal;
	class ACoverPoint* SuggestedCombatPosition;
	class AActor* SuggestedEnemy;
	class AActor* TetherTarget;
	class APawn* TetherPawn;
	class AActor* PreventTether;
	FLOAT PreventRange;
	FLOAT NextGunSafetyCheck;
	FLOAT TimeOfLastBattleStimulus;
	FLOAT TimeOfLastStimulus;
	FVector OffsetDirection;
	class APawn* AllyInWay;
	FLOAT AllyInWayRadius;
	FLOAT ClosestAllyAngle;
	class AActor* GrenadeTarget;
	BYTE Phase;
	BYTE GestureSuite;
	BYTE BumpCount;
	BYTE FriendlyFireCount;
	FLOAT LastFriendlyFireTime;
	FLOAT NextIdleGestureTime;
	FLOAT NextLookDirectorTime;
	class UClass* LastStateClass;
	FLOAT StateActivationTime;
	FLOAT LastStateLength;
	FLOAT DecisionInterval;
	FLOAT EmoteProbability;
	FLOAT DodgeErrorTime;
	FLOAT LastBumpTime;
	FLOAT PostWorldCheckFireDuration;
	FLOAT LastClearShotTime;
	BYTE HostileStimuliResponses[SG_MAX];
	BYTE BenignStimuliResponses[SG_MAX];
	BITFIELD StateWasForced:1;
	BITFIELD ExecutingCriticalGoal:1;
	BITFIELD bPlayEmoteHear:1;
	BITFIELD ShouldReloadSoon:1;
	BITFIELD CanReloadNow:1;
	BITFIELD CanDodgeNow:1;
	BITFIELD bLeapFrog:1;
	BITFIELD bBotCombatEnabled:1;
	BITFIELD bAutoSelectRunOrWalk:1;
	BITFIELD bShouldCrouch:1;
	BITFIELD bWantsToFire:1;
	BITFIELD bLastSafeToShoot:1;
	BITFIELD bAttackFromCrouch:1;
	BITFIELD bLookDirectorEnabled:1;
	BITFIELD bBotCombatAllowsMelee:1;
	BITFIELD bUseAdditionalTargets:1;
	BITFIELD bWasProcessingReflexes:1;
	BITFIELD bCanDecelerate:1;
	BITFIELD bPreventTetherOneWay:1;
	BITFIELD bCheckCorpseFire:1;
	BITFIELD bAutoAntiArmor:1;
	BITFIELD bAutoSnipe:1;
	BITFIELD bAutoGrenade:1;
	BITFIELD bIgnoreFF:1;
	BITFIELD bAbortShootToDefend:1;
	BITFIELD bCheckFavoriteWeapon:1;
	BITFIELD bCanGesture:1;
	class UCLASS* RequiredStates[UCONST_MAXSTATEOBJECTS];
	FLOAT HearingMultiplier;

	FLOAT MaxAimError();

	DECLARE_CLASS(ACTBot,AScriptedController,CLASS_Config,CTGame)
};

/*
*	CTPlayer
*/

class CTGAME_API ACTPlayer : public APlayerController{
public:
	FLOAT TargetLastUpdated;
	FVector HitNormal;
	FVector HitLocation;
	FLOAT DistToTarget;
	INT FriendliesKilled;
	INT FriendlyFireInstances;
	INT TimeOfLastFriendlyFire;
	FLOAT BeganFiringTime;
	FLOAT PickupTargetDistance;
	class UClass* WeaponRolloverEffectClass;
	class UClass* AmmoRolloverEffectClass;

	DECLARE_CLASS(ACTPlayer,APlayerController,CLASS_Config,CTGame)

	//Overrides
	virtual bool CrossesMyFire(const FVector&, const FVector&);
	virtual void Destroy();
	virtual void Spawned();

	//Functions
	BYTE SelectTargetType();
	void ServerRevive(class APawn* Other);
};

/*
*	Factory
*/

enum ESpawnMode{
	SPM_Cyclic,
	SPM_Random,
	SPM_FromFactory,
	SPM_NearPlayer,
	SPM_MAX
};

class CTGAME_API AFactory : public AActor{
public:
	BITFIELD bDrawLinks:1;
	BITFIELD bCovert:1;
	BITFIELD bWaitForIllegalSpawns:1;
	BITFIELD bGenerateForever:1;
	BITFIELD bStartTimerAfterDeath:1;
	INT Capacity;
	INT MaxAlive;
	FLOAT MaxInWorld;
	FLOAT SpawnInterval;
	FLOAT SpawnIntervalMax;
	BYTE SpawnMode;
	FLOAT MaxPlayerRange;
	FLOAT MinPlayerRange;
	BYTE InitialPhysicsFromFactory;
	FLOAT InitialSpeedFromFactory;
	FName ExhaustedEvent;
	FName SpawnEvent;
	class UClass* InternalPrototype;
	TArrayNoInit<class AActor*> SpawnedActors;
	TArrayNoInit<class ASpawnPoint*> SpawnPoints;
	INT NextSpawnPoint;
	INT RemainingItems;
	BITFIELD bEndWaiting:1;
	BITFIELD bWasOnceOnline:1;

	DECLARE_CLASS(AFactory,AActor,0,CTGame)

	void RenderEditorSelected(FLevelSceneNode* SceneNode,FRenderInterface* RI, FDynamicActor* FDA);
};

/*
*	PawnFactory
*/

class CTGAME_API APawnFactory : public AFactory{
public:
	class UClass* Prototype;
	FName AIScriptFromFactory;
	FName PawnTagFromFactory;
	FName FirstDamagedEventFromFactory;
	FName PawnEventFromFactory;
	TArrayNoInit<FPatrolPoint> PatrolRouteFromFactory;
	BYTE PatrolModeFromFactory;
	FLOAT PatrolPriorityFromFactory;
	BYTE StartStateFromFactory;
	INT TeamIndexFromFactory;
	FLOAT OptimalWeaponDistFromFactory;
	FLOAT SightRadiusFromFactory;
	BITFIELD bAlwaysUseFactorySettings:1;
	BITFIELD PreserveDeadBodiesFromFactory:1;
	BITFIELD DisableEmotesFromFactory:1;
	BITFIELD CanBeLeaderFromFactory:1;
	BITFIELD TossWeaponOnDeathFromFactory:1;
	BITFIELD DebugAIFromFactory:1;

	DECLARE_CLASS(APawnFactory,AFactory,0,CTGame)

	void RenderEditorSelected(FLevelSceneNode* SceneNode,FRenderInterface* RI, FDynamicActor* FDA);
};

/*
*	CTGameInfo
*/

class CTGAME_API ACTGameInfo : public AGameInfo{
public:
	DECLARE_CLASS(ACTGameInfo,AGameInfo,CLASS_Config,CTGame)
	NO_DEFAULT_CONSTRUCTOR(ACTGameInfo)
};

/*
*	CTSquadNative
*/

struct FSquadAssignment{
	class APawn* Member;
	class AActor* Subject;
	class UGoalObject* Goal;
	class UObject* Owner;
	BITFIELD bParallelGoal:1;
	class UClass* StateClass;
};

class CTGAME_API ACTSquadNative : public ASquad{
public:
	INT Head;
	class AActor* RallyActor;
	class AActor* OptionalRallyActor;
	TArrayNoInit<FSquadAssignment> Assignments;
	FLOAT NextCantFireTime;
	INT CurrentObjective;
	INT NextWaitFor;
	INT NextGoto;
	INT NextRequiredGoto;
	FLOAT LastBattleCueTime;
	class ANavigationPoint* LatestGotoPoint;
	class ANavigationPoint* NextGotoPoint;
	class UStaticMesh* RallyPointMesh;
	class UStaticMesh* SearchAndDestroyMesh;
	class UStaticMesh* OptionalSDMesh;
	class UClass* SecureAreaEffect;
	class UClass* EngageEffectClass;
	class AActor* FormationFocus;
	FLOAT LastMemberKilledTime;
	class USound* SquadDeathSound;
	class USound* SquadIncapSound;
	void UpdateVoice(FLOAT DeltaTime);
	void ReviveOrder(class APawn* Incapacitated);
	void CancelAllMarkers(class APawn* Instigator);
	UBOOL EngageLocation(FVector const& Location);
	void EngageTarget(class AActor* Target);
	void CancelAllOrders(class APawn* Instigator);
	void Recall(class APawn* Instigator);
	void ToggleCautious();
	void SetCommandedEnemy(class APawn* Target);

	DECLARE_CLASS(ACTSquadNative,ASquad,0,CTGame)
};

/*
*	CTTeamInfo
*/

class CTGAME_API ACTTeamInfo : public ATeamInfo{
public:
	BYTE RelationTowards[10];
	INT KillsBy[10];

	DECLARE_CLASS(ACTTeamInfo,ATeamInfo,0,CTGame)
};

/*
*	SpawnPoint
*/

class CTGAME_API ASpawnPoint : public AKeypoint{
public:
	BITFIELD bDrawLinks:1;
	BITFIELD PreserveDeadBodies:1;

	DECLARE_CLASS(ASpawnPoint,AKeypoint,0,CTGame)

	void RenderEditorSelected(FLevelSceneNode* SceneNode,FRenderInterface* RI, FDynamicActor* FDA);
};

/*
*	CTMarker
*/

class CTGAME_API ACTMarker : public ASquadMarker{
public:
	void MakeObsolete();

	DECLARE_CLASS(ACTMarker,ASquadMarker,0,CTGame)
};

/*
*	MarkerGetBactaNative
*/

class CTGAME_API AMarkerGetBactaNative : public ACTMarker{
public:
	DECLARE_CLASS(AMarkerGetBactaNative,ACTMarker,0,CTGame)

	UBOOL Update();

	virtual UBOOL IsRelevantFor(APawn *Pawn){ return (Pawn->HealthLevel < HL_Green); }
	virtual bool SortParticipants(int PotentialParticipants, int TotalParticipants);
};

/*
*	MarkerReviveOther
*/

class CTGAME_API AMarkerReviveOther : public ACTMarker{
public:
	FLOAT Duration;

	DECLARE_CLASS(AMarkerReviveOther,ACTMarker,/*CLASS_NoAutoLoad*/0,CTGame)

	virtual UBOOL Update();
	virtual void CompleteMarker();
};

/*
*	CTPawn
*/

class CTGAME_API ACTPawn : public APawn{
public:
	class UClass* IdleInfoClass;
	FStringNoInit IdleInfoClassName;
	class UClass* FootstepInfoClass;

	DECLARE_CLASS(ACTPawn,APawn,CLASS_Config,CTGame)

	//Overrides
	void PlayFootstepSound(BYTE eMatType, BYTE TypeOfWalk, USound* pDefaultSound);
	void PlayOwnedFootstepSound(BYTE eMatType, BYTE TypeOfWalk, USound* pDefaultSound);

protected:
	USound* DetermineFootstepSound(BYTE eMatType, BYTE TypeOfWalk, USound* pDefaultSound) const;
};

/*
*	KnockoverProp
*/

class CTGAME_API AKnockoverProp : public AKarmaProp{
public:
	BITFIELD KnockedOver:1;
	FName KnockoverAnim;

	DECLARE_CLASS(AKnockoverProp,AKarmaProp,0,CTGame)

	INT AddMyMarker(AActor* S);
};

/*
*	CTDamageType
*/

class CTGAME_API UCTDamageType : public UDamageType{
public:
	DECLARE_CLASS(UCTDamageType,UDamageType,0,CTGame)
	NO_DEFAULT_CONSTRUCTOR(UCTDamageType)
};

/*
*	CTDamageMelee
*/

class CTGAME_API UCTDamageMelee : public UCTDamageType{
public:
	DECLARE_CLASS(UCTDamageMelee,UCTDamageType,0,CTGame)
	NO_DEFAULT_CONSTRUCTOR(UCTDamageMelee)
};

/*
*	FootstepInfo
*/

struct FFootstepSoundInfo{
	BYTE StepOnMaterial;
	class USound* FootstepSound;
};

struct FFootstepSoundMap{
	TArrayNoInit<FFootstepSoundInfo> Footsteps;
	BYTE WalkType;
};

class CTGAME_API UFootstepInfo : public UObject{
public:
	TArrayNoInit<FFootstepSoundMap> FootstepSounds;

	DECLARE_CLASS(UFootstepInfo,UObject,0,CTGame)
	NO_DEFAULT_CONSTRUCTOR(UFootstepInfo)
};

/*
*	GoalQueue
*/

enum EGoalStatus{
	GS_Inactive,
	GS_PlanFailure,
	GS_ExecutionFailure,
	GS_InProgress,
	GS_Success,
	GS_MAX
};

class CTGAME_API UGoalQueue : public UObject{
public:
	class UGoalObject* Head;
	class UGoalObject* Tail;
	INT FailuresLeft;
	class ACTBot* Bot;

	DECLARE_CLASS(UGoalQueue,UObject,0,CTGame)
	NO_DEFAULT_CONSTRUCTOR(UGoalQueue)
};

/*
*	GoalObject
*/

class CTGAME_API UGoalObject : public UGoalQueue{
public:
	class UGoalObject* NextGoal;
	class UGoalObject* PrevGoal;
	BYTE Status;
	BITFIELD TopLevel:1;
	FLOAT Utility;

	DECLARE_CLASS(UGoalObject,UGoalQueue,0,CTGame)
};

/*
*	GOAL_ChangeAnimTurn
*/

enum EAimTurnGoal{
	ATG_Focus,
	ATG_FocalPoint,
	ATG_FocalDir,
	ATG_MAX
};

class CTGAME_API UGOAL_ChangeAimTurn : public UGoalObject{
public:
	class AActor* Focus;
	FVector FocalPoint;
	FRotator FocalDir;
	BYTE AimTurnGoal;
	BITFIELD EnableAim:1;
	BITFIELD EnableTurn:1;
	BITFIELD TurnExact:1;
	BITFIELD EnableHead:1;

	DECLARE_CLASS(UGOAL_ChangeAimTurn,UGoalObject,0,CTGame)

private:
	UGOAL_ChangeAimTurn();
};

/*
*	GOAL_ChangePhysics
*/

struct FPhysicsData{
	BYTE Physics;
	BYTE IdleState;
	FVector Acceleration;
	FVector Velocity;
	BITFIELD ShouldCrouch:1;
};

class CTGAME_API UGOAL_ChangePhysics : public UGoalObject{
public:
	FPhysicsData NewPhysicsData;
	INT ChangeFlags;

	DECLARE_CLASS(UGOAL_ChangePhysics,UGoalObject,0,CTGame)

private:
	UGOAL_ChangePhysics();
};

/*
*	GOAL_ChangeWeapon
*/

class CTGAME_API UGOAL_ChangeWeapon : public UGoalObject{
public:
	INT WeaponSlot;
	class AWeapon* Weapon;

	DECLARE_CLASS(UGOAL_ChangeWeapon,UGoalObject,0,CTGame)

private:
	UGOAL_ChangeWeapon();
};

/*
*	GOAL_CheckCorpse
*/

class CTGAME_API UGOAL_CheckCorpse : public UGoalObject{
public:
	class APawn* Corpse;
	BITFIELD OriginalSaveMyCorpse:1;

	DECLARE_CLASS(UGOAL_CheckCorpse,UGoalObject,0,CTGame)

	UGOAL_CheckCorpse();
};

/*
*	GOAL_Crouch
*/

class CTGAME_API UGOAL_Crouch : public UGoalObject{
public:
	BITFIELD Crouch:1;

	DECLARE_CLASS(UGOAL_Crouch,UGoalObject,0,CTGame)

private:
	UGOAL_Crouch();
};

/*
*	GOAL_ExecuteMarker
*/

class CTGAME_API UGOAL_ExecuteMarker : public UGoalObject{
public:
	class ASquadMarker* Marker;
	FLOAT MarkerPriority;
	BITFIELD bCancelIfUnderway:1;
	BITFIELD bWaitUntilFinish:1;

	DECLARE_CLASS(UGOAL_ExecuteMarker,UGoalObject,0,CTGame)

private:
	UGOAL_ExecuteMarker();
};

/*
*	GOAL_FinishingMove
*/

class CTGAME_API UGOAL_FinishingMove : public UGoalObject{
public:
	class ACTPawn* Target;
	FName Animation;
	FVector OffsetFromEnemy;
	FVector StartPos;
	BITFIELD ExecutedMove:1;
	BITFIELD bWasGodMode:1;

	DECLARE_CLASS(UGOAL_FinishingMove,UGoalObject,0,CTGame)
	NO_DEFAULT_CONSTRUCTOR(UGOAL_FinishingMove)
};

/*
*	GOAL_Follow
*/

class CTGAME_API UGOAL_Follow : public UGoalObject{
public:
	BITFIELD SucceedOnApproach:1;
	BITFIELD MatchSpeed:1;
	BITFIELD Formation:1;
	BITFIELD bNoPath:1;
	BITFIELD bAnchor:1;
	BITFIELD bFollowAnchor:1;
	BITFIELD bCanMoveDirect:1;
	BITFIELD bCheatedCollision:1;
	BITFIELD bMovedDirectLastTime:1;
	FLOAT LastCanMoveToCheck;
	FLOAT FollowOffsetForward;
	FLOAT FollowOffsetRight;
	class AActor* FollowTarget;
	FLOAT MinimumDistance;
	FLOAT MaximumDistance;
	FVector PreviousLocation;
	FLOAT StuckTime;

	DECLARE_CLASS(UGOAL_Follow,UGoalObject,0,CTGame)
	NO_DEFAULT_CONSTRUCTOR(UGOAL_Follow)
};

/*
*	GOAL_SquadFollow
*/

class CTGAME_API UGOAL_SquadFollow : public UGOAL_Follow{
public:
	DECLARE_CLASS(UGOAL_SquadFollow,UGOAL_Follow,0,CTGame)
	NO_DEFAULT_CONSTRUCTOR(UGOAL_SquadFollow)
};

/*
*	GOAL_FollowLink
*/

class CTGAME_API UGOAL_FollowLink : public UGoalObject{
public:
	class UReachSpec* Link;
	FVector Destination;
	FVector PreviousLocation;
	FLOAT StuckTime;
	BITFIELD bLastLink:1;
	BITFIELD bCheatedCollision:1;
	BITFIELD bOldBlockActors:1;
	BITFIELD bOldBlockPlayers:1;

	DECLARE_CLASS(UGOAL_FollowLink,UGoalObject,0,CTGame)
};

/*
*	GOAL_GetBacta
*/

class CTGAME_API UGOAL_GetBacta : public UGoalObject{
public:
	INT Stage;
	class ABactaDispenser* Dispenser;

	DECLARE_CLASS(UGOAL_GetBacta,UGoalObject,0,CTGame)

private:
	UGOAL_GetBacta();
};

/*
*	GOAL_GoThroughDoor
*/

class CTGAME_API UGOAL_GoThroughDoor : public UGoalObject{
public:
	class UReachSpec* Link;
	class AMover* Door;

	DECLARE_CLASS(UGOAL_GoThroughDoor,UGoalObject,0,CTGame)

private:
	UGOAL_GoThroughDoor();
};

/*
*	GOAL_Goto
*/

class CTGAME_API UGOAL_Goto : public UGoalObject{
public:
	FVector Destination;
	FVector ToleranceCheckLocation;
	class ANavigationPoint* Goal;
	FLOAT ToleranceSquared;
	BITFIELD bMatchOrientation:1;
	BITFIELD bPathComplete:1;
	BITFIELD bOverrideBlocked:1;

	DECLARE_CLASS(UGOAL_Goto,UGoalObject,0,CTGame)

private:
	UGOAL_Goto();
};

/*
*	GOAL_GotoCautious
*/

class CTGAME_API UGOAL_GotoCautious : public UGoalObject{
public:
	FVector Destination;
	FVector ToleranceCheckLocation;
	class ANavigationPoint* Goal;
	TArrayNoInit<class ANavigationPoint*> CoverPts;
	INT Index;
	FLOAT ToleranceSquared;
	BITFIELD bMatchOrientation:1;
	BITFIELD bPathComplete:1;

	DECLARE_CLASS(UGOAL_GotoCautious,UGoalObject,0,CTGame)

private:
	UGOAL_GotoCautious();
};

/*
*	GOAL_GotoPointBlind
*/

class CTGAME_API UGOAL_GotoPointBlind : public UGoalObject{
public:
	FVector Goal;
	FLOAT ToleranceSquared;
	BITFIELD StopUponCompletion:1;

	DECLARE_CLASS(UGOAL_GotoPointBlind,UGoalObject,0,CTGame)

private:
	UGOAL_GotoPointBlind();
};

/*
*	GOAL_GotoSpecial
*/

class CTGAME_API UGOAL_GotoSpecial : public UGoalObject{
public:
	class ANavigationPoint* Goal;
	FLOAT Tolerance;
	BITFIELD bReleaseNodeOnFinish:1;
	BITFIELD bEndInCrouch:1;
	BITFIELD bBackToWall:1;
	BITFIELD bAtNode:1;
	BITFIELD bKnockoverCover:1;

	DECLARE_CLASS(UGOAL_GotoSpecial,UGoalObject,0,CTGame)

private:
	UGOAL_GotoSpecial();
};

/*
*	GOAL_HealOther
*/

class CTGAME_API UGOAL_HealOther : public UGoalObject{
public:
	class APawn* Other;
	INT Stage;
	BITFIELD bChangedCommandedEnemy:1;

	DECLARE_CLASS(UGOAL_HealOther,UGoalObject,0,CTGame)

private:
	UGOAL_HealOther();
};

/*
*	GOAL_JumpTo
*/

class CTGAME_API UGOAL_JumpTo : public UGoalObject{
public:
	class AActor* Goal;
	FVector Destination;
	FLOAT ToleranceSquared;
	BITFIELD StartedJump:1;
	BITFIELD CompletedJump:1;

	DECLARE_CLASS(UGOAL_JumpTo,UGoalObject,0,CTGame)

private:
	UGOAL_JumpTo();
};

/*
*	GOAL_LaunchMissiles
*/

class CTGAME_API UGOAL_LaunchMissiles : public UGoalObject{
public:
	DECLARE_CLASS(UGOAL_LaunchMissiles,UGoalObject,0,CTGame)
};

/*
*	GOAL_ManTurret
*/

class CTGAME_API UGOAL_ManTurret : public UGoalObject{
public:
	class ATurret* Turret;
	BITFIELD Activate:1;
	BITFIELD InitiatedSequence:1;
	BITFIELD bWasGodMode:1;

	DECLARE_CLASS(UGOAL_ManTurret,UGoalObject,0,CTGame)
	NO_DEFAULT_CONSTRUCTOR(UGOAL_ManTurret)
};

/*
*	GOAL_MeleeAttack
*/

class CTGAME_API UGOAL_MeleeAttack : public UGoalObject{
public:
	class AActor* Target;
	FLOAT MaxAttackTime;
	INT NumAttacks;
	FLOAT CompletionTime;
	FLOAT NextReachabilityCheckTime;

	DECLARE_CLASS(UGOAL_MeleeAttack,UGoalObject,0,CTGame)
	NO_DEFAULT_CONSTRUCTOR(UGOAL_MeleeAttack)
};

/*
*	GOAL_MoveAndRotate
*/

class CTGAME_API UGOAL_MoveAndRotate : public UGoalObject{
public:
	FVector Location;
	FRotator Rotation;
	FVector LookAt;
	BITFIELD bUseRotator:1;
	BITFIELD bExact:1;

	DECLARE_CLASS(UGOAL_MoveAndRotate,UGoalObject,0,CTGame)

private:
	UGOAL_MoveAndRotate();
};

/*
*	GOAL_PlayAnim
*/

class CTGAME_API UGOAL_PlayAnim : public UGoalObject{
public:
	FName Sequence;
	FName Bone;
	INT Channel;
	FLOAT Time;
	BITFIELD bLoop:1;
	BITFIELD DisableImpactAnims:1;
	BITFIELD IsADodge:1;

	DECLARE_CLASS(UGOAL_PlayAnim,UGoalObject,0,CTGame)
	NO_DEFAULT_CONSTRUCTOR(UGOAL_PlayAnim)
};

/*
*	GOAL_PlaySound
*/

class CTGAME_API UGOAL_PlaySound : public UGoalObject{
public:
	class USound* Sound;
	BYTE AudioCue;
	FLOAT CueInterval;
	FLOAT CueTimeout;
	class AActor* CueSubject;
	BITFIELD WaitToFinish:1;
	BITFIELD UseSquadQueue:1;

	DECLARE_CLASS(UGOAL_PlaySound,UGoalObject,0,CTGame)
	NO_DEFAULT_CONSTRUCTOR(UGOAL_PlaySound)
};

/*
*	GOAL_Shoot
*/

class CTGAME_API UGOAL_Shoot : public UGoalObject{
public:
	FLOAT Time;
	INT NumShots;

	DECLARE_CLASS(UGOAL_Shoot,UGoalObject,0,CTGame)

private:
	UGOAL_Shoot();
};

/*
*	GOAL_Sleep
*/

class CTGAME_API UGOAL_Sleep : public UGoalObject{
public:
	FLOAT Time;

	DECLARE_CLASS(UGOAL_Sleep,UGoalObject,0,CTGame)

private:
	UGOAL_Sleep();
};

/*
*	GOAL_ThrowGrenade
*/

class CTGAME_API UGOAL_ThrowGrenade : public UGoalObject{
public:
	class UClass* GrenadeType;
	FName ThrowAnimation;

	DECLARE_CLASS(UGOAL_ThrowGrenade,UGoalObject,0,CTGame)
};

/*
*	GOAL_Trigger
*/

class CTGAME_API UGOAL_Trigger : public UGoalObject{
public:
	class AActor* Other;

	DECLARE_CLASS(UGOAL_Trigger,UGoalObject,0,CTGame)

private:
	UGOAL_Trigger();
};

/*
*	GOAL_TurnTo
*/

class CTGAME_API UGOAL_TurnTo : public UGoalObject{
public:
	class AActor* Other;
	class AActor* OldFocus;
	FVector Location;
	FRotator Rotation;
	BITFIELD bExact:1;
	BITFIELD bUseRotation:1;

	DECLARE_CLASS(UGOAL_TurnTo,UGoalObject,0,CTGame)

private:
	UGOAL_TurnTo();
};

/*
*	GOAL_UseActor
*/

class CTGAME_API UGOAL_UseActor : public UGoalObject{
public:
	class AActor* Other;

	DECLARE_CLASS(UGOAL_UseActor,UGoalObject,0,CTGame)
	NO_DEFAULT_CONSTRUCTOR(UGOAL_UseActor)
};

/*
*	GOAL_WaitForEvent
*/

class CTGAME_API UGOAL_WaitForEvent : public UGoalObject{
public:
	FName Event;
	BITFIELD Triggered:1;

	DECLARE_CLASS(UGOAL_WaitForEvent,UGoalObject,0,CTGame)

private:
	UGOAL_WaitForEvent();
};

/*
*	GOAL_WaitForLanding
*/

class CTGAME_API UGOAL_WaitForLanding : public UGoalObject{
public:
	DECLARE_CLASS(UGOAL_WaitForLanding,UGoalObject,0,CTGame)
};

/*
*	GOAL_WaitForScriptState
*/

class CTGAME_API UGOAL_WaitForScriptState : public UGoalObject{
public:
	class AActor* Other;
	FName State;

	DECLARE_CLASS(UGOAL_WaitForScriptState,UGoalObject,0,CTGame)
};

/*
*	GOAL_WaitUntilNear
*/

class CTGAME_API UGOAL_WaitUntilNear : public UGoalObject{
public:
	FLOAT DistanceSqr;
	class AActor* Actor;

	DECLARE_CLASS(UGOAL_WaitUntilNear,UGoalObject,0,CTGame)
};

/*
*	IdleInfo
*/

struct CTGAME_API FIdleAnimInfo{
	FName AnimationName;
	FLOAT RelativeWeight;
};

class CTGAME_API UIdleInfo : public UObject{
public:
	TArrayNoInit<FIdleAnimInfo> IdleAnimations;
	FLOAT MinTimeUntilNextCheck;
	FLOAT MaxTimeUntilNextCheck;

	DECLARE_CLASS(UIdleInfo,UObject,0,CTGame)
	NO_DEFAULT_CONSTRUCTOR(UIdleInfo)
};

/*
*	LocalSituation
*/

class CTGAME_API ULocalSituation : public UObject{
public:
	INT TotalEnemies;
	INT TotalAllies;
	INT EnemiesICanDetect;
	INT AlliesNearby;
	FLOAT LastUpdateTime;
	FLOAT ClosestEnemyDistSqr;
	class AActor* BestTarget;

	DECLARE_CLASS(ULocalSituation,UObject,0,CTGame)
};

/*
*	ACTION_MoveToPoint
*/

class CTGAME_API UACTION_MoveToPoint : public ULatentScriptedAction{
public:
	FName DestinationTag;
	class AActor* MoveTarget;
	BITFIELD WalkToPoint:1;
	BITFIELD OrientToPoint:1;

	DECLARE_CLASS(UACTION_MoveToPoint,ULatentScriptedAction,0,CTGame)
	NO_DEFAULT_CONSTRUCTOR(UACTION_MoveToPoint)
};

/*
*	StanceDefault
*/

class CTGAME_API UStanceDefault : public USquadStance{
public:
	DECLARE_CLASS(UStanceDefault,USquadStance,0,CTGame)
	NO_DEFAULT_CONSTRUCTOR(UStanceDefault)
};

/*
*	StanceEngageTarget
*/

class CTGAME_API UStanceEngageTarget : public USquadStance{
public:
	DECLARE_CLASS(UStanceEngageTarget,USquadStance,0,CTGame)
	NO_DEFAULT_CONSTRUCTOR(UStanceEngageTarget)
};

/*
*	StanceFormUp
*/

class CTGAME_API UStanceFormUp : public USquadStance{
public:
	DECLARE_CLASS(UStanceFormUp,USquadStance,0,CTGame)
	NO_DEFAULT_CONSTRUCTOR(UStanceFormUp)
};

/*
*	StanceFormUpTight
*/

class CTGAME_API UStanceFormUpTight : public UStanceFormUp{
public:
	DECLARE_CLASS(UStanceFormUpTight,UStanceFormUp,0,CTGame)
	NO_DEFAULT_CONSTRUCTOR(UStanceFormUpTight)
};

/*
*	StanceHold
*/

class CTGAME_API UStanceHold : public USquadStance{
public:
	DECLARE_CLASS(UStanceHold,USquadStance,0,CTGame)
	NO_DEFAULT_CONSTRUCTOR(UStanceHold)
};

/*
*	StanceHoldLoose
*/

class CTGAME_API UStanceHoldLoose : public UStanceHold{
public:
	DECLARE_CLASS(UStanceHoldLoose,UStanceHold,0,CTGame)
	NO_DEFAULT_CONSTRUCTOR(UStanceHoldLoose)
};

/*
*	StancePreviousOrder
*/

class CTGAME_API UStancePreviousOrder : public USquadStance{
public:
	DECLARE_CLASS(UStancePreviousOrder,USquadStance,0,CTGame)
	NO_DEFAULT_CONSTRUCTOR(UStancePreviousOrder)
};

/*
*	StanceSearchAndDestroy
*/

class CTGAME_API UStanceSearchAndDestroy : public USquadStance{
public:
	DECLARE_CLASS(UStanceSearchAndDestroy,USquadStance,0,CTGame)
	NO_DEFAULT_CONSTRUCTOR(UStanceSearchAndDestroy)
};

/*
*	StanceSecurePosition
*/

class CTGAME_API UStanceSecurePosition : public USquadStance{
public:
	DECLARE_CLASS(UStanceSecurePosition,USquadStance,0,CTGame)
	NO_DEFAULT_CONSTRUCTOR(UStanceSecurePosition)
};

/*
*	StateObject
*/

class CTGAME_API UStateObject : public UObject{
public:
	class ACTBot* Bot;
	BITFIELD Enabled:1;
	class UGoalQueue* Goals;

	DECLARE_CLASS(UStateObject,UObject,0,CTGame)
};

/*
*	StateAbstractAttack
*/

class CTGAME_API UStateAbstractAttack : public UStateObject{
public:
	FLOAT ReadyDistance;
	FLOAT SafeDistance;
	FVector MoveModePosition;
	FVector LocalEnemyPos;
	FVector DirToEnemy;
	FLOAT DistToEnemy;
	FLOAT NextMoveModeTime;
	FLOAT NextToggleAttackTime;
	class UGOAL_Follow* FollowEnemyGoal;
	BITFIELD InOffensiveMode:1;
	BITFIELD CanSeeEnemy:1;
	BITFIELD ForceMoveModeDecision:1;
	BITFIELD MoveModeBegun:1;
	BITFIELD FinishedMovement:1;
	BITFIELD Melee:1;
	BITFIELD FallBackFromEnemy:1;
	INT LastManuver;

	DECLARE_CLASS(UStateAbstractAttack,UStateObject,0,CTGame)
};

/*
*	StateAttack
*/

class CTGAME_API UStateAttack : public UStateAbstractAttack{
public:
	DECLARE_CLASS(UStateAttack,UStateAbstractAttack,0,CTGame)
};

/*
*	StateBattleDroidAttack
*/

class CTGAME_API UStateBattleDroidAttack : public UStateAbstractAttack{
public:
	FLOAT NextManuverTime;
	FLOAT MaxManuverTime;
	FLOAT MoveIntervalDist;

	DECLARE_CLASS(UStateBattleDroidAttack,UStateAbstractAttack,0,CTGame)
};

/*
*	StateBerserk
*/

class CTGAME_API UStateBerserk : public UStateAbstractAttack{
public:
	FLOAT BerserkThreshold;
	FLOAT MaxBerserkRange;
	FLOAT BerserkDamageFactor;

	DECLARE_CLASS(UStateBerserk,UStateAbstractAttack,0,CTGame)
};

/*
*	StateDroidekaAttack
*/

class CTGAME_API UStateDroidekaAttack : public UStateAbstractAttack{
public:
	DECLARE_CLASS(UStateDroidekaAttack,UStateAbstractAttack,0,CTGame)
};

/*
*	StateDroneAttack
*/

class CTGAME_API UStateDroneAttack : public UStateAbstractAttack{
public:
	FLOAT LungeDist;
	BITFIELD IsMeleeAttacking:1;

	DECLARE_CLASS(UStateDroneAttack,UStateAbstractAttack,0,CTGame)
};

/*
*	StateFlyingAttack
*/

class CTGAME_API UStateFlyingAttack : public UStateAbstractAttack{
public:
	class APawn* Victim;
	FLOAT KamikazeThreshold;
	FLOAT PostFirePauseTime;
	FLOAT MinDodgeDist;
	FLOAT AttachDist;
	FLOAT DrillTime;
	class UClass* DrillDamageType;
	BITFIELD CanKamikaze:1;
	BITFIELD CanHeadAttach:1;

	DECLARE_CLASS(UStateFlyingAttack,UStateAbstractAttack,0,CTGame)
};

/*
*	StateGeonosianWarriorAttack
*/

class CTGAME_API UStateGeonosianWarriorAttack : public UStateAbstractAttack{
public:
	FLOAT LungeDist;
	FLOAT JumpDist;
	FLOAT OffensiveJumpProbability;
	FLOAT DefensiveJumpProbability;
	FLOAT DefensiveJumpProbabilityForPlayer;
	BITFIELD IsMeleeAttacking:1;
	BITFIELD MustDoDefensiveJump:1;

	DECLARE_CLASS(UStateGeonosianWarriorAttack,UStateAbstractAttack,0,CTGame)
};

/*
*	StateHeavyAttack
*/

class CTGAME_API UStateHeavyAttack : public UStateAbstractAttack{
public:
	FLOAT NextManuverTime;
	FLOAT MaxManuverTime;
	FLOAT MoveIntervalDist;
	FLOAT NextShieldTime;
	FLOAT MinShieldTime;
	FLOAT ShieldFactor;
	BITFIELD HatesDroids:1;

	DECLARE_CLASS(UStateHeavyAttack,UStateAbstractAttack,0,CTGame)
};

/*
*	StateSimpleAttack
*/

class CTGAME_API UStateSimpleAttack : public UStateAbstractAttack{
public:
	DECLARE_CLASS(UStateSimpleAttack,UStateAbstractAttack,0,CTGame)
};

/*
*	StateSpiderDroidAttack
*/

class CTGAME_API UStateSpiderDroidAttack : public UStateAbstractAttack{
public:
	BITFIELD bCanBlock:1;
	BITFIELD bCanBlockNow:1;
	FLOAT ShotRange;
	INT ProxDefNPCThreshold;
	FLOAT ProxDefRange;
	FLOAT ProxDefMinInterval;
	FLOAT NextProxDefTime;
	FLOAT MinDefenseInterval;
	FLOAT NextDefenseTime;
	FRange BlinkInterval;
	FLOAT NextBlinkTime;
	class AAccessory* Scanner;

	DECLARE_CLASS(UStateSpiderDroidAttack,UStateAbstractAttack,0,CTGame)
};

/*
*	StateSquadAttack
*/

class CTGAME_API UStateSquadAttack : public UStateAbstractAttack{
public:
	TArrayNoInit<class ANavigationPoint*> BadCombatPts;

	DECLARE_CLASS(UStateSquadAttack,UStateAbstractAttack,0,CTGame)
};

/*
*	StateStationaryAttack
*/

class CTGAME_API UStateStationaryAttack : public UStateAbstractAttack{
public:
	DECLARE_CLASS(UStateStationaryAttack,UStateAbstractAttack,0,CTGame)
};

/*
*	StateTrandoshanAttack
*/

class CTGAME_API UStateTrandoshanAttack : public UStateAbstractAttack{
public:
	FRange CoverHideTime;
	FLOAT MinStepInterval;
	FLOAT AllySearchRadius;
	FName AttackGesture;
	FName RetreatGesture;
	FName ChangeCoverGesture;
	FName HoldGesture;
	BITFIELD FavorDefensiveCover:1;

	DECLARE_CLASS(UStateTrandoshanAttack,UStateAbstractAttack,0,CTGame)
};

/*
*	StateTurretAttack
*/

class CTGAME_API UStateTurretAttack : public UStateAbstractAttack{
public:
	INT NumKills;
	FLOAT LastFocusChange;
	FLOAT LastSetEnemyTime;
	BITFIELD MountedTurret:1;

	DECLARE_CLASS(UStateTurretAttack,UStateAbstractAttack,0,CTGame)
};

/*
*	StateWookieeAttack
*/

class CTGAME_API UStateWookieeAttack : public UStateAbstractAttack{
public:
	DECLARE_CLASS(UStateWookieeAttack,UStateAbstractAttack,0,CTGame)
};

/*
*	StateDispensing
*/

class CTGAME_API UStateDispensing : public UStateObject{
public:
	DECLARE_CLASS(UStateDispensing,UStateObject,0,CTGame)
};

/*
*	StateFreakOut
*/

class CTGAME_API UStateFreakOut : public UStateObject{
public:
	FLOAT Radius;
	FLOAT Time;
	FLOAT EndTime;
	class UClass* DeathDamageType;

	DECLARE_CLASS(UStateFreakOut,UStateObject,0,CTGame)
};

/*
*	StateIdle
*/

class CTGAME_API UStateIdle : public UStateObject{
public:
	FLOAT TimeUntilNextIdle;

	DECLARE_CLASS(UStateIdle,UStateObject,0,CTGame)
};

/*
*	StateIdleSquad
*/

class CTGAME_API UStateIdleSquad : public UStateObject{
public:
	FLOAT ActivateDistance;
	FLOAT ReleaseDistance;
	FLOAT TetherUtility;
	class APawn* TetherTarget;
	FLOAT LastCoverCheck;
	class AActor* UsefulActor;

	DECLARE_CLASS(UStateIdleSquad,UStateObject,0,CTGame)
};

/*
*	StateInvestigate
*/

class CTGAME_API UStateInvestigate : public UStateObject{
public:
	class UStimulus* CurrentStimulus;
	FLOAT CurrentStimulusPriority;
	BITFIELD bInvestigating:1;

	DECLARE_CLASS(UStateInvestigate,UStateObject,0,CTGame)
};

/*
*	StateMarker
*/

class CTGAME_API UStateMarker : public UStateObject{
public:
	FLOAT PriorityNoGoals;

	DECLARE_CLASS(UStateMarker,UStateObject,0,CTGame)
};

/*
*	StatePatrol
*/

class CTGAME_API UStatePatrol : public UStateObject{
public:
	INT GoalIndex;
	INT Step;
	BITFIELD ChangedGodStatus:1;
	BITFIELD InitialGodStatus:1;

	DECLARE_CLASS(UStatePatrol,UStateObject,0,CTGame)
};

/*
*	StateRetreat
*/

class CTGAME_API UStateRetreat : public UStateObject{
public:
	class ANavigationPoint* RetreatGoal;
	FLOAT HealthThreshold;
	FLOAT DamageThreshold;
	FRange EnemyDist;

	DECLARE_CLASS(UStateRetreat,UStateObject,0,CTGame)
};

/*
*	StateScriptWrapper
*/

class CTGAME_API UStateScriptWrapper : public UStateObject{
public:
	FLOAT Priority;
	FName WrappedState;

	DECLARE_CLASS(UStateScriptWrapper,UStateObject,0,CTGame)
};

/*
*	StateShutdown
*/

class CTGAME_API UStateShutdown : public UStateObject{
public:
	BYTE OldIdleState;
	BYTE OldPhysics;
	BITFIELD StartedShutdown:1;

	DECLARE_CLASS(UStateShutdown,UStateObject,0,CTGame)
};

/*
*	StateAsleep
*/

class CTGAME_API UStateAsleep : public UStateShutdown{
public:
	DECLARE_CLASS(UStateAsleep,UStateShutdown,0,CTGame)
};

/*
*	StatePerched
*/

class CTGAME_API UStatePerched : public UStateShutdown{
public:
	class APerch* MyPerch;
	FLOAT NextDetachTime;
	FLOAT DetachDelayTime;
	class AActor* StimInstigator;

	DECLARE_CLASS(UStatePerched,UStateShutdown,0,CTGame)
};

/*
*	StateSquad
*/

class CTGAME_API UStateSquad : public UStateObject{
public:
	FLOAT PriorityNoGoals;

	DECLARE_CLASS(UStateSquad,UStateObject,0,CTGame)
};

/*
*	StateTether
*/

class CTGAME_API UStateTether : public UStateObject{
public:
	FLOAT LastCoverCheck;

	DECLARE_CLASS(UStateTether,UStateObject,0,CTGame)
};

/*
*	StateWander
*/

class CTGAME_API UStateWander : public UStateObject{
public:
	DECLARE_CLASS(UStateWander,UStateObject,0,CTGame)
};

#if SUPPORTS_PRAGMA_PACK
#pragma pack (pop)
#endif

#endif //CTGAME_NATIVE_DEFS
