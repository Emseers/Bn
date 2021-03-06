// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "BnFloatMovement.generated.h"

/**
 * 
 */
UCLASS()
class BN_API UBnFloatMovement : public UPawnMovementComponent
{
	GENERATED_BODY()
public:
	void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	inline bool IsFlying() const override;
	// Add forces to centre of mass, for translational movement etc.. (off axis thrust etc.. is not included here)
	UFUNCTION(BlueprintCallable)
	void AddForce(FVector Force);
	UFUNCTION(BlueprintCallable)
	void SetMass(float NewMass);

private:
	FVector ComputeMoveDelta(const FVector& InVelocity, float DeltaTime) const;
	FVector ComputeVelocity(FVector InitialVelocity, float DeltaTime) const;
	FVector ComputeAcceleration(const FVector& InVelocity, float DeltaTime) const;
	FVector LimitVelocity(FVector NewVelocity) const;

	// Pending force for next tick.
	FVector PendingForce;

	float Mass;
};
