// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack * LeftTrackToSet, UTankTrack * RightTrackToSet)
{
	if (nullptr != LeftTrackToSet)
	{
		LeftTrack = LeftTrackToSet;
	}

	if (nullptr != RightTrackToSet)
	{
		RightTrack = RightTrackToSet;
	}
}

//
// Handle the intention to move forward
//
void UTankMovementComponent::IntendMoveForward(float Throw)
{
	//auto Intent = FMath::Clamp(Throw, -1.0f, 1.0f);

	if (nullptr != LeftTrack)
	{
		LeftTrack->SetThrottle(Throw);
	}

	if (nullptr != RightTrack)
	{
		RightTrack->SetThrottle(Throw);
	}
}

//
// Handle the intention to move forward
//
void UTankMovementComponent::TurnRight(float Throw)
{
	//auto Intent = FMath::Clamp(Throw, -1.0f, 1.0f);

	if (nullptr != LeftTrack)
	{
		LeftTrack->SetThrottle(Throw);
	}

	if (nullptr != RightTrack)
	{
		RightTrack->SetThrottle(-Throw);
	}
}