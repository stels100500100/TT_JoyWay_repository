// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TT_Widgets/TT_WeaponDataWidget.h"
#include "GameFramework/Actor.h"
#include "Player/TT_Character.h"
#include "TT_WeaponActor.generated.h"

class UStaticMeshComponent;

UCLASS()
class TESTTUSK_API ATT_WeaponActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ATT_WeaponActor();

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "TTGameplay")
		TSubclassOf<UTT_WeaponDataWidget> WeaponDataClass;
		UTT_WeaponDataWidget* WeaponData;

	UFUNCTION(BlueprintCallable)
	virtual void Fire();
	void IncreasAmmo();
	void EndUse();

	ATT_Character* GetCharacter() const;
	UTT_InventoryComponent* Inv() const;

	UFUNCTION(BlueprintCallable)
		void HideUI();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TTGameplay")

	int32 InnerAmmo=25;
protected:
	virtual void BeginPlay() override;
	void AddUI();


};
