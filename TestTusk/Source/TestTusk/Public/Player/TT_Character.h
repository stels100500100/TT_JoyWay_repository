// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <TT_Components/TT_CoreTypes.h>
#include "TT_Character.generated.h"

class UInputComponent;
class USkeletalMeshComponent;
class USceneComponent;
class UCameraComponent;
class UTT_HealthComponent;
class UTT_InventoryComponent;
class UWidgetInteractionComponent;
class UDamageType;
UCLASS()
class TESTTUSK_API ATT_Character : public ACharacter
{
	GENERATED_BODY()

public:
	ATT_Character();
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* Mesh1P;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* FirstPersonCameraComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		UTT_HealthComponent* HealthCom;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		UTT_InventoryComponent* InventoryCom;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		UWidgetInteractionComponent* WidgetInteraction;

		void OnDeath();
		UPROPERTY(EditAnywhere, BlueprintReadWrite)

		FName SoketName = "GripPoint";

		FHitResult H_Resoult;
		FVector GetTracedData();
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TTGameplay")
			float Damage=10;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
			float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
			float BaseLookUpRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
			FVector GunOffset;
	UPROPERTY(EditAnywhere)
			UClass* Item;
		AActor* Item_A;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UUserWidget* DefaultDeath;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		TSubclassOf<UUserWidget> DeathWidget;
	void PickUpItem(FHitResult HitResoult);
	/** Fires a projectile. */
	void OnFire();

	/** Handles moving forward/backward */
	void MoveForward(float Val);

	void Drop();

	void MoveRight(float Val);

	void TurnAtRate(float Rate);
	
	void LookUpAtRate(float Rate);
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;

	void Slot_1_Action();
	void Slot_2_Action();
	void Slot_3_Action();
	void Slot_4_Action();
	
	AActor* SpawnedActorAttached;

public:	
	virtual void Tick(float DeltaTime) override;
	void SpawnIItem();

	USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

};
