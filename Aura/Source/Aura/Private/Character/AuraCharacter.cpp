// Copyright Philip Choi


#include "Character/AuraCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

AAuraCharacter::AAuraCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true; //자동으로 캐릭터의 이동방향을 움직이는 방향에 맞춰주며, 회전보간을 해준다.
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true; //이동을 평면으로 제한하고
	GetCharacterMovement()->bSnapToPlaneAtStart = true; //시작할 때 캐릭터의 위치가 평면을 벗어난 상태라면 가까운 평면에 붙여서 시작하도록 한다./ 평면 - 네비게이션 메시

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}
