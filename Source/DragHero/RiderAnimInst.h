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
	UPROPERTY(BlueprintReadOnly)
		float lean;
	UPROPERTY(BlueprintReadOnly)
		float rt_legLean = 0;
	UPROPERTY(BlueprintReadOnly)
		float lt_legLean = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float maxLegLean = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float percentLegLean;
	UPROPERTY(BlueprintReadOnly)
		FVector rh_loc;
	UPROPERTY(BlueprintReadOnly)
		FVector lh_loc;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector rFootRest;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector lFootRest;
	UPROPERTY(BlueprintReadOnly)
		FVector SpeedRightHandle;
	UPROPERTY(BlueprintReadOnly)
		FVector SpeedLeftHandle;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector FinalRightHandLoc;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector FinalLeftHandLoc;
	UFUNCTION(BlueprintCallable)
		void UpdateParameters();
};
