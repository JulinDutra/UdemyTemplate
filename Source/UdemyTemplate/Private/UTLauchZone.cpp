// Fill out your copyright notice in the Description page of Project Settings.


#include "UTLauchZone.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UdemyTemplate/UdemyTemplateCharacter.h"

// Sets default values
AUTLauchZone::AUTLauchZone()
{
	OverlapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));
	OverlapComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	OverlapComp->SetCollisionResponseToAllChannels(ECR_Overlap);
	RootComponent = OverlapComp;

	OverlapComp->OnComponentBeginOverlap.AddDynamic(this, &AUTLauchZone::HandleOverlap);
}

void AUTLauchZone::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor == nullptr)
		return;
	
	if(OtherActor->bGenerateOverlapEventsDuringLevelStreaming)
	{
		if(AUdemyTemplateCharacter* MyPawn = Cast<AUdemyTemplateCharacter>(OtherActor))
		{
			MyPawn->LaunchCharacter(ForceDirection, false, false);
		}
		else if(UPrimitiveComponent* Primitive = Cast<UPrimitiveComponent>(OtherActor->GetRootComponent()))
		{
			Primitive->AddImpulse(ForceDirection);
		}
		
		UGameplayStatics::PlaySound2D(this, LauchSound);	
	}

	UE_LOG(LogTemp, Log, TEXT("Overlap with lauch zone"));
}





