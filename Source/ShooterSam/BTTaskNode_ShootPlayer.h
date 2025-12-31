// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTaskNode_ShootPlayer.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERSAM_API UBTTaskNode_ShootPlayer : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTTaskNode_ShootPlayer();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};
