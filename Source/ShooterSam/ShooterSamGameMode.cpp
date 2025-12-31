// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShooterSamGameMode.h"

#include "Kismet/GameplayStatics.h"
#include "ShooterSamCharacter.h"
#include "ShooterAI.h"

AShooterSamGameMode::AShooterSamGameMode()
{
	// stub
}

void AShooterSamGameMode::BeginPlay()
{
	Super::BeginPlay();

	AShooterSamCharacter* Player = Cast<AShooterSamCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	TArray<AActor*> EnemyAIActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AShooterAI::StaticClass(), EnemyAIActors);

	//int32 i = 0;
	//while (i < EnemyAIActors.Num())
	//{
	//	AShooterAI* ShooterAI = Cast<AShooterAI>(EnemyAIActors[i++]);
	//	ShooterAI->StartBehaviorTree(Player);

	//}
	
	//for (int32 i = 0; i < EnemyAIActors.Num(); i++)
	//{
	//	if (AShooterAI* ShooterAI = Cast<AShooterAI>(EnemyAIActors[i]))
	//	{
	//		ShooterAI->StartBehaviorTree(Player);
	//		UE_LOG(LogTemp, Display, TEXT("%s starting behavior tree"), *ShooterAI->GetActorNameOrLabel());
	//	}
	//}

	for (AActor* EnemyAIActor : EnemyAIActors)
	{
		if (AShooterAI* ShooterAI = Cast<AShooterAI>(EnemyAIActor))
		{
			ShooterAI->StartBehaviorTree(Player);
			UE_LOG(LogTemp, Display, TEXT("%s starting behavior tree"), *ShooterAI->GetActorNameOrLabel());
		}
	}
}
