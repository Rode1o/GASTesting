// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayTagContainer.h"
#include <GameplayEffectTypes.h>
#include "AbilitySystemInterface.h"
#include "RuneAtributeSet.h"
#include "InputActionValue.h"
#include "GASTestingCharacter.generated.h"


UCLASS(config=Game)
class AGASTestingCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, meta = (AllowPrivateAccess = "true"))
		class UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
		URuneAtributeSet* Attributes;
	/*

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;
	*/

public:
	AGASTestingCharacter();

	UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attributes")
		float MaxHealth = 100.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attributes")
		float MaxMana = 100.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attributes")
		float MaxStamina = 100.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attributes")
		int MaxStat = 99;

	

protected:

	/** Called for movement input */
	//void Move(const FInputActionValue& Value);

	/** Called for looking input */
	//void Look(const FInputActionValue& Value);
			

protected:
	// APawn interface
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	// called on server
	virtual void PossessedBy(AController* Newcontroller) override;
	// called on client
	virtual void OnRep_PlayerState() override;

	virtual void InitializeAttributes();
	virtual void GiveDefaultAbilites();



	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Abilities")
		TSubclassOf<class UGameplayEffect> DefaultAttributeEffect;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Abilities")
		TArray<TSubclassOf<class UGameplayAbility>> DefaultAbilities;

};

