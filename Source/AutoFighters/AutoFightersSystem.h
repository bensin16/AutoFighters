// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * game system manger
 * controls entire game logic and stuff
 */
class AUTOFIGHTERS_API AutoFightersSystem
{
public:
	AutoFightersSystem();
	~AutoFightersSystem();


private:
	void InitalizeGame();
};
