// Copyright Epic Games, Inc. All Rights Reserved.

#include "UdemyTemplateGameMode.h"
#include "UdemyTemplateCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUdemyTemplateGameMode::AUdemyTemplateGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
