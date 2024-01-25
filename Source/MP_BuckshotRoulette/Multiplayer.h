// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Multiplayer.generated.h"

UCLASS()
class MP_BUCKSHOTROULETTE_API AMultiplayer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMultiplayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

UFUNCTION(BlueprintCallable)
    void CreateGameSession();

    UFUNCTION(BlueprintCallable)
    void JoinGameSession();

    //Callbacks
    void OnCreateSessionComplete(FName SessionName, bool bWasSuccess);
    void OnFindSessionComplete(bool bWasSuccessful);
    void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result); 

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	IOnlineSessionPtr OnlineSessionInterface; 

private:
	FOnCreateSessionCompleteDelegate CreateSessionCompleteDelegate;
    FOnFindSessionsCompleteDelegate FindSessionsCompleteDelegate;
    FOnJoinSessionCompleteDelegate JoinSessionCompleteDelegate;

    TSharedPtr<FOnlineSessionSearch> SessionSearch;
};
