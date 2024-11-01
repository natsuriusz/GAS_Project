// Guided project nr 2

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

class AAuraPlayerState;
/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()
	AAuraCharacter();

public:
	virtual void Tick(float DeltaSeconds) override;

protected:
	virtual void BeginPlay() override;

public:
	virtual void OnRep_PlayerState() override;

	virtual void PossessedBy(AController* NewController) override;

private:
	void InitAbilityActorInfo();
protected:
	UPROPERTY(EditAnywhere)
	class USpringArmComponent* CameraBoom;
	UPROPERTY(EditAnywhere)
	class UCameraComponent* Cam;
};


