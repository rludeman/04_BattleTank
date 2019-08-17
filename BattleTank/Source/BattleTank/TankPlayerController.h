// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Public/Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h" // Used for world trace features
#include "TankPlayerController.generated.h" // Must be the last include.

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	// Begins moving the barrel so a shot would hit 
	// where the crosshair intersects the world.
	void AimTowardCrosshair();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
};
