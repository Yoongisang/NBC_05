// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class NBC_05_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void RandMove();
	UFUNCTION()
	void RandRotate();
	UFUNCTION()
	int TriggerEventWithProbability(float Probability);
private:
	UPROPERTY()
	// 엑터의 회전
	FRotator ActorRotation;
	UPROPERTY()
	// 엑터의 위치
	FVector ActorLocation;

};
