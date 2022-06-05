//// Fill out your copyright notice in the Description page of Project Settings.
//
//#pragma once
//
//#include "CoreMinimal.h"
//#include "GameFramework/Character.h"
//#include "BulletHitInterface.h"
//#include "SWeapon.h"
//#include "AI.generated.h"
//
//UCLASS()
//class HIDEANDSEEKGAME_API AAI : public ACharacter, public IBulletHitInterface
//{
//	GENERATED_BODY()
//
//public:
//	// Sets default values for this character's properties
//	AAI();
//
//	class ASWeapon* CurrentWeapon;
//
//	UPROPERTY(EditDefaultsOnly, Category = "Player")
//		TSubclassOf<ASWeapon> StarterWeaponClass;
//
//	UPROPERTY(VisibleDefaultsOnly, Category = "Player")
//		FName WeaponAttachSocketName;
//
//protected:
//	// Called when the game starts or when spawned
//	virtual void BeginPlay() override;
//
//	/**Particles that spawns when the AI is being hit*/
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
//	class UParticleSystem* ImpactParticles;
//
//	/**Sound that plays when the AI gets hit*/
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
//	class USoundCue* ImpactSound;
//
//	/**Current Health of the Enemy*/
//	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
//	float Health;
//
//	/**Maximum health of the Enemy*/
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
//	float MaxHealth;
//
//
//	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
//		class TSubclassOf<UDamageType>DamageType;
//
//	float DamageAmount;
//
//	void PlayDamageMontage(FName Section, float PlayRate = 1.0f);
//
//
//private:
//
//
//	/** Behavior Tree for the AI character */
//	UPROPERTY(EditAnywhere, Category = "Behavior Tree", meta = (AllowPrivateAccess = "true"))
//		class UBehaviorTree* BehaviorTree;
//
//	/** Makes the enemy move to this point*/
//	UPROPERTY(EditAnywhere, Category = "Behavior Tree", meta = (AllowPrivateAccess = "true", MakeEditWidget = "true"))
//	FVector PatrolPoint;
//
//	/** Makes the enemy move to second point*/
//	UPROPERTY(EditAnywhere, Category = "Behavior Tree", meta = (AllowPrivateAccess = "true", MakeEditWidget = "true"))
//	FVector PatrolPoint2;
//
//	class AEnemyController* EnemyController;
//
//
//	/**Montage that contains when damaged and death animations*/
//	UPROPERTY(EditAnywhere, BLueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
//	UAnimMontage* DamageMontage;
//
//
//public:	
//	// Called every frame
//	virtual void Tick(float DeltaTime) override;
//
//	// Called to bind functionality to input
//	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
//
//	virtual void BulletHit_Implementation(FHitResult HitResult) override;
//
//	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
//
//	FORCEINLINE UBehaviorTree* GetBehaviorTree() const { return BehaviorTree; }
//};
