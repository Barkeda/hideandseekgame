// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BulletHitInterface.h"
#include "AI.generated.h"

UCLASS()
class HIDEANDSEEKGAME_API AAI : public ACharacter, IBulletHitInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAI();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Combat")
		class USkeletalMeshComponent* GunSlotComp;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/**Particles that spawns when the AI is being hit*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	class UParticleSystem* ImpactParticels;

	/**Sound that plays when the AI gets hit*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	class USoundCue* ImpactSound;

private:


	/** Behavior Tree for the AI character */
	UPROPERTY(EditAnywhere, Category = "Behavior Tree", meta = (AllowPrivateAccess = "true"))
		class UBehaviorTree* BehaviorTree;

	/** Makes the enemy move to this point*/
	UPROPERTY(EditAnywhere, Category = "Behavior Tree", meta = (AllowPrivateAccess = "true", MakeEditWidget = "true"))
	FVector PatrolPoint;

	/** Makes the enemy move to second point*/
	UPROPERTY(EditAnywhere, Category = "Behavior Tree", meta = (AllowPrivateAccess = "true", MakeEditWidget = "true"))
	FVector PatrolPoint2;

	class AEnemyController* EnemyController;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void BulletHit_Implementation(FHitResult HitResult) override;


public:

	FORCEINLINE UBehaviorTree* GetBehaviorTree() const { return BehaviorTree; }
};
