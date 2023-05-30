/ Ghost size
int32 GhostCount = 0;
const int32 WinningGhostCount = 7;

// Automatically collecting nearby ghosts by your character.
void AMyCharacter::AutoCollectGhost()
{
    //Accuracy check is performed to detect nearby ghosts.
    TArray<AActor*> OverlappingActors;
    GetOverlappingActors(OverlappingActors, AGhostPickup::StaticClass());

    // Automatically collect nearby ghosts and increase the ghost count.
    for (AActor* Actor : OverlappingActors)
    {
        AGhostPickup* GhostPickup = Cast<AGhostPickup>(Actor);
        if (GhostPickup && !GhostPickup->IsPendingKill())
        {
            GhostCount++;
            GhostPickup->Collect();
        }
        if (GhostCount == WinningGhostCount)
        {
            UE_LOG(LogTemp, Warning, TEXT("winner!" + actor));
        }
    }
}
