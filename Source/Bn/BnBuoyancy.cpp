// Fill out your copyright notice in the Description page of Project Settings.


#include "BnBuoyancy.h"
#include "Net/UnrealNetwork.h"

// Sets default values for this component's properties
UBnBuoyancy::UBnBuoyancy()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
	SetIsReplicatedByDefault(true);
}


// Called when the game starts
void UBnBuoyancy::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBnBuoyancy::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

float UBnBuoyancy::GetForces() const
{
	return MAX_BUOYANCY * (CurrentTemp / MAX_TEMP);
}

void UBnBuoyancy::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UBnBuoyancy, CurrentTemp);
}

void UBnBuoyancy::TimerTick_Implementation()
{
	const float NewTemp = CurrentTemp - COOLDOWN_RATE;

	if(NewTemp >= MIN_TEMP)
	{
		CurrentTemp = NewTemp;
	}
}

void UBnBuoyancy::Burn_Implementation(const float BurnTemp)
{
	const float NewTemp = CurrentTemp + BurnTemp;

	if(NewTemp <= MAX_TEMP)
	{
		CurrentTemp = NewTemp;
	}
}

bool UBnBuoyancy::Burn_Validate(float BurnTemp)
{
	return true;
}

