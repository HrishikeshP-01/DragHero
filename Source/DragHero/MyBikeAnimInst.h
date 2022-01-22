// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyBikeAnimInst.generated.h"

/**
 * 
 */
UCLASS()
class DRAGHERO_API UMyBikeAnimInst : public UAnimInstance
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float steering;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// Set this variable in each child class
		float wheelRadius = 20.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float wheelRotAngle;

	UFUNCTION(BlueprintCallable, Category = "UpdateParameters")
		void UpdateParameters();
	UFUNCTION(BlueprintCallable, Category = "FindRotAngle")
		void FindRotAngle();
};
