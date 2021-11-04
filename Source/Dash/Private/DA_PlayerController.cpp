// Fill out your copyright notice in the Description page of Project Settings.


#include "DA_PlayerController.h"
#include "DA_Character.h"
#include "Components/AudioComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"


/*ADA_PlayerController::ADA_PlayerController()
{
	PrimaryComponentTick.bCanEverTick = true;
}*/

void ADA_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	DACharacter = Cast<ADA_Character>(GetCharacter());
}

/*void ADA_Character::Tick(float DeltaTime)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}*/


void ADA_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	if(InputComponent)
	{
		
		
		//Bind the axis which are set in Project Settings-> Engine-> Input.
		//BindAxis and Action functions bind a delegate function. The same as binding an event with a function from another object
		InputComponent->BindAxis("MoveForward", this, &ADA_PlayerController::MoveForward);
		InputComponent->BindAxis("MoveRight", this, &ADA_PlayerController::MoveRight);	

		//AddControllerYawInput & AddControllerYawPitch are methods inbuilt to the default Character class 
		InputComponent->BindAxis("Turn", this, &ADA_PlayerController::Turn);
		InputComponent->BindAxis("LookUp", this, &ADA_PlayerController::Look);

		// Set up action bindings
		InputComponent->BindAction("Jump", IE_Pressed, this, &ADA_PlayerController::StartJump);
		InputComponent->BindAction("Jump", IE_Released, this, &ADA_PlayerController::StopJump);  
		InputComponent->BindAction("Sprint", IE_Pressed, this, &ADA_PlayerController::ToggleSprint);

		InputComponent->BindAction("Dash", IE_Pressed, this, &ADA_PlayerController::Dash);
	}
}

void ADA_PlayerController::MoveForward(float AxisInput)
{
	//Set the maximum walk speed to be the movement speed which is exposed to the editor
	DACharacter->CharacterMovement->MaxWalkSpeed = FMovementSpeed;
	
	// Find out which way is "forward" and record that the player wants to move that way
	FRotator const ControlSpaceRot = GetControlRotation();
	// transform to world space and add it
	DACharacter->AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::X), AxisInput);
}

void ADA_PlayerController::MoveRight(float axisInput)
{
	FRotator const ControlSpaceRot = GetControlRotation();
	// transform to world space and add it
	DACharacter->AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::Y), axisInput);
}

void ADA_PlayerController::Look(float axisInput)
{
	AddPitchInput(axisInput * BaseLookRate * GetWorld()->GetDeltaSeconds());
}

void ADA_PlayerController::Turn(float axisInput)
{
	AddYawInput(axisInput * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ADA_PlayerController::StartJump()
{
	
}

void ADA_PlayerController::StopJump()
{
	
}

void ADA_PlayerController::ToggleSprint()
{
	
}

void ADA_PlayerController::Dash()
{	
	const FVector Forward = GetPawn()->GetActorForwardVector();
	DACharacter->CharacterMovement->AddImpulse(Forward * DashForce, true);

	DACharacter->DashAudioComponent->Play();
	
	float LerpTime = 0.9f;
	float CurrentTime = 0.0f;
	float Delta = GetWorld()->GetDeltaSeconds();

	while (CurrentTime < LerpTime)
	{
		DACharacter->CameraComponent->SetFieldOfView(FMath::Lerp(DefaultFOV, DashFOV, CurrentTime / LerpTime));
		CurrentTime += Delta;
	}
}