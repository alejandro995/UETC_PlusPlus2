// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SUETCMovingActor.generated.h"

class UStaticMeshComponent;
class UShapeComponent;

UCLASS()
class UETC_PLUSPLUS2_API ASUETCMovingActor : public AActor
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UETC_MovingActor")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UETC_MovingActor")
	UShapeComponent* ShapeComp;

	FTimerHandle TimeHandle_MoveAndRotate;
	

	// Sets default values for this actor's properties
	ASUETCMovingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FVector CurrentLocation;

	UFUNCTION()
	void MoveAndRotate();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
