#include "CompRegister.h"

#include "Logging/LogMacros.h"

DECLARE_LOG_CATEGORY_EXTERN(LogComp, Log, All);

UCompRegister::UCompRegister()
{
	bAutoRegister = true;
	bAutoActivate = true;
}

void UCompRegister::OnRegister()
{
	FString const ObjectName = GetName();
	FString const ClassName = GetClass()->GetName();
	UE_LOG(LogComp, Log, TEXT("UCompRegister::OnRegister for object \"%s\" of class \"%s\""), *ObjectName, *ClassName);
	Super::OnRegister();
}