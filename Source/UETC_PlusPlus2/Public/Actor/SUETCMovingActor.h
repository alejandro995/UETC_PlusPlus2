// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SUETCMovingActor.generated.h"

class UStaticMeshComponent;

UCLASS()
class UETC_PLUSPLUS2_API ASUETCMovingActor : public AActor
{
	GENERATED_BODY()
	
public:

	UStaticMeshComponent* StaticMeshComp;

	int CountDownTime;
	int EventCountdownTime;

	FVector OriginalLocation;
	FRotator OriginalRotation;

	FTimerHandle CountDownTimeHandler;
	FTimerHandle EventCountdownTimeHandler;

	void UpdateRotationAndLocation();

	void AdvanceTimers();

	void AdvanceEventTimer();

	void EventCountdownTimeHasFinished();

	void CountDownHasFinished();
	

	// Sets default values for this actor's properties
	ASUETCMovingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
