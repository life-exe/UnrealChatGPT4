// All content created by ChatGPT4, Copyright LifeEXE. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CircleSpawner.generated.h"

UENUM(BlueprintType)
enum class ESpawnerType : uint8
{
    Circle,
    Spiral,
};

UCLASS()
class UNREALCHATGPT4_API ACircleSpawner : public AActor
{
    GENERATED_BODY()

public:
    ACircleSpawner();

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
    ESpawnerType Type{ESpawnerType::Circle};

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
    TSubclassOf<AActor> ActorToSpawn;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
    int32 NumberOfActors{100};

    // UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
    // FVector CircleCenter{FVector::ZeroVector};

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
    float CircleRadius{500.0f};

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
    float InitialRotationOffset{0.0f};

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (EditCondition = "Type == ESpawnerType::Spiral"))
    float VerticalSpacing{20.0f};

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (EditCondition = "Type == ESpawnerType::Spiral"))
    float DistanceBetweenLoops{20.0f};

protected:
    virtual void BeginPlay() override;

private:
    void SpawnActorsInCircle();
    void SpawnActorsInSpiral();
};
