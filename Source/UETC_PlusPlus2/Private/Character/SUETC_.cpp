// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/SUETC_.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ASUETC_::ASUETC_()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(RootComponent);

	SpringArmComp->SetRelativeRotation(SpringArmRotation);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);

}

// Called when the game starts or when spawned
void ASUETC_::BeginPlay()
{
	SpringArmLength = SpringArmLength ? SpringArmLength : 400.0;
	SpringArmAngle = SpringArmAngle ? SpringArmAngle : -30.0;

	SpringArmRotation = SpringArmComp->GetRelativeRotation();
	SpringArmRotation.Pitch = SpringArmAngle;
	SpringArmComp->TargetArmLength = SpringArmLength;
	SpringArmComp->SetRelativeRotation(SpringArmRotation);

	Super::BeginPlay();
}

// Called every frame
void ASUETC_::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASUETC_::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

