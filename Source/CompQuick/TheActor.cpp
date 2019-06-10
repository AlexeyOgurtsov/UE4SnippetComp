#include "TheActor.h"
#include "Comp.h"
#include "Logging/LogMacros.h"

DECLARE_LOG_CATEGORY_EXTERN(ActLog, Log, All);

ATheActor::ATheActor()
{
	UE_LOG(ActLog, Log, TEXT("ATheActor::ATheActor, Name=%s"), *GetName());

	//CreateSubobj();
	//CreateComp_Editable();
	//CreateInstancedSubobj();
	CreateComp_Subobject();

	// WARNING!!! WARNING!!! WARNING!!!
	// When we create components using NewObject in constructor,
	// it can bring problems while saving the BP:
	// "Graph is linked to external private object ..."
	//CreateComp_NewObj_InCtor();

	Log_GetComponents(/*bCountOnly*/false);
}

void ATheActor::BeginPlay()
{
	UE_LOG(ActLog, Log, TEXT("ATheActor::BeginPlay, Name=%s"), *GetName());

	Super::BeginPlay();

	CreateComp_NewObj();
}

void ATheActor::UnregisterAllComponents(bool bForReregister)
{
	UE_LOG(ActLog, Log, TEXT("ATheActor::UnregisterAllComponents, Name=%s, bForReregister=%s"), *GetName(), (bForReregister ? TEXT("YES") : TEXT("no")));

	Super::UnregisterAllComponents(bForReregister);
}

void ATheActor::PostUnregisterAllComponents()
{
	UE_LOG(ActLog, Log, TEXT("ATheActor::PostUnregisterAllComponents, Name=%s"), *GetName());

	Super::PostUnregisterAllComponents();
}

void ATheActor::PostInitProperties()
{
	UE_LOG(ActLog, Log, TEXT("ATheActor::PostInitProperties, Name=%s"), *GetName());

	Super::PostInitProperties();

	Log_GetComponents(/*bCountOnly*/false);
}

void ATheActor::PreRegisterAllComponents()
{
	UE_LOG(ActLog, Log, TEXT("ATheActor::PreRegisterAllComponents {, Name=%s"), *GetName());

	Super::PreRegisterAllComponents();

	Log_GetComponents(/*bCountOnly*/false);

	UE_LOG(ActLog, Log, TEXT("} ATheActor::PreRegisterAllComponents DONE, Name=%s"), *GetName());
}

void ATheActor::PostRegisterAllComponents()
{
	UE_LOG(ActLog, Log, TEXT("ATheActor::PostRegisterAllComponents, Name=%s"), *GetName());

	Super::PostRegisterAllComponents();

	UE_LOG(ActLog, Log, TEXT("} ATheActor::PostRegisterAllComponents DONE, Name=%s"), *GetName());

	Log_GetComponents(/*bCountOnly*/false);
}

void ATheActor::PreInitializeComponents()
{
	UE_LOG(ActLog, Log, TEXT("ATheActor::PreInitializeComponents, Name=%s {"), *GetName());

	Super::PreInitializeComponents();

	UE_LOG(ActLog, Log, TEXT("} ATheActor::PreInitializeComponents DONE, Name=%s {"), *GetName());

	Log_GetComponents(/*bCountOnly*/false);
}

void ATheActor::PostInitializeComponents()
{
	UE_LOG(ActLog, Log, TEXT("ATheActor::PostInitializeComponents, Name=%s"), *GetName());

	Super::PostInitializeComponents();

	Log_GetComponents(/*bCountOnly*/false);
}

void ATheActor::Log_GetComponents(bool bInCountOnly)
{
	UE_LOG(ActLog, Log, TEXT("Doing GetComponents..."));

	TArray<UActorComponent*> Components;
	GetComponents(Components);

	UE_LOG(ActLog, Log, TEXT("Component Count=%d"), Components.Num());
	if(false == bInCountOnly)
	{
		int32 Index = 0;
		for(UActorComponent* TheComp : Components)
		{
			UE_LOG(ActLog, Log, TEXT("Comp: Index=%d, Name=\"%s\", ClassName=\"%s\""), Index, *TheComp->GetName(), *TheComp->GetClass()->GetName());
			Index++;
		}
	}
}

void ATheActor::CreateComp_Subobject()
{
	UE_LOG(ActLog, Log, TEXT("ATheActor::CreateComp_Subobject(): Name=%s"), *GetName());
	CompSubobject = CreateDefaultSubobject<UComp>(TEXT("SubobjComp"));
}

void ATheActor::CreateComp_NewObj()
{
	//UE_LOG(ActLog, Log, TEXT("ATheActor::CreateComp_NewObj(): Name=%s"), *GetName());
	//CompNewObj = NewObject<UComp>(this, TEXT("NewObjComp"));
}

void ATheActor::CreateComp_NewObj_InCtor()
{
	//UE_LOG(ActLog, Log, TEXT("ATheActor::CreateComp_NewObj_InCtor(): Name=%s"), *GetName());
	//CompNewObj_InCtor = NewObject<UComp>(this, TEXT("NewObjComp_InCtor"));
}

void ATheActor::CreateSubobj()
{
	//UE_LOG(ActLog, Log, TEXT("ATheActor::CreateSubobj(): Name=%s"), *GetName());
	//Obj = CreateDefaultSubobject<UObj>("Subobj");
}

void ATheActor::CreateComp_Editable()
{
	//UE_LOG(ActLog, Log, TEXT("ATheActor::CreateComp_Editable(): Name=%s"), *GetName());
	//EditableComp = CreateDefaultSubobject<UComp>("EditableComp");
}

void ATheActor::CreateInstancedSubobj()
{
	//UE_LOG(ActLog, Log, TEXT("ATheActor::CreateInstancedSubobj(): Name=%s"), *GetName());
	//InstancedObj = CreateDefaultSubobject<UObj>("InstancedObj");
}


DEFINE_LOG_CATEGORY(ActLog);