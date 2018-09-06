// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
	bWantsBeginPlay = true;
}

void UTankTrack::BeginPlay()
{
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//
	// The article is not conclusive
	// https://en.wikipedia.org/wiki/Slip_(vehicle_dynamics)
	//
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());

	//
	// acceleration this frame to correct
	// we correct in the *opposite* direction, note the negative slip speed
	// remember acceleration is distance over time
	// https://en.wikipedia.org/wiki/Acceleration
	//
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();

	//
	// calculate the sideways friction (F = m a)
	// divide by 2 for the 2 tank tracks
	// https://en.wikipedia.org/wiki/Friction
	//
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2;
	TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("Tank track OnHit"))
}

void UTankTrack::SetThrottle(float Throttle)
{
	auto ForceApplied = GetForwardVector() * Throttle * MaximumDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}