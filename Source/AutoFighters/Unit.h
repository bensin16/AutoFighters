// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Unit.generated.h"

class AHexTile;

UENUM()
enum class EUnitState : uint8
{
	INVALID,
	IDLE,
	MOVING,
	//MAX UMETA(Hidden) I dont understand this part yet
};

UCLASS()
class AUTOFIGHTERS_API AUnit : public AActor
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Unit")
	UStaticMeshComponent* UnitMesh;

	UPROPERTY()
	int32 Index;

	// tile this unit stands on. 
	UPROPERTY()
	AHexTile* OccupyingTile;

	UPROPERTY()
	EUnitState CurrentState;


public:	
	// Sets default values for this actor's properties
	AUnit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnClick(AActor* TouchedActor, FKey ButtonPressed);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetIndex(int32 index) { Index = index; }
	int32 GetIndex() const { return Index; }

	void SetOccupyingTile(AHexTile* ot) { OccupyingTile = ot; }

};
