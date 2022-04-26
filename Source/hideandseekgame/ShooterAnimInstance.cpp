// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAnimInstance.h"
#include "PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UShooterAnimInstance::UpdateAnimationProperties(float DeltaTime)
{
	// if the player character is none existent, then cast to the player character to try and fetch it, so no errors happen
	if (PlayerCharacter == nullptr)
	{
		PlayerCharacter = Cast<APlayerCharacter>(TryGetPawnOwner());
	}
	if (PlayerCharacter)
	{
		// Get the speed of the character from velocity
		FVector Velocity{ PlayerCharacter->GetVelocity() };
		// making sure the character don't drift upwards 
		Velocity.Z = 0;
		Speed = Velocity.Size();

		// Is the character in the air? (include characterMovementComponent)
		bIsInAir = PlayerCharacter->GetCharacterMovement()->IsFalling();

		// Is the Character Accelerating (moving)?
		if (PlayerCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f)
		{
			bIsAccelerating = true;
		}
		else
		{
			bIsAccelerating = false;
		}
	}
}

void UShooterAnimInstance::NativeInitializeAnimation()
{
	// include the character lib and tells the function to grab the player character with a cast to make sure it gets a valid object
	PlayerCharacter = Cast<APlayerCharacter>(TryGetPawnOwner());
}
