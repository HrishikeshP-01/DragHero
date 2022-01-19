// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBike.h"

// Sets default values
AMyBike::AMyBike()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set the pawn to be controller by Player 0
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// Setup the bike
	BikeMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BikeMesh"));
	RootComponent = BikeMesh;
	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	UCameraComponent* camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	camera->SetupAttachment(springArm);
	springArm->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMyBike::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyBike::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Bike Movement
	ApplyThrottleToBike();
	ApplySteerToBike();

}

// Called to bind functionality to input
void AMyBike::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("Throttle", this, &AMyBike::FindThrottle);
	InputComponent->BindAxis("Steer", this, &AMyBike::FindSteer);
}

void AMyBike::FindThrottle(float Axis)
{
	TCurrentSpeed = FMath::FInterpTo(TCurrentSpeed, Axis * TMaxSpeed, FApp::GetDeltaTime(), TInterpSpeed);
}

void AMyBike::FindSteer(float Axis)
{
	CurrentSteeringAngle = FMath::FInterpTo(CurrentSteeringAngle, Axis * MaxSteeringAngle, FApp::GetDeltaTime(), SInterpSpeed);
}

void AMyBike::FindLean()
{
	CurrentLeanAngle = FMath::FInterpTo(CurrentLeanAngle, ((TCurrentSpeed / TMaxSpeed) * CurrentSteeringAngle), FApp::GetDeltaTime(), LeanInterpSpeed);
}

void AMyBike::ApplyThrottleToBike()
{
	FVector deltaLoc = GetActorForwardVector() * TCurrentSpeed * FApp::GetDeltaTime();
	AddActorWorldOffset(deltaLoc, true);
}

void AMyBike::ApplySteerToBike()
{
	FindLean();
	float steer = TCurrentSpeed * CurrentSteeringAngle * SpeedSteeringToRotationFactor * FApp::GetDeltaTime();
	float yaw = steer + GetActorRotation().Yaw;
	SetActorRelativeRotation(FRotator(0.0f, yaw, CurrentLeanAngle), true);
}