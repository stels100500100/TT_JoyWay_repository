// Fill out your copyright notice in the Description page of Project Settings.


#include "TT_Actors/TT_Weapons/TT_GrenadeLauncher.h"
#include "Kismet/GameplayStatics.h"
#include "TT_Components/TT_InventoryComponent.h"
#include "Components/ArrowComponent.h"
#include "TT_GameInstance.h"

ATT_GrenadeLauncher::ATT_GrenadeLauncher()
{
	Arrow = CreateDefaultSubobject<UArrowComponent>("Arrow");
	Arrow->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
	Arrow->SetupAttachment(Mesh);
}

void ATT_GrenadeLauncher::BeginPlay()
{
	Super::BeginPlay();
	//WeaponData->Ammo=InnerAmmo;
	InnerAmmo = Inv()->GetAmmoG();
	WeaponData->GetAmmoOnScreen(InnerAmmo);
}

void ATT_GrenadeLauncher::Fire()
{
	if (ProjectileClass != nullptr)
	{
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			if (InnerAmmo != 0)
			{
				FRotator SpawnRotation = Arrow->GetComponentRotation();
				const FVector SpawnLocation = ((Mesh != nullptr) ? Mesh->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);

				FActorSpawnParameters ActorSpawnParams;
				ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

				World->SpawnActor<ATestTuskProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);

				InnerAmmo--;
				Inv()->SetAmmoG(InnerAmmo);
				WeaponData->GetAmmoOnScreen(InnerAmmo);
				GetGameInstance()->Set_I_AmmoR(InnerAmmo);

				if (InnerAmmo <= 0)
				{
					EndUse();

				}
			}
		}
	}
}

UTT_GameInstance* ATT_GrenadeLauncher::GetGameInstance() 
{
	const auto TQGameInst = Cast<UTT_GameInstance>(GetWorld()->GetGameInstance());
	if (!TQGameInst) return NULL;

	return TQGameInst;
}

ATT_Character* ATT_GrenadeLauncher::GetCharacter() const
{
	const auto Pawn = Cast<ATT_Character>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	return Pawn;
}

UTT_InventoryComponent* ATT_GrenadeLauncher::Inv() const
{
	const auto IC = GetCharacter()->FindComponentByClass<UTT_InventoryComponent>();

	return IC;
}
