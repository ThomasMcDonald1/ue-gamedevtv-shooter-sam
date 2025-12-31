// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"

#include "ShooterSamCharacter.h"

#include "ShooterAI.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERSAM_API AShooterAI : public AAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AShooterAI();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void StartBehaviorTree(AShooterSamCharacter* Player);
	AShooterSamCharacter* PlayerCharacter;
	AShooterSamCharacter* MyCharacter;


private:
	APawn* PlayerPawn;
	
	UPROPERTY(EditAnywhere)
	UBehaviorTree* EnemyAIBehaviorTree;
};
