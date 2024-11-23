// Guided project nr 2

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTags.h"
#include "AuraInputConfig.generated.h"

USTRUCT(Blueprintable)
struct FAuraInputAction
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly)
	const class UInputAction* InputAction = nullptr;

	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag = FGameplayTag();

	
};
/**
 * 
 */
UCLASS()
class AURA_API UAuraInputConfig : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "InputActions")
	TArray<FAuraInputAction> InputActions;
	
	const UInputAction* FindAbilityInputAction(const FGameplayTag& InputTag, bool bLogNotFound = false) const;
};
