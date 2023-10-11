// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Struct/SMyStruct.h"

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/SUETCInterface.h"

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

	UFUNCTION(BlueprintNativeEvent, Category = "Switch Functions")
    void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void OnOverlapBegin_Implementation(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	FSMyStruct Struct;

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
