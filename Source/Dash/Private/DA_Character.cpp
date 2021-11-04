// Fill out your copyright notice in the Description page of Project Settings.


#include "DA_Character.h"
#include "Camera/CameraComponent.h"
#include "Components/AudioComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

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
	DashAudioComponent->bAutoActivate = true;
	DashAudioComponent->SetupAttachment(RootComponent);
}

// Called every frame
void ADA_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/*// Called to bind functionality to input
void ADA_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//Bind the axis which are set in Project Settings-> Engine-> Input.
	//BindAxis and Action functions bind a delegate function. The same as binding an event with a function from another object
	PlayerInputComponent->BindAxis("MoveForward", this, &ADA_Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ADA_Character::MoveRight);	

	//AddControllerYawInput & AddControllerYawPitch are methods inbuilt to the default Character class 
	PlayerInputComponent->BindAxis("Turn", this, &ADA_Character::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &ADA_Character::AddControllerPitchInput);

	// Set up action bindings
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ADA_Character::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ADA_Character::StopJump);
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ADA_Character::ToggleSprint);

	PlayerInputComponent->BindAction("Dash", IE_Pressed, this, &ADA_Character::Dash);

}*/

/*void ADA_Character::MoveForward(float AxisInput)
{
	//Set the maximum walk speed to be the movement speed which is exposed to the editor
	CharacterMovement->MaxWalkSpeed = FMovementSpeed;
	
	// Find out which way is "forward" and record that the player wants to move that way
	const FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, AxisInput);
}

void ADA_Character::MoveRight(float AxisInput)
{
	const FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, AxisInput);
}

void ADA_Character::StartJump()
{
	
}

void ADA_Character::StopJump()
{
	
}

void ADA_Character::ToggleSprint()
{
	
}

void ADA_Character::Dash()
{
	UE_LOG(LogTemp, Warning, TEXT("Dash"));

	const FVector Forward = GetActorForwardVector();
	CharacterMovement->AddImpulse(Forward * DashForce, true);

	CameraComponent->SetFieldOfView(120);
}*/










