// Copyright Epic Games, Inc. All Rights Reserved.


#include "AutoFightersGameModeBase.h"

#include "HexGridManager.h" 
#include "HexTile.h"
#include "MousePlayerController.h"
#include "PlayerPawn.h"
#include "Unit.h"

AAutoFightersGameModeBase::AAutoFightersGameModeBase()
{
	HexGridHeight = 5;
	HexGridWidth = 5;

	DefaultPawnClass = APlayerPawn::StaticClass();
	PlayerControllerClass = AMousePlayerController::StaticClass();
}

void AAutoFightersGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	SpawnHexGrid();
	SpawnUnit(0, 1);
	SpawnUnit(3, 3);
}

void AAutoFightersGameModeBase::SpawnHexGrid()
{
	//https://forums.unrealengine.com/t/spawn-actor-with-dynamic-data/356847
	// doing it like this so i can pass data to things that are spawned
	const FTransform SpawnLocAndRotation;
	HexGridManager = GetWorld()->SpawnActorDeferred<AHexGridManager>(HexGridManagerBP, SpawnLocAndRotation);
	HexGridManager->Initialize(HexGridHeight, HexGridWidth);
	HexGridManager->FinishSpawning(SpawnLocAndRotation);
}

void AAutoFightersGameModeBase::SpawnUnit(int32 x, int32 y)
{
	FVector spawnLocation = HexGridManager->GetTileLocation(x, y);
	AHexTile* tileToSpawnOn = HexGridManager->GetTile(x, y);
	// this corrects the unit to spawn on top of the tiles
	spawnLocation.Z += 40;

	AUnit* spawnedUnit = GetWorld()->SpawnActor<AUnit>(UnitBP, spawnLocation, FRotator::ZeroRotator); 
	spawnedUnit->SetIndex(UnitsArray.Num());
	spawnedUnit->SetOccupyingTile(tileToSpawnOn);
	UnitsArray.Add(spawnedUnit);
}

