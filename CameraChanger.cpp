// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraChanger.h"
#include "Runtime/Engine/Public/EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"
// Sets default values
ACameraChanger::ACameraChanger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ChangeTime = 3.0f;
}

// Called when the game starts or when spawned
void ACameraChanger::BeginPlay()
{
	Super::BeginPlay();
	
	UWorld* CurrentWorld = GetWorld();
	for (const auto& target : FActorRange(CurrentWorld))
	{
		UActorComponent* comp = target->GetComponentByClass(UCameraComponent::StaticClass());
		UE_LOG(LogTemp, Warning, TEXT("%p"), comp);
		if (comp && target->GetName().StartsWith("Shape_")) {
			CameraActorList.Add(target);
		}
	}
	int32 num = CameraActorList.Num();
	UE_LOG(LogTemp, Warning, TEXT("%d"), num);
}

// Called every frame
void ACameraChanger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (RunningTime >= ChangeTime)
	{
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayerController)
		{
			OurPlayerController->SetViewTarget(CameraActorList[index]);
		}
		RunningTime = 0.0f;
		index++;
		if (index >= CameraActorList.Num())
		{
			index = 0;
		}
	}
	RunningTime += DeltaTime;
}

