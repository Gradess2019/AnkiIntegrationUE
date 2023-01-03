// Copyright Gradess Games. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BlueprintJsonLibrary.h"
#include "UObject/Object.h"
#include "AnkiLibrary.generated.h"

UCLASS()
class ANKIINTEGRATION_API UAnkiLibrary : public UObject
{
	GENERATED_BODY()

public:
	static bool SendRequest(const FBlueprintJsonObject& InBody, const TFunction<void(const FBlueprintJsonObject& InResponse)>& InCallback);
	
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
