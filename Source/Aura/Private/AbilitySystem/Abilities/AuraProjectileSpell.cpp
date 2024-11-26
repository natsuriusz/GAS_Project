// Guided project nr 2


#include "AbilitySystem/Abilities/AuraProjectileSpell.h"

#include "Actor/AuraProjectile.h"
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

		Projectile->FinishSpawning(SpawnTransform);
	}
}

void UAuraProjectileSpell::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                           const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                           const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	
}
