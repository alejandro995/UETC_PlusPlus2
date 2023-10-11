// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/SUETCPawn.h"
#include "UObject/ConstructorHelpers.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/SphereComponent.h"
#include "Camera/CameraComponent.h"
#include "Engine/Engine.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ASUETCPawn::ASUETCPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(40.0f);
	SphereComponent->SetCollisionProfileName(TEXT("Pawn"));

	UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));

	SphereVisual->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));

	USpringArmComponent* SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraAttachmentArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 3.0f;

	UCameraComponent* Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("ActualCamera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);


	AutoPossessPlayer = EAutoReceiveInput::Player0;
}


// Called when the game starts or when spawned
void ASUETCPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASUETCPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASUETCPawn::SetupPlayerInputComponent(class UInputComponent* InInputComponent)
{
	Super::SetupPlayerInputComponent(InInputComponent);

	InInputComponent->BindAxis("MoveForward", this, &ASUETCPawn::MoveForward);
	InInputComponent->BindAxis("MoveRight", this, &ASUETCPawn::MoveRight);
	InInputComponent->BindAxis("Turn", this, &ASUETCPawn::Turn);
}

UPawnMovementComponent* ASUETCPawn::GetMovementComponent() const
{
	return OurMovementComponent;
}

void ASUETCPawn::MoveForward(float AxisValue)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, FString::Printf(TEXT("%.2f"), AxisValue));
	if (OurMovementComponent && (OurMovementComponent->UpdatedComponent == RootComponent))
	{
		OurMovementComponent->AddInputVector(GetActorForwardVector() * AxisValue);
	}
}

void ASUETCPawn::MoveRight(float AxisValue)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("%.2f"), AxisValue));
	if (OurMovementComponent && (OurMovementComponent->UpdatedComponent == RootComponent))
	{
		OurMovementComponent->AddInputVector(GetActorRightVector() * AxisValue);
	}
}

void ASUETCPawn::Turn(float AxisValue)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString::Printf(TEXT("%.2f"), AxisValue));
	FRotator NewRotation = GetActorRotation();
	NewRotation.Yaw += AxisValue;
	SetActorRotation(NewRotation);
}

