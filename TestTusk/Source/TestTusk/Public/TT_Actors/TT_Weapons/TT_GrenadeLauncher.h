// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TT_Player/TestTuskProjectile.h"
#include "TT_GameInstance.h"
#include "TT_Actors/TT_Weapons/TT_WeaponActor.h"
#include "TT_GrenadeLauncher.generated.h"

class UArrowComponent;

UCLASS()
class TESTTUSK_API ATT_GrenadeLauncher : public ATT_WeaponActor
{
	GENERATED_BODY()
public:

	ATT_GrenadeLauncher();
		virtual void Fire() override;
		virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
		TSubclassOf<class ATestTuskProjectile> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
		float Damage = 10.f;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
		FVector GunOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TTGameplay")
		UArrowComponent* Arrow;
	UFUNCTION()
		UTT_GameInstance* GetGameInstance() ;
	ATT_Character* GetCharacter() const;
	UTT_InventoryComponent* Inv() const;



};
