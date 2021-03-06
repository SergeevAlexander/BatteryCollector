// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE UStaticMeshComponent* GetMesh() const { return PickupMesh; }

	UFUNCTION(BlueprintPure, Category = "AAA")
	bool IsActive() const { return bIsActive; }

	UFUNCTION(BlueprintCallable, Category = "AAA")
	void SetIsActive(bool NewIsActive) { bIsActive = NewIsActive; }

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "AAA")
	void WasCollected();
	virtual void WasCollected_Implementation();

protected:

	bool bIsActive;

private:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AAA", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* PickupMesh ;
	
};
