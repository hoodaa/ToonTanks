// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	void HandleDestruction();
	
	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite)
		int32 VisibleAnywhereInt = 12;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		int32 VisibleDefaultsOnlyInt = 10;

	UPROPERTY(VisibleInstanceOnly)
		int32 VisibleInstanceOnlyInt = 11;

	UPROPERTY(EditDefaultsOnly)
		int32 EditDeafultsOnlyInt = 9;

	UPROPERTY(EditInstanceOnly)
		int32 EditInstanceOnlyInt = 14;


protected:
	void RotateTurret(FVector LookAtTarget);
	void Fire();


private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent * BaseMesh;
	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpwanPoint;
	
	UPROPERTY(EditDefaultsOnly, Category = "Combat");
	TSubclassOf<class AProjectile> ProjectileClass;

	UPROPERTY(EditAnyWhere, Category = "Combat")
		UParticleSystem* DeathParticles;
public:	

	// Called to bind functionality to input

};
