// pizza.cpp

#include "pizza.h"

// Sets default values
Apizza::Apizza()
{
	// Initialize components
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	// Attach SpringArm to Mesh, Camera to SpringArm
	RootComponent = Mesh;
	SpringArm->SetupAttachment(Mesh);
	Camera->SetupAttachment(SpringArm);

	// Set physics on moving mesh
	Mesh->SetSimulatePhysics(true);
	MovementForce = 100000;

 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Apizza::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Apizza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void Apizza::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAxis("MoveUp", this, &Apizza::MoveUp);
	PlayerInputComponent->BindAxis("MoveRight", this, &Apizza::MoveRight);

	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Movement Functions
void Apizza::MoveUp(float Value) {
	FVector ForceToAdd = FVector(1, 0, 0) * MovementForce * Value;
	Mesh->AddForce(ForceToAdd);
}

void Apizza::MoveRight(float Value) {
	FVector ForceToAdd = FVector(0, 1, 0) * MovementForce * Value;
	Mesh->AddForce(ForceToAdd);
}