// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UTLauchZone.generated.h"

class UBoxComponent;

UCLASS()
class UDEMYTEMPLATE_API AUTLauchZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUTLauchZone();

protected:

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* OverlapComp;

	UPROPERTY(EditDefaultsOnly, Category = "Sounds")
	USoundBase* LauchSound;

	UPROPERTY(EditAnywhere, Category = "Config")
	FVector ForceDirection;

	UFUNCTION()
	void HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
