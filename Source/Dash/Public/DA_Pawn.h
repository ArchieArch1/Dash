// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "DA_Pawn.generated.h"

UCLASS()
class DASH_API ADA_Pawn : public APawn
{
	GENERATED_BODY()

public:
	
	// Sets default values for this pawn's properties
	ADA_Pawn();

	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
