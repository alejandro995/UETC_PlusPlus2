// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SUETCSharedPointers.generated.h"

UCLASS()
class UETC_PLUSPLUS2_API ASUETCSharedPointers : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASUETCSharedPointers();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
