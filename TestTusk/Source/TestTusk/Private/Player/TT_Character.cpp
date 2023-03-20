// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TT_Character.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"
#include "TT_Components/TT_HealthComponent.h"
#include "TT_Components/TT_InventoryComponent.h"
#include <DrawDebugHelpers.h>
#include "Components/StaticMeshComponent.h"
#include "TT_Actors/TT_BasePickUp.h"
#include "TT_Components/TT_CoreTypes.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/WidgetInteractionComponent.h"
#include "TT_Actors/TT_WeaponPickUp.h"
#include "GameFramework/DamageType.h"


DEFINE_LOG_CATEGORY_STATIC(TT_Character, All, All);

// Sets default values
ATT_Character::ATT_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	HealthCom = CreateDefaultSubobject<UTT_HealthComponent>("HealthCom");
	HealthCom->OnDeath.AddUObject(this, &ATT_Character::OnDeath);
	InventoryCom = CreateDefaultSubobject<UTT_InventoryComponent>("InventoryCom");

	//WidgetInteraction->TraceChannel(ECC_Visibility);
	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	WidgetInteraction = CreateDefaultSubobject<UWidgetInteractionComponent>("WidgetInteraction");
	WidgetInteraction->bEnableHitTesting = true;
	WidgetInteraction->SetupAttachment(FirstPersonCameraComponent);

	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh1P");
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);

}

// Called when the game starts or when spawned
void ATT_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATT_Character::OnDeath()
{
	DefaultDeath = CreateWidget<UUserWidget>(GetWorld(), DeathWidget);
	DefaultDeath->AddToViewport(2);
	InventoryCom->UpdateInventoryWidget();

}
// Called every frame
void ATT_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATT_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);

	// Bind jump events
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	// Bind inventory actions
	PlayerInputComponent->BindAction("InventorySlot1", IE_Pressed, this, &ATT_Character::Slot_1_Action);
	PlayerInputComponent->BindAction("InventorySlot2", IE_Pressed, this, &ATT_Character::Slot_2_Action);
	PlayerInputComponent->BindAction("InventorySlot3", IE_Pressed, this, &ATT_Character::Slot_3_Action);
	PlayerInputComponent->BindAction("InventorySlot4", IE_Pressed, this, &ATT_Character::Slot_4_Action);

	// Bind fire event
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ATT_Character::OnFire);
	// Drop event
	PlayerInputComponent->BindAction("Drop", IE_Pressed, this, &ATT_Character::Drop);
	// Bind movement events
	PlayerInputComponent->BindAxis("MoveForward", this, &ATT_Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATT_Character::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ATT_Character::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ATT_Character::LookUpAtRate);
}

void ATT_Character::Slot_1_Action()
{
	if (Item_A != nullptr)
	{
		Item_A->Destroy();
		if (InventoryCom->GetSlot1() != nullptr)
		{
			Item = InventoryCom->GetSlot1();
			SpawnIItem();
		}
	}
	else 
	{
		if (InventoryCom->GetSlot1() != nullptr)
		{
			Item = InventoryCom->GetSlot1();
			SpawnIItem();
		}
	}
	InventoryCom->UpdateInventoryWidget();

}

void ATT_Character::Slot_2_Action()
{
	//Item_A->Destroy();
	if (Item_A!=nullptr)
	{
		Item_A->Destroy();
		if (InventoryCom->GetSlot2() != nullptr)
		{
			Item = InventoryCom->GetSlot2();
			SpawnIItem();
		}
	}
	else 
	{
		if (InventoryCom->GetSlot2() != nullptr)
		{
			Item = InventoryCom->GetSlot2();
			SpawnIItem();
		}
	}
	InventoryCom->UpdateInventoryWidget();

}

void ATT_Character::Slot_3_Action()
{

	if (Item_A != nullptr)
	{
		Item_A->Destroy();

		if (InventoryCom->GetSlot3() != nullptr)
		{
			Item = InventoryCom->GetSlot3();
			SpawnIItem();
		}
	}
	else 
	{
		if (InventoryCom->GetSlot3() != nullptr)
		{
			Item = InventoryCom->GetSlot3();
			SpawnIItem();
		}
	}
	InventoryCom->UpdateInventoryWidget();

}

void ATT_Character::Slot_4_Action()
{
	//Item_A->Destroy();

	if (Item_A != nullptr)
	{
		Item_A->Destroy();
		if (InventoryCom->GetSlot4() != nullptr)
		{
			Item = InventoryCom->GetSlot4();
			SpawnIItem();
		}
	}
	else 
	{
		if (InventoryCom->GetSlot4() != nullptr)
		{
			Item = InventoryCom->GetSlot4();
			SpawnIItem();
		}
	}
	InventoryCom->UpdateInventoryWidget();

}

void ATT_Character::SpawnIItem()
{
	FActorSpawnParameters SpawnParams;
	Item_A = GetWorld()->SpawnActor<AActor>(Item, WidgetInteraction->GetComponentLocation(), FirstPersonCameraComponent->GetComponentRotation(), SpawnParams);
	Item_A->AttachToComponent(Mesh1P, FAttachmentTransformRules::SnapToTargetNotIncludingScale, SoketName);
}

FVector ATT_Character::GetTracedData()
{

	return FirstPersonCameraComponent->GetComponentTransform().GetRotation().GetForwardVector() * 1000.0f + FirstPersonCameraComponent->GetComponentLocation();
}

void ATT_Character::PickUpItem(FHitResult HitResoult)
{
	if (HitResoult.Actor.Get() != nullptr)
	{
		UE_LOG(TT_Character, Warning, TEXT("%s"), *HitResoult.GetActor()->GetName());
		const auto Pickup = Cast<ATT_BasePickUp>(HitResoult.GetActor());
		if (HitResoult.GetActor() == Pickup)
		{
			Pickup->GetPickUp(GetActorLocation());

		}
	
	}
}

void ATT_Character::OnFire()
{
	FHitResult HitResoult;
	FVector TraseFXEnd = HitResoult.ImpactPoint;

	DrawDebugLine(GetWorld(), GetActorLocation(), GetTracedData(), FColor::Cyan, false, 1.0f, 0, 2.0f);
	GetWorld()->LineTraceSingleByChannel(HitResoult, GetActorLocation(), GetTracedData(), ECC_Visibility);
	PickUpItem(HitResoult);
	H_Resoult = HitResoult;
		WidgetInteraction->PressPointerKey("LeftMouseButton");
		WidgetInteraction->ReleasePointerKey("LeftMouseButton");
}


void ATT_Character::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void ATT_Character::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void ATT_Character::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ATT_Character::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ATT_Character::Drop()
{
	//SpawnedActorAttached->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	/*FActorSpawnParameters SpawnParams;
	AActor* SpawnedActorRef = GetWorld()->SpawnActor<AActor>(Item, WidgetInteraction->GetComponentLocation(), FirstPersonCameraComponent->GetComponentRotation(), SpawnParams);*/
}