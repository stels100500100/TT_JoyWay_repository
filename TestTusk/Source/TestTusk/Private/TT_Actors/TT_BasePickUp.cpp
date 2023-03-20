

#include "TT_Actors/TT_BasePickUp.h"
#include <Components/StaticMeshComponent.h>
#include "TT_Components/TT_CoreTypes.h"
#include <Engine/Engine.h>
#include <Kismet/GameplayStatics.h>
#include "Engine/Texture2D.h"

DEFINE_LOG_CATEGORY_STATIC(TT_Pickup,All,All)

ATT_BasePickUp::ATT_BasePickUp()
{
	PrimaryActorTick.bCanEverTick = true;

	SetRootComponent(Mesh);
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetRelativeScale3D(FVector(0.25f,0.25f,0.25f));
	Mesh->OnComponentBeginOverlap.AddDynamic(this, &ATT_BasePickUp::PlayerCrossed);
}

void ATT_BasePickUp::BeginPlay()
{
	Super::BeginPlay();
}

void ATT_BasePickUp::PlayerCrossed(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	PickUpResault( OtherActor);
}

void ATT_BasePickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bCanUpdateLocation)
	{
		UpdateLocation(DeltaTime);
	}
}

void ATT_BasePickUp::UpdateLocation(float Delta)
{
	Mesh->SetWorldLocation(FMath::VInterpTo(Mesh->GetComponentLocation(), PlayerLocation, Delta, FlightSpeed));
}

void ATT_BasePickUp::GetPickUp(FVector ActorLocation) // rename to getter
{
	UE_LOG(TT_Pickup, Display, TEXT("GetPickUp"))
		PlayerLocation = ActorLocation;
		bCanUpdateLocation = true;
		Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
		if (MultyUse)
		{
			//GetWorld()->GetTimerManager().SetTimer(GoStaticHandle, this, &ATT_BasePickUp::GoStatic, 4.0f, false);

		}
}

void ATT_BasePickUp::PickUpResault(AActor* OtherActor)
{
	ATT_BasePickUp::Destroy();
}
void ATT_BasePickUp::GoStatic()
{
	UE_LOG(TT_Pickup, Display, TEXT("GetPickUp"))

	bCanUpdateLocation = false;
	Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
}
