// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUtil.h"
#include "MyPawnMovementComponent.h"

void UMyPawnMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//LOG("hahaha...");
};

