// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ShooterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class HIDEANDSEEKGAME_API UShooterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:

	/**makes this function accessible from blueprints inside Unreal*/
	UFUNCTION(BlueprintCallable)
	void UpdateAnimationProperties(float DeltaTime);

	/** Is like the begin play function for actors, but now called NativeInitializeAnimation since it's the animation class*/ 
	virtual void NativeInitializeAnimation() override;

private:

	// meta = (AllowPrivateAccess = "true")  means it can be accessed more like a public function

	/**Gets the player Character*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	class APlayerCharacter* PlayerCharacter;

	/** The speed of the character*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float Speed;

	/**Is the character in the air when called*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	bool bIsInAir;

	/** Do the character stand still or moving*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	bool bIsAccelerating;

};
