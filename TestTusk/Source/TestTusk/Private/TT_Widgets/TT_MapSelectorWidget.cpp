// Fill out your copyright notice in the Description page of Project Settings.


#include "TT_Widgets/TT_MapSelectorWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"

void UTT_MapSelectorWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	MapSelect_1->OnClicked.AddDynamic(this, &UTT_MapSelectorWidget::OpenNextLevel_1);
	MapSelect_2->OnClicked.AddDynamic(this, &UTT_MapSelectorWidget::OpenNextLevel_2);
	MapSelect_3->OnClicked.AddDynamic(this, &UTT_MapSelectorWidget::OpenNextLevel_3);
	MapSelect_4->OnClicked.AddDynamic(this, &UTT_MapSelectorWidget::OpenNextLevel_4);

}

void UTT_MapSelectorWidget::OpenNextLevel_1()
{
UGameplayStatics::OpenLevel(this, LevelName_1);
}
void UTT_MapSelectorWidget::OpenNextLevel_2()
{
	UGameplayStatics::OpenLevel(this, LevelName_2);
}
void UTT_MapSelectorWidget::OpenNextLevel_3()
{
	UGameplayStatics::OpenLevel(this, LevelName_3);
}
void UTT_MapSelectorWidget::OpenNextLevel_4()
{
	UGameplayStatics::OpenLevel(this, LevelName_4);
}