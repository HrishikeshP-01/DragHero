// Fill out your copyright notice in the Description page of Project Settings.


#include "InstancedProp.h"

// Sets default values
AInstancedProp::AInstancedProp()
{
	instMesh = CreateDefaultSubobject<UHierarchicalInstancedStaticMeshComponent>(TEXT("instMesh"));
	base = CreateDefaultSubobject<USceneComponent>(TEXT("base"));
	baseTransform = base->GetComponentTransform();
}

// Called when the game starts or when spawned
void AInstancedProp::BeginPlay()
{
	Super::BeginPlay();
	
}

void AInstancedProp::OnConstruction(const FTransform& Transform)
{
	instMesh->ClearInstances();
	if (meshType)
	{
		base->SetRelativeTransform(baseTransform);
		instMesh->SetStaticMesh(meshType);
		ULevelEssentials_BPFuncLib::generateHierarchialInstancedMeshes(base, instMesh, offset, count);
	}
}


