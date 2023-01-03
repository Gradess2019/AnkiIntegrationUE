// Copyright Gradess Games. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BlueprintJsonLibrary.h"
#include "UObject/Object.h"
#include "AnkiLibrary.generated.h"

/**
 * 
 */
UCLASS()
class ANKIINTEGRATION_API UAnkiLibrary : public UObject
{
	GENERATED_BODY()

public:
	FBlueprintJsonObject SendRequest(const FString& InAction, const int32 InVersion);
	
	// Card Actions
	// void GetEaseFactors();
	// void SetEaseFactors();
	// void SetSpecificValueOfCard();
	// void Suspend();
	// void Unsuspend();
	// void Suspended();
	// void AreSuspended();
	// void AreDue();
	// void GetIntervals();
	// void FindCards();
	// void CardsToNotes();
	// void CardsModTime();
	// void CardsInfo();
	// void ForgetCards();
	// void RelearnCards();
};
