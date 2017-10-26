// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

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
}
