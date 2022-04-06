// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KeycardForServer.generated.h"

UCLASS()
class HIDEANDSEEKGAME_API AKeycardForServer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKeycardForServer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Keycard")
		class UStaticMeshComponent* Keycard;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Keycard")
	class UBoxComponent* KeycardTrigger;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void KeycardCollected();

	bool bKeycardIsCollected;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


};
