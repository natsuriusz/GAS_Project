// Guided project nr 2

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Abilities/GameplayAbility.h"
#include "Interaction/CombatInterface.h"
#include "AuraCharacterBase.generated.h"


class UAbilitySystemComponent;
class UAttributeSet;
class UGameplayEffect;
class UAnimMontage;

UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface, public ICombatInterface
{
	GENERATED_BODY()

public:
	AAuraCharacterBase();

protected:
	virtual void BeginPlay() override;

public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual FVector GetCombatSocketLocation_Implementation(const FGameplayTag& MontageTag) override;

	virtual UAnimMontage* GetHitReactMontage_Implementation() override;	
	virtual void Die() override;	
	virtual bool IsDead_Implementation() const override;
	virtual AActor* GetAvatar_Implementation() override;
	/** end Combat Interface */
	
	FORCEINLINE UAttributeSet* GetAttributeSet() const {return AttributeSet;};

	UPROPERTY(EditAnywhere, Category = "Combat")
	TArray<FTaggedMontage> AttackMontages;
	
	virtual TArray<FTaggedMontage> GetCombatMontages_Implementation() override;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UGameplayEffect> DefaultPrimaryAttributes;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UGameplayEffect> DefaultSecondaryAttributes;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UGameplayEffect> DefaultVitalAttributes;
	
	
	void InitializePrimaryAttributes() const;
	void InitializeSecondaryAttributes() const;
	void InitializeVitalAttributes() const;

	
	UPROPERTY(EditAnywhere, Category = "Combat")
	FName WeaponTipSocketName;

	UPROPERTY(EditAnywhere, Category = "Combat")
	FName LeftHandSocketName;
	UPROPERTY(EditAnywhere, Category = "Combat")
	FName RightHandSocketName;

	bool bDead = false;


	UFUNCTION(NetMulticast, Reliable)
	virtual void MulticastHandleDeath();
	virtual void AddCharacterAbilities();
	void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const;
	virtual void InitializeDefaultAttributes() const;
	//Dissolve FX

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UMaterialInstance> Mesh_DissolveMaterialInstance;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UMaterialInstance> Weapon_DissolveMaterialInstance;

	UFUNCTION(BlueprintCallable)
	void Dissolve();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void StartDissolveTimeLine(UMaterialInstanceDynamic* MaterialInstanceDynamic);
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void StartWeaponDissolveTimeLine(UMaterialInstanceDynamic* MaterialInstanceDynamic);
	
private:
	virtual void InitAbilityActorInfo();

	UPROPERTY(EditAnywhere)
	TObjectPtr<UAnimMontage> HitReactMontage;
	
	UPROPERTY(EditAnywhere, Category = "Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;
};
