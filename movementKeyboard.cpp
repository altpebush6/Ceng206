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
            
            UE_LOG(LogTemp, Error, TEXT("Error: %s"), *FString(e.what()));
        }
    }
    AMyCharacter::~AMyCharacter()
    {
        try
        {
            cout << "Object is destroying" << WalkSpeed << RunSpeed << JumpHeight << endl:
        }
        catch (const std::exception& e)
        {
            
            UE_LOG(LogTemp, Error, TEXT("Error: %s"), *FString(e.what()));
        }
    }
   inline void AMyCharacter::StartRunning()
    {
        try
        {
            bIsRunning = true;
        }
        catch (const std::exception& e)
        {
            
            UE_LOG(LogTemp, Error, TEXT("Error: %s"), *FString(e.what()));
        }
    }

    inline void AMyCharacter::StopRunning()
    {
        try
        {
            bIsRunning = false;
        }
        catch (const std::exception& e)
        {
            
            UE_LOG(LogTemp, Error, TEXT("Error: %s"), *FString(e.what()));
        }
    }
   
    inline void AMyCharacter::MoveForward(float Value)
    {
        try
        {
            FVector Forward = GetActorForwardVector();
            AddMovementInput(Forward, Value * (bIsRunning ? RunSpeed : WalkSpeed));
        }
        catch (const std::exception& e)
        {
            UE_LOG(LogTemp, Error, TEXT("Error: %s"), *FString(e.what()));
        }
    }
   
    inline void AMyCharacter::MoveRight(float Value)
    {
        try
        {
            FVector Right = GetActorRightVector();
            AddMovementInput(Right, Value * (bIsRunning ? RunSpeed : WalkSpeed));
        }
        catch (const std::exception& e)
        {
            UE_LOG(LogTemp, Error, TEXT("Error: %s"), *FString(e.what()));
        }
    }
   
    inline void AMyCharacter::Jump()
    {
        try
        {
            Super::Jump();
        }
        catch (const std::exception& e)
        {
            UE_LOG(LogTemp, Error, TEXT("Error: %s"), *FString(e.what()));
        }
    }
};
