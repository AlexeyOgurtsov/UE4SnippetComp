#pragma once

#include "Obj.generated.h"

UCLASS()
class UObj : public UObject
{
	GENERATED_BODY()

public:
	UObj();

	UFUNCTION(BlueprintPure)
	int32 GetCounter() const { return Counter; }

	UFUNCTION(BlueprintCallable)
	void IncrCounter() { Counter++; }

protected:
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	int32 Counter = 0;
};