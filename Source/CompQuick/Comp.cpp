#include "Comp.h"
#include "Logging/LogMacros.h"

DECLARE_LOG_CATEGORY_EXTERN(LogComp, Log, All);

UComp::UComp()
{
	// Logging default properties:
	// @TODO

	// Initializing properties
	bWantsInitializeComponent = true;
	
	// Warning! bWantsBeginPlay is not considered anymore (I see the warning)
	//bWantsBeginPlay = true;
	
	// Ticking
	bTickInEditor = false;
	
	bAutoActivate = true;

	// WARNING!!! Ever if component is created with CreateDefaultSubobject, 
	// it must have bAutoRegister = true to be registered automatically!
	bAutoRegister = true;
}

void UComp::PostInitProperties()
{
	UE_LOG(LogComp, Log, TEXT("UComp::PostInitProperties(): Name=%s; ActorName=%s"), *GetName(), GetOwner() ? *GetOwner()->GetName() : TEXT(""));
	UE_LOG(LogComp, Log, TEXT("bRegistered=%s"), bRegistered ? TEXT("YES") : TEXT("no"));
	Super::PostInitProperties();
}

void UComp::BeginPlay()
{
	UE_LOG(LogComp, Log, TEXT("UComp::BeginPlay(): Name=%s; ActorName=%s"), *GetName(), GetOwner() ? *GetOwner()->GetName() : TEXT(""));
	UE_LOG(LogComp, Log, TEXT("bRegistered=%s"), bRegistered ? TEXT("YES") : TEXT("no"));
	Super::BeginPlay();
}

void UComp::InitializeComponent()
{
	UE_LOG(LogComp, Log, TEXT("UComp::InitializeComponent(): Name=%s; ActorName=%s"), *GetName(), GetOwner() ? *GetOwner()->GetName() : TEXT(""));
	Super::InitializeComponent();
}


void UComp::Activate(bool bReset)
{
	UE_LOG(LogComp, Log, TEXT("UComp::Activate(): Name=%s; ActorName=%s"), *GetName(), GetOwner() ? *GetOwner()->GetName() : TEXT(""));
	UE_LOG(LogComp, Log, TEXT("bReset=%s"), bRegistered ? TEXT("YES") : TEXT("no"));
	UE_LOG(LogComp, Log, TEXT("bRegistered=%s"), bRegistered ? TEXT("YES") : TEXT("no"));
	Super::Activate(bReset);
}

void UComp::Deactivate()
{
	UE_LOG(LogComp, Log, TEXT("UComp::Deactivate(): Name=%s; ActorName=%s"), *GetName(), GetOwner() ? *GetOwner()->GetName() : TEXT(""));
	UE_LOG(LogComp, Log, TEXT("bRegistered=%s"), bRegistered ? TEXT("YES") : TEXT("no"));
	Super::Deactivate();
}


void UComp::OnRegister()
{
	Super::OnRegister();
	UE_LOG(LogComp, Log, TEXT("UComp::OnRegister(): Name=%s; ActorName=%s"), *GetName(), GetOwner() ? *GetOwner()->GetName() : TEXT(""));
}

void UComp::OnUnregister()
{
	UE_LOG(LogComp, Log, TEXT("UComp::OnUnregister(): Name=%s; ActorName=%s"), *GetName(), GetOwner() ? *GetOwner()->GetName() : TEXT(""));
	Super::OnUnregister();
}

//void UComp::OnComponentDestroyed()
//{
//	Super::OnComponentDestroyed();
//	UE_LOG(LogComp, Log, TEXT("UComp::OnComponentDestroyed(): Name=%s; ActorName=%s"), *GetName(), GetOwner() ? *GetOwner()->GetName() : TEXT(""));
//}


void UComp::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	if(ShouldLog_TickComponent())
	{
		UE_LOG(LogComp, Log, TEXT("UComp::TickComponent(): Name=%s; ActorName=%s; TickCounter=%d"), *GetName(), GetOwner() ? *GetOwner()->GetName() : TEXT(""), TickCounter);
	}
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	TickCounter++;
}

bool UComp::ShouldLog_TickComponent() const
{
	return (TickCounter % TicksPerSingleLog) == 0;
}

DEFINE_LOG_CATEGORY(LogComp);