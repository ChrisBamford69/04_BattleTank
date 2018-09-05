// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "TankPlayerController.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
}

//
// Tick this actor
//
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!ensure(PlayerPawn && AimingComponent)) { return; }
	
	MoveToActor(PlayerPawn, AcceptanceRadius);
	AimingComponent->AimAt(PlayerPawn->GetActorLocation());
	AimingComponent->Fire();
}
