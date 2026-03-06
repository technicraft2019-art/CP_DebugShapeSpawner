/** This Projects name is CP_DebugShapwSpawner.
This current file is DrawDebugShapeSpawner.h
This is the Parent Debug Spawning Class Header file. */

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DrawDebugShapeSpawner.generated.h"

UCLASS()
class CP_DEBUGSHAPESPAWNER_API ADrawDebugShapeSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	ADrawDebugShapeSpawner();
	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	virtual void BeginPlay() override;

private:
	void DrawTestSphere() const;

};
