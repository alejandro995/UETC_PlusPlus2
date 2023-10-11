// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SUETCVisibilityActor.generated.h"

UCLASS()
class UETC_PLUSPLUS2_API ASUETCVisibilityActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASUETCVisibilityActor();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VisibleComponent")
	class UStaticMeshComponent* StaticMeshComp;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Switch Components")
	class USphereComponent* Sphere1;

	UFUNCTION(BlueprintNativeEvent, Category = "Switch Functions")
void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class
UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

void OnOverlapBegin_Implementation(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class
UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

UFUNCTION(BlueprintNativeEvent, Category = "Switch Functions")
void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

void OnOverlapEnd_Implementation(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class
UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

UFUNCTION()
void ToggleVisibility();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
