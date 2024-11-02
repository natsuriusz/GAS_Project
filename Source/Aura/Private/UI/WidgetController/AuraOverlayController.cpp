// Guided project nr 2


#include "UI/WidgetController/AuraOverlayController.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Animation/AnimAttributes.h"

void UAuraOverlayController::BroadcastInitialValues()
{
	
	const UAuraAttributeSet* AuraAttributes = CastChecked<UAuraAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(AuraAttributes->GetHealth());
	OnMaxMaxHealthChanged.Broadcast(AuraAttributes->GetMaxHealth());
	
	
}
