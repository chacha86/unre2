// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CameraGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CAMERA_API ACameraGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	ACameraGameModeBase();
	virtual void BeginPlay() override;
	virtual void Tick(float Delta) override;
private : 
	UPROPERTY(EditAnywhere)
	class ACubeActor* Cube;
	void test();
	
};
