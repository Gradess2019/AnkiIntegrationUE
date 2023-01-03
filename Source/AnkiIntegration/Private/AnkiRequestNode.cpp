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