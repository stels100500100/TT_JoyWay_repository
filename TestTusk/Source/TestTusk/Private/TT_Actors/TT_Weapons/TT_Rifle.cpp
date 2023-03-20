// Fill out your copyright notice in the Description page of Project Settings.


#include "TT_Components/TT_InventoryComponent.h"
#include "TT_Actors/TT_Weapons/TT_Rifle.h"
#include "Kismet/GameplayStatics.h"
#include "Player/TT_Character.h"
#include <DrawDebugHelpers.h>
#include "Components/ArrowComponent.h"
#include "TT_GameInstance.h"

DEFINE_LOG_CATEGORY_STATIC(Rifle, All, All)

ATT_Rifle::ATT_Rifle()
{
	Arrow = CreateDefaultSubobject<UArrowComponent>("Arrow");
	Arrow->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
	Arrow->SetupAttachment(Mesh);

}

void ATT_Rifle::BeginPlay()
{
	Super::BeginPlay();

	//WeaponData->Ammo = InnerAmmo;
	InnerAmmo = Inv()->GetAmmoR();
	WeaponData->GetAmmoOnScreen(InnerAmmo);
	
}

void ATT_Rifle::Fire()
{
	FHitResult HitResoult;
	DrawDebugLine(GetWorld(), GetActorLocation(), GetTracedData(), FColor::Red, false, 20.0f, 0, 20.0f);
	GetWorld()->LineTraceSingleByChannel(HitResoult, GetActorLocation(), GetTracedData(), ECC_Visibility);
	
			if (GetCharacter()->H_Resoult.Actor.Get() != nullptr)
			{
				GetCharacter()->H_Resoult.GetActor()->TakeDamage(Damage, FDamageEvent{}, GetCharacter()->GetController(), this);
			}
			if (InnerAmmo >= 0)
			{
				InnerAmmo--;
				Inv()->SetAmmoR(InnerAmmo);
				//WeaponData->Ammo = InnerAmmo;
				GetGameInstance()->Set_I_AmmoR(InnerAmmo);
				WeaponData->GetAmmoOnScreen(InnerAmmo);
			}
}

FVector ATT_Rifle::GetTracedData()
{
	
	return Arrow->GetComponentTransform().GetRotation().GetForwardVector() * 1500.0f + Arrow->GetComponentLocation();
}

UTT_GameInstance* ATT_Rifle::GetGameInstance() 
{
	const auto TQGameInst = Cast<UTT_GameInstance>(GetWorld()->GetGameInstance());
	if (!TQGameInst) return NULL;

	return TQGameInst;
}

ATT_Character* ATT_Rifle::GetCharacter() const
{
	const auto Pawn = Cast<ATT_Character>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));
	return Pawn;
}

UTT_InventoryComponent* ATT_Rifle::Inv() const
{
	const auto IC = GetCharacter()->FindComponentByClass<UTT_InventoryComponent>();

	return IC;
}
