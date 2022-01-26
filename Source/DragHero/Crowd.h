// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Crowd.generated.h"

UCLASS()
class DRAGHERO_API ACrowd : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACrowd();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<UInstancedStaticMeshComponent*> meshArray;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int rowCount;

	UFUNCTION(BlueprintCallable)
		void PopulateRow(USceneComponent* base, FVector offset);

};