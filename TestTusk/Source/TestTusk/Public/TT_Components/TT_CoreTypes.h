#pragma once
#include <TT_CoreTypes.generated.h>

UENUM(BlueprintType)
enum class EWeapons : uint8
{
	None =0,
	GrenadeLauncher ,
	Rifle
};

DECLARE_MULTICAST_DELEGATE(FOnDeath);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnHealthChanged, float, float);