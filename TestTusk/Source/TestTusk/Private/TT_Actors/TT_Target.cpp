// Fill out your copyright notice in the Description page of Project Settings.


#include "TT_Actors/TT_Target.h"
#include <Components/StaticMeshComponent.h>
#include <Engine/Engine.h>
#include <Kismet/GameplayStatics.h>
#include "Components/TextRenderComponent.h"

DEFINE_LOG_CATEGORY_STATIC(TTT,All,All)

ATT_Target::ATT_Target()
{
	PrimaryActorTick.bCanEverTick = false;


	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	Mesh->SetRelativeScale3D(FVector(0.25f, 0.25f, 0.25f));
	SetRootComponent(Mesh);

	HealthRender = CreateDefaultSubobject<UTextRenderComponent>("HealthRender");;
	HealthRender->SetText(FText::FromString(FString::Printf(TEXT("%f"), Health)));
	HealthRender->SetupAttachment(Mesh);

}


void ATT_Target::BeginPlay()
{
	Super::BeginPlay();
	HealthRender->SetText(FText::FromString(FString::Printf(TEXT("%f"), Health)));

}

float ATT_Target::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	UE_LOG(TTT, Warning, TEXT("OnApplayDamage"))
		Health -= DamageAmount;
	HealthRender->SetText(FText::FromString(FString::Printf(TEXT("%f"), Health)));

	if (Health <= 0)
	{
		ATT_Target::Destroy();
	}
	return 0.0;

}

