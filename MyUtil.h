// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyUtil.generated.h"

#define LOG(s, ...) UE_LOG(LogTemp, Warning, TEXT(s), __VA_ARGS__)

UCLASS()
class CAMERA_API AMyUtil : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyUtil();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
