// Copyright Gradess Games. All Rights Reserved.


#include "AnkiLibrary.h"

#include "HttpModule.h"

FBlueprintJsonObject UAnkiLibrary::SendRequest(const FString& InAction, const int32 InVersion)
{
	auto HttpModule = &FHttpModule::Get();
	auto Request = HttpModule->CreateRequest();
	Request->SetURL()
	return UBlueprintJsonLibrary::JsonMake();
}

// void UAnkiLibrary::GetEaseFactors()
// {
// 	
// }
