// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();

	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s."), *(PlayerTank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AIController could not find player."));
	}
}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	else return Cast<ATank>(PlayerPawn);
}
