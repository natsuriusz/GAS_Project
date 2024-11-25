// Guided project nr 2


#include "AbilitySystem/AbilityTasks/TargetDataUnderMouse.h"
#include "AbilitySystemComponent.h"

UTargetDataUnderMouse* UTargetDataUnderMouse::CreateTargetDataUnderMouse(UGameplayAbility* OwningAbility)
{
	UTargetDataUnderMouse* MyObj = NewAbilityTask<UTargetDataUnderMouse>(OwningAbility);
	return MyObj;
}

void UTargetDataUnderMouse::Activate()
{
	bool bIsLocallyController = Ability->GetCurrentActorInfo()->IsLocallyControlled();

	if (bIsLocallyController)
	{
		SendMouseData();
	}

	else
	{
		FGameplayAbilitySpecHandle SpecHandle = GetAbilitySpecHandle();
		FPredictionKey PredictionKey = GetActivationPredictionKey();
		AbilitySystemComponent.Get()->AbilityTargetDataSetDelegate(GetAbilitySpecHandle(), GetActivationPredictionKey()).AddUObject(this, &UTargetDataUnderMouse::OnTargetDataReplicationCallback);
		const bool bCalledDelegate = AbilitySystemComponent.Get()->CallReplicatedTargetDataDelegatesIfSet(SpecHandle, PredictionKey);

		if (!bCalledDelegate)
		{
			SetWaitingOnRemotePlayerData();
		}
	}
}
void UTargetDataUnderMouse::SendMouseData()
{
	FScopedPredictionWindow ScopedPredictionWindow(AbilitySystemComponent.Get());
	
	
	FGameplayAbilityTargetData_SingleTargetHit* Data = new FGameplayAbilityTargetData_SingleTargetHit();
			
	FHitResult CursorHit;
	Ability->GetCurrentActorInfo()->PlayerController.Get()->GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	Data->HitResult = CursorHit;
	FGameplayAbilityTargetDataHandle DataHandle;
	DataHandle.Add(Data);
	FGameplayTag AplicationTag;
	AbilitySystemComponent->ServerSetReplicatedTargetData(GetAbilitySpecHandle(), GetActivationPredictionKey(), DataHandle, AplicationTag, AbilitySystemComponent->ScopedPredictionKey);
	
	if (!ShouldBroadcastAbilityTaskDelegates()) return;
	ValidData.Broadcast(DataHandle);
}

void UTargetDataUnderMouse::OnTargetDataReplicationCallback(const FGameplayAbilityTargetDataHandle& DataHandle,
	FGameplayTag ActivationTag)
{
	AbilitySystemComponent->ConsumeClientReplicatedTargetData(GetAbilitySpecHandle(), GetActivationPredictionKey());
	if (ShouldBroadcastAbilityTaskDelegates())
	{
		ValidData.Broadcast(DataHandle);
	}
}
