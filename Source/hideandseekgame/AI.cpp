//// Fill out your copyright notice in the Description page of Project Settings.
//
//
//#include "AI.h"
//#include "Kismet/KismetMathLibrary.h"
//#include "DrawDebugHelpers.h"
//#include "EnemyController.h"
//#include "Kismet/GameplayStatics.h"
//#include "Sound/SoundCue.h"
//#include "Components/CapsuleComponent.h"
//#include "Particles/ParticleSystemComponent.h"
//#include "HealthComponent.h"
//#include "SWeapon.h"
//#include "BehaviorTree/BlackboardComponent.h"
//
//// Sets default values
//AAI::AAI() :
//	Health(100.f),
//	MaxHealth(100.f),
//	DamageAmount(15.f)
//
//
//{
// 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
//	PrimaryActorTick.bCanEverTick = true;
//
//	WeaponAttachSocketName = "weapon_socket";
//
//}
//
//// Called when the game starts or when spawned
//void AAI::BeginPlay()
//{
//	Super::BeginPlay();
//	
//	// Makes it possible to hit the enemy with the Line trace
//	GetMesh()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
//
//	// Getting the AI controller 
//	EnemyController = Cast<AEnemyController>(GetController());
//
//	// Using UKismetMathLibrary to get access to the patrol point world location, so we can move it relative to the enemy character
//	FVector WorldPatrolPoint = UKismetMathLibrary::TransformLocation(GetActorTransform(), PatrolPoint);
//
//	const FVector WorldPatrolPoint2 = UKismetMathLibrary::TransformLocation(GetActorTransform(), PatrolPoint2);
//
//	// Spawn a default weapon
//	FActorSpawnParameters SpawnParams;
//	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
//
//	CurrentWeapon = GetWorld()->SpawnActor<ASWeapon>(StarterWeaponClass, FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
//	if (CurrentWeapon)
//	{
//		CurrentWeapon->SetOwner(this);
//		CurrentWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponAttachSocketName);
//	}
//
//	// Looking for a enemy controller is valid
//	if (EnemyController)
//	{
//		// Setting the vector value that was made in the Blackboard to match the values below
//		EnemyController->GetBlackboardComponent()->SetValueAsVector(TEXT("PatrolPoint"), WorldPatrolPoint);
//		EnemyController->GetBlackboardComponent()->SetValueAsVector(TEXT("PatrolPoint2"), WorldPatrolPoint2);
//		// Makes the Behavior tree on the enemy accessable and able to do tasks with the blackboard
//		EnemyController->RunBehaviorTree(BehaviorTree);
//
//	}
//}
//
//// Lets play the animations that are setup inside the engine
//void AAI::PlayDamageMontage(FName Section, float PlayRate)
//{
//	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
//	if (AnimInstance)
//	{
//		AnimInstance->Montage_Play(DamageMontage, PlayRate);
//		AnimInstance->Montage_JumpToSection(Section, DamageMontage);
//	}
//}
//
//
//
//// Called every frame
//void AAI::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}
//
//// Called to bind functionality to input
//void AAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//}
//
//void AAI::BulletHit_Implementation(FHitResult HitResult)
//{
//	// Making sure Impact sound is not a null pointer 
//	if (ImpactSound)
//	{
//		// Make a sound where the bullet hit a target
//		UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, GetActorLocation());
//	}
//	if (ImpactParticles)
//	{
//		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactParticles, HitResult.Location, FRotator(0.f), true);
//	}
//	
//	PlayDamageMontage(FName("HitReact1"));
//}
//
//float AAI::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
//{
//	if (Health - DamageAmount <= 0.0f)
//	{
//		Health = 0.f;
//	}
//	else {
//		Health -= DamageAmount;
//	}
//	return DamageAmount;
//}
//
