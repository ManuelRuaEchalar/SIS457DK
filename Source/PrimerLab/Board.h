// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Cubo.h"
#include "Plataforma.h"
#include "BoarCamera.h"
#include "Board.generated.h"

UCLASS()
class PRIMERLAB_API ABoard : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABoard();

	ACubo* cubo;
	APlataforma* escenario;
	ABoarCamera* BoardCamera;
	bool bIsMovingRight;
	bool bIsMovingLeft;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void StartMovingRight();
	void StopMovingRight();
	void MoveRight();
};
