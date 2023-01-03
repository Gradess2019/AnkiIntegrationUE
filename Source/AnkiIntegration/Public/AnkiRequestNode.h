// Copyright Gradess Games. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AnkiRequestNode.generated.h"

class IHttpRequest;
struct FBlueprintJsonObject;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAnkiResponse, FBlueprintJsonObject, Response);

UCLASS()
class ANKIINTEGRATION_API UAnkiRequestNode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "AnkiRequest")
	FAnkiResponse OnResponse;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* AnkiRequest(UObject* WorldContextObject, const FBlueprintJsonObject& InBody);

	// Card actions
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GetEaseFactors(UObject* InWorldContextObject, const TArray<int64>& InCards);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* SetEaseFactors(UObject* InWorldContextObject, const TArray<int64>& InCards, const TArray<int64>& InEaseFactors);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* SetSpecificValueOfCard(UObject* InWorldContextObject, const int64 InCard, const TArray<FString>& InKeys, const TArray<FString>& InNewValues);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* Suspend(UObject* InWorldContextObject, const TArray<int64>& InCards);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* Unsuspend(UObject* InWorldContextObject, const TArray<int64>& InCards);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* Suspended(UObject* InWorldContextObject, const int64 InCard);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* AreSuspended(UObject* InWorldContextObject, const TArray<int64>& InCards);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* AreDue(UObject* InWorldContextObject, const TArray<int64>& InCards);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GetIntervals(UObject* InWorldContextObject, const TArray<int64>& InCards, const bool InComplete = false);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* FindCards(UObject* InWorldContextObject, const FString& InQuery);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* CardsToNotes(UObject* InWorldContextObject, const TArray<int64>& InCards);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* CardsModTime(UObject* InWorldContextObject, const TArray<int64>& InCards);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* CardsInfo(UObject* InWorldContextObject, const TArray<int64>& InCards);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* ForgetCards(UObject* InWorldContextObject, const TArray<int64>& InCards);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* RelearnCards(UObject* InWorldContextObject, const TArray<int64>& InCards);
	

	// Deck actions
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* DeckNames(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* DeckNamesAndIds(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GetDecks(UObject* WorldContextObject, const TArray<int64>& DeckIds);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* CreateDeck(UObject* WorldContextObject, const FString& DeckName);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* ChangeDeck(UObject* WorldContextObject, const TArray<int64>& InCards, const FString& InDeck);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* DeleteDecks(UObject* WorldContextObject, const TArray<FString>& InDecks, const bool InCardsToo);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GetDeckConfig(UObject* WorldContextObject, const FString& Deck);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* SaveDeckConfig(UObject* WorldContextObject, const FBlueprintJsonObject& Config);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* SetDeckConfigId(UObject* WorldContextObject, const TArray<FString>& InDecks, const int64 InConfigId);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* CloneDeckConfigId(UObject* WorldContextObject, const FString& InName, const int64 InCloneFrom);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* RemoveDeckConfigId(UObject* WorldContextObject, const int64 InConfigId);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GetDeckStats(UObject* WorldContextObject, const TArray<FString>& InDecks);
	
	virtual void Activate() override;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "AnkiRequest")
	FBlueprintJsonObject Body;

	TSharedPtr<IHttpRequest> Request;
};


