// Fill out your copyright notice in the Description page of Project Settings.


#include "WheelSpawnPoint.h"
#include "SprungWheel.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UWheelSpawnPoint::UWheelSpawnPoint()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

ASprungWheel * UWheelSpawnPoint::GetWheel() const
{
	return SprungWheel;
}

// Called when the game starts
void UWheelSpawnPoint::BeginPlay()
{
	Super::BeginPlay();

	//
	// check for a valid type to be spawned
	//
	if (nullptr == WheelToSpawn) { return; }

	//
	// spawn and check for a valid new actor
	//
	SprungWheel = GetWorld()->SpawnActorDeferred<ASprungWheel>(WheelToSpawn, GetComponentTransform());
	if (nullptr == SprungWheel) { return; }

	//
	// attach the actor to the spawn point
	//
	SprungWheel->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);

	//
	// finish the spawn
	//
	UGameplayStatics::FinishSpawningActor(SprungWheel, GetComponentTransform());
}


// Called every frame
void UWheelSpawnPoint::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
