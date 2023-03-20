// Fill out your copyright notice in the Description page of Project Settings.


#include "TT_Components/TT_InventoryComponent.h"
#include "Blueprint/UserWidget.h"
#include "TT_Widgets/TT_InventoryWidget.h"
#include "Kismet/GameplayStatics.h"
#include "TT_GameInstance.h"

// Sets default values for this component's properties
UTT_InventoryComponent::UTT_InventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UTT_InventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	UpdateInventoryWidget();
	UpdateInventory();
	AmmoR = GetGameInstance()->Get_I_AmmoR();
	AmmoG = GetGameInstance()->Get_I_AmmoG();
}
void UTT_InventoryComponent::UpdateInventory()
{
	index_S1 =GetGameInstance()->Get_i_Slot1();
	index_S2 =GetGameInstance()->Get_i_Slot2();
	index_S3= GetGameInstance()->Get_i_Slot3();
	index_S3= GetGameInstance()->Get_i_Slot4();

	Slot1 = Inventorymap[index_S1];
	Slot2 = Inventorymap[index_S2];
	Slot3 = Inventorymap[index_S3];
	Slot4 = Inventorymap[index_S4];


}


void UTT_InventoryComponent::UpdateInventoryWidget()
{
	if(InventoryWidget!=NULL)	InventoryWidget->RemoveFromParent();
	InventoryWidget = CreateWidget<UTT_InventoryWidget>(GetWorld(), T_InventoryWidget);
	InventoryWidget->AddToViewport();
	InventoryWidget->SetSlots(index_S1, index_S2, index_S3,index_S4);
	InventoryWidget->ReDrawIm();

}



UTT_GameInstance* UTT_InventoryComponent::GetGameInstance()
{
	const auto TQGameInst = Cast<UTT_GameInstance>(GetWorld()->GetGameInstance());
	if (!TQGameInst) return NULL;

	return TQGameInst;
}

void UTT_InventoryComponent::AddItem(UClass* ToAdd, int32 index)
{
	if (Slot1 == nullptr)
	{
		Slot1 = ToAdd;
		index_S1 = index;

	}
	else
		if (Slot2 == nullptr)
		{
			Slot2 = ToAdd;
			index_S2 = index;

		}
		else
			if (Slot3 == nullptr)
			{
				Slot3 = ToAdd;
				index_S3 = index;

			}
			else
				if (Slot4 == nullptr)
				{
					Slot4 = ToAdd;
					index_S4 = index;

				}
	GetGameInstance()->SetSlots(index_S1, index_S2, index_S3, index_S4);
	InventoryWidget->ReDrawIm();

}

void UTT_InventoryComponent::RemoveItem(UClass* ToRemove)
{
	if (Slot1 == ToRemove)
	{
		Slot1 = nullptr;
		index_S1 = 0;

	}
	else
		if (Slot2 == ToRemove)
		{
			Slot2 = nullptr;
			index_S2 = 0;

		}
		else
			if (Slot3 == ToRemove)
			{
				Slot3 = nullptr;
				index_S3 = 0;

			}
			else
				if (Slot4 == ToRemove)
				{
					Slot4 = nullptr;
					index_S4 = 0;

				}
	InventoryWidget->ReDrawIm();

}
