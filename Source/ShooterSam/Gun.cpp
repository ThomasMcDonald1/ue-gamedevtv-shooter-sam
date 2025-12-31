// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Kismet/GameplayStatics.h"

#define PI 3.14159f

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Root"));
	SetRootComponent(SceneRoot);

	GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun Mesh"));
	GunMesh->SetupAttachment(SceneRoot);

	MuzzleFlashParticleSystem = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Muzzle Flash"));
	MuzzleFlashParticleSystem->SetupAttachment(GunMesh);
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	MuzzleFlashParticleSystem->Deactivate();

	//GetWorldTimerManager().SetTimer()
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGun::PullTrigger()
{
	MuzzleFlashParticleSystem->Activate(true);
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), ShootSound, GetActorLocation());

	//UE_LOG(LogTemp, Display, TEXT("PEW PEW"));
	if (OwnerController)
	{
		FVector ViewPointLocation;
		FRotator ViewPointRotation;
		OwnerController->GetPlayerViewPoint(ViewPointLocation, ViewPointRotation);
		//DrawDebugCamera(GetWorld(), ViewPointLocation, ViewPointRotation, 90.0f, 2.0f, FColor::Red, true);
		
		FVector EndLocation = ViewPointLocation + ViewPointRotation.Vector() * MaxRange;
		FHitResult HitResult;
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(this);
		Params.AddIgnoredActor(GetOwner());
		if (bool HasHit = GetWorld()->LineTraceSingleByChannel(HitResult, ViewPointLocation, EndLocation, ECC_GameTraceChannel2, Params))
		{
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), ImpactSound, HitResult.ImpactPoint);
			//DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 5.0f, 16, FColor::Purple, true);
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ImpactParticleSystem, HitResult.ImpactPoint, HitResult.ImpactPoint.Rotation());
			if (AActor* ActorHit = HitResult.GetActor())
			{
				UGameplayStatics::ApplyDamage(ActorHit, BulletDamage, OwnerController, this, UDamageType::StaticClass());
			}
		}

		
	}
}

