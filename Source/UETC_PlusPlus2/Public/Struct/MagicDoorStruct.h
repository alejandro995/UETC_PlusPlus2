// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MagicDoorStruct.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct UETC_PLUSPLUS2_API FMagicDoorStruct
{
public:
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	class USoundCue* DoorSound;

	UPROPERTY(BlueprintReadWrite)
	class UParticleSystem* DoorEffect;

	UPROPERTY(BlueprintReadWrite)
	bool DoorOpened;

	UPROPERTY(BlueprintReadWrite)
	FString Destination;

	FMagicDoorStruct();
	~FMagicDoorStruct();
};
