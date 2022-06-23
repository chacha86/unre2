// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MySpawner.generated.h"

UCLASS()
class CAMERA_API AMySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMySpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
	float SpawnTime = 5.0f;
	float RunningTime = 0.0f;
	UPROPERTY(EditAnywhere)
	float IntervalLength = 100.f;
	int32 count = 1;
};
