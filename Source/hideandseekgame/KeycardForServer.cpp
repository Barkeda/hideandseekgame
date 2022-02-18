// Fill out your copyright notice in the Description page of Project Settings.


#include "KeycardForServer.h"
#include "Components/StaticMeshComponent.h"

AKeycardForServer::AKeycardForServer()
{

	KeyCard = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Key Card"));
	KeyCard->SetupAttachment(RootComponent);


}
