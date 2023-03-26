// All content created by ChatGPT4, Copyright LifeEXE. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameOfLifeGrid.generated.h"

UCLASS()
class UNREALCHATGPT4_API AGameOfLifeGrid : public AActor
{
    GENERATED_BODY()

public:
    AGameOfLifeGrid();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game of Life")
    TSubclassOf<class ACell> CellClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game of Life")
    int32 GridWidth;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game of Life")
    int32 GridHeight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game of Life")
    float CellSize;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game of Life")
    float TickInterval;

protected:
    virtual void BeginPlay() override;

private:
    TArray<TArray<ACell*>> Cells;

    FTimerHandle GameOfLifeTimerHandle;

    void InitializeGrid();
    void TickGameOfLife();
    int32 GetAliveNeighbors(int32 X, int32 Y);
};