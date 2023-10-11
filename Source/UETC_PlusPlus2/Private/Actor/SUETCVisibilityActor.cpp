// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/SUETCVisibilityActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ASUETCVisibilityActor::ASUETCVisibilityActor()
{

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComp");
	StaticMeshComp->SetVisibility(true);
	StaticMeshComp->Activate(true);
	RootComponent = StaticMeshComp;

	Sphere1 = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere1"));
	Sphere1->InitSphereRadius(250.0f);
	Sphere1->SetupAttachment(RootComponent);

	Sphere1->OnComponentBeginOverlap.AddDynamic(this, &ASUETCVisibilityActor::OnOverlapBegin); // set up a notification for when this component overlaps something
	Sphere1->OnComponentEndOverlap.AddDynamic(this, &ASUETCVisibilityActor::OnOverlapEnd); // set up a notification for when this component overlaps something
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ASUETCVisibilityActor::OnOverlapBegin_Implementation(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		FName CollitionProfileName = FName("NoCollision");
		StaticMeshComp->SetCollisionProfileName(CollitionProfileName);
		ToggleVisibility();
	}
}

void ASUETCVisibilityActor::OnOverlapEnd_Implementation(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		FName CollitionProfileName = FName("BlockAllDynamic");
		StaticMeshComp->SetCollisionProfileName(CollitionProfileName);
		ToggleVisibility();
	}
}

void ASUETCVisibilityActor::ToggleVisibility()
{
	StaticMeshComp->ToggleVisibility();
	StaticMeshComp->ToggleActive();
}

// Called when the game starts or when spawned
void ASUETCVisibilityActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASUETCVisibilityActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

