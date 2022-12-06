// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "RuneAtributeSet.generated.h"


// Macros to avoid rewrite attributes
 #define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


UCLASS()
class GASTESTING_API URuneAtributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	URuneAtributeSet();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
		FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(URuneAtributeSet, Health);

	UFUNCTION()
		virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
		FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(URuneAtributeSet, Mana);

	UFUNCTION()
		virtual void OnRep_Mana(const FGameplayAttributeData& OldMana);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
		FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(URuneAtributeSet, Stamina);

	UFUNCTION()
		virtual void OnRep_Stamina(const FGameplayAttributeData& OldStamina);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
		FGameplayAttributeData Strenght;
	ATTRIBUTE_ACCESSORS(URuneAtributeSet, Strenght);

	UFUNCTION()
		virtual void OnRep_Strenght(const FGameplayAttributeData& OldStrenght);


	
};
