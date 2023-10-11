// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/SUETCMagicDoor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
ASUETCMagicDoor::ASUETCMagicDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	RootComponent = StaticMeshComp;

	Sphere1 = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere1"));
	Sphere1->InitSphereRadius(250.0f);
	Sphere1->SetupAttachment(RootComponent);

	DoorStruct.DoorOpened = false;
	DoorStruct.Destination = "C+ +Multiverse";

}

void ASUETCMagicDoor::Interaction()
{
	DoorStruct.DoorOpened = true;
	UE_LOG(LogTemp, Warning, TEXT("Portal opened : %b"), DoorStruct.DoorOpened);
	UE_LOG(LogTemp, Warning, TEXT("Portal Destination: %s"), *DoorStruct.Destination);

}

// Called when the game starts or when spawned
void ASUETCMagicDoor::BeginPlay()
{

	Super::BeginPlay();
	
}

// Called every frame
void ASUETCMagicDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

