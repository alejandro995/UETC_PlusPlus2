// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/SUETCMovingPlatform.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
ASUETCMovingPlatform::ASUETCMovingPlatform()
{

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComp");
	RootComponent = StaticMeshComp;

	Sphere1 = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere1"));
	Sphere1->InitSphereRadius(350.0f);
	Sphere1->SetupAttachment(RootComponent);

	Sphere1->OnComponentBeginOverlap.AddDynamic(this, &ASUETCMovingPlatform::OnOverlapBegin); // set up a notification for when this component overlaps something
	Sphere1->OnComponentEndOverlap.AddDynamic(this, &ASUETCMovingPlatform::OnOverlapEnd); // set up a notification for when this component overlaps something

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ASUETCMovingPlatform::OnOverlapBegin_Implementation(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		MovePlatformToTarget();
		GetWorldTimerManager().SetTimer(MoveToTargetTimer, this, &ASUETCMovingPlatform::MovePlatformToTarget, 0.001f, true);
	}
}

void ASUETCMovingPlatform::OnOverlapEnd_Implementation(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		//MovePlatformToOrigin();
	}
}

void ASUETCMovingPlatform::MovePlatformToTarget()
{



	float unitToMovePerTick = 100.0f;
	float speedOfTick = 0.001f; //Mas Bajo mas rapido

	FVector Direction = (WorldOriginLocation - WorldTargetLocation).GetSafeNormal();
	float Distance = (WorldTargetLocation - StaticMeshComp->GetRelativeLocation()).Size();

	if (Distance < 10.0f && Distance >= 0.1f) {
		GetWorldTimerManager().ClearTimer(MoveToTargetTimer);
	}
	

	FVector NewLocation = FVector(Direction.X != 0 ? StaticMeshComp->GetComponentLocation().X + (unitToMovePerTick * speedOfTick) : StaticMeshComp->GetComponentLocation().Z,
		Direction.Y != 0 ? StaticMeshComp->GetComponentLocation().Y + (unitToMovePerTick * speedOfTick) : StaticMeshComp->GetComponentLocation().Y,
		Direction.Z != 0 ? StaticMeshComp->GetComponentLocation().Z + (unitToMovePerTick * speedOfTick) : StaticMeshComp->GetComponentLocation().Z);

	StaticMeshComp->SetRelativeLocation(NewLocation);


}

void ASUETCMovingPlatform::MovePlatformToOrigin()
{
	
}

// Called when the game starts or when spawned
void ASUETCMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASUETCMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

