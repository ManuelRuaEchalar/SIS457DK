// Fill out your copyright notice in the Description page of Project Settings.


#include "BoarCamera.h"


// Called when the game starts or when spawned
void ABoarCamera::BeginPlay()
{
    Super::BeginPlay();

}

void ABoarCamera::moveRight()
{
    FVector NewLocation = GetActorLocation();
    NewLocation.Y += 10;
    SetActorLocation(NewLocation);
}

void ABoarCamera::moveLeft()
{
    FVector NewLocation = GetActorLocation();
    NewLocation.Y -= 10;
    SetActorLocation(NewLocation);
}