// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 *  Responsible for moving the tank around the game world
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankTrack * LeftTrackToSet, UTankTrack * RightTrackToSet);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void intendMoveForward(float Throw);
	
	UFUNCTION(BlueprintCallable, Category = "Input")
	void intendTurnRight(float Throw);

	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

private:
	UTankTrack * LeftTrack = nullptr;
	UTankTrack * RightTrack = nullptr;
};
