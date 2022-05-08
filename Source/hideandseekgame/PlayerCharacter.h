// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class HIDEANDSEEKGAME_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
	class UCameraComponent* HeadCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Combat")
	class USkeletalMeshComponent* GunSlotComp;


protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** forward / backwards movement input */ 
	void MoveForward(float value);

	/** right / left movement input */
	void MoveRight(float value);

	/** Called when the fire button is pressed*/
	void FireWeapon();
	
	/**Set bAiming to true or false depending on button pressed or released*/
	void AimingButtonPressed();
	void AimingButtonReleased();

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat")
	//class TSubclassOf<UDamageType>DamageType;

	UFUNCTION()
	void OnHealthChanged(UHealthComponent* HealthComp, float Health, float HealthDelta, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	/** Player is dead*/
	UPROPERTY(BlueprintReadOnly, Category = "Player")
	bool bDead;

public:	


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	float DamageAmount;

private:

	/** Rifle sound cue*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	class USoundCue* FireSound;

	/** muzzle flash effect spawned at barrel socket*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	class UParticleSystem* Muzzleflash;

	/** Particles spawned upon bullet impact*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
		UParticleSystem* ImpactParticles;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	bool bAiming; 




};
