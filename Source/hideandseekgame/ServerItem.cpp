// Fill out your copyright notice in the Description page of Project Settings.


#include "ServerItem.h"
#include "PlayerCharacter.h"
#include "Components/BoxComponent.h"
#include "Components/BillboardComponent.h"
#include "KeycardForServer.h"

// Sets default values
AServerItem::AServerItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ServerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Server Box"));
	ServerBox->SetupAttachment(RootComponent);

	Billboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("Billboard"));
	Billboard->SetupAttachment(ServerBox);

}

// Called when the game starts or when spawned
void AServerItem::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void AServerItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


