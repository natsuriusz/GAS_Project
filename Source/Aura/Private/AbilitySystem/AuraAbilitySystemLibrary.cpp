// Guided project nr 2


#include "AbilitySystem/AuraAbilitySystemLibrary.h"

#include "AbilitySystemComponent.h"
#include "Game/AuraGameMode.h"
#include "UI/AuraHUD/AuraHUD.h"
#include "Player/AuraPlayerState.h"
#include "Kismet/GameplayStatics.h"
#include "UI/WidgetController/AuraWidgetController.h"

UAuraOverlayController* UAuraAbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AAuraHUD* AuraHUD = Cast<AAuraHUD>(PC->GetHUD()))
		{
			AAuraPlayerState* PS = PC->GetPlayerState<AAuraPlayerState>();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
			return AuraHUD->GetOverlayController(WidgetControllerParams);
		}
	}
	return nullptr;
}

UAttributeMenuWidgetController* UAuraAbilitySystemLibrary::GetAttributeMenuWidgetController(
	const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AAuraHUD* AuraHUD = Cast<AAuraHUD>(PC->GetHUD()))
		{
			AAuraPlayerState* PS = PC->GetPlayerState<AAuraPlayerState>();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
			return AuraHUD->GetAttributeMenuWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}

void UAuraAbilitySystemLibrary::InitializeDefaultAttributes(const UObject* WorldContextObject, ECharacterClass CharacterClass, float Level, UAbilitySystemComponent* ASC)
{
	AAuraGameMode* AuraGameMode = Cast<AAuraGameMode>(UGameplayStatics::GetGameMode(WorldContextObject));
	if (!AuraGameMode) return;

	AActor* AvatarActor = ASC->GetAvatarActor();
	
	FGameplayEffectContextHandle PrimaryACH = ASC->MakeEffectContext();
	PrimaryACH.AddSourceObject(AvatarActor);

	FGameplayEffectContextHandle SecondaryACH = ASC->MakeEffectContext();
	SecondaryACH.AddSourceObject(AvatarActor);
	
	FGameplayEffectContextHandle VitalACH = ASC->MakeEffectContext();
	VitalACH.AddSourceObject(AvatarActor);
	
	const FCharacterClassDefaultInfo DefaultInfo = AuraGameMode->CharacterClass->GetClassDefaultInfo(CharacterClass);
	
	const UCharacterClassInfo* CharacterClassInfo = AuraGameMode->CharacterClass;
	
	const FGameplayEffectSpecHandle PrimaryAttributesSpecHandle =  ASC->MakeOutgoingSpec(DefaultInfo.PrimaryAttributes, Level, PrimaryACH);
	ASC->ApplyGameplayEffectSpecToSelf(*PrimaryAttributesSpecHandle.Data.Get());

	const FGameplayEffectSpecHandle SecondaryAttributesSpecHandle =  ASC->MakeOutgoingSpec(CharacterClassInfo->SecondaryAttributes, Level, SecondaryACH);
	ASC->ApplyGameplayEffectSpecToSelf(*SecondaryAttributesSpecHandle.Data.Get());

	const FGameplayEffectSpecHandle VitalAttributesSpecHandle =  ASC->MakeOutgoingSpec(CharacterClassInfo->VitalAttributes, Level, VitalACH);
	ASC->ApplyGameplayEffectSpecToSelf(*VitalAttributesSpecHandle.Data.Get());
}
