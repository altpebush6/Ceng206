// RandomMovementActor.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandomMovementActor.generated.h"

UCLASS()
class YOURPROJECT_API ARandomMovementActor : public AActor
{
    GENERATED_BODY()

public:
    ARandomMovementActor();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(EditAnywhere, Category = "Movement")
        float MaxSpeed;

    FVector CurrentVelocity;
};
