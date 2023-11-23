// Copyright Philip Choi


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h" 
#include "EnhancedInputComponent.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true; // Replication essential in multiplayer/ when an entity changes on the server that change that
						// took place on the server will replicate or be sent down to all clients connected to server
						// Replication is responding to data, updating on the server and sending that down to clients.
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext); // Check Validity 만약에 환경이 조성되지 않았다면 멈추게 한다.

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(AuraContext, 0);

	bShowMouseCursor = true; //마우스 커서 보이기
	DefaultMouseCursor = EMouseCursor::Default; 

	FInputModeGameAndUI InputModeData; //UI 작동
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock); // viewport에 마우스 커서를 Lock 하지 않는다.
	InputModeData.SetHideCursorDuringCapture(false); 
	SetInputMode(InputModeData); //위 기능을 사용하려면 추가해야한다.
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent(); //부모 클래스에 접근한느것

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent); //Enhanced Input Action에 바인딩 하려면 Input Component 를 Enhanced Input Component에 캐스팅해야한다.

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);

}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.Y);

	}

}
