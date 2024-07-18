// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/Fox.h"
#include "Components/BoxComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include <EnhancedInputSubsystems.h>

class UEnhancedInputComponent;

AFox::AFox()
{
	PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	SetRootComponent(BoxCollision);

	FoxMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FoxMesh"));
	FoxMesh->SetupAttachment(GetRootComponent());

	// CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("FoxMesh"));
	// CameraBoom->SetupAttachment(GetRootComponent());
	// CameraBoom->TargetArmLength = 300.f;

	// ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	// ViewCamera->SetupAttachment(CameraBoom);

	//AutoPossessPlayer = EAutoReceiveInput::Player1;
}

void AFox::BeginPlay()
{
	Super::BeginPlay();
	// APlayerController* PlayerController = Cast<APlayerController>(Controller);
	// if (PlayerController)
	// {
	//		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
	//		if (Subsystem)
	//		{
	//		Subsystem->AddMappingContext(FoxMappingContext, 0);
	//		}
	//	}
}

/*void AFox::Move(const FInputActionValue& Value)
{
	const float DirectionValue = Value.Get<float>();

	if (Controller && (DirectionValue != 0.f))
	{
		FVector Forward = GetActorForwardVector();
		AddMovementInput(Forward, DirectionValue);
	}
}

void AFox::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisValue = Value.Get<FVector2D>();
	if (GetController())
	{
		AddControllerYawInput(LookAxisValue.X);
		AddControllerPitchInput(LookAxisValue.Y);
	}
}

// void AFox::Tick(float DeltaTime)
// {
	// Super::Tick(DeltaTime);
// }

/*
void AFox::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	if (EnhancedInputComponent)
	{
		EnhancedInputComponent->BingAction(MoveAction, ETriggerEvent::Triggered, this, ABird::Move);
		EnhancedInputComponent->BingAction(LookAction, ETriggerEvent::Triggered, this, ABird::Look);
	}
}
*/

