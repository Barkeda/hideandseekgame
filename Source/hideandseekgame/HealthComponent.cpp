// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{

	DefaultHealth = 100;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	AActor* MyCharacter = GetOwner();
	if (MyCharacter)
	{
		MyCharacter->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::HandleTakeAnyDamage);
	}
	// So health is the same at the beginning 
	Health = DefaultHealth;
}



// This HandleTakeAnyDamage is form a lib inside the engine
void UHealthComponent::HandleTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{

	// Updated health clamped so it can't go beneath zero
	Health = FMath::Clamp(Health - Damage, 0.0f, DefaultHealth);

	UE_LOG(LogTemp, Warning, TEXT("you are losing health: %s"), *FString::SanitizeFloat(Health));

	bDied = Health <= 0.0f;

	OnHealthChanged.Broadcast(this, Health, Damage, DamageType, InstigatedBy, DamageCauser);

	
	
}




