// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interface/SUETCInterface.h"
#include "SUETCRotate.generated.h"

UCLASS()
class UETC_PLUSPLUS2_API ASUETCRotate : public AActor, public ISUETCInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASUETCRotate();

	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interfaz Components")
	class UStaticMeshComponent* StaticMeshComp;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interfaz Components")
	class USphereComponent* Sphere1;

	void Interaction() override;

	FTimerHandle RotateTimeHandler;

	void Rotate();

	float RotateCounter;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
