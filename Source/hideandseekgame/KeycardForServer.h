// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ServerItem.h"
#include "KeycardForServer.generated.h"

/**
 * 
 */
UCLASS()
class HIDEANDSEEKGAME_API AKeycardForServer : public AServerItem
{
	GENERATED_BODY()
	

public:

	AKeycardForServer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Keycard")
	class UStaticMeshComponent* KeyCard;

};
