// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TT_Actors/TT_BasePickUp.h"
#include "Player/TT_Character.h"
#include "TT_WeaponPickUp.generated.h"

/**
 * 
 */
UCLASS()
class TESTTUSK_API ATT_WeaponPickUp : public ATT_BasePickUp
{
	GENERATED_BODY()
public:
	virtual void PickUpResault(AActor* OtherActor) override;
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		FName SoketName = "GripPoint";
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UClass* Content;

};
