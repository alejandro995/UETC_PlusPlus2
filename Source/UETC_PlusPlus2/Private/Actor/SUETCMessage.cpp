// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/SUETCMessage.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
ASUETCMessage::ASUETCMessage()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	RootComponent = StaticMeshComp;

	Sphere1 = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere1"));
	Sphere1->InitSphereRadius(250.0f);
	Sphere1->SetupAttachment(RootComponent);

}

void ASUETCMessage::Interaction()
{
	UE_LOG(LogTemp, Warning, TEXT("Overlapped Switch, Light Event"))
}

// Called when the game starts or when spawned
void ASUETCMessage::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASUETCMessage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

