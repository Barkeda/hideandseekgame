// Copyright Epic Games, Inc. All Rights Reserved.

#include "hideandseekgameGameMode.h"
#include "hideandseekgameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AhideandseekgameGameMode::AhideandseekgameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
