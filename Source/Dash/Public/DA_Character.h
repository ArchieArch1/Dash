// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Sound/SoundCue.h"
#include "DA_Character.generated.h"

UCLASS()
class DASH_API ADA_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADA_Character();

	UPROPERTY(EditAnywhere)
	float FMovementSpeed;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void Dash();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USoundCue* DashSoundCue;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAudioComponent* DashAudioComponent;
	
	UCharacterMovementComponent* CharacterMovement = GetCharacterMovement();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Force Variables")
	float DashForce = 500;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterMovementVariables")
	float DashAccelerationDifference = 1500;

	UPROPERTY(EditAnywhere)
	float DefaultFOV = 90.0f;

	UPROPERTY(EditAnywhere)
	float DashFOV = 130.0f;

	UPROPERTY(EditAnywhere)
	float DashLength = 0.5f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LerpTime = 0.1;

private:
	UPROPERTY()
	float CurrentTime = 0.0f;

	UPROPERTY()
	bool bCanLerp = false;

	UPROPERTY()
	bool bDashing = false;

	UPROPERTY()
	bool bLerpToDefault = false;
};
