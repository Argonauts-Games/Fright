// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Slingshot.generated.h"

UCLASS()
class TOPDOWN_API ASlingshot : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASlingshot();

protected:
	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USkeletalMeshComponent* MeshComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	FName MuzzleSocketName;

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

};
