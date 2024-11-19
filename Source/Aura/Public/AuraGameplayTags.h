// Guided project nr 2

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * 
 */

struct FAuraGameplayTags
{
public:
 static const FAuraGameplayTags& Get() { return GameplayTags;}
 static void InitializeNativeGameplayTags();
protected:

private:
 static FAuraGameplayTags GameplayTags;
};