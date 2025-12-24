// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Engine/Engine.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Hello"));
	
	RandMove();
	RandRotate();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::RandMove()
{
	FVector RandomLocation;
	RandomLocation.X = FMath::RandRange(-100.f, 100.f);
	RandomLocation.Y = FMath::RandRange(-100.f, 100.f);

	SetActorLocation(GetActorLocation() + RandomLocation);
}


void AMyActor::RandRotate()
{
	FRotator RandomRotation;
	RandomRotation.Yaw = FMath::RandRange(0.f, 360.f);
	RandomRotation.Pitch = FMath::RandRange(0.f, 360.f);

	SetActorRotation(GetActorRotation() + RandomRotation);
}

