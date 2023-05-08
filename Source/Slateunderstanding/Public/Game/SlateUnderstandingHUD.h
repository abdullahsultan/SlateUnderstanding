// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SlateUnderstandingHUD.generated.h"

/**
 * 
 */
UCLASS()
class SLATEUNDERSTANDING_API ASlateUnderstandingHUD : public AHUD
{
	GENERATED_BODY()

public:
	TSharedPtr<class SCompoundWidgetSlate> CompountWidgetSlate;
	TSharedPtr<class SWidget> ContainerWidget;

	virtual void BeginPlay() override;
	
};
