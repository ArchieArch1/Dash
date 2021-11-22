// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DA_Character.h"
#include "Components/ActorComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/App.h"
#include "DA_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class DASH_API ADA_PlayerController : public APlayerController
{
	GENERATED_BODY()
public:

	UPROPERTY()
	ADA_Character* DACharacter = nullptr;

	//ADA_PlayerController();
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction);

	UPROPERTY(EditAnywhere)
	float FMovementSpeed = 500;

	UPROPERTY(EditAnywhere)
	float BaseLookRate = 90.0f;
	
	UPROPERTY(EditAnywhere)
	float BaseTurnRate = 90.0f;
	
	UFUNCTION()
	void MoveForward(float axisInput);

	UFUNCTION()
	void MoveRight(float axisInput);

	UFUNCTION()
	void Look(float axisInput);

	UFUNCTION()
	void Turn(float axisInput);
	
	UFUNCTION()
	void ToggleSprint();

	UFUNCTION()
	void StartJump();

	UFUNCTION()
	void StopJump();

	UFUNCTION()
	void Dash();
	
protected:

	virtual void BeginPlay() override;
	void SetupInputComponent() override;
	
};
