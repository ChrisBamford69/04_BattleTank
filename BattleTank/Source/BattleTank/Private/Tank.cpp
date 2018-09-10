// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Engine/World.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCausor)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, InnerHealth);

	InnerHealth -= DamageToApply;
	if (InnerHealth <= 0)
	{
		TankDeath.Broadcast();
	}

	return DamageToApply;
}

float ATank::GetHealthRemaining() const
{
	return (float)InnerHealth / (float)StartingHealth;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	// needed for Blueprint BeginPlay to work correctly
	Super::BeginPlay();

	InnerHealth = StartingHealth;
}
