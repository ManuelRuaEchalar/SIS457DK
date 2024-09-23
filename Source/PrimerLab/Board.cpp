// Fill out your copyright notice in the Description page of Project Settings.
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"
#include "Board.h"

// Sets default values
ABoard::ABoard()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void ABoard::BeginPlay()
{
	Super::BeginPlay();

	bIsMovingRight = false;
    bIsMovingLeft = false;

	FVector Location = FVector(-3000.0f, 0.0f, 400.0f);
	FRotator Rotation = FRotator(0.0f, 0.0f, 0.0f);
	BoardCamera = GetWorld()->SpawnActor<ABoarCamera>(ABoarCamera::StaticClass(), Location, Rotation);

	for (TActorIterator<ACameraActor> it(GetWorld()); it; ++it)
	{
		if (it->GetFName() == TEXT("BoarCamera_0"))
		{
			APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
			if (PC)
			{
				PC->SetViewTargetWithBlend(*it, 0.5f);
			}
			break;
		}
	}

	FVector LocationEscenario = FVector(100.0f, 0.0f, 100.0f);
	FRotator RotationEscenario = FRotator(0.0f, 0.0f, 90.0f);

	escenario = GetWorld()->SpawnActor<APlataforma>(LocationEscenario, RotationEscenario);

	if (escenario)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Escenario creado"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Error al generar el escenario"));
	}

	Location = FVector(100.0f, 0.0f, 700.0f);
	Rotation = FRotator(90.0f, 0.0f, 0.0f);

	cubo = GetWorld()->SpawnActor<ACubo>(Location, Rotation);

	if (cubo)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hola Mundo desde BeginPlay!"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Error al generar el cubo"));
	}

	
}

// Called every frame
void ABoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsMovingRight)
	{
		if (cubo)
		{
			cubo->moveRight();
			BoardCamera->moveRight();
		}
	}

}

// Called to bind functionality to input
void ABoard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("MoveRight", IE_Pressed, this, &ABoard::StartMovingRight);
	PlayerInputComponent->BindAction("MoveRight", IE_Released, this, &ABoard::StopMovingRight);

}



void ABoard::StartMovingRight()
{
	bIsMovingRight = true;
}

void ABoard::StopMovingRight()
{
	bIsMovingRight = false;
}

void ABoard::MoveRight()
{
	if (cubo)
	{
		cubo->moveRight();
	}
}

