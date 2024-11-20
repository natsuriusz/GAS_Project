// Guided project nr 2

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AuraWidgetController.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;


USTRUCT(BlueprintType)
struct FWidgetControllerParams
{
GENERATED_BODY()

FWidgetControllerParams() {}
FWidgetControllerParams(APlayerController* PC, APlayerState* APS, UAbilitySystemComponent* ASC, UAttributeSet* ATS) 
	: PlayerController(PC), PlayerState(APS), AbilitySystemComponent(ASC), AttributeSet(ATS) {}

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = WidgetController)
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = WidgetController)
	TObjectPtr<APlayerState> PlayerState = nullptr;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = WidgetController)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = WidgetController)
	TObjectPtr<UAttributeSet> AttributeSet = nullptr;

};

class UAttributeSet;
class UAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class AURA_API UAuraWidgetController : public UObject
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = WidgetController)
	virtual void BroadcastInitialValues();
	virtual void BindCallbacksToDependencies();
	UFUNCTION(BlueprintCallable, Category = WidgetController)
	void SetWidgetControllerParams(const FWidgetControllerParams& WidgetControllerParams);
	
protected:
	UPROPERTY(BlueprintReadWrite, Category = WidgetController)
	TObjectPtr<APlayerController> PlayerController;
	UPROPERTY(BlueprintReadWrite, Category = WidgetController)
	TObjectPtr<APlayerState> PlayerState;
	UPROPERTY(BlueprintReadWrite, Category = WidgetController)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(BlueprintReadWrite, Category = WidgetController)
	TObjectPtr<UAttributeSet> AttributeSet;
	

	
};
