#pragma once

#include "Components/ActorComponent.h"
#include "Comp.generated.h"

UCLASS()
class UComp : public UActorComponent
{
	GENERATED_BODY()

public:
	UComp();

	// ~ UObject Begin
	virtual void PostInitProperties() override;
	virtual void BeginPlay() override;
	// ~ UObject End

	// ~ UActorComponent Begin
	virtual void InitializeComponent() override;
	virtual void Activate(bool bReset) override;
	virtual void Deactivate() override;

	virtual void OnRegister() override;
	virtual void OnUnregister() override;

	//virtual void OnComponentDestroyed() override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	// ~ UActorComponent End

	UFUNCTION(BlueprintPure)
	int32 GetCounter() const { return Counter; }

	UFUNCTION(BlueprintCallable)
	void IncrCounter() { Counter++; }

	// ~ Props Begin
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 PropertyEditAnywhereInt_public = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int32 PropertyEditDefaultsOnlyInt_public = 0;
	// ~ Props End

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	int32 PropertyEditAnywhereInt_Protected = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	int32 PropertyEditDefaultsOnlyInt_Protected = 0;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	int32 PropertyEditAnywhereInt_Private = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	int32 PropertyEditDefaultsOnlyInt_Private = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	int32 Counter = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Meta = (AllowPrivateAccess = true))
	int32 TickCounter = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Meta = (AllowPrivateAccess = true))
	int32 TicksPerSingleLog = 10000;

	UFUNCTION()
	bool ShouldLog_TickComponent() const;
};