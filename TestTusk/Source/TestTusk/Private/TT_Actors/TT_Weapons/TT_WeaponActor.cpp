// Fill out your copyright notice in the Description page of Project Settings.


#include "TT_Actors/TT_Weapons/TT_WeaponActor.h"
#include "TT_Widgets/TT_WeaponDataWidget.h"
#include "TT_Components/TT_InventoryComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Player/TT_Character.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ArrowComponent.h"

DEFINE_LOG_CATEGORY_STATIC(TT_WeaponActor, All, All);

// Sets default values
ATT_WeaponActor::ATT_WeaponActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetCollisionResponseToAllChannels(ECR_Ignore);
	SetRootComponent(Mesh);

	
}

// Called when the game starts or when spawned
void ATT_WeaponActor::BeginPlay()
{
	Super::BeginPlay();
	AddUI();
}


void ATT_WeaponActor::AddUI()
{
	WeaponData = CreateWidget<UTT_WeaponDataWidget>(GetWorld(), WeaponDataClass);
	WeaponData->AddToViewport(1);
	WeaponData->SetAmmo(InnerAmmo);


}

void ATT_WeaponActor::HideUI()
{
	WeaponData->RemoveFromParent();
}


void ATT_WeaponActor::Fire()
{	
}



void ATT_WeaponActor::EndUse()
{
	WeaponData->RemoveFromParent();
	ATT_WeaponActor::Destroy();
}

ATT_Character* ATT_WeaponActor::GetCharacter() const
{
	const auto Pawn = Cast<ATT_Character>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	return Pawn;
}

UTT_InventoryComponent* ATT_WeaponActor::Inv() const
{
	const auto IC = GetCharacter()->FindComponentByClass<UTT_InventoryComponent>();

	return IC;
}