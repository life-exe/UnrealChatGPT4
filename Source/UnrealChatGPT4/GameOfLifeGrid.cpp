// All content created by ChatGPT4, Copyright LifeEXE. All Rights Reserved.

#include "GameOfLifeGrid.h"
#include "Cell.h"

AGameOfLifeGrid::AGameOfLifeGrid()
{
    PrimaryActorTick.bCanEverTick = false;
    GridWidth = 10;
    GridHeight = 10;
    CellSize = 100.0f;
    TickInterval = 0.5f;
}

void AGameOfLifeGrid::BeginPlay()
{
    Super::BeginPlay();

    InitializeGrid();

    // Start ticking the game of life
    GetWorldTimerManager().SetTimer(GameOfLifeTimerHandle, this, &AGameOfLifeGrid::TickGameOfLife, TickInterval, true);
}

void AGameOfLifeGrid::InitializeGrid()
{
    for (int32 Y = 0; Y < GridHeight; Y++)
    {
        TArray<ACell*> Row;
        for (int32 X = 0; X < GridWidth; X++)
        {
            FVector SpawnLocation = FVector(X * CellSize, Y * CellSize, 0);
            ACell* Cell = GetWorld()->SpawnActor<ACell>(CellClass, SpawnLocation, FRotator::ZeroRotator);
            Cell->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
            Cell->SetAlive(FMath::RandBool());
            Row.Add(Cell);
        }
        Cells.Add(Row);
    }
}

void AGameOfLifeGrid::TickGameOfLife()
{
    TArray<TArray<bool>> NewGridState;
    for (int32 Y = 0; Y < GridHeight; Y++)
    {
        TArray<bool> NewRow;
        for (int32 X = 0; X < GridWidth; X++)
        {
            int32 AliveNeighbors = GetAliveNeighbors(X, Y);
            bool bIsAlive = Cells[Y][X]->bIsAlive;

            if (bIsAlive && (AliveNeighbors == 2 || AliveNeighbors == 3))
            {
                NewRow.Add(true);
            }
            else if (!bIsAlive && AliveNeighbors == 3)
            {
                NewRow.Add(true);
            }
            else
            {
                NewRow.Add(false);
            }
        }
        NewGridState.Add(NewRow);
    }

    // Update the grid state
    for (int32 Y = 0; Y < GridHeight; Y++)
    {
        for (int32 X = 0; X < GridWidth; X++)
        {
            Cells[Y][X]->SetAlive(NewGridState[Y][X]);
        }
    }
}

int32 AGameOfLifeGrid::GetAliveNeighbors(int32 X, int32 Y)
{
    int32 AliveNeighbors = 0;
    for (int32 NeighborY = Y - 1; NeighborY <= Y + 1; NeighborY++)
    {
        for (int32 NeighborX = X - 1; NeighborX <= X + 1; NeighborX++)
        {
            if ((NeighborX == X && NeighborY == Y) || NeighborX < 0 || NeighborY < 0 || NeighborX >= GridWidth || NeighborY >= GridHeight)
            {
                continue;
            }

            if (Cells[NeighborY][NeighborX]->bIsAlive)
            {
                AliveNeighbors++;
            }
        }
    }

    return AliveNeighbors;
}
