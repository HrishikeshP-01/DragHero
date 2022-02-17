// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ModeButton.h"
#include "ModeMenu.generated.h"

/**
 * 
 */
UCLASS()
class DRAGHERO_API UModeMenu : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(meta=(BindWidget))
		UModeButton* storyMode;
	UPROPERTY(meta = (BindWidget))
		UModeButton* careerMode;
	UPROPERTY(meta = (BindWidget))
		UModeButton* pvpMode;
	virtual void NativeConstruct()override;
	UFUNCTION(BlueprintCallable)
		void ButtonClicked_StoryMode();
};

