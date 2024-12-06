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
//Secondary
 FGameplayTag Attributes_Secondary_Armor;
 FGameplayTag Attributes_Secondary_ArmorPenetration;
 FGameplayTag Attributes_Secondary_BlockChance;
 FGameplayTag Attributes_Secondary_CriticalHitChance;
 FGameplayTag Attributes_Secondary_CriticalHitDamage;
 FGameplayTag Attributes_Secondary_CriticalHitResistance;
 FGameplayTag Attributes_Secondary_HealthRegeneration;
 FGameplayTag Attributes_Secondary_ManaRegeneration;
 FGameplayTag Attributes_Secondary_MaxHealth;
 FGameplayTag Attributes_Secondary_MaxMana;
 //Primary
 FGameplayTag Attributes_Primary_Intelligence;
 FGameplayTag Attributes_Primary_Resilience;
 FGameplayTag Attributes_Primary_Strength;
 FGameplayTag Attributes_Primary_Vigor;
 //Vital

 FGameplayTag Attributes_Vital_Mana;
 FGameplayTag Attributes_Vital_Health;
//Input Tags

 FGameplayTag InputTag_LMB;
 FGameplayTag InputTag_RMB;
 FGameplayTag InputTag_1;
 FGameplayTag InputTag_2;
 FGameplayTag InputTag_3;
 FGameplayTag InputTag_4;
// Resistance
 FGameplayTag Resistance_Fire;
 FGameplayTag Resistance_Lightning;
 FGameplayTag Resistance_Arcane;
 FGameplayTag Resistance_Physical;
 FGameplayTag Resistance_Water;
 FGameplayTag Resistance_Earth;
 //Damage Tag
 FGameplayTag Damage;
 FGameplayTag Damage_Fire;
 FGameplayTag Damage_Lightning;
 FGameplayTag Damage_Arcane;
 FGameplayTag Damage_Physical;
 FGameplayTag Damage_Water;
 FGameplayTag Damage_Earth;
 
 //HitReacts
FGameplayTag Effects_HitReact;

 TMap<FGameplayTag, FGameplayTag> DamageToResistances;

 TArray<FGameplayTag> DamageTypes;
protected:

private:
 static FAuraGameplayTags GameplayTags;
};