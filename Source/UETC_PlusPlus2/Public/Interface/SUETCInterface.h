// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SUETCInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USUETCInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UETC_PLUSPLUS2_API ISUETCInterface
{
	GENERATED_BODY()

public:
	virtual void Interaction() {};
};
