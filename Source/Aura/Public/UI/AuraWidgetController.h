// Guided project nr 2

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AuraWidgetController.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class AURA_API UAuraWidgetController : public UObject
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(BlueprintReadWrite, Category = WidgetController)
	TObjectPtr<APlayerController> PlayerController;
	UPROPERTY(BlueprintReadWrite, Category = WidgetController)
	TObjectPtr<APlayerState> PlayerState;
	UPROPERTY(BlueprintReadWrite, Category = WidgetController)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(BlueprintReadWrite, Category = WidgetController)
	TObjectPtr<UAttributeSet> AttributeSet;
	

	
};
