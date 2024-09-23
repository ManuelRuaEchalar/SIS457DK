// Fill out your copyright notice in the Description page of Project Settings.


#include "Cubo.h"

// Sets default values
ACubo::ACubo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Crear y configurar el Static Mesh Component
    CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));

    // Asignar el mesh a la raíz del Pawn
    RootComponent = CubeMesh;

    // Opcional: Configurar un mesh predeterminado para el cubo
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
    if (CubeMeshAsset.Succeeded())
    {
        CubeMesh->SetStaticMesh(CubeMeshAsset.Object);
    }

    // Configurar la colisión del cubo
    CubeMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    CubeMesh->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);
    CubeMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);



    // Habilitar la simulación de física para el cubo
    CubeMesh->SetSimulatePhysics(true);

    // Habilitar la gravedad
    CubeMesh->SetEnableGravity(true);

}

// Called when the game starts or when spawned
void ACubo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACubo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACubo::moveRight()
{
    FVector NewLocation = GetActorLocation();
    NewLocation.Y += 10;
    SetActorLocation(NewLocation);
}

void ACubo::moveLeft()
{
    FVector NewLocation = GetActorLocation();
    NewLocation.Y -= 10;
    SetActorLocation(NewLocation);
}

