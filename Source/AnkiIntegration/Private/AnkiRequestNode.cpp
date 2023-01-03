// Copyright Gradess Games. All Rights Reserved.

#include "AnkiRequestNode.h"
#include "AnkiLibrary.h"
#include "BlueprintJsonLibrary.h"
#include "HttpModule.h"

UAnkiRequestNode* UAnkiRequestNode::AnkiRequest(UObject* WorldContextObject, const FBlueprintJsonObject& InBody)
{
	auto RequestNode = NewObject<UAnkiRequestNode>();
	RequestNode->Body = InBody;
	return RequestNode;
}

void UAnkiRequestNode::Activate()
{
	Super::Activate();

	UAnkiLibrary::SendRequest(Body, [&](const FBlueprintJsonObject& InResponse) { OnResponse.Broadcast(InResponse); });
}

UAnkiRequestNode* UAnkiRequestNode::GetEaseFactors(UObject* InWorldContextObject, const TArray<int64>& InCards)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("getEaseFactors"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	TArray<FBlueprintJsonValue> CardValues;
	UAnkiLibrary::Conv_Int64ArrayToJsonArray(InCards, CardValues);
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("cards"), UBlueprintJsonLibrary::JsonMakeArray(CardValues));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::SetEaseFactors(UObject* InWorldContextObject, const TArray<int64>& InCards, const TArray<int64>& InEaseFactors)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("setEaseFactors"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	TArray<FBlueprintJsonValue> CardValues;
	TArray<FBlueprintJsonValue> EaseFactorValues;
	UAnkiLibrary::Conv_Int64ArrayToJsonArray(InCards, CardValues);
	UAnkiLibrary::Conv_Int64ArrayToJsonArray(InEaseFactors, EaseFactorValues);
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("cards"), UBlueprintJsonLibrary::JsonMakeArray(CardValues));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("easeFactors"), UBlueprintJsonLibrary::JsonMakeArray(EaseFactorValues));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::SetSpecificValueOfCard(UObject* InWorldContextObject, const int64 InCard, const TArray<FString>& InKeys, const TArray<FString>& InNewValues)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("setSpecificValueOfCard"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	TArray<FBlueprintJsonValue> KeyValues;
	TArray<FBlueprintJsonValue> NewValues;
	UAnkiLibrary::Conv_StringArrayToJsonArray(InKeys, KeyValues);
	UAnkiLibrary::Conv_StringArrayToJsonArray(InKeys, NewValues);
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("card"), UAnkiLibrary::JsonMakeInt64(InCard));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("keys"), UBlueprintJsonLibrary::JsonMakeArray(KeyValues));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("newValues"), UBlueprintJsonLibrary::JsonMakeArray(NewValues));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::Suspend(UObject* InWorldContextObject, const TArray<int64>& InCards)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("suspend"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	TArray<FBlueprintJsonValue> CardValues;
	UAnkiLibrary::Conv_Int64ArrayToJsonArray(InCards, CardValues);
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("cards"), UBlueprintJsonLibrary::JsonMakeArray(CardValues));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::Unsuspend(UObject* InWorldContextObject, const TArray<int64>& InCards)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("unsuspend"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	TArray<FBlueprintJsonValue> CardValues;
	UAnkiLibrary::Conv_Int64ArrayToJsonArray(InCards, CardValues);
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("cards"), UBlueprintJsonLibrary::JsonMakeArray(CardValues));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::Suspended(UObject* InWorldContextObject, const int64 InCard)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("suspended"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("card"), UAnkiLibrary::JsonMakeInt64(InCard));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::AreSuspended(UObject* InWorldContextObject, const TArray<int64>& InCards)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("areSuspended"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	TArray<FBlueprintJsonValue> CardValues;
	UAnkiLibrary::Conv_Int64ArrayToJsonArray(InCards, CardValues);
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("cards"), UBlueprintJsonLibrary::JsonMakeArray(CardValues));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::AreDue(UObject* InWorldContextObject, const TArray<int64>& InCards)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("areDue"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	TArray<FBlueprintJsonValue> CardValues;
	UAnkiLibrary::Conv_Int64ArrayToJsonArray(InCards, CardValues);
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("cards"), UBlueprintJsonLibrary::JsonMakeArray(CardValues));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::GetIntervals(UObject* InWorldContextObject, const TArray<int64>& InCards, const bool InComplete)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("getIntervals"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	TArray<FBlueprintJsonValue> CardValues;
	UAnkiLibrary::Conv_Int64ArrayToJsonArray(InCards, CardValues);
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("cards"), UBlueprintJsonLibrary::JsonMakeArray(CardValues));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("complete"), UBlueprintJsonLibrary::JsonMakeBool(InComplete));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::FindCards(UObject* InWorldContextObject, const FString& InQuery)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("findCards"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("query"), UBlueprintJsonLibrary::JsonMakeString(InQuery));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::CardsToNotes(UObject* InWorldContextObject, const TArray<int64>& InCards)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("cardsToNotes"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	TArray<FBlueprintJsonValue> CardValues;
	UAnkiLibrary::Conv_Int64ArrayToJsonArray(InCards, CardValues);
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("cards"), UBlueprintJsonLibrary::JsonMakeArray(CardValues));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::CardsModTime(UObject* InWorldContextObject, const TArray<int64>& InCards)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("cardsModTime"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	TArray<FBlueprintJsonValue> CardValues;
	UAnkiLibrary::Conv_Int64ArrayToJsonArray(InCards, CardValues);
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("cards"), UBlueprintJsonLibrary::JsonMakeArray(CardValues));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::CardsInfo(UObject* InWorldContextObject, const TArray<int64>& InCards)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("cardsInfo"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	TArray<FBlueprintJsonValue> CardValues;
	UAnkiLibrary::Conv_Int64ArrayToJsonArray(InCards, CardValues);
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("cards"), UBlueprintJsonLibrary::JsonMakeArray(CardValues));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::ForgetCards(UObject* InWorldContextObject, const TArray<int64>& InCards)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("forgetCards"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	TArray<FBlueprintJsonValue> CardValues;
	UAnkiLibrary::Conv_Int64ArrayToJsonArray(InCards, CardValues);
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("cards"), UBlueprintJsonLibrary::JsonMakeArray(CardValues));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::RelearnCards(UObject* InWorldContextObject, const TArray<int64>& InCards)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("relearnCards"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	TArray<FBlueprintJsonValue> CardValues;
	UAnkiLibrary::Conv_Int64ArrayToJsonArray(InCards, CardValues);
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("cards"), UBlueprintJsonLibrary::JsonMakeArray(CardValues));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::DeckNames(UObject* WorldContextObject)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("deckNames"));

	return AnkiRequest(WorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::DeckNamesAndIds(UObject* WorldContextObject)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("deckNamesAndIds"));

	return AnkiRequest(WorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::GetDecks(UObject* WorldContextObject, const TArray<int64>& DeckIds)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("getDecks"));

	const FBlueprintJsonObject Params = UBlueprintJsonLibrary::JsonMake();
	TArray<FBlueprintJsonValue> Values;
	UAnkiLibrary::Conv_Int64ArrayToJsonArray(DeckIds, Values);
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("cards"), UBlueprintJsonLibrary::JsonMakeArray(Values));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(WorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::CreateDeck(UObject* WorldContextObject, const FString& DeckName)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("createDeck"));

	const FBlueprintJsonObject Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("deck"), UBlueprintJsonLibrary::JsonMakeString(DeckName));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(WorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::ChangeDeck(UObject* WorldContextObject, const TArray<int64>& InCards, const FString& InDeck)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("changeDeck"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	TArray<FBlueprintJsonValue> CardValues;
	UAnkiLibrary::Conv_Int64ArrayToJsonArray(InCards, CardValues);
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("cards"), UBlueprintJsonLibrary::JsonMakeArray(CardValues));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("deck"), UBlueprintJsonLibrary::JsonMakeString(InDeck));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(WorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::DeleteDecks(UObject* WorldContextObject, const TArray<FString>& InDecks, const bool InCardsToo)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("deleteDecks"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	TArray<FBlueprintJsonValue> DeckValues;
	UAnkiLibrary::Conv_StringArrayToJsonArray(InDecks, DeckValues);
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("decks"), UBlueprintJsonLibrary::JsonMakeArray(DeckValues));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("cardsToo"), UBlueprintJsonLibrary::JsonMakeBool(InCardsToo));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(WorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::GetDeckConfig(UObject* WorldContextObject, const FString& Deck)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("getDeckConfig"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("deck"), UBlueprintJsonLibrary::JsonMakeString(Deck));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(WorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::SaveDeckConfig(UObject* WorldContextObject, const FBlueprintJsonObject& Config)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("saveDeckConfig"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("config"), UBlueprintJsonLibrary::JsonMakeObject(Config));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(WorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::SetDeckConfigId(UObject* WorldContextObject, const TArray<FString>& InDecks, const int64 InConfigId)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("setDeckConfigId"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	TArray<FBlueprintJsonValue> DeckValues;
	UAnkiLibrary::Conv_StringArrayToJsonArray(InDecks, DeckValues);
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("decks"), UBlueprintJsonLibrary::JsonMakeArray(DeckValues));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("configId"), UAnkiLibrary::JsonMakeInt64(InConfigId));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(WorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::CloneDeckConfigId(UObject* WorldContextObject, const FString& InName, const int64 InCloneFrom)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("cloneDeckConfigId"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("name"), UBlueprintJsonLibrary::JsonMakeString(InName));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("cloneFrom"), UAnkiLibrary::JsonMakeInt64(InCloneFrom));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(WorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::RemoveDeckConfigId(UObject* WorldContextObject, const int64 InConfigId)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("removeDeckConfigId"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("configId"), UAnkiLibrary::JsonMakeInt64(InConfigId));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(WorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::GetDeckStats(UObject* WorldContextObject, const TArray<FString>& InDecks)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("getDeckStats"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	TArray<FBlueprintJsonValue> DeckValues;
	UAnkiLibrary::Conv_StringArrayToJsonArray(InDecks, DeckValues);
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("decks"), UBlueprintJsonLibrary::JsonMakeArray(DeckValues));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(WorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::StoreMediaFile(UObject* InWorldContextObject, const FString& InFilename, const FString& InData)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("storeMediaFile"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("filename"), UBlueprintJsonLibrary::JsonMakeString(InFilename));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("data"), UBlueprintJsonLibrary::JsonMakeString(InData));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::StoreMediaFileByPath(UObject* InWorldContextObject, const FString& InFilename, const FString& InPath)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("storeMediaFile"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("filename"), UBlueprintJsonLibrary::JsonMakeString(InFilename));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("path"), UBlueprintJsonLibrary::JsonMakeString(InPath));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::StoreMediaFileByUrl(UObject* InWorldContextObject, const FString& InFilename, const FString& InPath)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("storeMediaFile"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("filename"), UBlueprintJsonLibrary::JsonMakeString(InFilename));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("url"), UBlueprintJsonLibrary::JsonMakeString(InPath));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::RetrieveMediaFile(UObject* InWorldContextObject, const FString& InFilename)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("retrieveMediaFile"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("filename"), UBlueprintJsonLibrary::JsonMakeString(InFilename));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::GetMediaFilesNames(UObject* InWorldContextObject, const FString& InPattern)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("getMediaFilesNames"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("pattern"), UBlueprintJsonLibrary::JsonMakeString(InPattern));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::DeleteMediaFile(UObject* InWorldContextObject, const FString& InFilename)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("deleteMediaFile"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("filename"), UBlueprintJsonLibrary::JsonMakeString(InFilename));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::RequestPermission(UObject* InWorldContextObject)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("requestPermission"));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::Version(UObject* InWorldContextObject)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("version"));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::ApiReflect(UObject* InWorldContextObject, const TArray<FString>& InScopes, const TArray<FString>& InActions)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("apiReflect"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	TArray<FBlueprintJsonValue> ScopeValues;
	TArray<FBlueprintJsonValue> ActionValues;
	UAnkiLibrary::Conv_StringArrayToJsonArray(InScopes, ScopeValues);
	UAnkiLibrary::Conv_StringArrayToJsonArray(InActions, ActionValues);
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("scopes"), UBlueprintJsonLibrary::JsonMakeArray(ScopeValues));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("actions"), UBlueprintJsonLibrary::JsonMakeArray(ActionValues));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::Sync(UObject* InWorldContextObject)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("sync"));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::GetProfiles(UObject* InWorldContextObject)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("getProfiles"));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::LoadProfile(UObject* InWorldContextObject, const FString& InName)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("loadProfile"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("name"), UBlueprintJsonLibrary::JsonMakeString(InName));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::Multi(UObject* InWorldContextObject, const TArray<FBlueprintJsonObject>& InActions)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("multi"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	TArray<FBlueprintJsonValue> ActionValues;
	UAnkiLibrary::Conv_JsonObjectArrayToJsonArray(InActions, ActionValues);
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("actions"), UBlueprintJsonLibrary::JsonMakeArray(ActionValues));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::ExportPackage(UObject* InWorldContextObject, const FString& InDeck, const FString& InPath, const bool InIncludeSched)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("exportPackage"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("deck"), UBlueprintJsonLibrary::JsonMakeString(InDeck));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("path"), UBlueprintJsonLibrary::JsonMakeString(InPath));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("includeSched"), UBlueprintJsonLibrary::JsonMakeBool(InIncludeSched));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::ImportPackage(UObject* InWorldContextObject, const FString& InPath)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("importPackage"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("path"), UBlueprintJsonLibrary::JsonMakeString(InPath));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::ReloadCollection(UObject* InWorldContextObject)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("reloadCollection"));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::ModelNames(UObject* InWorldContextObject)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("modelNames"));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::ModelNamesAndIds(UObject* InWorldContextObject)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("modelNamesAndIds"));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::ModelFieldNames(UObject* InWorldContextObject, const FString& InModelName)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("modelFieldNames"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("modelName"), UBlueprintJsonLibrary::JsonMakeString(InModelName));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::ModelFieldDescriptions(UObject* InWorldContextObject, const FString& InModelName)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("modelFieldDescriptions"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("modelName"), UBlueprintJsonLibrary::JsonMakeString(InModelName));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::ModelFieldFonts(UObject* InWorldContextObject, const FString& InModelName)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("modelFieldFonts"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("modelName"), UBlueprintJsonLibrary::JsonMakeString(InModelName));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::ModelFieldsOnTemplates(UObject* InWorldContextObject, const FString& InModelName)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("modelFieldsOnTemplates"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("modelName"), UBlueprintJsonLibrary::JsonMakeString(InModelName));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::CreateModel(UObject* InWorldContextObject, const FString& InModelName, const TArray<FString>& InInOrderFields, const TArray<FBlueprintJsonObject>& InCardTemplates, const FString& InCss, const bool InIsCloze)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("createModel"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	TArray<FBlueprintJsonValue> OrderFieldValues;
	TArray<FBlueprintJsonValue> CardTemplateValues;
	UAnkiLibrary::Conv_StringArrayToJsonArray(InInOrderFields, OrderFieldValues);
	UAnkiLibrary::Conv_JsonObjectArrayToJsonArray(InCardTemplates, CardTemplateValues);
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("modelName"), UBlueprintJsonLibrary::JsonMakeString(InModelName));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("inOrderFields"), UBlueprintJsonLibrary::JsonMakeArray(OrderFieldValues));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("cardTemplates"), UBlueprintJsonLibrary::JsonMakeArray(CardTemplateValues));

	if (!InCss.IsEmpty())
	{
		UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("css"), UBlueprintJsonLibrary::JsonMakeString(InCss));
	}

	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("isCloze"), UBlueprintJsonLibrary::JsonMakeBool(InIsCloze));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::ModelTemplates(UObject* InWorldContextObject, const FString& InModelName)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("modelTemplates"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("modelName"), UBlueprintJsonLibrary::JsonMakeString(InModelName));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::ModelStyling(UObject* InWorldContextObject, const FString& InModelName)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("modelStyling"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("modelName"), UBlueprintJsonLibrary::JsonMakeString(InModelName));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::UpdateModelTemplates(UObject* InWorldContextObject, const FBlueprintJsonObject& InModel)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("updateModelTemplates"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("model"), UBlueprintJsonLibrary::JsonMakeObject(InModel));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::UpdateModelStyling(UObject* InWorldContextObject, const FBlueprintJsonObject& InModel)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("updateModelStyling"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("model"), UBlueprintJsonLibrary::JsonMakeObject(InModel));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::FindAndReplaceInModels(UObject* InWorldContextObject, const FBlueprintJsonObject& InModel)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("findAndReplaceInModels"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("model"), UBlueprintJsonLibrary::JsonMakeObject(InModel));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::ModelFieldRename(UObject* InWorldContextObject, const FString& InModelName, const FString& InOldFieldName, const FString& InNewFieldName)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("modelFieldRename"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("modelName"), UBlueprintJsonLibrary::JsonMakeString(InModelName));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("oldFieldName"), UBlueprintJsonLibrary::JsonMakeString(InOldFieldName));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("newFieldName"), UBlueprintJsonLibrary::JsonMakeString(InNewFieldName));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::ModelFieldReposition(UObject* InWorldContextObject, const FString& InModelName, const FString& InFieldName, const int32 InIndex)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("modelFieldReposition"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("modelName"), UBlueprintJsonLibrary::JsonMakeString(InModelName));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("fieldName"), UBlueprintJsonLibrary::JsonMakeString(InFieldName));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("index"), UBlueprintJsonLibrary::JsonMakeInt(InIndex));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::ModelFieldAdd(UObject* InWorldContextObject, const FString& InModelName, const FString& InFieldName, const int32 InIndex)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("modelFieldAdd"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("modelName"), UBlueprintJsonLibrary::JsonMakeString(InModelName));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("fieldName"), UBlueprintJsonLibrary::JsonMakeString(InFieldName));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("index"), UBlueprintJsonLibrary::JsonMakeInt(InIndex));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::ModelFieldRemove(UObject* InWorldContextObject, const FString& InModelName, const FString& InFieldName)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("modelFieldRemove"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("modelName"), UBlueprintJsonLibrary::JsonMakeString(InModelName));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("fieldName"), UBlueprintJsonLibrary::JsonMakeString(InFieldName));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::ModelFieldSetFont(UObject* InWorldContextObject, const FString& InModelName, const FString& InFieldName, const FString& InFont)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("modelFieldSetFont"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("modelName"), UBlueprintJsonLibrary::JsonMakeString(InModelName));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("fieldName"), UBlueprintJsonLibrary::JsonMakeString(InFieldName));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("font"), UBlueprintJsonLibrary::JsonMakeString(InFont));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::ModelFieldSetFontSize(UObject* InWorldContextObject, const FString& InModelName, const FString& InFieldName, const int32 InFontSize)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("modelFieldSetFontSize"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("modelName"), UBlueprintJsonLibrary::JsonMakeString(InModelName));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("fieldName"), UBlueprintJsonLibrary::JsonMakeString(InFieldName));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("fontSize"), UBlueprintJsonLibrary::JsonMakeInt(InFontSize));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}

UAnkiRequestNode* UAnkiRequestNode::ModelFieldSetDescription(UObject* InWorldContextObject, const FString& InModelName, const FString& InFieldName, const FString& InDescription)
{
	const auto Body = UAnkiLibrary::MakeDefaultBodyObject(TEXT("modelFieldSetDescription"));
	const auto Params = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("modelName"), UBlueprintJsonLibrary::JsonMakeString(InModelName));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("fieldName"), UBlueprintJsonLibrary::JsonMakeString(InFieldName));
	UBlueprintJsonLibrary::JsonMakeField(Params, TEXT("description"), UBlueprintJsonLibrary::JsonMakeString(InDescription));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("params"), UBlueprintJsonLibrary::JsonMakeObject(Params));

	return AnkiRequest(InWorldContextObject, Body);
}
