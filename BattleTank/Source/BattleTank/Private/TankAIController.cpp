// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

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
}

ATank* ATankAIController::GetControlledTank() const
{
	return ControlledTank;
}
