// Fill out your copyright notice in the Description page of Project Settings.


#include "TT_Actors/TT_WeaponPickUp.h"
#include <TT_Components/TT_CoreTypes.h>
#include "Components/StaticMeshComponent.h"
#include "Player/TT_Character.h"
#include <Kismet/GameplayStatics.h>
#include <DrawDebugHelpers.h>
#include "TT_Components/TT_InventoryComponent.h"


DEFINE_LOG_CATEGORY_STATIC(Weapon, All, All)
void ATT_WeaponPickUp::BeginPlay()
{
	Super::BeginPlay();

}

void ATT_WeaponPickUp::PickUpResault(AActor* OtherActor)
{
	const auto IC = OtherActor->FindComponentByClass<UTT_InventoryComponent>();
	if (!IC) return;

	IC->AddItem(Content, ItemIndex);
	IC->UpdateInventoryWidget();
	ATT_WeaponPickUp::Destroy();
}


