// Fill out your copyright notice in the Description page of Project Settings.


#include "Slates/SCompoundWidgetSlate.h"
#include "Game/SlateUnderstandingHUD.h"

#define LOCTEXT_NAMESPACE "CompoundWidgetSlate"

void SCompoundWidgetSlate::Construct(const FArguments& Arguments)
{
	bCanSupportFocus = true;
	CompoundWidgetSlateHUD = Arguments._CompoundWidgetSlateHUDArg;

	const FMargin ContentPadding = FMargin(500.0f, 300.0f);
	const FMargin ButtonPadding = FMargin(10.0f);

	FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	ButtonTextStyle.Size = 40.0f;

	const FText TitleText = LOCTEXT("CompoundWidgetSlate", "CompoundWidgetSlateTest"); // Different languages in game
	const FText PlayText = LOCTEXT("PlayGame","Play");
	const FText SettingsText = LOCTEXT("Settings","Settings");
	const FText QuitText = LOCTEXT("QuitGame","Quit Game");

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
				//Some Text
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				[
					SNew(STextBlock)
					.Text(TitleText)
					.Font(ButtonTextStyle)
					.Justification(ETextJustify::Center)
				]

				//Button Play
				+ SVerticalBox::Slot()
				.Padding(ButtonPadding)
				[
					SNew(SButton)
					.OnClicked(this, &SCompoundWidgetSlate::OnPlayClicked)
					[
						SNew(STextBlock)
						.Font(ButtonTextStyle)
						.Text(PlayText)
						.Justification(ETextJustify::Center)
					]
				]

				//Button Settings
				+ SVerticalBox::Slot()
				.Padding(ButtonPadding)
				[
					SNew(SButton)
					[
					  SNew(STextBlock)
					 .Font(ButtonTextStyle)
					 .Text(SettingsText)
					 .Justification(ETextJustify::Center)
					]
				]

				//Button Quit
				+ SVerticalBox::Slot()
					.Padding(ButtonPadding)
					[
					  SNew(SButton)
					 .OnClicked(this, &SCompoundWidgetSlate::OnQuitClicked)
					   [
						 SNew(STextBlock)
						.Font(ButtonTextStyle)
						.Text(QuitText)
						.Justification(ETextJustify::Center)
					   ]
					]
			]

		];

}

FReply SCompoundWidgetSlate::OnPlayClicked() const
{
	return FReply::Handled();
}

FReply SCompoundWidgetSlate::OnQuitClicked() const
{
	CompoundWidgetSlateHUD->RemoveSlate();
	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
