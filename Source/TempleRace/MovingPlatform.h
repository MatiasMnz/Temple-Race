// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class TEMPLERACE_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(EditAnywhere, Category="Moving")
    FVector DeltaVelocity = FVector(100, 100, 0);

    FVector StartLocation;

    UPROPERTY(EditAnywhere, Category="Moving")
	float MoveDistance = 0;

    UPROPERTY(EditAnyWhere, Category="Rotation")
	FRotator DeltaRotation;

	void MovePlatform(float DeltaTime);

	void RotationPlatform(float Deltatime);

	bool MovePlatformReturn() const;

	float DistanceMoved() const;
};

