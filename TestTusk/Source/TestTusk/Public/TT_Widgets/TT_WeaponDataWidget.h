// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TT_WeaponDataWidget.generated.h"

class UTextBlock;

UCLASS()
class TESTTUSK_API UTT_WeaponDataWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeOnInitialized() override;
	UFUNCTION(BlueprintCallable)
		int32 GetAmmoOnScreen(int32 InAmmo) ;
		
	UPROPERTY()
		int32 Ammo=20;
		void SetAmmo(int32 InAmmo) { Ammo = InAmmo; };

private:
	UPROPERTY(Meta=(BindWidget))
	UTextBlock* AmmoCounter;
};
