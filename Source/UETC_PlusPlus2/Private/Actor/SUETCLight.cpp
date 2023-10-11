// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/SUETCLight.h"
#include "Components/SphereComponent.h"
#include "Components/PointLightComponent.h"


// Sets default values
ASUETCLight::ASUETCLight()
{
	DesiredIntensity = 3000.0f;

	PointLight1 = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight1"));
	PointLight1->Intensity = DesiredIntensity;
	PointLight1->SetVisibility(true, false);
	RootComponent = PointLight1;

	Sphere1 = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere1"));
	Sphere1->InitSphereRadius(250.0f);
	Sphere1->SetupAttachment(RootComponent);

	Sphere1->OnComponentBeginOverlap.AddDynamic(this, &ASUETCLight::OnOverlapBegin); // set up a notification for when this component overlaps something
	Sphere1->OnComponentEndOverlap.AddDynamic(this, &ASUETCLight::OnOverlapEnd); // set up a notification for when this component overlaps something


 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ASUETCLight::OnOverlapBegin_Implementation(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		ToggleLight();
	}
}

void ASUETCLight::OnOverlapEnd_Implementation(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)

	{
		ToggleLight();
	}
}

void ASUETCLight::ToggleLight()
{
	PointLight1->ToggleVisibility();
	//Interaction();
}

void ASUETCLight::Interaction()
{
	UE_LOG(LogTemp, Warning, TEXT("Overlapped Switch, Light Event"))
}

// Called when the game starts or when spawned
void ASUETCLight::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASUETCLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

