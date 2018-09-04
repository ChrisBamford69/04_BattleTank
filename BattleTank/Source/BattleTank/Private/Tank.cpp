// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"
#include "Projectile.h"
#include "Engine/World.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::Fire()
{
	if (!ensure(Barrel)) { return; }

	bool IsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (IsReloaded)
	{
		AProjectile* NewProjectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileToLaunch,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile")));

		NewProjectile->Launch(LaunchSpeed);

		LastFireTime = FPlatformTime::Seconds();
	}
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	// needed for Blueprint BeginPlay to work correctly
	Super::BeginPlay();
}

void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) { return; }

	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}
