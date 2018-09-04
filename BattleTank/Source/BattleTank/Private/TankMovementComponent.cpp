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
void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

//
// Handle the intention to move forward
//
void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	float ForwardIntention = FVector::DotProduct(TankForward, AIForwardIntention);
	IntendMoveForward(ForwardIntention);

	float RightIntention = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	IntendTurnRight(RightIntention);
	//UE_LOG(LogTemp, Warning, TEXT("%s: RequestDirectMove to: %s"), *GetOwner()->GetName(), *MoveVelocity.ToString());
}
