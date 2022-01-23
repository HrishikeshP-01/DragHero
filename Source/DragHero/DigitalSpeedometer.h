// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Speedometer.h"
#include <Components/TextBlock.h>
#include <Components/ProgressBar.h>
#include "DigitalSpeedometer.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class DRAGHERO_API UDigitalSpeedometer : public USpeedometer
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* SpeedLabel;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* GearLabel;
	UPROPERTY(meta = (BindWidget))
		class UProgressBar* FuelProgress;

	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime)override;
};
