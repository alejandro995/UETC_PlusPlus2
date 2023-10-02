// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/SUETCMovingActor.h"
#include "Components/ShapeComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ASUETCMovingActor::ASUETCMovingActor()
{
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComp");
	RootComponent = StaticMeshComp;

	ShapeComp = CreateDefaultSubobject<UShapeComponent>("ShapeComp");

	

	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASUETCMovingActor::BeginPlay()
{
	CurrentLocation = StaticMeshComp->GetRelativeTransform().GetLocation();

	Super::BeginPlay();
	
}

void ASUETCMovingActor::MoveAndRotate()
{
	FVector NewMeshLocation = CurrentLocation;


		NewMeshLocation.Z += 1000;

		StaticMeshComp->SetRelativeLocation(NewMeshLocation);
	
}

// Called every frame
void ASUETCMovingActor::Tick(float DeltaTime)
{
	
	Super::Tick(DeltaTime);

	MoveAndRotate();

}

