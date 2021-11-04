// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
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

	/*// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void MoveForward(float axisInput);

	UFUNCTION()
	void MoveRight(float axisInput);

	UFUNCTION()
	void ToggleSprint();

	UFUNCTION()
	void StartJump();

	UFUNCTION()
	void StopJump();

	UFUNCTION()
	void Dash();*/

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USoundCue* DashSoundCue;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAudioComponent* DashAudioComponent;
		
	UCharacterMovementComponent* CharacterMovement = GetCharacterMovement();
};
