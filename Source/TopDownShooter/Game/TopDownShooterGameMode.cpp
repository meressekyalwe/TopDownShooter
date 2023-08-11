// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "TopDownShooterGameMode.h"
#include "TopDownShooterPlayerController.h"
#include "Character/TopDownShooterCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATopDownShooterGameMode::ATopDownShooterGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATopDownShooterPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprint/Character/BP_TopDownShooterCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}