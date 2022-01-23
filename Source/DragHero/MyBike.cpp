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

	// Gear system
	gearToSpeedMapping.Init(0, maxGear);
	TMaxSpeed = 0;
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
	InputComponent->BindAxis("Brake", this, &AMyBike::ApplyBrake);
	
	InputComponent->BindAction("GearUp", IE_Pressed, this,&AMyBike::IncrementGear);
	InputComponent->BindAction("GearDown", IE_Pressed, this, & AMyBike::DecrementGear);
}

void AMyBike::FindThrottle(float Axis)
{
	if (!brakeApplied)
	{
		float CurrentSpeed = FMath::FInterpTo(TCurrentSpeed, Axis * TMaxSpeed, FApp::GetDeltaTime(), TInterpSpeed);
		TCurrentSpeed = FMath::Clamp(CurrentSpeed, TMaxReverseSpeed, TMaxSpeed);
	}
}

void AMyBike::FindSteer(float Axis)
{
	CurrentSteeringAngle = FMath::FInterpTo(CurrentSteeringAngle, Axis * MaxSteeringAngle * FMath::FloatSelect((TCurrentSpeed < 0) ? 1.0 : -1.0, 2.0, 1.0), FApp::GetDeltaTime(), SInterpSpeed);
}

void AMyBike::FindLean()
{
	CurrentLeanAngle = FMath::FInterpTo(CurrentLeanAngle, ((TCurrentSpeed / maxBikeSpeed) * CurrentSteeringAngle), FApp::GetDeltaTime(), LeanInterpSpeed);
}

void AMyBike::ApplyThrottleToBike()
{
	FVector deltaLoc = GetActorForwardVector() * TCurrentSpeed * FApp::GetDeltaTime();
	AddActorWorldOffset(deltaLoc, false, nullptr, ETeleportType::TeleportPhysics);
}

void AMyBike::ApplySteerToBike()
{
	FindLean();
	float steer = TCurrentSpeed * CurrentSteeringAngle * SpeedSteeringToRotationFactor * FApp::GetDeltaTime();
	float yaw = steer + GetActorRotation().Yaw;
	SetActorRelativeRotation(FRotator(0.0f, yaw, CurrentLeanAngle), false, nullptr,ETeleportType::TeleportPhysics);
}

void AMyBike::ApplyBrake(float Axis)
{
	if (Axis != 0.0f)
	{
		brakeApplied = true;
		float targetSpeed = TCurrentSpeed - (Axis * BrakeFactor);
		float newCurrentSpeed = FMath::FInterpTo(TCurrentSpeed, targetSpeed, FApp::GetDeltaTime(), BrakeInterpSpeed);
		// Just stop when brake applied during rev no interp needed
		TCurrentSpeed = FMath::Clamp(newCurrentSpeed, 0.0f, TMaxSpeed);
	}
	else
	{
		brakeApplied = false;
	}
}

void AMyBike::IncrementGear()
{
	currentGear = FMath::Clamp(currentGear + 1, 0, maxGear - 1);
	TMaxSpeed = (gearToSpeedMapping[currentGear] / gearToSpeedMapping[gearToSpeedMapping.Num() - 1]) * maxBikeSpeed;
	
	gearChanged.Broadcast(currentGear);
}

void AMyBike::DecrementGear()
{
	currentGear = FMath::Clamp(currentGear - 1, 0, maxGear - 1);
	TMaxSpeed = (gearToSpeedMapping[currentGear] / gearToSpeedMapping[gearToSpeedMapping.Num() - 1]) * maxBikeSpeed;

	gearChanged.Broadcast(currentGear);
}

float AMyBike::GetTCurrentSpeed()
{
	return TCurrentSpeed;
}

float AMyBike::GetCurrentSteeringAngle()
{
	return CurrentSteeringAngle;
}

float AMyBike::GetMaxPossibleSpeed()
{
	return maxBikeSpeed;
}

float AMyBike::GetSpeedInGearSpeedFormat()
{
	return TCurrentSpeed / maxBikeSpeed * gearToSpeedMapping[gearToSpeedMapping.Num() - 1];
}

float AMyBike::GetFuel()
{
	return fuel;
}