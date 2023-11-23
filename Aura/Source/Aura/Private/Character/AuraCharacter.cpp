// Copyright Philip Choi


#include "Character/AuraCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

AAuraCharacter::AAuraCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true; //�ڵ����� ĳ������ �̵������� �����̴� ���⿡ �����ָ�, ȸ�������� ���ش�.
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true; //�̵��� ������� �����ϰ�
	GetCharacterMovement()->bSnapToPlaneAtStart = true; //������ �� ĳ������ ��ġ�� ����� ��� ���¶�� ����� ��鿡 �ٿ��� �����ϵ��� �Ѵ�./ ��� - �׺���̼� �޽�

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}
