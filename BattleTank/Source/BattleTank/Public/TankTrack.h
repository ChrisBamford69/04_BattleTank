// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UTankTrack();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);

	void DriveTrack(float CurrentThrottle);

private:
	// Maximum driving force in Newtons
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	float MaximumDrivingForce = 40000000.0f;

	TArray<class ASprungWheel*> GetWheels() const;
};
