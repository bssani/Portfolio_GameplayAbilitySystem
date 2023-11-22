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

	//SkeletalMesh Component pointer 대신 TObjectPtr 사용
	//패키지 파일에서는 같으나, 에디터에서 추가 기능이 있다. 
	// Access Tracking and Optional Lazy Load Behavior
	// Access Tracking - 얼마나 자주 포인터가 참조되거나 역참조되는지 트래킹할 수 있다.
	// Lazy Loading - 에셋이 프로그램에 필요하거나 사용되기 전에는 로드 되지 않는다.
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;


};
