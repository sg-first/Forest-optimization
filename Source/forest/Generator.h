// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "Generator.generated.h"

UCLASS()
class FOREST_API AGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGenerator();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UHierarchicalInstancedStaticMeshComponent* HISM;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	float GetLandscapeHeightAtLocation(int X, int Y);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
