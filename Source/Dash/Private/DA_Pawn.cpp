// Fill out your copyright notice in the Description page of Project Settings.


#include "DA_Pawn.h"

// Sets default values
ADA_Pawn::ADA_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADA_Pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADA_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADA_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

