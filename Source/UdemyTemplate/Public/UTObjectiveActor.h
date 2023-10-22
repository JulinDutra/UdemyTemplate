// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UTObjectiveActor.generated.h"

class USphereComponent;
class UParticleSystem;

UCLASS()
class UDEMYTEMPLATE_API AUTObjectiveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUTObjectiveActor();

protected:

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* SphereComp;

	UPROPERTY(EditDefaultsOnly, Category = "FX")
	UParticleSystem* PickupFX;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void PlayEffects();

public:
	
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
