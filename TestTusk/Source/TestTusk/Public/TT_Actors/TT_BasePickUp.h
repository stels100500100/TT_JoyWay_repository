#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TT_BasePickUp.generated.h"

class UStaticMeshComponent;
UCLASS()
class TESTTUSK_API ATT_BasePickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	ATT_BasePickUp();
	UFUNCTION()
	 virtual void PickUpResault(AActor* OtherActor);
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh;
		FTimerHandle GoStaticHandle;
	UPROPERTY(EditAnywhere)
		float FlightSpeed=2.0f;
	UPROPERTY(EditAnywhere)
		bool MultyUse=true;
		FVector PlayerLocation;
		bool bCanUpdateLocation=false;
	UFUNCTION()
			void GetPickUp(FVector ActorLocation);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 ItemIndex;
protected:
	UFUNCTION()
	void PlayerCrossed(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void UpdateLocation(float Delta);
	void GoStatic();

};

