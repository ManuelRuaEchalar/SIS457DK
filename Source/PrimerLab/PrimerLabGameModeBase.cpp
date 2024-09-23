// Copyright Epic Games, Inc. All Rights Reserved.

#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"
#include "PrimerLabGameModeBase.h"
#include "Board.h"

APrimerLabGameModeBase::APrimerLabGameModeBase()
{
	DefaultPawnClass = ABoard::StaticClass();
}

void APrimerLabGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	
}

