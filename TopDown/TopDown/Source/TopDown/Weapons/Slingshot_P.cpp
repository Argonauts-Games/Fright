// Fill out your copyright notice in the Description page of Project Settings.


#include "Slingshot_P.h"
#include "Components\SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ASlingshot_P::ASlingshot_P()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComp"));
	CollisionComp->InitSphereRadius(2.5f);
	CollisionComp->SetCollisionProfileName("Projectile");
	
	RootComponent = CollisionComp;


	ProjectileInitialSpeed = 3000.f;
	ProjectileMaxSpeed = 3000.f;

	ProjectileProperties = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileProperties"));
	ProjectileProperties->UpdatedComponent = CollisionComp;
	ProjectileProperties->InitialSpeed = ProjectileInitialSpeed;
	ProjectileProperties->MaxSpeed = ProjectileMaxSpeed;
	ProjectileProperties->bRotationFollowsVelocity = true;
	ProjectileProperties->bRotationRemainsVertical = true;


}

// Called when the game starts or when spawned
/*void ASlingshot_P::BeginPlay()
{
	Super::BeginPlay();
	
}*/

// Called every frame
/*void ASlingshot_P::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}*/

