// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraPawn.h"
#include "MyUtil.h"
#include "MyPawnMovementComponent.h"
#include "Framework/Commands/InputChord.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
ACameraPawn::ACameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	SphereVisual->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (SphereVisualAsset.Succeeded())
	{
		SphereVisual->SetStaticMesh(SphereVisualAsset.Object);
	}
	//SetActorLocationAndRotation(FVector::ZeroVector, FRotator::ZeroRotator);
	OurMovement = CreateDefaultSubobject<UMyPawnMovementComponent>(TEXT("Movement"));
	OurMovement->UpdatedComponent = RootComponent;
}

// Called when the game starts or when spawned
void ACameraPawn::BeginPlay()
{
	Super::BeginPlay();
//	APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
//	if (OurPlayerController)
//	{
//		OurPlayerController->SetViewTarget(MainCam);
//	}
}

// Called every frame
void ACameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
//	if(IsForwardMoving)
//	{
//		SetActorLocation(GetActorLocation() + GetActorForwardVector());
//	}
}

// Called to bind functionality to input
void ACameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

//	PlayerInputComponent->BindKey(EKeys::A, IE_Released, this, &ACameraPawn::StopForward);
	PlayerInputComponent->BindAction(TEXT("Test"), IE_Pressed, this, &ACameraPawn::Test);
	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &ACameraPawn::MoveForHorizon);
}

void ACameraPawn::MoveForHorizon(float val)
{
	if (OurMovement && (OurMovement->UpdatedComponent == RootComponent))
	{
		FVector Vec = OurMovement->GetPendingInputVector();
		//LOG("%f, %f, %f", Vec.X, Vec.Y, Vec.Z);
		OurMovement->AddInputVector(GetActorForwardVector() * val);
	}
}

void ACameraPawn::MoveForVertical(float val)
{
	AddMovementInput(GetActorForwardVector(),  val);
}

UPawnMovementComponent* ACameraPawn::GetMovementComponent() const
{
	return OurMovement;
}

void ACameraPawn::Test() {
	FVector Vec = OurMovement->GetLastInputVector();
	FVector Loc = GetActorLocation();
	SetActorLocation(Loc + Vec);
	OurMovement->ConsumeInputVector();
}


