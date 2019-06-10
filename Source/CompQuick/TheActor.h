#pragma once

#include "GameFramework/Actor.h"
#include "Obj.h"
#include "Comp.h"
#include "TheActor.generated.h"

UCLASS()
class ATheActor : public AActor
{
	GENERATED_BODY()

public:
	ATheActor();

	// ~AActor Begin
	virtual void PostInitProperties() override;

	virtual void PreRegisterAllComponents() override;
	virtual void PostRegisterAllComponents() override;

	virtual void PreInitializeComponents() override;
	virtual void PostInitializeComponents() override;

	virtual void BeginPlay() override;

	virtual void UnregisterAllComponents(bool bForReregister) override;
	virtual void PostUnregisterAllComponents() override;
	// ~AActor End

	UFUNCTION(BlueprintPure)
	//UObj* GetObj() const { return Obj; }
	UObj* GetObj() const { return nullptr; }

	UFUNCTION(BlueprintPure)
	//UObj* GetInstancedObj() const { return InstancedObj; }
	UObj* GetInstancedObj() const { return nullptr; }

	UFUNCTION(BlueprintPure)
	//UObj* GetEditObj() const { return EditableObj; }
	UObj* GetEditObj() const { return nullptr; }

	UFUNCTION(BlueprintPure)
	//UObj* GetInstancedEditObj() { return InstancedEditableObj; }
	UObj* GetInstancedEditObj() { return nullptr; }

	UFUNCTION(BlueprintPure)
	UComp* GetCompSubobject() const { return CompSubobject; }
	//UComp* GetCompSubobject() const { return nullptr; }

	UFUNCTION(BlueprintPure)
	//UComp* GetCompNewObj() const { return CompNewObj; }
	UComp* GetCompNewObj() const { return nullptr; }

	UFUNCTION(BlueprintPure)
	//UComp* GetEditComp() const { return EditableComp; }
	UComp* GetEditComp() const { return nullptr; }

	UFUNCTION(BlueprintPure)
	//UComp* GetInstancedEditComp() const { return InstancedEditableComp; }
	UComp* GetInstancedEditComp() const { return nullptr; }

protected:

private:
	UFUNCTION(BlueprintCallable, Meta = (AllowPrivateAccess = true))
	void Log_GetComponents(bool bInCountOnly);

	UFUNCTION()
	void CreateComp_Subobject();

	UFUNCTION()
	void CreateComp_NewObj();

	UFUNCTION()
	void CreateComp_NewObj_InCtor();

	UFUNCTION()
	void CreateComp_Editable();

	UFUNCTION()
	void CreateSubobj();

	UFUNCTION()
	void CreateInstancedSubobj();

	//UPROPERTY()
	//UObj* Obj = nullptr;

	//UPROPERTY(Instanced)
	//UObj* InstancedObj = nullptr;

	//UPROPERTY(EditDefaultsOnly)
	//UObj* EditableObj = nullptr;

	//UPROPERTY(Instanced, EditDefaultsOnly)
	//UObj* InstancedEditableObj = nullptr;

	UPROPERTY()
	UComp* CompSubobject = nullptr;

	//UPROPERTY()
	//UComp* CompNewObj  = nullptr;

	//UPROPERTY()
	//UComp* CompNewObj_InCtor = nullptr;

	//UPROPERTY(EditDefaultsOnly)
	//UComp* EditableComp = nullptr;

	//UPROPERTY(Instanced, EditDefaultsOnly)
	//UComp* InstancedEditableComp = nullptr;
};