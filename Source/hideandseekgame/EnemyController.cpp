// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "AI.h"

// Need to have your enemy controller declared, since we made a struct in the h file
AEnemyController::AEnemyController()
{
	// To be able to use the BlackboardComponent, we need to make an object of it and include the library for it as above
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
	// check is an analysis tool in c++ that detect bugs and undefined behavior if code is wrong
	check(BlackboardComponent);

	// To be able to use the BehaviorTreeComponent, we need to make an object of it and include the library for it as above
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTree Component"));
	check(BehaviorTreeComponent);
}
 // Taking the OnPosses function and overrides the parent, so it will suit to what is needed
void AEnemyController::OnPossess(APawn* InPawn)
{
	// Calling the parent function
	Super::OnPossess(InPawn);

	// Checking to see if we have a pawn at all, if not return
	if (InPawn == nullptr) { return; }
	
	// if a pawn is accessable possses it and get the behaviortree for that pawn (enemy)
	AAI* AI = Cast<AAI>(InPawn);
	if (AI)
	{
		if (AI->GetBehaviorTree())
		{
			// BlackboardAsset is a pointer from the AI class, but since we are in the Enemycontroller we need to dereference it to be able to use it here 
			BlackboardComponent->InitializeBlackboard(*(AI->GetBehaviorTree()->BlackboardAsset));
		}
	}
}
