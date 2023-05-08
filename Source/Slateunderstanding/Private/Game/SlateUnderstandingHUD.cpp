// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/SlateUnderstandingHUD.h"
#include "Slates/SCompoundWidgetSlate.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/Engine.h"

void ASlateUnderstandingHUD::BeginPlay()
{
	Super::BeginPlay();
	if (GEngine && GEngine->GameViewport)
	{
		CompountWidgetSlate = SNew(SCompoundWidgetSlate).CompoundWidgetSlateHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(ContainerWidget, SWeakWidget).PossiblyNullContent(CompountWidgetSlate.ToSharedRef()));
	}
}
