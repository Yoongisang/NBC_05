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

	int32 RandomValue = FMath::RandRange(1, 100);
	int32 Probability = 50;
	float TotalDistance = 0.f;
	int32 EventCount = 0;

	if (IsValid(GEngine))
	{
		GEngine->AddOnScreenDebugMessage(-1, 50.0f, FColor::Black, 
			FString::Printf(TEXT("시작 위치 X = %0.f, Y = %0.f"), GetActorLocation().X, GetActorLocation().Y));
	}

	for (int i = 0; i < 10; i++)
	{
		if (RandomValue <= Probability)
		{
			FVector PrevLocation = GetActorLocation();
			RandMove();
			TotalDistance += FVector::Dist(PrevLocation, GetActorLocation());

			if (IsValid(GEngine))
			{
				GEngine->AddOnScreenDebugMessage(-1, 50.0f, FColor::Black, 
					FString::Printf(TEXT("%d 번째, 위치 X = %0.f, Y = %0.f"), i + 1, GetActorLocation().X, GetActorLocation().Y));
			}
		}
		else
		{
			RandRotate();
			if (IsValid(GEngine))
			{
				GEngine->AddOnScreenDebugMessage(-1, 50.0f, FColor::Black, 
					FString::Printf(TEXT("%d 번째, Yaw = %0.f°, Pitch = %0.f°"), i + 1, GetActorRotation().Yaw, GetActorRotation().Pitch));
			}
		}

		EventCount += TriggerEventWithProbability(50);
		RandomValue = FMath::RandRange(1, 100);
		
	}

	if (IsValid(GEngine))
	{
		GEngine->AddOnScreenDebugMessage(-1, 50.0f, FColor::Green, 
			FString::Printf(TEXT("총 이동거리: %0.f, 이벤트 발생: %d회"), TotalDistance, EventCount));
	}
	
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

int AMyActor::TriggerEventWithProbability(float Probability)
{
	int32 RandomValue = FMath::RandRange(1, 100);

	if (RandomValue <= Probability)
	{
		if (IsValid(GEngine))
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, 
				TEXT("Event Triggered!"));
		}
		return 1;
	}
	else
	{
		if (IsValid(GEngine))
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, 
				TEXT("Event Not Triggered"));
		}
		return 0;
	}
}

