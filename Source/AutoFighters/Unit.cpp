// Fill out your copyright notice in the Description page of Project Settings.


#include "Unit.h"

#include "Components/BoxComponent.h"


// Sets default values
AUnit::AUnit()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// set up root component and mesh component
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	UnitMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("UnitMesh"));
	UnitMesh->OnClicked.AddDynamic(this, &AUnit::OnClick);
	UnitMesh->SetupAttachment(RootComponent);

	// assuming idle is the starting state
	CurrentState = EUnitState::IDLE;

}

// Called when the game starts or when spawned
void AUnit::BeginPlay()
{
	Super::BeginPlay();
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("unit begin play"));
}

//https://forums.unrealengine.com/t/onclicked-adddynamic-this-function-error/384223/2
//to understand params
void AUnit::OnClick(UPrimitiveComponent* ClickedComp, FKey ButtonPressed)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("unit begin play"));
}

// Called every frame
void AUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	switch (CurrentState)
	{
	case EUnitState::IDLE:
		break;
	case EUnitState::INVALID:
	default:
		break;

	}
}
