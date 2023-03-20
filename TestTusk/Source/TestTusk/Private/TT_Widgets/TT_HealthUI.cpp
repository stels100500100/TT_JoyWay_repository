// Fill out your copyright notice in the Description page of Project Settings.


#include "TT_Widgets/TT_HealthUI.h"
#include "TT_Components/TT_HealthComponent.h"
#include "Player/TT_Character.h"

DEFINE_LOG_CATEGORY_STATIC(PHUDW, All, All)

float UTT_HealthUI::GetHealthPercent() const
{
	const auto Player = Cast<ATT_Character>(GetOwningPlayerPawn());

	const auto Component = Player->GetComponentByClass(UTT_HealthComponent::StaticClass());

	const auto HealthComponent = Cast<UTT_HealthComponent>(Component);

	if (!HealthComponent) return 0.0f;

	return HealthComponent->GetHealthPercent();
}