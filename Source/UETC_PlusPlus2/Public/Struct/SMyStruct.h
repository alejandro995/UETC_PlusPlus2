// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SMyStruct.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
 struct UETC_PLUSPLUS2_API FSMyStruct
{
public:
	GENERATED_BODY()

		UPROPERTY(BlueprintReadWrite)
		float Health;

	UPROPERTY(BlueprintReadWrite)
	FString Character_Name;
		FSMyStruct();
	~FSMyStruct();
};
