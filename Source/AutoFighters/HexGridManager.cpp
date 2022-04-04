// Fill out your copyright notice in the Description page of Project Settings.


#include "HexGridManager.h"

#include "HexTile.h"

// Sets default values

AHexGridManager::AHexGridManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


	GridWidth = 5;
	GridHeight = 4;

	CalculateOffsets();

}

// Called when the game starts or when spawned
void AHexGridManager::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnHexGrid();

}

// code from: https://www.youtube.com/watch?v=viw8QLV-lJ8&t=1500s
void AHexGridManager::SpawnHexGrid()
{
	// make sure current grid gets wiped out
	ClearHexGridArray();

	HexGridArray.SetNumZeroed(GridWidth);
	for (int32 i = 0; i < HexGridArray.Num(); ++i)
	{
		HexGridArray[i].SetNumZeroed(GridHeight);
	}

	for (int32 y = 0; y < GridHeight; ++y)
	{
		for (int32 x = 0; x < GridWidth; ++x)
		{
			const bool oddRow = y % 2 == 1;
			const float xPos = oddRow ? (x * TileHorizontalOffset) + OddRowHorizontalOffset : x * TileHorizontalOffset;
			const float yPos = y * TileVerticalOffset;

			TSubclassOf<AHexTile> tileToSpawn = GrassHexTile;

			AHexTile* newTile = GetWorld()->SpawnActor<AHexTile>(tileToSpawn, FVector(FIntPoint(xPos, yPos)), FRotator::ZeroRotator);
			newTile->TileIndex = FIntPoint(x, y);
			newTile->SetActorLabel(FString::Printf(TEXT("Tile_%d-%d"), x, y)); //DEBUG ONLY
			newTile->SetTileManager(this);
			HexGridArray[x][y] = newTile;
		}
	}
}

void AHexGridManager::ClearHexGridArray()
{
	if (HexGridArray.Num() == 0) // already empty
		return;

	// i have no clue if this is necessary but we ball regardless
	for (int32 i = 0; i < HexGridArray.Num(); ++i)
	{
		HexGridArray[i].Empty();
	}
	HexGridArray.Empty();
}

FVector AHexGridManager::GetTileLocation(int32 x, int32 y)
{
	// i guess zerovector values if it fails for now. find some "invalid" vector to error check
	FVector tileLocation = FVector::ZeroVector;
	if (HexGridArray.IsValidIndex(x) && HexGridArray[x].IsValidIndex(y))
	{
		tileLocation = HexGridArray[x][y]->GetActorLocation();
	}
	return tileLocation;
}

AHexTile* AHexGridManager::GetTile(int32 x, int32 y)
{
	if (HexGridArray.IsValidIndex(x) && HexGridArray[x].IsValidIndex(y))
	{
		return HexGridArray[x][y];
	}
	return nullptr;
}

void AHexGridManager::Initialize(int32 Height, int32 Width)
{
	GridHeight = Height;
	GridWidth = Width;
	CalculateOffsets();
}

void AHexGridManager::CalculateOffsets()
{
	// you're gonna want this: https://www.redblobgames.com/grids/hexagons/#coordinates
	TileHorizontalOffset = sqrt(3.0f) * (HexagonMeshHeight / 2);
	OddRowHorizontalOffset = TileHorizontalOffset / 2;
	TileVerticalOffset = HexagonMeshHeight * 0.75;

	// add extra spacing offsets
	TileHorizontalOffset += SpacingDistance;
	TileVerticalOffset += SpacingDistance;
	OddRowHorizontalOffset += (SpacingDistance / 2);
}

FIntPoint AHexGridManager::FindNearestUnit(FIntPoint startingLoc)
{
	const FIntPoint DirectionVectors[6]  = {
		FIntPoint(1, 0), FIntPoint(1, -1), FIntPoint(0, -1),
		FIntPoint(-1, 0),FIntPoint(-1, 1), FIntPoint(0, 1),
	};

	return FIntPoint();
}
