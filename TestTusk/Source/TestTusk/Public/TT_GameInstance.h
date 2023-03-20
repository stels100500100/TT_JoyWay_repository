// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TT_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TESTTUSK_API UTT_GameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 I_Slot1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 I_Slot2;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 I_Slot3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 I_Slot4;
	int32 Get_i_Slot1() { return  I_Slot1; }
	int32 Get_i_Slot2() { return  I_Slot2; }
	int32 Get_i_Slot3() { return  I_Slot3; }
	int32 Get_i_Slot4() { return  I_Slot4; }

	void SetSlots(int32 s1, int32 s2, int32 s3, int32 s4){ I_Slot1= s1, I_Slot2= s2, I_Slot3= s3, I_Slot4= s4; }
	int32 AmmoR=25;
	int32 Get_I_AmmoR() { return AmmoR; };
	void Set_I_AmmoR(int32 I_R) { AmmoR = I_R; };
	int32 AmmoG=30;
	int32 Get_I_AmmoG() { return AmmoG; };
	void Set_I_AmmoG(int32 I_G) { AmmoG = I_G; };

};
