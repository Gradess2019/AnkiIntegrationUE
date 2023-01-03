// Copyright Gradess Games. All Rights Reserved.


#include "AnkiLibrary.h"
#include "AnkiTypes.h"
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"

bool UAnkiLibrary::SendRequest(const FBlueprintJsonObject& InBody, const TFunction<void(const FBlueprintJsonObject& InResponse)>& InCallback)
{
	checkf(UBlueprintJsonLibrary::JsonHasField(InBody, TEXT("action")), TEXT("AnkiLibrary::SendRequest: Request body must have 'action' field"));
	checkf(UBlueprintJsonLibrary::JsonHasField(InBody, TEXT("version")), TEXT("AnkiLibrary::SendRequest: Request body must have 'version' field"));
	
	const auto HttpModule = &FHttpModule::Get();
	const auto Request = HttpModule->CreateRequest();
	Request->SetURL(TEXT("http://localhost:8765"));
	Request->SetVerb(TEXT("POST"));
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetContentAsString(UBlueprintJsonLibrary::Conv_JsonObjectToString(InBody));

	Request->OnProcessRequestComplete().BindLambda([InCallback] (FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
	{
		if (!bConnectedSuccessfully)
		{
			UE_LOG(LogAnki, Error, TEXT("Couldn't connect: "), *Response->GetContentAsString());
			return;
		}
		
		FBlueprintJsonObject ResponseData;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
		
		if (FJsonSerializer::Deserialize(Reader, ResponseData.Object))
		{
			UE_LOG(LogAnki, Log, TEXT("Response: %s"), *Response->GetContentAsString());
			InCallback(ResponseData);
		} else
		{
			UE_LOG(LogAnki, Error, TEXT("Couldn't deserialize response: "), *Response->GetContentAsString());
		}
	});
	
	return Request->ProcessRequest();
}

void UAnkiLibrary::Conv_Int64ArrayToJsonArray(const TArray<int64>& InArray, TArray<FBlueprintJsonValue>& OutArray)
{
	OutArray.Empty(InArray.Num());
	for (const auto& Element : InArray)
	{
		OutArray.Add(JsonMakeInt64(Element));
	}
}

void UAnkiLibrary::Conv_StringArrayToJsonArray(const TArray<FString>& InArray, TArray<FBlueprintJsonValue>& OutArray)
{
	OutArray.Empty(InArray.Num());
	for (const auto& Element : InArray)
	{
		OutArray.Add(UBlueprintJsonLibrary::JsonMakeString(Element));
	}
}

void UAnkiLibrary::Conv_JsonObjectArrayToJsonArray(const TArray<FBlueprintJsonObject>& InArray, TArray<FBlueprintJsonValue>& OutArray)
{
	OutArray.Empty(InArray.Num());
	for (const auto& Element : InArray)
	{
		OutArray.Add(UBlueprintJsonLibrary::JsonMakeObject(Element));
	}
}

FBlueprintJsonValue UAnkiLibrary::JsonMakeInt64(int64 IntValue)
{
	FBlueprintJsonValue Value;
	Value.Value = MakeShareable(new FJsonValueNumber(IntValue));
	return Value;
}

FBlueprintJsonObject UAnkiLibrary::MakeDefaultBodyObject(const FString& InAction)
{
	const FBlueprintJsonObject Body = UBlueprintJsonLibrary::JsonMake();
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("action"), UBlueprintJsonLibrary::JsonMakeString(InAction));
	UBlueprintJsonLibrary::JsonMakeField(Body, TEXT("version"), UBlueprintJsonLibrary::JsonMakeInt(6));

	return Body;
}

