// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "WheelSpawnPoint.generated.h"

class ASprungWheel;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UWheelSpawnPoint : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWheelSpawnPoint();

	ASprungWheel* GetWheel() const;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	TSubclassOf<AActor> WheelToSpawn = nullptr;
	
	// the spawned wheel
	UPROPERTY()
	ASprungWheel* SprungWheel = nullptr;
};
