// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ClearBlackboardValue.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_ClearBlackboardValue::UBTTask_ClearBlackboardValue()
{
	NodeName = TEXT("Clear Blackboard Value");
}

EBTNodeResult::Type UBTTask_ClearBlackboardValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// return EBTNodeResult::Type();
	Super::ExecuteTask(OwnerComp, NodeMemory);
	// Get the blackboard comp
	if (UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent())
	{
		// Clear the value of the selected key
		Blackboard->ClearValue(GetSelectedBlackboardKey());

		// Return success or failure
	}
	return EBTNodeResult::Succeeded;
}
