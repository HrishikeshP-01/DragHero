// Fill out your copyright notice in the Description page of Project Settings.


#include "ModeMenu.h"

void UModeMenu::NativeConstruct()
{
	Super::NativeConstruct();
	storyMode->mbd.AddDynamic(this, &UModeMenu::ButtonClicked_StoryMode);
	careerMode->mbd.AddDynamic(this, &UModeMenu::ButtonClicked_StoryMode);
	pvpMode->mbd.AddDynamic(this, &UModeMenu::ButtonClicked_StoryMode);
}

void UModeMenu::ButtonClicked_StoryMode()
{
	this->RemoveFromViewport();
}