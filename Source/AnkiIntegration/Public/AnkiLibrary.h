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

	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToJsonArray (int64)", CompactNodeTitle = "ToJsonArray", BlueprintAutocast), Category = "AnkiLibrary")
	static void Conv_Int64ArrayToJsonArray(const TArray<int64>& InArray, UPARAM(ref) TArray<FBlueprintJsonValue>& OutArray);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToJsonArray (String)", CompactNodeTitle = "ToJsonArray", BlueprintAutocast), Category = "AnkiLibrary")
	static void Conv_StringArrayToJsonArray(const TArray<FString>& InArray, UPARAM(ref) TArray<FBlueprintJsonValue>& OutArray);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToJsonValue (int64)", CompactNodeTitle = "ToJsonValue", BlueprintAutocast), Category = "AnkiLibrary")
	static FBlueprintJsonValue JsonMakeInt64(int64 IntValue);

	UFUNCTION(BlueprintPure, Category = "AnkiLibrary")
	static FBlueprintJsonObject MakeDefaultBodyObject(const FString& InAction);
	
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
