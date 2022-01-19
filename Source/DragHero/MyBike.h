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
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
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

	void FindThrottle(float Axis);
	void FindSteer(float Axis);
	void FindLean();

	void ApplySteerToBike();
	void ApplyThrottleToBike();

protected:
	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* BikeMesh;
	UPROPERTY(EditAnywhere)
		USpringArmComponent* springArm;
};
