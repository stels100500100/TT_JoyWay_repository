// Vasiliy Bukin


#include "TT_Actors/TT_JustAddHealth.h"
#include "Components/StaticMeshComponent.h"
#include "TT_Components/TT_HealthComponent.h"

// Sets default values
ATT_JustAddHealth::ATT_JustAddHealth()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetCollisionResponseToAllChannels(ECR_Overlap);
	SetRootComponent(Mesh);
	Mesh->OnComponentBeginOverlap.AddDynamic(this, &ATT_JustAddHealth::CrossPlayer);
}

// Called when the game starts or when spawned
void ATT_JustAddHealth::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATT_JustAddHealth::CrossPlayer(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)

{
	const auto HC = OtherActor->FindComponentByClass<UTT_HealthComponent>();
	if (!HC) return;
	if (!HC->IsHealthFull())
	{
		HC->TryToAddHealth(HealthAmount);
	}
}
