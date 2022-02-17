// Fill out your copyright notice in the Description page of Project Settings.


#include "Crowd.h"

// Sets default values
ACrowd::ACrowd()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACrowd::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACrowd::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACrowd::PopulateRow(USceneComponent* base, FVector offset)
{
	FTransform currentMeshTransform = base->GetRelativeTransform();
	int size = meshArray.Num();
	for (int i = 0; i < rowCount; i++)
	{
		meshArray[FMath::RandRange(0,size-1)]->AddInstance(currentMeshTransform);
		currentMeshTransform.SetLocation(currentMeshTransform.GetLocation() + offset);
	}
}
