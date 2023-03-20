// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TT_MapSelectorWidget.generated.h"

class UButton;

UCLASS()
class TESTTUSK_API UTT_MapSelectorWidget : public UUserWidget
{
	GENERATED_BODY()
private:
		virtual void NativeOnInitialized() override;
		UFUNCTION()
			void OpenNextLevel_1();
		UFUNCTION()
			void OpenNextLevel_2();
		UFUNCTION()
			void OpenNextLevel_3();
		UFUNCTION()
			void OpenNextLevel_4();
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="TTGameplay")
		FName LevelName_1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TTGameplay")
		FName LevelName_2;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TTGameplay")
		FName LevelName_3;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TTGameplay")
		FName LevelName_4;
	UPROPERTY(Meta=(BindWidget))
		UButton* MapSelect_1;
	UPROPERTY(Meta = (BindWidget))
		UButton* MapSelect_2;
	UPROPERTY(Meta = (BindWidget))
		UButton* MapSelect_3;
	UPROPERTY(Meta = (BindWidget))
		UButton* MapSelect_4;
};
