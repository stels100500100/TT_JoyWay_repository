// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TT_GameInstance.h"
#include "TT_Actors/TT_Weapons/TT_WeaponActor.h"
#include "TT_Rifle.generated.h"

class UArrowComponent;

UCLASS()
class TESTTUSK_API ATT_Rifle : public ATT_WeaponActor
{
	GENERATED_BODY()
public:
	ATT_Rifle();
		virtual void Fire() override;
	virtual void BeginPlay() override;
		FVector GetTracedData();
		UPROPERTY(EditDefaultsOnly, Category = "Gameplay")

		float Damage = 10.0f;
		ATT_Character* GetCharacter() const;
		UTT_InventoryComponent* Inv() const;
		UFUNCTION()
		UTT_GameInstance* GetGameInstance() ;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TTGameplay")

		UArrowComponent* Arrow;
};
