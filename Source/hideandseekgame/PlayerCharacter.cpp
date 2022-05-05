// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Engine/SkeletalMeshSocket.h"

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

	GunSlotComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon Slot"));
	GunSlotComp->SetupAttachment(GetMesh(), FName("weapon_socket"));
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
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

	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("FireButton", IE_Pressed, this, &APlayerCharacter::FireWeapon);

}

void APlayerCharacter::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector() * value);
}

void APlayerCharacter::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector() * value);
}

void APlayerCharacter::FireWeapon()
{
	// Making sure the fire sound is valid
	if (FireSound)
	{
		// Fetching the playsound from the gameplaystatics lib and makes sure teh character is the one using the fire sound 
		UGameplayStatics::PlaySound2D(this, FireSound);
	}
	// Making it const since it should not be changed
	const USkeletalMeshSocket* BarrelSocket = GetMesh()->GetSocketByName("Barrel_Socket");
	// Making sure there is a barrel socket attached
	if (BarrelSocket)
	{
		const FTransform SocketTransform = BarrelSocket->GetSocketTransform(GetMesh());

		// Making sure there is a muzzleflash attached for nullptr exception
		if (Muzzleflash)
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Muzzleflash, SocketTransform);
		}
	}
}

