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

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* AnkiRequest(UObject* InWorldContextObject, const FBlueprintJsonObject& InBody);

	virtual void Activate() override;

	// Card actions
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GetEaseFactors(UObject* InWorldContextObject, const TArray<int64>& InCards);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* SetEaseFactors(UObject* InWorldContextObject, const TArray<int64>& InCards, const TArray<int64>& InEaseFactors);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* SetSpecificValueOfCard(UObject* InWorldContextObject, const int64 InCard, const TArray<FString>& InKeys, const TArray<FString>& InNewValues);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* Suspend(UObject* InWorldContextObject, const TArray<int64>& InCards);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* Unsuspend(UObject* InWorldContextObject, const TArray<int64>& InCards);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* Suspended(UObject* InWorldContextObject, const int64 InCard);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* AreSuspended(UObject* InWorldContextObject, const TArray<int64>& InCards);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* AreDue(UObject* InWorldContextObject, const TArray<int64>& InCards);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GetIntervals(UObject* InWorldContextObject, const TArray<int64>& InCards, const bool InComplete = false);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* FindCards(UObject* InWorldContextObject, const FString& InQuery);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* CardsToNotes(UObject* InWorldContextObject, const TArray<int64>& InCards);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* CardsModTime(UObject* InWorldContextObject, const TArray<int64>& InCards);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* CardsInfo(UObject* InWorldContextObject, const TArray<int64>& InCards);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* ForgetCards(UObject* InWorldContextObject, const TArray<int64>& InCards);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* RelearnCards(UObject* InWorldContextObject, const TArray<int64>& InCards);
	

	// Deck actions
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* DeckNames(UObject* InWorldContextObject);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* DeckNamesAndIds(UObject* InWorldContextObject);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GetDecks(UObject* InWorldContextObject, const TArray<int64>& DeckIds);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* CreateDeck(UObject* InWorldContextObject, const FString& DeckName);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* ChangeDeck(UObject* InWorldContextObject, const TArray<int64>& InCards, const FString& InDeck);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* DeleteDecks(UObject* InWorldContextObject, const TArray<FString>& InDecks, const bool InCardsToo);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GetDeckConfig(UObject* InWorldContextObject, const FString& Deck);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* SaveDeckConfig(UObject* InWorldContextObject, const FBlueprintJsonObject& Config);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* SetDeckConfigId(UObject* InWorldContextObject, const TArray<FString>& InDecks, const int64 InConfigId);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* CloneDeckConfigId(UObject* InWorldContextObject, const FString& InName, const int64 InCloneFrom);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* RemoveDeckConfigId(UObject* InWorldContextObject, const int64 InConfigId);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GetDeckStats(UObject* InWorldContextObject, const TArray<FString>& InDecks);

	// Media actions
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* StoreMediaFile(UObject* InWorldContextObject, const FString& InFilename, const FString& InData);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* StoreMediaFileByPath(UObject* InWorldContextObject, const FString& InFilename, const FString& InPath);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* StoreMediaFileByUrl(UObject* InWorldContextObject, const FString& InFilename, const FString& InPath);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* RetrieveMediaFile(UObject* InWorldContextObject, const FString& InFilename);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GetMediaFilesNames(UObject* InWorldContextObject, const FString& InPattern);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* DeleteMediaFile(UObject* InWorldContextObject, const FString& InFilename);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "AnkiRequest")
	FBlueprintJsonObject Body;

	TSharedPtr<IHttpRequest> Request;
};


