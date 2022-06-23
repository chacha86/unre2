// Copyright Epic Games, Inc. All Rights Reserved.


#include "CameraGameModeBase.h"
#include "MyPawn.h"
#include "CubeActor.h"
#include "CameraPawn.h"
#include "MyPlayerController.h"
ACameraGameModeBase::ACameraGameModeBase()
{
	UE_LOG(LogTemp, Warning, TEXT("GameMode Create!!"));
	//DefaultPawnClass = AMyPawn::StaticClass();
	DefaultPawnClass = ACameraPawn::StaticClass();
	PlayerControllerClass = AMyPlayerController::StaticClass();
	UE_LOG(LogTemp, Warning, TEXT("GameMode setting complete!!"));
}

void ACameraGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	test();
}

void ACameraGameModeBase::Tick(float Delta)
{
	Super::Tick(Delta);
	UE_LOG(LogTemp, Warning, TEXT("GameMode Tick!!"));
}

void ACameraGameModeBase::test()
{
	UE_LOG(LogTemp, Warning, TEXT("hihihi"));
}


