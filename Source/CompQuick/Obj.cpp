#include "Obj.h"
#include "Logging/LogMacros.h"

DECLARE_LOG_CATEGORY_EXTERN(LogMyObj, Log, All);

UObj::UObj()
{
	FString OuterName = GetOuter() ? GetOuter()->GetName() : FString(TEXT("nullptr"));
	UE_LOG(LogMyObj, Log, TEXT("UObj::UObj: Name=%s; Outer=%s"), *GetName(), *OuterName);
}

DEFINE_LOG_CATEGORY(LogMyObj);