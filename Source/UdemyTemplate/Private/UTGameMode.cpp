// Fill out your copyright notice in the Description page of Project Settings.


#include "UTGameMode.h"

#include "UTHUD.h"
#include "Kismet/GameplayStatics.h"

AUTGameMode::AUTGameMode()
{
	HUDClass = AUTHUD::StaticClass();
}

void AUTGameMode::CompleteMission(APawn* InstigatorPawn)
{
	if(InstigatorPawn)
	{
		InstigatorPawn->DisableInput(nullptr);

		if(SpectatingViewpointClass)
		{
			TArray<AActor*> ReturnedActors;
			UGameplayStatics::GetAllActorsOfClass(this, SpectatingViewpointClass,ReturnedActors);

			// Change viewtarget if any valid actor found
			if(ReturnedActors.Num() > 0)
			{
				AActor* NewViewTarget = ReturnedActors[0];

				APlayerController* PC = Cast<APlayerController>(InstigatorPawn->GetController());
				if(PC)
				{
					PC->SetViewTargetWithBlend(NewViewTarget, 0.5f, VTBlend_Cubic);
				}
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("SpectatingViewpointClass is nullptr. Please update GameMode class with valid subclass. Cannot change spectating viewpoint"));
		}
	}

	OnMissionCompleted(InstigatorPawn);
}
