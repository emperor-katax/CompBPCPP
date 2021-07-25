// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/TargetPoint.h"
#include "CP_Magic_02.generated.h"

UCLASS()
class COMPCP_01_API ACP_Magic_02 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACP_Magic_02();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Magic Variables", meta = (ExposeOnSpawn = "true"))
		ATargetPoint* TargetPoint;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Magic Variables", meta = (ExposeOnSpawn = "true"))
		float Speed = 500.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector temp_01 = FVector(FVector::ZeroVector);
	float temp_02 = 0.f;

	bool Active = false;
	bool impact = false;
	FVector Target = FVector(FVector::ZeroVector);

	void Move();

};
