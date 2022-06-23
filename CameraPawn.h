// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CameraPawn.generated.h"

UCLASS()
class CAMERA_API ACameraPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACameraPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	void MoveForHorizon(float val);
	void MoveForVertical(float val);
	virtual UPawnMovementComponent* GetMovementComponent() const override;
	class UMyPawnMovementComponent* OurMovement;
	void Test();
	bool IsForwardMoving;
	UPROPERTY(EditAnywhere)
	AActor* MainCam;
};
