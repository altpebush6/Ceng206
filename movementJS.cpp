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
    AMyCharacter::~AMyCharacter()
    {
        try
        {
            cout << "Object is destroying" << WalkSpeed << RunSpeed << JumpHeight << endl:
        }
        catch (const std::exception& e)
        {
            UE_LOG(LogTemp, Error, TEXT("Hata: %s"), *FString(e.what()));
        }
    }
   void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
    {
        Super::SetupPlayerInputComponent(PlayerInputComponent);
     
        PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
        PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);

        // Koşma girişleri tanımlanır
        PlayerInputComponent->BindAction("Run", IE_Pressed, this, &AMyCharacter::StartRunning);
        PlayerInputComponent->BindAction("Run", IE_Released, this, &AMyCharacter::StopRunning);

        // Zıplama girişi tanımlanır
        PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter::Jump);
    }
