// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Struct/MagicDoorStruct.h"
#include "Interface/SUETCInterface.h"
#include "SUETCMagicDoor.generated.h"

UCLASS()
class UETC_PLUSPLUS2_API ASUETCMagicDoor : public AActor, public ISUETCInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASUETCMagicDoor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Struct Components")
	class UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Struct Components")
	class USphereComponent* Sphere1;

	UFUNCTION(BlueprintCallable)
	void Interaction() override;

	FMagicDoorStruct DoorStruct;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
