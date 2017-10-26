// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"
#include "RunTime/Engine/Public/DrawDebugHelpers.h"

ATankPlayerController::ATankPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ControlledTank = Cast<ATank>(GetPawn());
	if (nullptr == ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("%s: no controlled tank"), *GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s: controlled tank is %s"), *GetName(), *ControlledTank->GetName());
	}
}

//
// Tick this actor
//
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return ControlledTank;
}


void ATankPlayerController::AimTowardsCrosshair()
{
	if (nullptr == ControlledTank)
	{
		return;
	}

	FVector HitLocation;
	if (true == GetSightRayHitLocation(HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *HitLocation.ToString());
	}
}


bool ATankPlayerController::GetSightRayHitLocation(FVector & OutHitLocation) const
{
	int32 ViewportSizeX = 0;
	int32 ViewportSizeY = 0;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	return true;
}

const FVector ATankPlayerController::GetBarrelStart() const
{
	FVector BarrelLocation;
	FRotator BarrelRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT BarrelLocation, OUT BarrelRotation);

	return BarrelLocation;
}

const FVector ATankPlayerController::GetShotEnd() const
{
	FVector BarrelLocation;
	FRotator BarrelRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT BarrelLocation, OUT BarrelRotation);

	/// calculate the end of of the "reach" vector
	FVector ShotEnd = BarrelLocation + (BarrelRotation.Vector() * ShotDistance);
	return ShotEnd;
}
