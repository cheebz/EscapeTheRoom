// Copyright Craig O'Donnell 2017

#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPETHEROOM_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:
    // Player grab distance
    UPROPERTY(EditAnywhere)
    float Reach = 300.f;
		
	// Physics Handle
    UPhysicsHandleComponent* PhysicsHandle = nullptr;
    
    // Input Handle
    UInputComponent* InputComponent = nullptr;
    
    // Get physics handle of Actor owning Grabber
    void GetPhysicsHandle();
    
    // Setup input component
    void SetInputComponent();
    
    // Ray-cast and Grab what is in Reach
    void Grab();
    
    // Release what it being held
    void Release();
    
    const FHitResult GetFirstPhysicsBodyInReach();
};
