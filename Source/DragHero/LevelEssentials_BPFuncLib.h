// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "LevelEssentials_BPFuncLib.generated.h"

/**
 * 
 */
UCLASS()
class DRAGHERO_API ULevelEssentials_BPFuncLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Props")
		static void generateHierarchialInstancedMeshes(USceneComponent* base, UHierarchicalInstancedStaticMeshComponent* HInstMesh, FVector offset, int count);
	
};
