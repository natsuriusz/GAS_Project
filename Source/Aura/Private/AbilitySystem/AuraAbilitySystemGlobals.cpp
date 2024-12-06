// Guided project nr 2
#include "AbilitySystem/AuraAbilitySystemGlobals.h"
#include "AuraAbilityTypes.h"
FGameplayEffectContext* UAuraAbilitySystemGlobals::AllocGameplayEffectContext() const
{
	return new FAuraGameplayEffectContext();
}