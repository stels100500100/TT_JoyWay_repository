// Fill out your copyright notice in the Description page of Project Settings.


#include "TT_Components/TT_HealthComponent.h"

DEFINE_LOG_CATEGORY_STATIC(TT_HealthComponent,All,All)
// Sets default values for this component's properties
UTT_HealthComponent::UTT_HealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UTT_HealthComponent::BeginPlay()
{
	Super::BeginPlay();

	check(MaxHealth > 0);

	SetHealth(MaxHealth);
	
	AActor* ComponentOwner = GetOwner();
	if (ComponentOwner) {
		ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &UTT_HealthComponent::OnTakeAnyDamageHandle);

	}
}


void UTT_HealthComponent::OnTakeAnyDamageHandle(AActor* DamageActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
		OnApplayDamage(Damage);
}



void UTT_HealthComponent::OnApplayDamage(float Damage)
{
	if (Damage < 0.0f || IsDead() || !GetWorld()) return;
	SetHealth(Health - Damage);


	if (IsDead()) 
	{
		OnDeath.Broadcast();
	}
}

void UTT_HealthComponent::SetHealth(float NewHealth)
{
	const auto NextHealth = FMath::Clamp(NewHealth, 0.0f, MaxHealth);
	const auto HealthDelta = NextHealth - Health;


	Health = NextHealth;

	OnHealthChanged.Broadcast(Health, HealthDelta);

}
bool UTT_HealthComponent::TryToAddHealth(float HealthAmount)
{
	UE_LOG(TT_HealthComponent, Warning, TEXT("SetHealth"))

	if (IsDead() || IsHealthFull()) return false;

	SetHealth(Health + HealthAmount);

	return true;
}
bool UTT_HealthComponent::IsHealthFull()const
{
	return FMath::IsNearlyEqual(Health, MaxHealth);
}

