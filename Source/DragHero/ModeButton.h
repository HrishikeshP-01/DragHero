// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Engine/DataTable.h"
#include "ButtonData.h"
#include "ModeButton.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FModeButtonClicked);

UCLASS()
class DRAGHERO_API UModeButton : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
		class UButton* xButton;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* xText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UDataTable* dataTable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName rowName;
	virtual void NativeConstruct() override;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText buttonText;
	UFUNCTION(BlueprintCallable, Category = "SetupButton")
		void SetupButton();
	UFUNCTION(BlueprintCallable, Category = "xButtonPressed")
		void xButtonPressed();
	UPROPERTY(BlueprintAssignable, Category = "EventDispatchers")
		FModeButtonClicked mbd;
};