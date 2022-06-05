// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Engine/SkeletalMeshSocket.h"
#include "SWeapon.h"
#include "DrawDebugHelpers.h"
#include "HealthComponent.h"
#include "hideandseekgame.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Camera that we see through as the character
	HeadCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	// Attaches the camera to the characters head, so it don't glitch with the rest of the body since the character got a head with an attached camera
	HeadCamera->SetupAttachment(GetMesh(), FName("head"));

	// character turns with camera, so we don't break it's neck while looking backwards
	HeadCamera->bUsePawnControlRotation = true;


	GetCapsuleComponent()->SetCollisionResponseToChannel(COLLISION_WEAPON, ECR_Ignore);

	WeaponAttachSocketName = "weapon_socket";

	HealthComp = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComp"));

	bAiming = false;
	bDied = false;

	PlayerHealth = 100.f;
	PlayerMaxHealth = 100.f;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	HealthComp->OnHealthChanged.AddDynamic(this, &APlayerCharacter::OnHealthChanged);

	// Spawn a default weapon
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	CurrentWeapon = GetWorld()->SpawnActor<ASWeapon>(StarterWeaponClass, FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
	if (CurrentWeapon)
	{
		CurrentWeapon->SetOwner(this);
		CurrentWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponAttachSocketName);
	}
}


// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Set up game play key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("AimingButton", IE_Pressed, this, &APlayerCharacter::AimingButtonPressed);
	PlayerInputComponent->BindAction("AimingButton", IE_Pressed, this, &APlayerCharacter::AimingButtonReleased);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerCharacter::StartFire);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &APlayerCharacter::StopFire);


}

FVector APlayerCharacter::GetPawnViewLocation() const
{
	if (HeadCamera)
	{
		return HeadCamera->GetComponentLocation();
	}
	return Super::GetPawnViewLocation();
}

void APlayerCharacter::StartFire()
{
	if (CurrentWeapon)
	{
		CurrentWeapon->StartFire();
	}
}

void APlayerCharacter::StopFire()
{
	if (CurrentWeapon)
	{
		CurrentWeapon->StopFire();
	}
}


void APlayerCharacter::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector() * value);
}

void APlayerCharacter::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector() * value);
}


void APlayerCharacter::AimingButtonPressed()
{
	bAiming = true;
}

void APlayerCharacter::AimingButtonReleased()
{
	bAiming = false;
}

void APlayerCharacter::OnHealthChanged(UHealthComponent* OwningHealthComp, float Health, float HealthDelta, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
		if (Health <= 0.f && !bDied)
		{
			bDied = true;

			GetMovementComponent()->StopMovementImmediately();
			GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			DetachFromControllerPendingDestroy();

			SetLifeSpan(10.0f);
		}
	
}


