// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TT_Actors/TT_BasePickUp.h"
#include "TT_Health_PickUp.generated.h"

/**
 * 
 */
UCLASS()
class TESTTUSK_API ATT_Health_PickUp : public ATT_BasePickUp
{
	GENERATED_BODY()
public:
	ATT_Health_PickUp();
	virtual void BeginPlay() override;
	virtual void PickUpResault(AActor* OtherActor) override;
	UPROPERTY(EditAnywhere)
	float HealthAmount=25.0f;
	UClass* Content;
};
