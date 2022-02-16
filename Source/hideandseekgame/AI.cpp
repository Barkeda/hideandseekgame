// Fill out your copyright notice in the Description page of Project Settings.


#include "AI.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"
#include "EnemyController.h"
#include "BehaviorTree/BlackboardComponent.h"

// Sets default values
AAI::AAI()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAI::BeginPlay()
{
	Super::BeginPlay();
	
	// Getting the AI controller 
	EnemyController = Cast<AEnemyController>(GetController());

	// Using UKismetMathLibrary to get access to the patrol point world location, so we can move it relative to the enemy character
	FVector WorldPatrolPoint = UKismetMathLibrary::TransformLocation(GetActorTransform(), PatrolPoint);

	const FVector WorldPatrolPoint2 = UKismetMathLibrary::TransformLocation(GetActorTransform(), PatrolPoint2);

	// Draws a sphere around the Patrol point in the world
	//DrawDebugSphere(GetWorld(), WorldPatrolPoint, 25.f, 12, FColor::Red, true);

	// Draws a sphere around the Patrol point in the world
	//DrawDebugSphere(GetWorld(), WorldPatrolPoint2, 25.f, 12, FColor::Red, true);

	// Looking for a enemy controller is valid
	if (EnemyController)
	{
		// Setting the vecotr value that was made in the Blackboard to match the values below
		EnemyController->GetBlackboardComponent()->SetValueAsVector(TEXT("PatrolPoint"), WorldPatrolPoint);
		EnemyController->GetBlackboardComponent()->SetValueAsVector(TEXT("PatrolPoint2"), WorldPatrolPoint2);
		// Makes the Behavior tree on the enemy accessable and able to do tasks with the blackboard
		EnemyController->RunBehaviorTree(BehaviorTree);

	}
}

// Called every frame
void AAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

