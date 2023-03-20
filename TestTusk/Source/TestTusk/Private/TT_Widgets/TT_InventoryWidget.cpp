// Fill out your copyright notice in the Description page of Project Settings.


#include "TT_Widgets/TT_InventoryWidget.h"
#include "Engine/Texture2D.h"
#include "Components/Image.h"

void UTT_InventoryWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	ReDrawIm();
}

void UTT_InventoryWidget::ReDrawIm()
{
	Slot1Image->SetBrushFromTexture(inventoryimageMap[W_I_Index1]);
	Slot2Image->SetBrushFromTexture(inventoryimageMap[W_I_Index2]);
	Slot3Image->SetBrushFromTexture(inventoryimageMap[W_I_Index3]);
	Slot4Image->SetBrushFromTexture(inventoryimageMap[W_I_Index4]);
}