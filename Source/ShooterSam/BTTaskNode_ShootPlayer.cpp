// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskNode_ShootPlayer.h"
#include <ShooterAI.h>

UBTTaskNode_ShootPlayer::UBTTaskNode_ShootPlayer()
{
	NodeName = TEXT("Shoot At Player");
}

EBTNodeResult::Type UBTTaskNode_ShootPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	EBTNodeResult::Type Result = EBTNodeResult::Failed;

	if (AShooterAI* OwnerController = Cast<AShooterAI>(OwnerComp.GetAIOwner()))
	{
		AShooterSamCharacter* OwnerCharacter = OwnerController->MyCharacter;
		AShooterSamCharacter* PlayerCharacter = OwnerController->PlayerCharacter;
		if (OwnerCharacter && PlayerCharacter && PlayerCharacter->IsAlive)
		{
			OwnerCharacter->Shoot();
			Result = EBTNodeResult::Succeeded;
		}
	}

	return Result;
}
