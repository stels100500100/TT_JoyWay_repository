// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TT_HealthUI.generated.h"

class UProgressBar;

UCLASS()
class TESTTUSK_API UTT_HealthUI : public UUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(meta = (BindWidget), EditAnywhere)
		UProgressBar* Pbar;
public:

	UFUNCTION(BlueprintCallable)
		float GetHealthPercent() const;

};
