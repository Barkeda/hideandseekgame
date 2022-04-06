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

	ServerBox->OnComponentBeginOverlap.AddDynamic(this, &AServerItem::OnOverlapBegin);
	ServerBox->OnComponentEndOverlap.AddDynamic(this, &AServerItem::OnOverlapEnd);


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

void AServerItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{


	//if (Keycard.bKeycardIsCollected == true)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("keycard inserted"));
	//}
	//else {
	//	UE_LOG(LogTemp, Warning, TEXT("keycard Missing"));
	//}

	
}

void AServerItem::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

