// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectMovingController.h"
#include "Runtime/Engine/Public/EngineUtils.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AObjectMovingController::AObjectMovingController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ChangeTime = 5.0f;

}

// Called when the game starts or when spawned
void AObjectMovingController::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (OurPlayerController)
	{
		OurPlayerController->SetViewTarget(MainCamera);
	}
	UWorld* CurrentWorld = GetWorld();
	for (const auto& target : FActorRange(CurrentWorld))
	{
		//UE_LOG(LogTemp, Warning, TEXT("%s"), *target->GetName());
		if (target->GetName().StartsWith("Shape_")) {
			UE_LOG(LogTemp, Warning, TEXT("%s"), *target->GetName());
			TargetList.Add(target);
		}
	}
}

// Called every frame
void AObjectMovingController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (RunningTime >= ChangeTime)
	{
		ChangeMoveProperty();
		//UE_LOG(LogTemp, Warning, TEXT("adfsdf"));
		RunningTime = 0.f;
	}
	
	MoveTargetList();
	RunningTime += DeltaTime;
}

void AObjectMovingController::MoveTargetList() {
	for (const auto& target : TargetList) {
		FVector loc = target->GetActorLocation();
		FVector rst = loc + target->GetActorForwardVector();
		target->SetActorLocation(rst);

	}
}

void AObjectMovingController::ChangeMoveProperty()
{
	for (auto target : TargetList)
	{
		float yaw = GetRandomRotation();
		FRotator rot = target->GetActorRotation();
		rot.Yaw = yaw;
		target->SetActorRotation(rot);
	}
}

float AObjectMovingController::GetRandomRotation() {
	float yaw = FMath::RandRange(0.0f, 360.0f);
	return yaw;
}



