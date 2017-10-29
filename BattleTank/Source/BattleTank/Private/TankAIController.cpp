// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "TankPlayerController.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
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

	PlayerTank = GetPlayerTank();
	if (nullptr == PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("%s: cannot find player tank"), *GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s: Player tank is: %s"), *GetName(), *PlayerTank->GetName());
	}
}

//
// Tick this actor
//
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (nullptr != ControlledTank && nullptr != PlayerTank) 
	{
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return ControlledTank;
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (nullptr != PlayerPawn)
	{
		return Cast<ATank>(PlayerPawn);
	}

	return nullptr;
}
