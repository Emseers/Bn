// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BnBuoyancy.h"
#include "BnFloatMovement.h"
#include "BnAirship.generated.h"

UCLASS()
class BN_API ABnAirship : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABnAirship();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// TODO: Replace with more generic solution to allow arbitrary # balloon + subtypes of BnBuoyancy
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Gameplay", Replicated)
	UBnBuoyancy* MainBalloon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Gameplay", Replicated)
	UBnFloatMovement* Movement;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Gameplay")
	float Mass = 1000.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Visual")
	UStaticMeshComponent* HullMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Visual")
	UStaticMeshComponent* MainBalloonMesh;

	FTimerHandle TimerTickHandle;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(Server, Reliable)
	void TimerTick();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
