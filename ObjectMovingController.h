// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjectMovingController.generated.h"

UCLASS()
class CAMERA_API AObjectMovingController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObjectMovingController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	UPROPERTY(EditAnywhere)
	float ChangeTime;
	float RunningTime;
	TArray<AActor*> TargetList;
	void ChangeMoveProperty();
	float GetRandomRotation();
	void MoveTargetList();
	UPROPERTY(EditAnywhere)
	AActor* MainCamera;
};
