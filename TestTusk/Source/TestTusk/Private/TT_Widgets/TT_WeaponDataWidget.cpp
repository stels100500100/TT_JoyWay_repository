// Fill out your copyright notice in the Description page of Project Settings.


#include "TT_Widgets/TT_WeaponDataWidget.h"
#include "Components/TextBlock.h"

DEFINE_LOG_CATEGORY_STATIC(WDW, All, All);

void UTT_WeaponDataWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	AmmoCounter->SetText(FText::FromString(FString::FromInt(Ammo)));
}

int32 UTT_WeaponDataWidget::GetAmmoOnScreen(int32 InAmmo)
{
	Ammo = InAmmo;
	UE_LOG(WDW,Error,TEXT("Ammo: %i"),Ammo)
	AmmoCounter->SetText(FText::FromString(FString::FromInt(Ammo)));
	return Ammo;
}


