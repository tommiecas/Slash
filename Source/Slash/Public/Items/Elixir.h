// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Item.h"
#include "Elixir.generated.h"

/**
 * 
 */
UCLASS()
class SLASH_API AElixir : public AItem
{
	GENERATED_BODY()
	
protected:
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

private:
	UPROPERTY(EditAnywhere, Category = "Health Properties")
	int32 AmountToHeal;

public:
	FORCEINLINE int32 GetAmountToHeal() const { return AmountToHeal; }
	FORCEINLINE void SetAmountToHeal(int32 NumberOfElixirs) { AmountToHeal = NumberOfElixirs; }
};

