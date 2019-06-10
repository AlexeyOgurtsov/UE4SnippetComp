#pragma once

#include "CompBlueprintLib.generated.h"

class ATheActor;

UCLASS()
class UCompBlueprintLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static void LogCounter(const FString& InLabel, const FString& InActorName, int32 InValue);

	UFUNCTION(BlueprintCallable)
	static void LogAllCounters(ATheActor* InActor);
};