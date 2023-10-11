// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interface/SUETCInterface.h"
#include "SUETCLight.generated.h"

UCLASS()
class UETC_PLUSPLUS2_API ASUETCLight : public AActor, public ISUETCInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASUETCLight();

	/** point light component */
UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Switch Components")
class UPointLightComponent* PointLight1;
/** sphere component */
UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Switch Components")
class USphereComponent* Sphere1;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Switch Variables")
float DesiredIntensity;

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
void ToggleLight();

void Interaction() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
