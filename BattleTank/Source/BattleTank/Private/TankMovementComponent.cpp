// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack * LeftTrackToSet, UTankTrack * RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

//
// Handle the intention to move forward
//
void UTankMovementComponent::intendMoveForward(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

//
// Handle the intention to move forward
//
void UTankMovementComponent::intendTurnRight(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardintention = MoveVelocity.GetSafeNormal();

	float Forwardintention = FVector::DotProduct(TankForward, AIForwardintention);
	intendMoveForward(Forwardintention);

	float Rightintention = FVector::CrossProduct(TankForward, AIForwardintention).Z;
	intendTurnRight(Rightintention);
	//UE_LOG(LogTemp, Warning, TEXT("%s: RequestDirectMove to: %s"), *GetOwner()->GetName(), *MoveVelocity.ToString());
}
