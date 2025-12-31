// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAI.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

AShooterAI::AShooterAI()
{
}

void AShooterAI::BeginPlay()
{
	Super::BeginPlay();
}

void AShooterAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*if (PlayerPawn)
	{
		if (LineOfSightTo(PlayerPawn))
		{
			this->SetFocus(PlayerPawn);
			this->MoveToActor(PlayerPawn, 300.0f);
		}
		else
		{
			this->ClearFocus(EAIFocusPriority::Gameplay);
			this->StopMovement();
		}
	}*/
}

void AShooterAI::StartBehaviorTree(AShooterSamCharacter* Player)
{
	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (EnemyAIBehaviorTree)
	{
		MyCharacter = Cast<AShooterSamCharacter>(GetPawn());
		if (Player)
		{
			PlayerCharacter = Player;
		}
		RunBehaviorTree(EnemyAIBehaviorTree);

		UBlackboardComponent* MyBlackboard = GetBlackboardComponent();
		if (MyBlackboard && PlayerCharacter && MyCharacter)
		{
			// Don't ever do this code below since the player will always be moving. This was for testing purposes.
			//MyBlackboard->SetValueAsVector("PlayerLocation", PlayerCharacter->GetActorLocation());
			MyBlackboard->SetValueAsVector("EnemyStartLocation", MyCharacter->GetActorLocation());
		}
	}
}
