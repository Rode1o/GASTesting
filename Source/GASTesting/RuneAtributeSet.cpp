// Fill out your copyright notice in the Description page of Project Settings.


#include "RuneAtributeSet.h"
#include "Net/UnrealNetwork.h"


URuneAtributeSet::URuneAtributeSet()
{

}

void URuneAtributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAtributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAtributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAtributeSet, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAtributeSet, Strenght, COND_None, REPNOTIFY_Always);


	// Notify are useful to avoid override , ex: old health cant be current health;
}

void URuneAtributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAtributeSet, Health, OldHealth);
}

void URuneAtributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAtributeSet, Mana, OldMana);
}

void URuneAtributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAtributeSet, Stamina, OldStamina);
}

void URuneAtributeSet::OnRep_Strenght(const FGameplayAttributeData& OldStrenght)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAtributeSet, Strenght, OldStrenght);
}

