// Fill out your copyright notice in the Description page of Project Settings.


#include "MousePlayerController.h"

AMousePlayerController::AMousePlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
}

void AMousePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//InputComponent->BindAction("LeftMouse", IE_Pressed, this, &AMousePlayerController::LeftMouseDown);
	//InputComponent->BindAction("LeftMouse", IE_Released, this, &AMousePlayerController::LeftMouseUp);
}

void AMousePlayerController::LeftMouseDown()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("LMBDown"));
}

void AMousePlayerController::LeftMouseUp()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("LMBUp"));
}