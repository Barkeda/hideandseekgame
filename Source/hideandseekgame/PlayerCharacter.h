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
	class UCameraComponent* headCamera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** forward / backwards movement input */ 
	void MoveForward(float value);

	/** right / left movement input */
	void MoveRight(float value);

	
public:	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "KeycardItems")
	TArray<KeycardItem> Keycards;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
