// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class SLATEUNDERSTANDING_API SCompoundWidgetSlate : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCompoundWidgetSlate) {}

	SLATE_ARGUMENT(TWeakObjectPtr<class ASlateUnderstandingHUD>, CompoundWidgetSlateHUDArg)

	SLATE_END_ARGS()

	void Construct(const FArguments& Arguments);

	TWeakObjectPtr<class ASlateUnderstandingHUD> CompoundWidgetSlateHUD;

	virtual bool SupportsKeyboardFocus() const override { return true; }

	FReply OnPlayClicked() const;
	FReply OnQuitClicked() const;
};
