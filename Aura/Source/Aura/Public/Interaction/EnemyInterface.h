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
	virtual void UnHighlightActor() = 0; // ���� ���� �Լ��� ������ ���� ������ ���߿� �����ϵ��� ���� �Լ�
};
