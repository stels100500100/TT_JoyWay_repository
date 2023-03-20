// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TT_Components/TT_CoreTypes.h"
#include "TT_HealthComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTTUSK_API UTT_HealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTT_HealthComponent();
	FOnDeath OnDeath;
	FOnHealthChanged OnHealthChanged;
	virtual void BeginPlay() override;



	UFUNCTION(BlueprintCallable)
		bool IsDead() const { return FMath::IsNearlyZero(Health); }
	UFUNCTION(BlueprintCallable)
		float GetHealthPercent() const { return Health / MaxHealth; }

	float GetHealth() const { return Health; }

	bool TryToAddHealth(float HealthAmount);

	bool IsHealthFull()const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TTGamePlay")
		float Health = 100.0f;
		float MaxHealth = 100.0f;


	void SetHealth(float NewHealth);

	UFUNCTION()
		void OnTakeAnyDamageHandle(AActor* DamageActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

		void OnApplayDamage(float Damage);

		
};
