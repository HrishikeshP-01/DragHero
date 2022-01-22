// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Math/UnrealMathUtility.h"
#include "Misc/App.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "MyBike.generated.h"

UCLASS()
class DRAGHERO_API AMyBike : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyBike();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


// Variables for the bike movement
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float TMaxSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float TMaxReverseSpeed;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly) // Changed this from read only & visible to get this in the anim classs
		float TCurrentSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float TInterpSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxSteeringAngle;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float CurrentSteeringAngle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SInterpSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	   float SpeedSteeringToRotationFactor;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float CurrentLeanAngle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float LeanInterpSpeed;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool brakeApplied;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BrakeFactor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BrakeInterpSpeed;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int currentGear = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int maxGear = 6;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<float> gearToSpeedMapping;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float maxBikeSpeed;

	void FindThrottle(float Axis);
	void FindSteer(float Axis);
	void ApplyBrake(float Axis);
	void FindLean();

	void ApplySteerToBike();
	void ApplyThrottleToBike();

	void DecrementGear();
	void IncrementGear();

protected:
	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* BikeMesh;
	UPROPERTY(EditAnywhere)
		USpringArmComponent* springArm;

public:
	float GetTCurrentSpeed();
	float GetCurrentSteeringAngle();
	float GetMaxPossibleSpeed();
};
