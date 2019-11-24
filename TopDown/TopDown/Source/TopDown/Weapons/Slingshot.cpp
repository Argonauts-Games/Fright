// Fill out your copyright notice in the Description page of Project Settings.


#include "Slingshot.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
ASlingshot::ASlingshot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;

	MuzzleSocketName = "MuzzleSocket";

}

// Called when the game starts or when spawned
/*void ASlingshot::BeginPlay()
{
	Super::BeginPlay();
	
}*/

// Called every frame
/*(void ASlingshot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}*/

