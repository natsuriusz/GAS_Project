// Guided project nr 2


#include "Input/AuraInputConfig.h"

#include "SNegativeActionButton.h"

const UInputAction* UAuraInputConfig::FindAbilityInputAction(const FGameplayTag& InputTag, bool bLogNotFound) const
{
	for (auto Action : InputActions)
	{
		if (Action.InputAction && Action.InputTag.MatchesTagExact(InputTag))
		{
			return Action.InputAction;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("Tag Not Found"));

	return nullptr;
}
