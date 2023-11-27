// Copyright Philip Choi

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEnemyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class AURA_API IEnemyInterface
{
	GENERATED_BODY()


public:
	virtual void HighlightActor() = 0; //pure virtual function -> not provide a definition here in this class
	virtual void UnHighlightActor() = 0; // 순수 가상 함수는 선언은 지금 하지만 나중에 정의하도록 놔둔 함수
};
