// Fill out your copyright notice in the Description page of Project Settings.


#include "TT_Actors/TT_Health_PickUp.h"
#include "TT_Components/TT_HealthComponent.h"
#include "TT_Components/TT_InventoryComponent.h"

DEFINE_LOG_CATEGORY_STATIC(HEalthComp, Warning, All);

ATT_Health_PickUp::ATT_Health_PickUp()
{
	SetRootComponent(Mesh);

}
void ATT_Health_PickUp::BeginPlay()
{
	Super::BeginPlay();

}

void ATT_Health_PickUp::PickUpResault(AActor* OtherActor)
{
	const auto HC = OtherActor->FindComponentByClass<UTT_HealthComponent>();
	if (!HC) return;
	if (!HC->IsHealthFull())
	{
		HC->TryToAddHealth(HealthAmount);
	}
	else
	{
		const auto IC = OtherActor->FindComponentByClass<UTT_InventoryComponent>();
		if (!IC) return;

		IC->AddItem(Content,ItemIndex);
		IC->UpdateInventoryWidget();
	}
		
		ATT_Health_PickUp::Destroy();
}

