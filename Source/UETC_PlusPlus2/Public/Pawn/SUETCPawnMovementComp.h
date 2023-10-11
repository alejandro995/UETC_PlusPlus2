// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "SUETCPawnMovementComp.generated.h"

/**
 * 
 */
UCLASS()
class UETC_PLUSPLUS2_API USUETCPawnMovementComp : public UPawnMovementComponent
{
	GENERATED_BODY()

public:


		virtual void TickComponent(float DeltaTime, enum ELevelTick TickType,
			FActorComponentTickFunction* ThisTickFunction) override;

	
};
