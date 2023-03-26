// All content created by ChatGPT4, Copyright LifeEXE. All Rights Reserved.

#include "CircleSpawner.h"

ACircleSpawner::ACircleSpawner()
{
    PrimaryActorTick.bCanEverTick = false;
}

void ACircleSpawner::BeginPlay()
{
    Super::BeginPlay();

    switch (Type)
    {
        case ESpawnerType::Circle:  //
            SpawnActorsInCircle();
            break;

        case ESpawnerType::Spiral:  //
            SpawnActorsInSpiral();
            break;

        default:  //
            checkNoEntry();
            break;
    }
}

void ACircleSpawner::SpawnActorsInCircle()
{
    if (!ActorToSpawn || NumberOfActors <= 0)
    {
        return;
    }

    UWorld* World = GetWorld();
    if (!World)
    {
        return;
    }

    const float AngleBetweenActors = 360.0f / static_cast<float>(NumberOfActors);

    const FVector CircleCenter = GetActorLocation();

    for (int32 i = 0; i < NumberOfActors; ++i)
    {
        const float CurrentAngle = (InitialRotationOffset + AngleBetweenActors * i) * (PI / 180.0f);

        const FVector SpawnLocation = CircleCenter + CircleRadius * FVector(cosf(CurrentAngle), sinf(CurrentAngle), 0.0f);
        const FRotator SpawnRotation = FRotator(0.0f, CurrentAngle * (180.0f / PI), 0.0f);

        FActorSpawnParameters SpawnParameters;
        SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

        World->SpawnActor<AActor>(ActorToSpawn, SpawnLocation, SpawnRotation, SpawnParameters);
    }
}

void ACircleSpawner::SpawnActorsInSpiral()
{
    if (!ActorToSpawn || NumberOfActors <= 0)
    {
        return;
    }

    UWorld* World = GetWorld();
    if (!World)
    {
        return;
    }

    float AngleBetweenActors = 360.0f / static_cast<float>(NumberOfActors);

    const FVector CircleCenter = GetActorLocation();

    for (int32 i = 0; i < NumberOfActors; ++i)
    {
        const float CurrentAngle = (InitialRotationOffset + AngleBetweenActors * i) * (PI / 180.0f);

        float CurrentRadius = CircleRadius + (DistanceBetweenLoops * i / NumberOfActors);
        FVector SpawnLocation = CircleCenter + CurrentRadius * FVector(FMath::Cos(CurrentAngle), FMath::Sin(CurrentAngle), 0.0f);
        SpawnLocation.Z += i * VerticalSpacing;
        FRotator SpawnRotation = FRotator(0.0f, CurrentAngle * (180.0f / PI), 0.0f);

        FActorSpawnParameters SpawnParameters;
        SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

        World->SpawnActor<AActor>(ActorToSpawn, SpawnLocation, SpawnRotation, SpawnParameters);
    }
}