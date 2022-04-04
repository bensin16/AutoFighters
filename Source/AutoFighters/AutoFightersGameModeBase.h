// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "AutoFightersGameModeBase.generated.h"

class AHexGridManager;
class AHexTile;
class AUnit;

/**
 * 
 */
UCLASS()
class AUTOFIGHTERS_API AAutoFightersGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	AHexGridManager* HexGridManager;

	UPROPERTY()
	int32 HexGridHeight;

	UPROPERTY()
	int32 HexGridWidth;

	UPROPERTY(EditAnywhere, Category = "GameModeBase|GridManager")
	TSubclassOf<AHexGridManager> HexGridManagerBP;

	UPROPERTY(EditAnywhere, Category = "GameModeBase|Unit")
	TSubclassOf<AUnit> UnitBP; 

	UPROPERTY(VisibleAnywhere)
	TArray<AUnit*> UnitsArray;

public:
	AAutoFightersGameModeBase();

	UFUNCTION()
	void SpawnHexGrid();

	UFUNCTION()
	void SpawnUnit(int32 x, int32 y);

protected:
	//virtual void StartPlay() override;
	UFUNCTION()
	virtual void BeginPlay() override;


};
