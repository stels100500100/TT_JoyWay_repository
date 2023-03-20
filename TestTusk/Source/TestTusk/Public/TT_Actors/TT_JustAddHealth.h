// Vasiliy Bukin

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TT_JustAddHealth.generated.h"
class UStaticMeshComponent;
UCLASS()
class TESTTUSK_API ATT_JustAddHealth : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATT_JustAddHealth();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;
	UFUNCTION()

	void CrossPlayer(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere)
		float HealthAmount = 25.0f;

};
