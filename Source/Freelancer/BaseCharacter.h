// Copyrighted by Binx Games.

#pragma once

#include "CoreMinimal.h"
#include "Possessable.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

struct FInputActionValue;

UCLASS()
class FREELANCER_API ABaseCharacter : public ACharacter, public IPossessable
{
	GENERATED_BODY()

	// Camera boom positioning the camera behind the character
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	// Follow camera 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	
	// MappingContext 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* MappingContext;

	// Jump Input Action 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	// Move Input Action 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	// Look Input Action 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

	// Use Input Action 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* UseAction;

	// Use Input Action 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* CameraZoomAction;

	// Use Trace Channel
	UPROPERTY(EditAnywhere, Category = "Use")
	TEnumAsByte<ECollisionChannel> TraceChannel;

public:
	// Sets default values for this character's properties
	ABaseCharacter(const FObjectInitializer& OI);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Returns CameraBoom subobject
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	// Returns FollowCamera subobject
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	// Called when pawn gets possessed
	virtual void OnPossess() override;

	// Called when pawn gets unpossessed
	virtual void OnUnPossess() override;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called for movement input
	void Move(const FInputActionValue& Value);

	// Called for looking input
	void Look(const FInputActionValue& Value);

	// Called for using input
	void UseObject();

	// Called for camera zoom input
	void ZoomCamera(const FInputActionValue& Value);
	

public:	
	// Camera Zoom Multiplier
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera Zoom")
	float CameraZoomMultiplier = 50.f;

	// Min Zoom
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera Zoom")
	float MinCameraZoom = 300.f;

	// Max Zoom
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera Zoom")
	float MaxCameraZoom = 700.f;

	// Use Trace Distance
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Use")
	float UseDistance = 500.f;

	
private:
	void SetupInput();
	void RemoveInput();

};
