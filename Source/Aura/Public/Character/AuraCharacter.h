// Guided project nr 2

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()
	AAuraCharacter();

public:
private:
protected:
	UPROPERTY(EditAnywhere)
	class USpringArmComponent* CameraBoom;
	UPROPERTY(EditAnywhere)
	class UCameraComponent* Cam;
	
};

