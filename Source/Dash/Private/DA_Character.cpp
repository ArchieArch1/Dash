// Fill out your copyright notice in the Description page of Project Settings.


#include "DA_Character.h"
#include "Camera/CameraComponent.h"
#include "Components/AudioComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADA_Character::ADA_Character()
{
	//Define the camera and spring arm components
	//RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));

	//Attach the spring arm component to the root component
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->TargetArmLength = 3.0f;
	SpringArmComponent->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	//Attach the camera component to the spring arm component socket, which is at the end of the spring arm length
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = true;

	static ConstructorHelpers::FObjectFinder<USoundCue> DashCue(TEXT("SoundCue'/Game/Audio/DashFX_Cue.DashFX_Cue'"));
	DashSoundCue = DashCue.Object;

	DashAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("DashAudioComponent"));
	DashAudioComponent->SetupAttachment(RootComponent);
	DashAudioComponent->bAutoActivate = false;
	DashAudioComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

	if(DashSoundCue->IsValidLowLevelFast())
	{
		DashAudioComponent->SetSound(DashSoundCue);
	}
}

// Called every frame
void ADA_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Start lerping FOV for dash if bool is set to true
	if(bCanLerp)
	{
		if(CurrentTime < LerpTime)
		{
			CameraComponent->SetFieldOfView(FMath::Lerp(DefaultFOV, DashFOV, CurrentTime / LerpTime));
			CurrentTime += DeltaTime;

			//FOV lerp done, wait before lerping back to default
			if(CurrentTime >= LerpTime)
			{
				CurrentTime = 0.0f;
				bCanLerp = false;
				bDashing = true;
			}
		}
	}

	//Player is dashing, wait before lerping back to default
	if(bDashing)
	{
		if(CurrentTime < DashLength)
		{
			CurrentTime += DeltaTime;
		}

		if(CurrentTime >= DashLength)
		{
			CurrentTime = 0.0f;
			bDashing = false;
			bLerpToDefault = true;
		}
	}

	//Dash ended, lerp fov back to default
	if(bLerpToDefault)
	{
		if(CurrentTime < LerpTime)
		{
			CameraComponent->SetFieldOfView(FMath::Lerp(DashFOV, DefaultFOV, CurrentTime / LerpTime));
			CurrentTime += DeltaTime;
		}

		if(CurrentTime >= LerpTime)
		{
			CharacterMovement->MaxWalkSpeed -= DashForce;
			CharacterMovement->MaxAcceleration -= DashAccelerationDifference;
			bLerpToDefault = false;
			CurrentTime = 0.0f;
		}
	}

}

void ADA_Character::Dash()
{
	DashAudioComponent->Play();
	CharacterMovement->MaxWalkSpeed += DashForce;
	CharacterMovement->MaxAcceleration += DashAccelerationDifference;
	bCanLerp = true;
	
}








