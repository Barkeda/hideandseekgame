// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SWeapon.h"
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


protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** forward / backwards movement input */ 
	void MoveForward(float value);

	/** right / left movement input */
	void MoveRight(float value);
	
	/**Set bAiming to true or false depending on button pressed or released*/
	void AimingButtonPressed();
	void AimingButtonReleased();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UHealthComponent* HealthComp;

	UFUNCTION()
	void OnHealthChanged(UHealthComponent* OwningHealthComp, float Health, float HealthDelta, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

public:	

	float PlayerHealth;

	float PlayerMaxHealth;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Returns	Pawn's eye location */
	virtual FVector GetPawnViewLocation() const override;


	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	class ASWeapon* CurrentWeapon;

	UFUNCTION(BlueprintCallable, Category = "Player")
	void StartFire();

	UFUNCTION(BlueprintCallable, Category = "Player")
	void StopFire();

	UPROPERTY(EditDefaultsOnly, Category = "Player")
	TSubclassOf<ASWeapon> StarterWeaponClass;

	UPROPERTY(VisibleDefaultsOnly, Category = "Player")
	FName WeaponAttachSocketName;

	UPROPERTY(BlueprintReadOnly, Category = "Player")
	bool bDied;

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	bool bAiming; 

	/**Montage for character death*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	class UAnimMontage* DeathMontage;



};
