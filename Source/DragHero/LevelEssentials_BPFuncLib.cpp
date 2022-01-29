// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelEssentials_BPFuncLib.h"

void ULevelEssentials_BPFuncLib::generateHierarchialInstancedMeshes(USceneComponent* base, UHierarchicalInstancedStaticMeshComponent* HInstMesh, FVector offset, int count)
{
	FTransform meshTransformation = base->GetRelativeTransform();
	for (int i = 0;i < count;i++)
	{
		HInstMesh->AddInstance(meshTransformation);
		meshTransformation.SetLocation(meshTransformation.GetLocation() + offset);
	}
}