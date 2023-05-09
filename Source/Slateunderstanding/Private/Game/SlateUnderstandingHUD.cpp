// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/SlateUnderstandingHUD.h"
#include "Slates/SCompoundWidgetSlate.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"

void ASlateUnderstandingHUD::BeginPlay()
{
	Super::BeginPlay();
	if (GEngine && GEngine->GameViewport)
	{
		CompountWidgetSlate = SNew(SCompoundWidgetSlate).CompoundWidgetSlateHUDArg(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(ContainerWidget, SWeakWidget).PossiblyNullContent(CompountWidgetSlate.ToSharedRef()));
	}
}

void ASlateUnderstandingHUD::RemoveSlate()
{
	if (GEngine && GEngine->GameViewport && ContainerWidget.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(ContainerWidget.ToSharedRef());
	}
}
