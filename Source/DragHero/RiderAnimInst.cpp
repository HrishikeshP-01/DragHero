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
	}
}
