// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TT_Actors/TT_BasePickUp.h"
#include "TT_Ammo_PickUp.generated.h"

/**
 * 
 */
UCLASS()
class TESTTUSK_API ATT_Ammo_PickUp : public ATT_BasePickUp
{
	GENERATED_BODY()
public:
	virtual void PickUpResault(AActor* OtherActor) override;

	int32 RAmmo = 5;
	int32 GAmmo = 5;

	
};
