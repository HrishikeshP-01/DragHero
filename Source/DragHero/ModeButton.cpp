// Fill out your copyright notice in the Description page of Project Settings.


#include "ModeButton.h"

void UModeButton::SetupButton()
{
	FButtonData* Row = dataTable->FindRow<FButtonData>(rowName, TEXT(""));
	if (Row)
	{
		xButton->SetStyle((*Row).style);
		xText->SetText(buttonText);
	}
	else
	{
		GLog->Log(rowName.ToString());
	}
}

void UModeButton::NativeConstruct()
{
	Super::NativeConstruct();
	xButton->OnClicked.AddDynamic(this, &UModeButton::xButtonPressed);
	SetupButton();
}

void UModeButton::xButtonPressed()
{
	mbd.Broadcast();
}

