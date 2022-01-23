// Fill out your copyright notice in the Description page of Project Settings.


#include "Speedometer.h"

void USpeedometer::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (!OwnerBike.IsValid())
		return;
	speed = OwnerBike->GetSpeedInGearSpeedFormat();
	fuel = OwnerBike->GetFuel();
}

void USpeedometer::SetOwnerBike(AMyBike* bike)
{
	OwnerBike = bike;
	OwnerBike->gearChanged.AddDynamic(this, &USpeedometer::GearChangeDetected);
}

void USpeedometer::GearChangeDetected(float gearId)
{
	gear = gearId;
}