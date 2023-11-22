// Copyright Philip Choi

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AuraCharacterBase.generated.h"

UCLASS(Abstract) //prevent class from being able to be dragged into the level
class AURA_API AAuraCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AAuraCharacterBase();

protected:
	virtual void BeginPlay() override;

	//SkeletalMesh Component pointer ��� TObjectPtr ���
	//��Ű�� ���Ͽ����� ������, �����Ϳ��� �߰� ����� �ִ�. 
	// Access Tracking and Optional Lazy Load Behavior
	// Access Tracking - �󸶳� ���� �����Ͱ� �����ǰų� �������Ǵ��� Ʈ��ŷ�� �� �ִ�.
	// Lazy Loading - ������ ���α׷��� �ʿ��ϰų� ���Ǳ� ������ �ε� ���� �ʴ´�.
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;


};
