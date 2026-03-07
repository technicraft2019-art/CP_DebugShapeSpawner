/** This Projects name is CP_DebugShapwSpawner.
This current file is DrawDebugShapeSpawner.h
This is the Parent Debug Spawning Class Header file. */

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DrawDebugShapeSpawner.generated.h"

class USceneComponent;
class UStaticMeshComponent;
class UMaterialInstanceDynamic;

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

	UPROPERTY(VisibleAnywhere, Category = "Debug")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, Category = "Debug")
	UStaticMeshComponent* PersistentSphere;

	UPROPERTY(EditAnywhere, Category = "Debug")
	bool bShowPersistentSphere = true;

	UPROPERTY(EditAnywhere, Category = "Debug", meta = (ClampMin = "0.01"))
	float SphereScale = 0.5f;

	UPROPERTY(EditAnywhere, Category = "Debug")
	FLinearColor SphereColor = FLinearColor::Green;
	
	UPROPERTY(EditAnywhere, Category = "Debug", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float SphereOpacity = 1.0f;

	UPROPERTY(Transient)
	UMaterialInstanceDynamic* SphereDynamicMaterial = nullptr;
};
