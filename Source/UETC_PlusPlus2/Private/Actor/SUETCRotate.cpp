// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/SUETCRotate.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ASUETCRotate::ASUETCRotate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	RootComponent = StaticMeshComp;

	Sphere1 = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere1"));
	Sphere1->InitSphereRadius(250.0f);
	Sphere1->SetupAttachment(RootComponent);

}

void ASUETCRotate::Interaction()
{
	RotateCounter = 10000;
	GetWorldTimerManager().SetTimer(RotateTimeHandler, this, &ASUETCRotate::Rotate, 0.01f, true);
}

void ASUETCRotate::Rotate()
{
	--RotateCounter;
	double RotationPitch = StaticMeshComp->GetComponentRotation().Pitch;
	double RotationYaw = StaticMeshComp->GetComponentRotation().Yaw;
	double RotationRoll = StaticMeshComp->GetComponentRotation().Roll;
	FRotator NewRotation = FRotator(RotationPitch , RotationYaw + (20.0f * 0.01f), RotationRoll);

	StaticMeshComp->SetRelativeRotation(NewRotation);

	if (RotateCounter <= 1) {
		GetWorldTimerManager().ClearTimer(RotateTimeHandler);
	}
}

// Called when the game starts or when spawned
void ASUETCRotate::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASUETCRotate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

