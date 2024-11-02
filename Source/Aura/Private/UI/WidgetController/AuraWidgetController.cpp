// Guided project nr 2


#include "UI/WidgetController/AuraWidgetController.h"

void UAuraWidgetController::BroadcastInitialValues()
{
	
}

void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WidgetControllerParams)
{

	PlayerController = WidgetControllerParams.PlayerController;
	PlayerState = WidgetControllerParams.PlayerState;
	AbilitySystemComponent = WidgetControllerParams.AbilitySystemComponent;
	AttributeSet = WidgetControllerParams.AttributeSet;
	
}
