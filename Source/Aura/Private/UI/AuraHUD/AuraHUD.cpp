// Guided project nr 2


#include "UI/AuraHUD/AuraHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/Widgets/AuraUserWidget.h"

void AAuraHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* AuraUserWidget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	AuraUserWidget->AddToViewport();
}
