// Guided project nr 2

#pragma once

class UAuraWidgetController;
struct FWidgetControllerParams;
class UAuraOverlayController;
class UAuraUserWidget;
class UAbilitySystemComponent;
class UAttributeSet;
#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()
public:
	
	UPROPERTY()
	TObjectPtr<UAuraUserWidget> OverlayWidget;

	UAuraOverlayController* GetOverlayController(const FWidgetControllerParams WCParams);

	void InitOverlay(APlayerController* PC, APlayerState* APS, UAbilitySystemComponent* ASC, UAttributeSet* ATS);

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UAuraOverlayController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraWidgetController> OverlayWidgetControllerClass;
};
