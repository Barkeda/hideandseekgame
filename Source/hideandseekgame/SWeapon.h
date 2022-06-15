// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SWeapon.generated.h"

class UParticleSystem;

UCLASS()
class HIDEANDSEEKGAME_API ASWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASWeapon();


	void StartFire();

	void StopFire();

	void Fire();

protected:

	virtual void BeginPlay()  override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class USkeletalMeshComponent* MeshComp;


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	class TSubclassOf<UDamageType>DamageType;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
		FName MuzzleSocketName;

	void PlayFireEffect();

	/** muzzle flash effect spawned at barrel socket*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
		UParticleSystem* Muzzleflash;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
		UParticleSystem* ImpactEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
		UParticleSystem* FleshImpactEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
		class USoundCue* ImpactSound;



	FTimerHandle TimerHandle_TimeBetweenShots;

	float LastTimeFired;

	/** BPM - Bullets Fired per minute*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	float RateOfFire;

	/**Derived from rate of fire*/
	float TimeBetweenShots;

	/**Bullet spread in degrees*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon", meta = (ClampMin = 0.0f))
	float BulletSpread;


};
