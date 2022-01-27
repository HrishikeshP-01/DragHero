// Fill out your copyright notice in the Description page of Project Settings.


#include "RiderAnimInst.h"

void URiderAnimInst::UpdateParameters()
{
	APawn* pawn = TryGetPawnOwner();
	if (pawn)
	{
		AMyBike* bike = Cast<AMyBike>(pawn);
		TArray<FVector> y = bike->GetSocketLocation();
		rh_loc = y[0];
		lh_loc = y[1];
		rh_elbow = y[2];
		lh_elbow = y[3];
		// Body leans forward with speed
		lean = FMath::FInterpTo(lean, (bike->GetTCurrentSpeed() / bike->GetMaxPossibleSpeed() * maxLean), FApp::GetDeltaTime(), leanInterpTime);
		// Leg leans with bike lean
		rt_legLean = FMath::Clamp(FMath::FInterpTo(rt_legLean, (bike->GetLean() * percentLegLean), FApp::GetDeltaTime(), 1.0f), 0.0f, maxLegLean);
		lt_legLean = FMath::Clamp(FMath::FInterpTo(lt_legLean, (bike->GetLean() * percentLegLean), FApp::GetDeltaTime(), 1.0f), -maxLegLean, 0.0f);
		rFootRest = y[4];
		lFootRest = y[5];
	}
}
