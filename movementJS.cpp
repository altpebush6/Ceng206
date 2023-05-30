#include "movement.h"
class AMyCharacter : private ACharacter {
    AMyCharacter::AMyCharacter()
    {
        WalkSpeed = 300.0f;
        RunSpeed = 600.0f;
        JumpHeight = 500.0f;
        try
        {
            GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
        }
        catch (const std::exception& e)
        {
            UE_LOG(LogTemp, Error, TEXT("Hata: %s"), *FString(e.what()));
        }
        PrimaryActorTick.bCanEverTick = true;
        bIsRunning = false;
    }
   
