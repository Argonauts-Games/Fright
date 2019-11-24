// Fill out your copyright notice in the Description page of Project Settings.
#include "C:\Users\nevet\Documents\TopDown\TopDown\Source\TopDown\Public\PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components\InputComponent.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
	//Set size for player capsule component...
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	//Don't rotate character to camera direction...
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	//Handles turning of the character based on the movement being input by the user
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bAbsoluteRotation = true; //So the camera won't rotate when the character does.
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->RelativeRotation = FRotator(-60.f, 0.f, 0.f); //Sets the rotation angle that this will view the player at.
	CameraBoom->bDoCollisionTest = false; //Don't want to pull in the camera when it collides with the level

	// Create a camera
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));

	//Orthographic camera
	TopDownCameraComponent->SetProjectionMode(ECameraProjectionMode::Orthographic);

	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to the arm

}

void APlayerCharacter::MoveUp(float Value)
{

	AddMovementInput(TopDownCameraComponent->GetUpVector() * Value);
}

void APlayerCharacter::MoveRight(float Value)
{

	AddMovementInput(TopDownCameraComponent->GetRightVector() * Value);
}



void APlayerCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveUp);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
}

// Called when the game starts or when spawned
/*void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}*/

// Called every frame
/*void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}*/

// Called to bind functionality to input
/*void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}*/

