// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MousePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class AUTOFIGHTERS_API AMousePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMousePlayerController();

public:
	// Called to bind functionality to input
	virtual void SetupInputComponent() override;
	void LeftMouseDown();
	void LeftMouseUp();
};
