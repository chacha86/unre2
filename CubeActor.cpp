// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeActor.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
ACubeActor::ACubeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("ACubeActor create!!"));
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (StaticMesh.Succeeded())
	{
		MeshComponent->SetStaticMesh(StaticMesh.Object);
	}
	RootComponent = MeshComponent;
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);
	Camera->SetRelativeLocationAndRotation(FVector(0.0f, -50.0f, 35.0f), FRotator(0.0f, -90.0f, 0.0f));
	//Camera->SetWorldLocation(FVector(0.0f, -50.0f, 35.0f));
	//Camera->SetWorldRotation(FRotator(0.0f, -90.0f, 0.0f));
}

// Called when the game starts or when spawned
void ACubeActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("ACubeActor Begin Play!!"));
	APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
	/*APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (OurPlayerController)
	{
		OurPlayerController->SetViewTarget(this);
	}*/
}

// Called every frame
void ACubeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector loc = GetActorLocation();
	if (loc.X >= 300) {
		direction = -1.0f;
	}
	if (loc.X <= 0) {
		direction = 1.0f;
	}
	loc += FVector(1.0f * direction, 0.0f, 0.0f);

	SetActorLocation(loc);
}

