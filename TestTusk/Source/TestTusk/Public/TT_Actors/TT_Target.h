// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TT_Target.generated.h"

class UStaticMeshComponent;
class UTextRenderComponent;

UCLASS()
class TESTTUSK_API ATT_Target : public AActor
{
	GENERATED_BODY()
	
public:
	ATT_Target();

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh;
	UPROPERTY(EditAnywhere)
		UTextRenderComponent* HealthRender;
	UPROPERTY(EditAnywhere)
		float Health;
	virtual float TakeDamage(float DamageAmount,struct FDamageEvent const& DamageEvent,	class AController* EventInstigator,	AActor* DamageCauser);
protected:
	UFUNCTION()
	virtual void BeginPlay() override;
};
