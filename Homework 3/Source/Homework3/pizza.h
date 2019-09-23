// pizza.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "pizza.generated.h"

UCLASS()
class HOMEWORK3_API Apizza : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	Apizza();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Movement Functions that are bound to axis mappings
	void MoveUp(float Value);		// Applies force on the X-axis
	void MoveRight(float Value);	// Applies force on the Y-axis

	// Public member variables
	// Static Mesh: Allows for selecting a mesh to represent the player
	// Spring Arm: Operates like a camera boom.
	// Camera: What the player sees.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCameraComponent* Camera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementForce;

};
