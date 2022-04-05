// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HexTile.generated.h"

class AHexGridManager;
class AUnit;
class UStaticMeshComponent;

/*
uncomment this if you want tile types or something

UENUM()
enum class EHexTileType : uint8
{
	INVALID,
	GRASS,
	WATER,
	MAX UMETA(Hidden)
};
*/

UCLASS()
class AUTOFIGHTERS_API AHexTile : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleInstanceOnly, Category = "Tile")
	FIntPoint TileIndex;
	
protected:
	/*
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tile")
	EHexTileType TileType;
	*/

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tile")
	UStaticMeshComponent* TileMesh;

	UPROPERTY()
	AHexGridManager* GridManager;

public:	
	// Sets default values for this actor's properties
	AHexTile();

	UFUNCTION()
	void SetTileManager(AHexGridManager* tm) { GridManager = tm; }

	UFUNCTION()
	FIntPoint FindNearestUnit();

protected:
	UFUNCTION()
	void OnClick(AActor* TouchedActor, FKey ButtonPressed);

	virtual void BeginPlay() override;
};
