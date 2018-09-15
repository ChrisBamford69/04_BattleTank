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


// Called when the game starts
void UWheelSpawnPoint::BeginPlay()
{
	Super::BeginPlay();

	if (nullptr == WheelToSpawn) { return; }

	ASprungWheel* NewSprungWheel = GetWorld()->SpawnActorDeferred<ASprungWheel>(WheelToSpawn, GetComponentTransform());
	if (nullptr == NewSprungWheel) { return; }

	NewSprungWheel->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);

	UGameplayStatics::FinishSpawningActor(NewSprungWheel, GetComponentTransform());
}


// Called every frame
void UWheelSpawnPoint::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

