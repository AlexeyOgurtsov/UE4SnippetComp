#include "CompBlueprintLib.h"
#include "TheActor.h"
#include "Logging/LogMacros.h"

DECLARE_LOG_CATEGORY_EXTERN(LogCompLib, Log, All);

void UCompBlueprintLib::LogCounter(const FString& InLabel, const FString& InActorName, int32 InValue)
{
	UE_LOG(LogCompLib, Log, TEXT("Obj=%s: Counter: %s=%d"), *InActorName, *InLabel, InValue);
}

void UCompBlueprintLib::LogAllCounters(ATheActor* InActor)
{
	FString const ActorName = InActor->GetName();

	if(InActor->GetObj())
	{
		LogCounter(TEXT("Obj"), ActorName, InActor->GetObj()->GetCounter());
	}
	else
	{
		UE_LOG(LogCompLib, Log, TEXT("Obj is nullptr"));
	}
	if(InActor->GetInstancedObj())
	{
		LogCounter(TEXT("InstancedObj"), ActorName, InActor->GetInstancedObj()->GetCounter());
	}
	else
	{
		UE_LOG(LogCompLib, Log, TEXT("InstancedObj is nullptr"));
	}
	if(InActor->GetEditObj())
	{
		LogCounter(TEXT("EditObj"), ActorName, InActor->GetEditObj()->GetCounter());
	}
	else
	{
		UE_LOG(LogCompLib, Log, TEXT("EditObj is nullptr"));
	}	
	if(InActor->GetInstancedEditObj())
	{
		LogCounter(TEXT("InstancedEditObj"), ActorName, InActor->GetInstancedEditObj()->GetCounter());
	}
	else
	{
		UE_LOG(LogCompLib, Log, TEXT("InstancedEditObj is nullptr"));
	}	
	if(InActor->GetCompSubobject())
	{
		LogCounter(TEXT("CompSubobject"), ActorName, InActor->GetCompSubobject()->GetCounter());
	}
	else
	{
		UE_LOG(LogCompLib, Log, TEXT("CompSubobject is nullptr"));
	}
	if(InActor->GetCompNewObj())
	{
		LogCounter(TEXT("CompNewObj"), ActorName, InActor->GetCompNewObj()->GetCounter());
	}
	else
	{
		UE_LOG(LogCompLib, Log, TEXT("CompNewObj is nullptr"));
	}
	if(InActor->GetEditComp())
	{
		LogCounter(TEXT("EditComp"), ActorName, InActor->GetEditComp()->GetCounter());
	}
	else
	{
		UE_LOG(LogCompLib, Log, TEXT("EditComp is nullptr"));
	}
	if(InActor->GetInstancedEditComp())
	{
		LogCounter(TEXT("InstancedEditComp"), ActorName, InActor->GetInstancedEditComp()->GetCounter());
	}
	else
	{
		UE_LOG(LogCompLib, Log, TEXT("InstancedEditComp is nullptr"));
	}
}

DEFINE_LOG_CATEGORY(LogCompLib);