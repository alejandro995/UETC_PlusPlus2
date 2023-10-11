// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/SUETCLigthInterface.h"
#include "Components/SpotLightComponent.h"
#include "Components/SphereComponent.h"


// Sets default values
ASUETCLigthInterface::ASUETCLigthInterface()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DesiredIntensity = 3000.0f;

	SpotLightComp = CreateDefaultSubobject<USpotLightComponent>(TEXT("PointLight1"));
	SpotLightComp->Intensity = DesiredIntensity;
	SpotLightComp->SetVisibility(true, false);
	RootComponent = SpotLightComp;

	Sphere1 = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere1"));
	Sphere1->InitSphereRadius(250.0f);
	Sphere1->SetupAttachment(RootComponent);

}


void ASUETCLigthInterface::Interaction()
{
	SpotLightComp->ToggleVisibility();
}

// Called when the game starts or when spawned
void ASUETCLigthInterface::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASUETCLigthInterface::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

