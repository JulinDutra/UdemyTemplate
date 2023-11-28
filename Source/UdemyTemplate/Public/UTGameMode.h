// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "UTGameMode.generated.h"


UCLASS()
class UDEMYTEMPLATE_API AUTGameMode : public AGameMode
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Spectating")
	TSubclassOf<AActor> SpectatingViewpointClass;

public:

	AUTGameMode();
	
	void CompleteMission(APawn* InstigatorPawn);

	UFUNCTION(BlueprintImplementableEvent, Category = "GameMode")
	void OnMissionCompleted(APawn* InstigatorPawn);
};
