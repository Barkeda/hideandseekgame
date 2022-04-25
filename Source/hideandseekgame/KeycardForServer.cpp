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

}

// Called when the game starts or when spawned
void AKeycardForServer::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void AKeycardForServer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



