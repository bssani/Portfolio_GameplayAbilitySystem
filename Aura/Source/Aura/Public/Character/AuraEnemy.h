// Copyright Philip Choi

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"
/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
	
	virtual void HighlightActor() override; // �߻�Ŭ������ �ν��Ͻ� ���� �� �� ���ٴ� �޽����̴�. �߻� Ŭ������ pure virtual function class
	virtual void UnHighlightActor() = override; // ��� �޴� ������ ���ǰ� �Ǿ� �־�� �ϴµ� ���� �Ǿ� ���� �ʱ� ������ ���� ������.
};
