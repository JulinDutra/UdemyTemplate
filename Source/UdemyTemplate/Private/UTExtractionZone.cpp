// Fill out your copyright notice in the Description page of Project Settings.


#include "UTExtractionZone.h"
#include "UTGameMode.h"
#include "Components/BoxComponent.h"
#include "Components/DecalComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UdemyTemplate/UdemyTemplateCharacter.h"
#include "UdemyTemplate/Public/UTGameMode.h"

// Sets default values
AUTExtractionZone::AUTExtractionZone()
{
	OverlapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));
	OverlapComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OverlapComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	OverlapComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	OverlapComp->SetBoxExtent(FVector(200.0f));
	RootComponent = OverlapComp;

	OverlapComp->SetHiddenInGame(false);

	OverlapComp->OnComponentBeginOverlap.AddDynamic(this, &AUTExtractionZone::HandleOverlap);

	DecalComp = CreateDefaultSubobject<UDecalComponent>(TEXT("DecalComp"));
	DecalComp->DecalSize = FVector(200.0f, 200.0f, 200.0f);
	DecalComp->SetupAttachment(RootComponent);
}

void AUTExtractionZone::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AUdemyTemplateCharacter* MyPawn = Cast<AUdemyTemplateCharacter>(OtherActor);
	
	if(MyPawn == nullptr)
	{
		return;
	}

	if(MyPawn->bIsCarryingObjective)
	{
		AUTGameMode* GM = Cast<AUTGameMode>(GetWorld()->GetAuthGameMode());
		if(GM)
		{
			GM->CompleteMission(MyPawn);
		}
	}
	else
	{
		UGameplayStatics::PlaySound2D(this, ObjectiveMissingSound);
	}

	UE_LOG(LogTemp, Log, TEXT("Overlap with extraction zone"));
}

