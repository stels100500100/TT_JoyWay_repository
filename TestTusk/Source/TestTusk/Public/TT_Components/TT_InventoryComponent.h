// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TT_Widgets/TT_InventoryWidget.h"
#include "Components/ActorComponent.h"
#include "TT_GameInstance.h"
#include "TT_InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTTUSK_API UTT_InventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTT_InventoryComponent();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UClass* Slot1;
		int32 index_S1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UClass* Slot2;
		int32 index_S2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UClass* Slot3;
		int32 index_S3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UClass* Slot4;
		int32 index_S4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		TSubclassOf<UTT_InventoryWidget> T_InventoryWidget;
		UTT_InventoryWidget* InventoryWidget;

		UTT_GameInstance* GetGameInstance();



public:	
	// Called every frame
	void AddItem(UClass* ToAdd,int32 index);
	void RemoveItem(UClass* ToRemove);
	UFUNCTION(BlueprintCallable)
	void UpdateInventory();
	UFUNCTION(BlueprintCallable)
	void UpdateInventoryWidget();
	UFUNCTION()
	UClass* GetSlot1() { return Slot1; };

	UFUNCTION()

	UClass* GetSlot2() { return Slot2; };
	UFUNCTION()

	UClass* GetSlot3() { return Slot3; };

	UFUNCTION()
	UClass* GetSlot4() { return Slot4; };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)

	TMap<int32, UClass*> Inventorymap;
		
	int32 AmmoR = 25;
	int32 GetAmmoR() { return AmmoR; };
	void SetAmmoR(int32 GetAmmo) { AmmoR = GetAmmo; };
	int32 AmmoG = 30;
	int32 GetAmmoG() { return AmmoG; };
	void SetAmmoG(int32 GetAmmo) { AmmoG = GetAmmo; };
};
