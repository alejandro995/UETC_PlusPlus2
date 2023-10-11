// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SUETCMovingPlatform.generated.h"

UCLASS()
class UETC_PLUSPLUS2_API ASUETCMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASUETCMovingPlatform();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Moving Platform ")
	class UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Moving Platform ")
	class USphereComponent* Sphere1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category ="Moving Targets")
	FVector WorldTargetLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category ="Moving Targets")
	FVector WorldOriginLocation;

	FTimerHandle MoveToTargetTimer;
	FTimerHandle MoveToOriginTimer;


		UFUNCTION(BlueprintNativeEvent, Category = "Moving Functions")
void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class
UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

void OnOverlapBegin_Implementation(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class
UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

UFUNCTION(BlueprintNativeEvent, Category = "Moving Functions")
void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

void OnOverlapEnd_Implementation(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class
UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

UFUNCTION()
void MovePlatformToTarget();

UFUNCTION()
void MovePlatformToOrigin();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
