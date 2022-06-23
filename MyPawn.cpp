// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "MyPlayerController.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("AMyPawn Create!!"));
	AMyPlayerController* con = static_cast<AMyPlayerController*>(GetController());
	UE_LOG(LogTemp, Warning, TEXT("%p"), GetController());
	UE_LOG(LogTemp, Warning, TEXT("%p"), con);
	if (con) {
		UE_LOG(LogTemp, Warning, TEXT("%d"), con->GetData());
	}
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AMyPawn Begin Play!!"));
	UE_LOG(LogTemp, Warning, TEXT("%p"), GetController());
	AMyPlayerController* con = static_cast<AMyPlayerController*>(GetController());
	AMyPlayerController* con2 = static_cast<AMyPlayerController*>(UGameplayStatics::GetPlayerController(this, 0));
	UE_LOG(LogTemp, Warning, TEXT("%p"), con);
	UE_LOG(LogTemp, Warning, TEXT("%p"), con2);
	if (con) {
		UE_LOG(LogTemp, Warning, TEXT("%d"), con->GetData());
	}
	if (con2) {
		UE_LOG(LogTemp, Warning, TEXT("%d"), con2->GetData());
	}
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

