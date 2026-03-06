/** This Projects name is CP_DebugShapwSpawner.
This current file is DrawDebugShapeSpawner.cpp 
This is the Parent Debug Spawning Class Source file. */

#include "DrawDebugShapeSpawner.h"
#include "DrawDebugHelpers.h"

ADrawDebugShapeSpawner::ADrawDebugShapeSpawner()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ADrawDebugShapeSpawner::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	DrawTestSphere();
}

void ADrawDebugShapeSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	DrawTestSphere();
}

void ADrawDebugShapeSpawner::DrawTestSphere() const
{
	if (!GetWorld())
	{
		return;
	}

	DrawDebugSphere(GetWorld(),	GetActorLocation(),	50.0f, 16, FColor::Green, false, 10.0f,	0, 2.0f);
}
