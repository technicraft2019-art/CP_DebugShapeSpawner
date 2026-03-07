/** This project's name is CP_DebugShapeSpawner.
This current file is DrawDebugShapeSpawner.cpp
This is the Parent Debug Spawning Class Source file. */

#include "DrawDebugShapeSpawner.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInterface.h"
#include "Materials/MaterialInstanceDynamic.h"

ADrawDebugShapeSpawner::ADrawDebugShapeSpawner()
{
	PrimaryActorTick.bCanEverTick = false;

	// Root
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	// Sphere component
	PersistentSphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PersistentSphere"));
	PersistentSphere->SetupAttachment(SceneRoot);

	// Load the built-in sphere mesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMesh(
		TEXT("/Engine/BasicShapes/Sphere.Sphere")
	);

	if (SphereMesh.Succeeded())
	{
		PersistentSphere->SetStaticMesh(SphereMesh.Object);
	}

	// Make it behave like a debug object
	PersistentSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	PersistentSphere->SetGenerateOverlapEvents(false);
	PersistentSphere->CastShadow = false;

	// Initial scale
	PersistentSphere->SetRelativeScale3D(FVector(0.5f));
}

void ADrawDebugShapeSpawner::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (!PersistentSphere)
	{
		return;
	}

	PersistentSphere->SetVisibility(bShowPersistentSphere);
	PersistentSphere->SetRelativeScale3D(FVector(SphereScale));
	
	// Create the dynamic material if it does not already exist
	if (!SphereDynamicMaterial)
	{
		UMaterialInterface* BaseMaterial = PersistentSphere->GetMaterial(0);

		if (BaseMaterial)
		{
			SphereDynamicMaterial = UMaterialInstanceDynamic::Create(BaseMaterial, this);

			if (SphereDynamicMaterial)
			{
				PersistentSphere->SetMaterial(0, SphereDynamicMaterial);
			}
		}
	}

	// Update the color parameter on the dynamic material
	if (SphereDynamicMaterial)
	{
		SphereDynamicMaterial->SetVectorParameterValue(TEXT("Color"), SphereColor);
		SphereDynamicMaterial->SetScalarParameterValue(TEXT("Opacity"), SphereOpacity);
	}
}

void ADrawDebugShapeSpawner::BeginPlay()
{
	Super::BeginPlay();
}