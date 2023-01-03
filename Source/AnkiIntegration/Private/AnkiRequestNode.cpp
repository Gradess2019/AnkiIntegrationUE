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
