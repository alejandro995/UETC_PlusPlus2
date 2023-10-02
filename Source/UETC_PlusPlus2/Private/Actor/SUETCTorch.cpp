// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/SUETCTorch.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"

// Sets default values
ASUETCTorch::ASUETCTorch()
{

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComp");
	RootComponent = StaticMeshComp;

	TorchEffectComp = CreateDefaultSubobject<UParticleSystemComponent>("TorchEffectComp");
	TorchEffectComp->SetupAttachment(StaticMeshComp);

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASUETCTorch::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(Combustible, this, &ASUETCTorch::TurnOffTorch, 2.5f, true);
	
}

void ASUETCTorch::TurnOffTorch()
{
	TorchEffectComp->Deactivate();
}

// Called every frame
void ASUETCTorch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

