// Copyright Epic Games, Inc. All Rights Reserved.

#include "TT_Player/TestTuskGameMode.h"
#include "TT_Player/TestTuskHUD.h"
#include "TT_Player/TestTuskCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATestTuskGameMode::ATestTuskGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATestTuskHUD::StaticClass();
}
