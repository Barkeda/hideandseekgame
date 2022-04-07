// Fill out your copyright notice in the Description page of Project Settings.


#include "KeycardForServer.h"
#include "Components/StaticmeshComponent.h"
#include "Components/BoxComponent.h"
#include "PlayerCharacter.h"

// Sets default values
AKeycardForServer::AKeycardForServer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Keycard = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Key Card"));
	Keycard->SetupAttachment(RootComponent);

	KeycardTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Key Card trigger"));
	KeycardTrigger->SetupAttachment(Keycard);

	KeycardTrigger->OnComponentBeginOverlap.AddDynamic(this, &AKeycardForServer::OnOverlapBegin);
	KeycardTrigger->OnComponentEndOverlap.AddDynamic(this, &AKeycardForServer::OnOverlapEnd);

	bKeycardIsCollected = false;

}

// Called when the game starts or when spawned
void AKeycardForServer::BeginPlay()
{
	Super::BeginPlay();
	
}

//void AKeycardForServer::KeycardCollected()
//{
//	bKeycardIsCollected = true;
//}

// Called every frame
void AKeycardForServer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AKeycardForServer::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APlayerCharacter* OtherCharacter = Cast<APlayerCharacter>(OtherActor);
	if (OtherCharacter)
	{
		Keycard->SetVisibility(true);
		KeycardTrigger->SetVisibility(false);
		UE_LOG(LogTemp, Warning, TEXT("You Got the keycard"));
		bKeycardIsCollected = true;
		//KeycardCollected();
	}
	

}

void AKeycardForServer::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

