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
	
	virtual void HighlightActor() override; // 추상클래스를 인스턴스 생성 할 수 없다는 메시지이다. 추상 클래스란 pure virtual function class
	virtual void UnHighlightActor() = override; // 상속 받는 측에서 정의가 되어 있어야 하는데 정의 되어 있지 않기 때문에 나는 에러다.
};
