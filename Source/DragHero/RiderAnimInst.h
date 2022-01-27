// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyBike.h"
#include "RiderAnimInst.generated.h"

/**
 * 
 */
UCLASS()
class DRAGHERO_API URiderAnimInst : public UAnimInstance
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float maxLean;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float leanInterpTime = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float lean;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float rt_legLean = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float lt_legLean = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float maxLegLean = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float percentLegLean;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector rh_loc;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector lh_loc;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector lh_elbow;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector rh_elbow;
	UPROPERTY(BlueprintReadOnly)
		FVector rFootRest;
	UPROPERTY(BlueprintReadOnly)
		FVector lFootRest;
	UFUNCTION(BlueprintCallable)
		void UpdateParameters();
};
