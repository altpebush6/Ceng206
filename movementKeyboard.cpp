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
};
