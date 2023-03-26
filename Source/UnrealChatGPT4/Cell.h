// All content created by ChatGPT4, Copyright LifeEXE. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cell.generated.h"

UCLASS()
class UNREALCHATGPT4_API ACell : public AActor
{
    GENERATED_BODY()

public:
    ACell();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    class UStaticMeshComponent* CellMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game of Life")
    bool bIsAlive;

    UFUNCTION(BlueprintCallable, Category = "Game of Life")
    void SetAlive(bool bNewState);
};
