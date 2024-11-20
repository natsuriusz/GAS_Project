// Guided project nr 2

#pragma once

class UAuraWidgetController;
struct FWidgetControllerParams;
class UAuraOverlayController;
class UAuraUserWidget;
class UAbilitySystemComponent;
class UAttributeSet;
class UAttributeMenuWidgetController;
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
	


	UAuraOverlayController* GetOverlayController(const FWidgetControllerParams WCParams);
	UAttributeMenuWidgetController* GetAttributeMenuWidgetController(const FWidgetControllerParams WCParams);

	void InitOverlay(APlayerController* PC, APlayerState* APS, UAbilitySystemComponent* ASC, UAttributeSet* ATS);

private:

	UPROPERTY()
	TObjectPtr<UAuraUserWidget> OverlayWidget;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UAuraOverlayController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraWidgetController> OverlayWidgetControllerClass;

	UPROPERTY()
	TObjectPtr<UAttributeMenuWidgetController> AttributeMenuWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAttributeMenuWidgetController> AttributeMenuWidgetControllerClass;
	
};
