// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HexGridManager.generated.h"

class AHexTile;

UCLASS()
class AUTOFIGHTERS_API AHexGridManager : public AActor
{
	GENERATED_BODY()
	
protected:
	TArray<TArray<AHexTile*>> HexGridArray;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Layout")
	int32 GridWidth;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Layout")
	int32 GridHeight;
	
	UPROPERTY(EditAnywhere, Category = "HexGrid|Layout")
	float TileHorizontalOffset;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Layout")
	float OddRowHorizontalOffset;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Layout")
	float TileVerticalOffset;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Setup")
	TSubclassOf<AHexTile> GrassHexTile;

public:	
	// Sets default values for this actor's properties
	AHexGridManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION()
	void SpawnHexGrid();

	UFUNCTION()
	void ClearHexGridArray();

	UFUNCTION()
	FVector GetTileLocation(int32 x, int32 y);

	UFUNCTION()
	AHexTile* GetTile(int32 x, int32 y);

	UFUNCTION()
	void Initialize(int32 x, int32 y);

	UFUNCTION()
	void CalculateOffsets();

	UFUNCTION()
	FIntPoint FindNearestUnit(FIntPoint startingLoc);

private:
	// find best practice for constants like this
	const int32 HexagonMeshHeight = 200;
	const int8 SpacingDistance = 5;
};
