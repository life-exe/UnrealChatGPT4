// All content created by ChatGPT4, Copyright LifeEXE. All Rights Reserved.

#include "Cell.h"
#include "Components/StaticMeshComponent.h"

ACell::ACell()
{
    PrimaryActorTick.bCanEverTick = false;

    CellMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CellMesh"));
    RootComponent = CellMesh;
}

void ACell::SetAlive(bool bNewState)
{
    bIsAlive = bNewState;
    CellMesh->SetVisibility(bIsAlive);
}
