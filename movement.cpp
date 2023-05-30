#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class YOURPROJECT_API ACharacter
{
    GENERATED_BODY()

public:
    ACharacter();

protected:
    virtual void BeginPlay() override;

    virtual void Tick(float DeltaTime) override;

    void MoveForward(float Value);

    void MoveRight(float Value);

    void StartRunning();

    void StopRunning();

    void Jump();

    void AutoCollectGhost();

private:
    UPROPERTY(EditDefaultsOnly, Category = "Movement")
        float WalkSpeed;

    UPROPERTY(EditDefaultsOnly, Category = "Movement")
        float RunSpeed;

    UPROPERTY(EditDefaultsOnly, Category = "Movement")
        float JumpHeight;

    bool bIsRunning;

    int32 GhostCount;
    const int32 WinningGhostCount;
};
