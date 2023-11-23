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
	check(AuraContext); // Check Validity ���࿡ ȯ���� �������� �ʾҴٸ� ���߰� �Ѵ�.

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(AuraContext, 0);

	bShowMouseCursor = true; //���콺 Ŀ�� ���̱�
	DefaultMouseCursor = EMouseCursor::Default; 

	FInputModeGameAndUI InputModeData; //UI �۵�
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock); // viewport�� ���콺 Ŀ���� Lock ���� �ʴ´�.
	InputModeData.SetHideCursorDuringCapture(false); 
	SetInputMode(InputModeData); //�� ����� ����Ϸ��� �߰��ؾ��Ѵ�.
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent(); //�θ� Ŭ������ �����Ѵ���

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent); //Enhanced Input Action�� ���ε� �Ϸ��� Input Component �� Enhanced Input Component�� ĳ�����ؾ��Ѵ�.

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
