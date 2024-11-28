// Guided project nr 2

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AEnemyCharacter : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
	AEnemyCharacter();

public:
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual int32 GetPlayerLevel() override;
protected:
	virtual void BeginPlay() override;
	
	virtual void InitAbilityActorInfo() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level")
	int32 Level = 1;

	float Again = 0.f;
private:
	
};
