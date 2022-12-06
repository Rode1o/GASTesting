// Copyright Epic Games, Inc. All Rights Reserved.

#include "GASTestingGameMode.h"
#include "GASTestingCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGASTestingGameMode::AGASTestingGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
