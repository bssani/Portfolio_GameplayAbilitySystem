// Copyright Philip Choi


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h" 

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
