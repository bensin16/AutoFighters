// Fill out your copyright notice in the Description page of Project Settings.


#include "HexTile.h"

#include "HexGridManager.h"

#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AHexTile::AHexTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// set up root component and mesh component
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	TileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TileMesh"));
	TileMesh->SetupAttachment(RootComponent);

}

void AHexTile::BeginPlay()
{
	OnClicked.AddUniqueDynamic(this, &AHexTile::OnClick);
}

void AHexTile::OnClick(AActor* TouchedActor, FKey ButtonPressed)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("yo"));
}

FIntPoint AHexTile::FindNearestUnit()
{
	return GridManager->FindNearestUnit(TileIndex);
}
