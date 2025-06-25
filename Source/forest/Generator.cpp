// Fill out your copyright notice in the Description page of Project Settings.


#include "Generator.h"
#include "Landscape.h"

// Sets default values
AGenerator::AGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	HISM = CreateDefaultSubobject<UHierarchicalInstancedStaticMeshComponent>(TEXT("HISM"));
	HISM->SetupAttachment(RootComponent);
}

float AGenerator::GetLandscapeHeightAtLocation(int X, int Y)
{
	UWorld* World = GetWorld();
    // 从一个很高的位置开始向下射线
    FVector Start = FVector(X, Y, 10000.f);
    FVector End = FVector(X, Y, -10000.f);

    FHitResult HitResult;
    bool bHit = World->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility);

    if (bHit && HitResult.Actor.IsValid())
    {
        // 判断是否击中了Landscape
        if (HitResult.Actor->IsA(ALandscape::StaticClass()))
        {
            return HitResult.Location.Z;
        }
    }
	return 0.f;
}

// Called when the game starts or when spawned
void AGenerator::BeginPlay()
{
	Super::BeginPlay();

	//FSoftObjectPath CityActorBpPath(TEXT("Blueprint'/Game/tree/SM_Wood_plainTree02_Impostors.SM_Wood_plainTree02_Impostors_C'"));
	/* UStaticMesh* MyStaticMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/tree/SM_Wood_plainTree02_Impostors.SM_Wood_plainTree02_Impostors"));
	HISM->SetStaticMesh(MyStaticMesh); */

	for (int i = 0; i < Num; i++)
	{
		int X = (int)FMath::RandRange(-20000, 20000);
		int Y = (int)FMath::RandRange(-20000, 20000);
		int Z = GetLandscapeHeightAtLocation(X, Y);
		FTransform InstanceTransform(FVector(X, Y, Z));
		int32 InstanceIndex = HISM->AddInstance(InstanceTransform);
	}
}

// Called every frame
void AGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

