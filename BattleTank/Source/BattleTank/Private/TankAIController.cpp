// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "TankPlayerController.h"
#include "Tank.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

//
// Tick this actor
//
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GetControlledTank()->AimAt(GetPlayerTankLocation());
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

FVector ATankAIController::GetPlayerTankLocation() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (nullptr != PlayerPawn)
	{
		return PlayerPawn->GetActorLocation();
	}

	return FVector(0);
}
