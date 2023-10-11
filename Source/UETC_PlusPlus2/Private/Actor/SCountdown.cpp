// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/SCountdown.h"
#include "Components/TextRenderComponent.h"

// Sets default values
ASCountdown::ASCountdown()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CountdownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("CountdownNumber"));
	CountdownText->SetHorizontalAlignment(EHTA_Center);
	CountdownText->SetWorldSize(150.0f);
	RootComponent = CountdownText;

	CountdownTime = 3;

}

void ASCountdown::UpdateTimerDisplay()
{
	CountdownText->SetText(FText::FromString(FString::FromInt(FMath::Max(CountdownTime, 0))));
}

void ASCountdown::AdvanceTimer()
{
	--CountdownTime;
	UpdateTimerDisplay();
	if (CountdownTime < 1)
	{
		//We're done counting down, so stop running the timer.
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		CountdownHasFinished();
	}
}

void ASCountdown::CountdownHasFinished()
{
	//Change to a special readout
	FString MyString = TEXT("GO!");
	FText MyText = FText::FromString(MyString);
	CountdownText->SetText(MyText);
}

// Called when the game starts or when spawned
void ASCountdown::BeginPlay()
{
	UpdateTimerDisplay();
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ASCountdown::AdvanceTimer, 1.0f, true);
	
}

// Called every frame
void ASCountdown::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

