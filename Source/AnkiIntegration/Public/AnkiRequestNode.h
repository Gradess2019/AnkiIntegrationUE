// Copyright Gradess Games. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BlueprintJsonLibrary.h"

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

	// GUI actions
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GuiBrowse(UObject* InWorldContextObject, const FString& InQuery);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GuiSelectedNotes(UObject* InWorldContextObject);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GuiAddCards(UObject* InWorldContextObject, const FBlueprintJsonObject& InNote);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GuiEditNote(UObject* InWorldContextObject, const int64 InNote);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GuiCurrentCard(UObject* InWorldContextObject);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GuiStartCardTimer(UObject* InWorldContextObject);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GuiShowQuestion(UObject* InWorldContextObject);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GuiShowAnswer(UObject* InWorldContextObject);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GuiAnswerCard(UObject* InWorldContextObject, const int32 InEase);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GuiDeckOverview(UObject* InWorldContextObject, const FString& InName);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GuiDeckBrowser(UObject* InWorldContextObject);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GuiDeckReview(UObject* InWorldContextObject, const FString& InName);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GuiExitAnki(UObject* InWorldContextObject);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GuiCheckDatabase(UObject* InWorldContextObject);

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

	// Miscellaneous actions
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* RequestPermission(UObject* InWorldContextObject);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* Version(UObject* InWorldContextObject);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* ApiReflect(UObject* InWorldContextObject, const TArray<FString>& InScopes, const TArray<FString>& InActions);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* Sync(UObject* InWorldContextObject);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GetProfiles(UObject* InWorldContextObject);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* LoadProfile(UObject* InWorldContextObject, const FString& InName);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* Multi(UObject* InWorldContextObject, const TArray<FBlueprintJsonObject>& InActions);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* ExportPackage(UObject* InWorldContextObject, const FString& InDeck, const FString& InPath, const bool InIncludeSched = false);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* ImportPackage(UObject* InWorldContextObject, const FString& InPath);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* ReloadCollection(UObject* InWorldContextObject);

	// Model actions
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* ModelNames(UObject* InWorldContextObject);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* ModelNamesAndIds(UObject* InWorldContextObject);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* ModelFieldNames(UObject* InWorldContextObject, const FString& InModelName);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* ModelFieldDescriptions(UObject* InWorldContextObject, const FString& InModelName);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* ModelFieldFonts(UObject* InWorldContextObject, const FString& InModelName);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* ModelFieldsOnTemplates(UObject* InWorldContextObject, const FString& InModelName);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* CreateModel(UObject* InWorldContextObject, const FString& InModelName, const TArray<FString>& InInOrderFields, const TArray<FBlueprintJsonObject>& InCardTemplates, const FString& InCss = "", const bool InIsCloze = false);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* ModelTemplates(UObject* InWorldContextObject, const FString& InModelName);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* ModelStyling(UObject* InWorldContextObject, const FString& InModelName);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* UpdateModelTemplates(UObject* InWorldContextObject, const FBlueprintJsonObject& InModel);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* UpdateModelStyling(UObject* InWorldContextObject, const FBlueprintJsonObject& InModel);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* FindAndReplaceInModels(UObject* InWorldContextObject, const FBlueprintJsonObject& InModel);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* ModelFieldRename(UObject* InWorldContextObject, const FString& InModelName, const FString& InOldFieldName, const FString& InNewFieldName);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* ModelFieldReposition(UObject* InWorldContextObject, const FString& InModelName, const FString& InFieldName, const int32 InIndex);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* ModelFieldAdd(UObject* InWorldContextObject, const FString& InModelName, const FString& InFieldName, const int32 InIndex);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* ModelFieldRemove(UObject* InWorldContextObject, const FString& InModelName, const FString& InFieldName);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* ModelFieldSetFont(UObject* InWorldContextObject, const FString& InModelName, const FString& InFieldName, const FString& InFont);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* ModelFieldSetFontSize(UObject* InWorldContextObject,  const FString& InModelName, const FString& InFieldName, const int32 InFontSize);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* ModelFieldSetDescription(UObject* InWorldContextObject, const FString& InModelName, const FString& InFieldName, const FString& InDescription);
	
	// Note actions
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* AddNote(UObject* InWorldContextObject, const FBlueprintJsonObject& InNote);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* AddNotes(UObject* InWorldContextObject, const TArray<FBlueprintJsonObject>& InNotes);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* CanAddNotes(UObject* InWorldContextObject, const TArray<FBlueprintJsonObject>& InNotes);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* UpdateNoteFields(UObject* InWorldContextObject, const FBlueprintJsonObject& InNote);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* AddTags(UObject* InWorldContextObject, const TArray<int64>& InNotes, const FString& InTags);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* RemoveTags(UObject* InWorldContextObject, const TArray<int64>& InNotes, const FString& InTags);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GetTags(UObject* InWorldContextObject);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* ClearUnusedTags(UObject* InWorldContextObject);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* ReplaceTags(UObject* InWorldContextObject, const TArray<int64>& InNotes, const FString& InTagToReplace, const FString& InReplaceWithTag);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* ReplaceTagsInAllNotes(UObject* InWorldContextObject, const FString& InTagToReplace, const FString& InReplaceWithTag);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* FindNotes(UObject* InWorldContextObject, const FString& InQuery);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* NotesInfo(UObject* InWorldContextObject, const TArray<int64>& InNotes);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* DeleteNotes(UObject* InWorldContextObject, const TArray<int64>& InNotes);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* RemoveEmptyNotes(UObject* InWorldContextObject);

	// Statistic actions
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GetNumCardsReviewedToday(UObject* InWorldContextObject);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GetNumCardsReviewedByDay(UObject* InWorldContextObject);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GetCollectionStatsHTML(UObject* InWorldContextObject, const bool InWholeCollection);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* CardReviews(UObject* InWorldContextObject, const FString& InDeck, const int64 InStartID);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GetReviewsOfCards(UObject* InWorldContextObject, const TArray<FString>& InCards);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* GetLatestReviewID(UObject* InWorldContextObject, const FString& InDeck);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"), Category = "AnkiRequest")
	static UAnkiRequestNode* InsertReviews(UObject* InWorldContextObject, const TArray<FBlueprintJsonObject>& InReviews);
	
	
protected:
	UPROPERTY(BlueprintReadOnly, Category = "AnkiRequest")
	FBlueprintJsonObject Body;

	TSharedPtr<IHttpRequest> Request;
};


