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

	auto ControlledTank = Cast<ATank>(GetPawn());
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!ensure(ControlledTank && PlayerPawn)) { return; }
	
	MoveToActor(PlayerPawn, AcceptanceRadius);
	ControlledTank->AimAt(PlayerPawn->GetActorLocation());
	ControlledTank->Fire();
}

