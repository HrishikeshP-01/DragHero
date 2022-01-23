// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyBike.h"
#include "Speedometer.generated.h"

UCLASS(Abstract)
class DRAGHERO_API USpeedometer : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetOwnerBike(AMyBike* bike);

protected:
	TWeakObjectPtr<AMyBike> OwnerBike;
	float fuel;
	int speed;
	int gear;
	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime)override;
	UFUNCTION()
	void GearChangeDetected(float gearId);
};
