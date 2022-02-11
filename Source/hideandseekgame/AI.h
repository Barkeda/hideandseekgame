// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AI.generated.h"

UCLASS()
class HIDEANDSEEKGAME_API AAI : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAI();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

private:

	/** Behavior Tree for the AI character */
	UPROPERTY(EditAnywhere, Category = "Behavior Tree", meta = (AllowPrivateAccess = "true"))
		class UBehaviorTree* BehaviorTree;

	/** Makes the enemy move to this point*/
	UPROPERTY(EditAnywhere, Category = "Behavior Tree", meta = (AllowPrivateAccess = "true", MakeEditWidget = "true"))
	FVector PatrolPoint;

	class AEnemyController* EnemyController;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



public:

	FORCEINLINE UBehaviorTree* GetBehaviorTree() const { return BehaviorTree; }
};
