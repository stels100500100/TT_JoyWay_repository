// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TT_InventoryWidget.generated.h"

class UTexture2D;
class UImage;
UCLASS()
class TESTTUSK_API UTT_InventoryWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeOnInitialized() override;
	void ReDrawIm();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (bindWidget))
		UImage* Slot1Image;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (bindWidget))
		UImage* Slot2Image;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (bindWidget))
		UImage* Slot3Image;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,meta=(bindWidget))
		UImage* Slot4Image;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (bindWidget))
		TMap<int32, UTexture2D*> inventoryimageMap;
	int32 W_I_Index1;
	int32 W_I_Index2;
	int32 W_I_Index3;
	int32 W_I_Index4;
	void SetSlots(int32 s1, int32 s2, int32 s3, int32 s4)
	{
		W_I_Index1 = s1, W_I_Index2 = s2, W_I_Index3 = s3, W_I_Index4 = s4; ReDrawIm();
	}

};
