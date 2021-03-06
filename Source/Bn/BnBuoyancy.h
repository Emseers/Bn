// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "BnBuoyancy.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent, IsBlueprintBase = true) )
class BN_API UBnBuoyancy : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBnBuoyancy();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Gameplay")
	float MAX_TEMP = 100.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Gameplay")
	float MIN_TEMP = 20.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Gameplay")
	float COOLDOWN_RATE = 0.5f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Gameplay", Replicated)
	float CurrentTemp = MIN_TEMP;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Gameplay")
	float MAX_BUOYANCY = 100.0f;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(Server, Reliable, WithValidation)
	void Burn(float BurnTemp);

	UFUNCTION(Server, Reliable)
	void TimerTick();

	UFUNCTION()
	float GetForces() const;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
