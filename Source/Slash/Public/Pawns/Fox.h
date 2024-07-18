// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "Fox.generated.h"

class UBoxComponent;
class USkeletalMeshComponent;
//class UCameraComponent;
//class USpringArmComponent;
//class UInputMappingContext;
//class UInputAction;

UCLASS()
class SLASH_API AFox : public APawn
{
	GENERATED_BODY()

public:
	AFox();
	// virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	// virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

	/* UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* FoxMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* LookAction;

	void Move(const FInputActionValue& Value); 
	void Look(const FInputActionValue& Value); */

private:
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxCollision;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* FoxMesh;

	//UPROPERTY(VisibleAnywhere)
	//USpringArmComponent* CameraBoom;

//	UPROPERTY(VisibleAnywhere)
	// UCameraComponent* ViewCamera;
};