// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

AMyPlayerController::AMyPlayerController()
{
	UE_LOG(LogTemp, Warning, TEXT("AMyPlayerContoller Create!!"));
}

int AMyPlayerController::GetData()
{
	return data;
}

