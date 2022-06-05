//// Fill out your copyright notice in the Description page of Project Settings.
//
//#pragma once
//
//#include "CoreMinimal.h"
//#include "AIController.h"
//#include "EnemyController.generated.h"
//
///**
// * 
// */
//UCLASS()
//class HIDEANDSEEKGAME_API AEnemyController : public AAIController
//{
//	GENERATED_BODY()
//
//public:
//
//	AEnemyController();
//
//	virtual void OnPossess(APawn* InPawn) override;
//	
//
//private: // Makes these classes private, because only the Enemy AI is going to use them
//
//
//	/** Makes the blackboard component accessable for the enemy class */
//	/** makes it so we can see and change it from inside unreal engine itself by making it BlueprintreadWrite*/
//	UPROPERTY(BlueprintReadWrite, Category = "AI Behavior", meta = (AllowPrivateAccess = "true"))
//	class UBlackboardComponent* BlackboardComponent;
//
//	/** Makes the Behaviortree component accessable for the enemy class*/
//	UPROPERTY(BlueprintReadWrite, Category = "AI Behavior", meta = (AllowPrivateAccess = "true"))
//	class UBehaviorTreeComponent* BehaviorTreeComponent;
//
//public:
//
//	FORCEINLINE UBlackboardComponent* GetBlackboardComponent() const { return BlackboardComponent; }
//
//
//};
