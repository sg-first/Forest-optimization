// Fill out your copyright notice in the Description page of Project Settings.


#include "Generator.h"

// Sets default values
AGenerator::AGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	HISM = CreateDefaultSubobject<UHierarchicalInstancedStaticMeshComponent>(TEXT("HISM"));
	HISM->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AGenerator::BeginPlay()
{
	Super::BeginPlay();

	//FSoftObjectPath CityActorBpPath(TEXT("Blueprint'/Game/tree/SM_Wood_plainTree02_Impostors.SM_Wood_plainTree02_Impostors_C'"));
	/* UStaticMesh* MyStaticMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/tree/SM_Wood_plainTree02_Impostors.SM_Wood_plainTree02_Impostors"));
	HISM->SetStaticMesh(MyStaticMesh); */

	for (int i = 0; i < 50000; i++)
	{
		int X = (int)FMath::RandRange(-20000, 20000);
		int Y = (int)FMath::RandRange(-20000, 20000);
		FTransform InstanceTransform(FVector(X, Y, 0));
		int32 InstanceIndex = HISM->AddInstance(InstanceTransform);
	}
}

// Called every frame
void AGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

