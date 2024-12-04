// Guided project nr 2


#include "AbilitySystem/Abilities/AuraProjectileSpell.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "Actor/AuraProjectile.h"
#include "AuraGameplayTags.h"
#include "Interaction/CombatInterface.h"

void UAuraProjectileSpell::SpawnProjectile(const FVector& ProjectileTargetLocation)
{
	const bool bIsServer =  GetAvatarActorFromActorInfo()->HasAuthority();

	if (!bIsServer) return;
	

	ICombatInterface* CombatInterface = Cast<ICombatInterface>(GetAvatarActorFromActorInfo());
	

	if (CombatInterface)
	{
		FTransform SpawnTransform;
		const FVector SocketLocation = CombatInterface->GetCombatSocketLocation();

		SpawnTransform.SetLocation(SocketLocation);
		FRotator ProjectileRotation = (ProjectileTargetLocation - SocketLocation).Rotation();
		ProjectileRotation.Pitch = 0.f;
		SpawnTransform.SetRotation(ProjectileRotation.Quaternion());
		
		AAuraProjectile* Projectile = GetWorld()->SpawnActorDeferred<AAuraProjectile>(ProjectileClass,
	SpawnTransform,
	GetOwningActorFromActorInfo(),
	Cast<APawn>(GetOwningActorFromActorInfo()),
	ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

		const UAbilitySystemComponent* SourceASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetAvatarActorFromActorInfo());
		const FGameplayEffectSpecHandle SpecHandle = SourceASC->MakeOutgoingSpec(DamageEffectClass, GetAbilityLevel(), SourceASC->MakeEffectContext());

		Projectile->DamageEffectSpecHandle = SpecHandle;
		FAuraGameplayTags GameplayTags = FAuraGameplayTags::Get();

		for (auto& Pair : DamageTypes)
		{
			const float AppliedDamage = Pair.Value.GetValueAtLevel(GetAbilityLevel());
			UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(SpecHandle, Pair.Key, AppliedDamage);
		}
		
		Projectile->FinishSpawning(SpawnTransform);
	}
}

void UAuraProjectileSpell::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                           const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                           const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	
}
