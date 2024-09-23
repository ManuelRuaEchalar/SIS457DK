// Fill out your copyright notice in the Description page of Project Settings.

#include "EngineUtils.h"
#include "Plataforma.h"

// Sets default values
APlataforma::APlataforma()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Crear y configurar el Static Mesh Component
	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));

	// Asignar el mesh a la raíz del Pawn
	RootComponent = PlatformMesh;

	// Configurar un mesh predeterminado para la plataforma
	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlatformMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Architecture/Wall_500x500.Wall_500x500'")); // Cambia esta ruta si es necesario
	if (PlatformMeshAsset.Succeeded())
	{
		PlatformMesh->SetStaticMesh(PlatformMeshAsset.Object);
	}

	// Configurar la colisión de la plataforma
	PlatformMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	PlatformMesh->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic); // Cambiado a ECC_WorldStatic para una plataforma
	PlatformMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);

	// Deshabilitar la simulación de física para la plataforma
	PlatformMesh->SetSimulatePhysics(false); // No queremos que la plataforma se mueva
	PlatformMesh->SetEnableGravity(false); // La plataforma no debe ser afectada por la gravedad

}

// Called when the game starts or when spawned
void APlataforma::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlataforma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

