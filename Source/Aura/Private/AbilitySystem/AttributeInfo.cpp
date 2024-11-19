// Guided project nr 2


#include "AbilitySystem/AttributeInfo.h"

FAuraAttributeInfo UAttributeInfo::FindInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
	for (const FAuraAttributeInfo& Info : AttributeInfo)
	{
		
			if (Info.AttributeTag.MatchesTagExact(AttributeTag))
			{
				return Info;
			}
		
	}
	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find Info for AttributeTag [%s] on AttributeInfo [%s]."), *AttributeTag.ToString(),*GetNameSafe(this));

	}
	return FAuraAttributeInfo();
}
