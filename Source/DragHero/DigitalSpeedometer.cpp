// Fill out your copyright notice in the Description page of Project Settings.


#include "DigitalSpeedometer.h"

void UDigitalSpeedometer::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	SpeedLabel->SetText(FText::AsNumber(speed));
	GearLabel->SetText(FText::AsNumber(gear));
	FuelProgress->SetPercent(fuel);
}