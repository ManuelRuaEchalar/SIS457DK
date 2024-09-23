// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "PrimerLabGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PRIMERLAB_API APrimerLabGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	APrimerLabGameModeBase();
	virtual void BeginPlay() override;
	
};
