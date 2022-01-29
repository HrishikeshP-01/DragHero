// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelEssentials_BPFuncLib.h"
#include "InstancedProp.generated.h"

UCLASS()
class DRAGHERO_API AInstancedProp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInstancedProp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void OnConstruction(const FTransform& Transform) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTransform baseTransform;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMesh* meshType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector offset = FVector(0);
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int count = 0;

protected:
	UPROPERTY()
		UHierarchicalInstancedStaticMeshComponent* instMesh;
	UPROPERTY()
		USceneComponent* base;
};
