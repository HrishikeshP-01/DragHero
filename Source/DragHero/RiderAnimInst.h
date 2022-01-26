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
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector rh_loc;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector lh_loc;
	UFUNCTION(BlueprintCallable)
		void UpdateParameters();
};
