// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBikeAnimInst.h"
#include "MyBike.h"

void UMyBikeAnimInst::UpdateParameters()
{
	APawn* pawn = TryGetPawnOwner();
	if (pawn)
	{
		AMyBike* bike = Cast<AMyBike>(pawn);
		speed = bike->GetTCurrentSpeed();
		steering = bike->GetCurrentSteeringAngle() * FMath::GetMappedRangeValueClamped(TRange<float>(0, bike->GetMaxPossibleSpeed()), TRange<float>(1, 0.1f), speed);
	}

}

void UMyBikeAnimInst::FindRotAngle()
{
	wheelRotAngle += FMath::RadiansToDegrees((speed / wheelRadius) * (float)FApp::GetDeltaTime());
}

