// Guided project nr 2

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "DamageTextComponent.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UDamageTextComponent : public UWidgetComponent
{
	GENERATED_BODY()
	public:

	UFUNTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetDamageText(float Damage);
};
