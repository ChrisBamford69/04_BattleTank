// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"
#include "SprungWheel.h"
#include "WheelSpawnPoint.h"
#include "Engine/World.h"


UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();
}

void UTankTrack::SetThrottle(float Throttle)
{
	auto CurrentThrottle = FMath::Clamp<float>(Throttle, -1, 1);
	DriveTrack(CurrentThrottle);
}

void UTankTrack::DriveTrack(float CurrentThrottle)
{
	auto ForceApplied = CurrentThrottle * MaximumDrivingForce;
	auto Wheels = GetWheels();
	auto ForcePerWheel = ForceApplied / Wheels.Num();

	for (ASprungWheel* Wheel : Wheels)
	{
		Wheel->AddDrivingForce(ForcePerWheel);
	}
}

TArray<ASprungWheel*> UTankTrack::GetWheels() const
{
	TArray<USceneComponent*> ChildComponents;
	GetChildrenComponents(true, ChildComponents);
	TArray<ASprungWheel*> WheelsArray;

	for (USceneComponent* Component : ChildComponents)
	{
		//
		// check for valid pointer on cast
		//
		if (UWheelSpawnPoint * SpawnPoint = Cast<UWheelSpawnPoint>(Component))
		{
			ASprungWheel* Wheel = SpawnPoint->GetWheel();
			if (nullptr != Wheel)
			{
				WheelsArray.Add(Wheel);
			}
		}
	}

	return WheelsArray;
}
