// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Speedometer.h"
#include "Components/Image.h"
#include "Materials/MaterialInstanceConstant.h"
#include "AnalogSpeedometer.generated.h"

/**
 * 
 */
UCLASS()
class DRAGHERO_API UAnalogSpeedometer : public USpeedometer
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UMaterialInstanceConstant* speedometerConst;
	UPROPERTY()
		UMaterialInstanceDynamic* speedometerDynamic;
	UPROPERTY(meta = (BindWidget))
		UImage* speedometerImage;
	// For analog speedometer set max speed manually as the value of the material also matters. Remember speed is in gearSpeedMapping format
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float maxSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float wheelRadius;
	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime)override;
	void NativeConstruct()override;
};