#pragma once

#include "Components/ActorComponent.h"
#include "CompRegister.generated.h"

UCLASS(ClassGroup = (Test), Meta = (BlueprintSpawnableComponent))
class UCompRegister : public UActorComponent
{
	GENERATED_BODY()

public:
	UCompRegister();

	virtual void OnRegister() override;
};