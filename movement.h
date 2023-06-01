#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class MYPROJECT2_API AMyCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AMyCharacter();

protected:
    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
    virtual void Tick(float DeltaSeconds) override;

    // Speeds
    UPROPERTY(EditDefaultsOnly, Category = "Movement")
        float WalkSpeed;

    UPROPERTY(EditDefaultsOnly, Category = "Movement")
        float RunSpeed;

    UPROPERTY(EditDefaultsOnly, Category = "Movement")
        float JumpHeight;

    // Action and Axis Events
    void MoveForward(float Value);
    void MoveRight(float Value);
    void StartRunning();
    void StopRunning();
    void Jump();

    // Collect Ghost
    UFUNCTION(BlueprintCallable)
        void AutoCollectGhost();

private:
    bool bIsRunning;
    int32 GhostCount;
};
