// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ServerItem.generated.h"


UCLASS()
class HIDEANDSEEKGAME_API AServerItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AServerItem();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServerBox")
	class UBoxComponent* ServerBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServerBox")
	class UBillboardComponent* Billboard;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Keycard")
	int keycardValue;

};
