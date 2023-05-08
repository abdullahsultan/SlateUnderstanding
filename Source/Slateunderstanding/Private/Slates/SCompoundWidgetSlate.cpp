// Fill out your copyright notice in the Description page of Project Settings.


#include "Slates/SCompoundWidgetSlate.h"

#define LOCTEXT_NAMESPACE "CompoundWidgetSlate"

void SCompoundWidgetSlate::Construct(const FArguments& Arguments)
{
	const FMargin ContentPadding = FMargin(500.0f, 300.0f);
	const FText TitleText = LOCTEXT("CompoundWidgetSlate", "CompoundWidgetSlateTest"); // Different languages in game

		ChildSlot
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SImage)
				.ColorAndOpacity(FColor::Black)
			]
			+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(ContentPadding)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				[
					SNew(STextBlock)
					.Text(TitleText)
				]
			]

		];

}

#undef LOCTEXT_NAMESPACE
