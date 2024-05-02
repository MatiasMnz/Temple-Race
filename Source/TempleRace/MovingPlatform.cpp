// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
    
	StartLocation = GetActorLocation();

}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    MovePlatform(DeltaTime);

	RotationPlatform(DeltaTime);

}

void AMovingPlatform::MovePlatform(float Deltatime)
{
	 // Las notas representan lo llamada pseudocodigok
	
	if(MovePlatformReturn())
	{
		FVector MoveDirection = DeltaVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		DeltaVelocity = -DeltaVelocity;
	}
	else
	{
		FVector CurrentLocation = GetActorLocation();
    
	    CurrentLocation = CurrentLocation + (DeltaVelocity * Deltatime);
    
	    SetActorLocation(CurrentLocation);
	}
}

void AMovingPlatform::RotationPlatform(float Deltatime)
{
    AddActorLocalRotation(DeltaRotation * Deltatime);
}

bool AMovingPlatform::MovePlatformReturn() const
{
	return DistanceMoved() > MoveDistance;
}

float AMovingPlatform::DistanceMoved() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}
