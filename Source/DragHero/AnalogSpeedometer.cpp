// Fill out your copyright notice in the Description page of Project Settings.


#include "AnalogSpeedometer.h"

void UAnalogSpeedometer::NativeConstruct()
{
	Super::NativeConstruct();
	speedometerDynamic = UMaterialInstanceDynamic::Create(speedometerConst, nullptr);
	speedometerImage->SetBrushFromMaterial(speedometerDynamic);
}

void UAnalogSpeedometer::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	// Can't use speed as it's in km/h (gear speed mapping)
	speedometerDynamic->SetScalarParameterValue(FName(TEXT("Speed")), speed/maxSpeed);
	speedometerDynamic->SetScalarParameterValue(FName(TEXT("RPM")), speed / wheelRadius);
}