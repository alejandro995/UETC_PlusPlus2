// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/SUETCMovingActor.h"
#include "Components/ShapeComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"



// Sets default values
ASUETCMovingActor::ASUETCMovingActor()
{
	PrimaryActorTick.bCanEverTick = false;
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComp");
	RootComponent = StaticMeshComp;

	OriginalLocation = StaticMeshComp->GetComponentLocation();
	OriginalRotation = StaticMeshComp->GetComponentRotation();

	CountDownTime = 3;
	EventCountdownTime = 3;
}

// Called when the game starts or when spawned


void ASUETCMovingActor::UpdateRotationAndLocation()
{
	double LocationX = StaticMeshComp->GetComponentLocation().X;
	double LocationY = StaticMeshComp->GetComponentLocation().Y;
	double LocationZ = StaticMeshComp->GetComponentLocation().Z;
	FVector NewLocation = FVector(LocationX, LocationY, LocationZ + (20.0f * 0.01f));

	StaticMeshComp->SetRelativeLocation(NewLocation);

	double RotationPitch = StaticMeshComp->GetComponentRotation().Pitch;
	double RotationYaw = StaticMeshComp->GetComponentRotation().Yaw;
	double RotationRoll = StaticMeshComp->GetComponentRotation().Roll;

	FRotator NewRotation = FRotator(RotationPitch + (20.0f* 0.01f), RotationYaw + (20.0f * 0.01f),  RotationRoll);

	StaticMeshComp->SetRelativeRotation(NewRotation);

}

void ASUETCMovingActor::AdvanceTimers()
{
	--CountDownTime;
	UpdateRotationAndLocation();
	if (CountDownTime < 1) {
		GetWorldTimerManager().ClearTimer(CountDownTimeHandler);
		CountDownHasFinished();
	}

}

void ASUETCMovingActor::AdvanceEventTimer()
{
	--EventCountdownTime;
	if (EventCountdownTime < 1) {
		GetWorldTimerManager().ClearTimer(EventCountdownTimeHandler);
		EventCountdownTimeHasFinished();
	}
}

void ASUETCMovingActor::EventCountdownTimeHasFinished()
{
	UpdateRotationAndLocation();
	GetWorldTimerManager().SetTimer(CountDownTimeHandler, this, &ASUETCMovingActor::UpdateRotationAndLocation, 0.01f, true);
}

void ASUETCMovingActor::CountDownHasFinished()
{
	StaticMeshComp->SetWorldLocation(OriginalLocation);
	StaticMeshComp->SetWorldRotation(OriginalRotation);
}

void ASUETCMovingActor::BeginPlay()
{
	GetWorldTimerManager().SetTimer(EventCountdownTimeHandler, this, &ASUETCMovingActor::AdvanceEventTimer, 1.0f, true);
}

// Called every frame
void ASUETCMovingActor::Tick(float DeltaTime)
{
	
	Super::Tick(DeltaTime);
}

