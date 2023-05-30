#include "CoreMinimal.h"
#include "Actor.h"

UCLASS()
class YOURPROJECT_API AMyGhostActor : public AActor
{
    GENERATED_BODY()

public:
    AMyGhostActor()
    {
        PrimaryActorTick.bCanEverTick = true;
    }

    virtual void BeginPlay() override
    {
        Super::BeginPlay();
        // In the beginning, we place the locations of the ghosts randomly.
        for (int32 i = 0; i < 13; ++i)
        {
            FVector Location(FMath::RandRange(-1000.f, 1000.f), FMath::RandRange(-1000.f, 1000.f), 0.f);
            FRotator Rotation(0.f, FMath::RandRange(0.f, 360.f), 0.f);
            GetWorld()->SpawnActor<AMyGhostActor>(GetClass(), Location, Rotation);
        }
    }
    virtual void Tick(float DeltaTime) override
    {
        Super::Tick(DeltaTime);

        // Here, we determine the movement of the ghosts.
        // For example, we can move the ghosts in different directions.
        // You can update the positions of the ghosts randomly.
        // We will update only the X and Y coordinates of the ghosts randomly.
        FVector Location = GetActorLocation();
        Location.X += FMath::RandRange(-100.f, 100.f) * DeltaTime;
        Location.Y += FMath::RandRange(-100.f, 100.f) * DeltaTime;
        SetActorLocation(Location);
    }
};
