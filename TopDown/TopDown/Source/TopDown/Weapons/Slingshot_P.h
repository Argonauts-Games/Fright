// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Slingshot_P.generated.h"

UCLASS()
class TOPDOWN_API ASlingshot_P : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASlingshot_P();

protected:
	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Projectile")
	float ProjectileMaxSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWRite, Category = "Projectile")
	float ProjectileInitialSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Projectile")
	class USphereComponent* CollisionComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Projectile")
	USkeletalMeshComponent* MeshComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Projectile")
	class UProjectileMovementComponent* ProjectileProperties;

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

};
