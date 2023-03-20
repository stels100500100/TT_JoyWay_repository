// Fill out your copyright notice in the Description page of Project Settings.


#include "TT_Actors/TT_Ammo_PickUp.h"
#include "TT_Components/TT_InventoryComponent.h"

void ATT_Ammo_PickUp::PickUpResault(AActor* OtherActor)
{
	const auto IC = OtherActor->FindComponentByClass<UTT_InventoryComponent>();
	if (!IC) return;
	IC->SetAmmoR(RAmmo) ;
	IC->SetAmmoG(GAmmo);

	ATT_Ammo_PickUp::Destroy();
}


