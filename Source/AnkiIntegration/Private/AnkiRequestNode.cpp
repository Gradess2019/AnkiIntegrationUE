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

void UAnkiRequestNode::Activate()
{
	Super::Activate();

	UAnkiLibrary::SendRequest(Body, [&](const FBlueprintJsonObject& InResponse) { OnResponse.Broadcast(InResponse); });
}
