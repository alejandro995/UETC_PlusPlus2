// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SUETCTorch.generated.h"

class UParticleSystemComponent;
class UStaticMeshComponent;

UCLASS()
class UETC_PLUSPLUS2_API ASUETCTorch : public AActor
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="UETC_Torch")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="UETC_Torch")
	UParticleSystemComponent* TorchEffectComp;

	FTimerHandle Combustible;

	// Sets default values for this actor's properties
	ASUETCTorch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void TurnOffTorch();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
