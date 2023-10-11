// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interface/SUETCInterface.h"
#include "SUETCLigthInterface.generated.h"

UCLASS()
class UETC_PLUSPLUS2_API ASUETCLigthInterface : public AActor, public ISUETCInterface
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Switch Components")
class USpotLightComponent* SpotLightComp;
/** sphere component */
UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Switch Components")
class USphereComponent* Sphere1;

void Interaction() override;

float DesiredIntensity;
	// Sets default values for this actor's properties
	ASUETCLigthInterface();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
