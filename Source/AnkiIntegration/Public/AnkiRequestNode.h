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

	virtual void Activate() override;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "AnkiRequest")
	FBlueprintJsonObject Body;

	TSharedPtr<IHttpRequest> Request;
};


