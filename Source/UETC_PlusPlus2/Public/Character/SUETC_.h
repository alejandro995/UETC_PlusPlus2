// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SUETC_.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class UETC_PLUSPLUS2_API ASUETC_ : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CPlusPlus")
	USpringArmComponent* SpringArmComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CPlusPlus")
	UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CPlusPlus")
	float SpringArmLength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CPlusPlus")
	float SpringArmAngle;

	FRotator SpringArmRotation;


	ASUETC_();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
