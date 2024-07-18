// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "CharacterTypes.h"
#include "Interfaces/PickupInterface.h"
#include "Interfaces/HitInterface.h"
#include "InputActionValue.h"
#include "SlashCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UGroomComponent;
class AItem;
class ASoul;
class ATreasure;
class UAnimMontage;
class USlashOverlay;
class UInputMappingContext;
class UInputAction;




UCLASS()
class SLASH_API ASlashCharacter : public ABaseCharacter, public IPickUpInterface, public IHitInterface
{
	GENERATED_BODY()

public:
	ASlashCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Jump() override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	virtual void GetHit_Implementation(const FVector& ImpactPoint, AActor* Hitter) override;
	void SetOverlappingItem(AItem* Item);
	void AddSouls(ASoul* Soul);
	void AddGold(ATreasure* Treasure);
	void Heal(AElixir* Elixir);
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* SlashContext;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* MovementAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* LookingAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* EquipAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* AttackAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* DodgeAction;

	/** Callbacks for input	*/
	void Move (const FInputActionValue& Value);
	void Look (const FInputActionValue& Value);
	void Dodge ();
	void EKeyPressed();
	virtual void Attack() override;

	/** Combat */
	void EquipWeapon(AWeapon* Weapon);
	virtual void AttackEnd() override;
	virtual void DodgeEnd() override;
	virtual bool CanAttack() override;
	bool CanDisarm();
	bool CanArm();
	void Disarm();
	void Arm();
	void PlayEquipMontage(const FName& SectionName);
	virtual int32 PlayAttackMontage() override;
	int32 PlayOneHandedAttackMontage();
	int32 PlayTwoHandedAttackMontage();
	virtual void StopAttackMontage() override;
	virtual void Die() override;
	bool HasEnoughStamina();
	bool IsOccupied();

	UFUNCTION(BlueprintCallable)
	void AttachWeaponToBack();

	UFUNCTION(BlueprintCallable)
	void AttachWeaponToHand();

	UFUNCTION(BlueprintCallable)
	void FinishEquipping();

	UFUNCTION(BlueprintCallable)
	void HitReactEnd();

	virtual void SetWeaponCollisionEnabled(ECollisionEnabled::Type CollisionEnabled) override;

	UPROPERTY(VisibleAnywhere, Category = Weapon)
	AWeapon* EquippedOneHandedWeapon;

	UPROPERTY(VisibleAnywhere, Category = Weapon)
	AWeapon* EquippedTwoHandedWeapon;

private:
	bool IsUnoccupied();
	
	void InitializeSlashOverlay();
	void SetHUDHealth();

	/** Character components */

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;

	UPROPERTY(VisibleAnywhere, Category = Hair)
	UGroomComponent* Hair;

	UPROPERTY(VisibleAnywhere, Category = Hair)
	UGroomComponent* Eyebrows;

	UPROPERTY(VisibleInstanceOnly)
	AItem* OverlappingItem;

	UPROPERTY(EditDefaultsOnly, Category = Montages)
	UAnimMontage* EquipMontage;

	UPROPERTY(EditDefaultsOnly, Category = Combat)
	UAnimMontage* OneHandedAttackMontage;

	UPROPERTY(EditDefaultsOnly, Category = Combat)
	UAnimMontage* TwoHandedAttackMontage;

	UPROPERTY(EditAnywhere, Category = Combat)
	TArray<FName> OneHandedAttackMontageSections;

	UPROPERTY(EditAnywhere, Category = Combat)
	TArray<FName> TwoHandedAttackMontageSections;

	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	EActionState ActionState = EActionState::EAS_Unoccupied;

	UPROPERTY()
	USlashOverlay* SlashOverlay;

public:
	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }
	FORCEINLINE EActionState GetActionState() const { return ActionState; }
};