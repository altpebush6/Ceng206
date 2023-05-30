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
        PlayerInputComponent->BindAction("Run", IE_Pressed, this, &AMyCharacter::StartRunning);
        PlayerInputComponent->BindAction("Run", IE_Released, this, &AMyCharacter::StopRunning);
        PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter::Jump);
    }
    void AMyCharacter::MoveForward(float Value)
    {
        FVector Forward = GetActorForwardVector();
        AddMovementInput(Forward, Value * (bIsRunning ? RunSpeed : WalkSpeed));
    }

    void AMyCharacter::MoveRight(float Value)
    {
        FVector Right = GetActorRightVector();
        AddMovementInput(Right, Value * (bIsRunning ? RunSpeed : WalkSpeed));
    }

    void AMyCharacter::StartRunning()
    {
        bIsRunning = true;
    }

    void AMyCharacter::StopRunning()
    {
        bIsRunning = false;
    }

    void AMyCharacter::Jump()
    {
        Super::Jump();
    }
};
