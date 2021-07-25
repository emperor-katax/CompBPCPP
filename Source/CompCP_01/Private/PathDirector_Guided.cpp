// Fill out your copyright notice in the Description page of Project Settings.


#include "PathDirector_Guided.h"

// Sets default values for this component's properties
UPathDirector_Guided::UPathDirector_Guided()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPathDirector_Guided::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPathDirector_Guided::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	temp_02 = Speed * DeltaTime;
	if (Active) {
		Target = TargetPoint->GetActorLocation();
		Move();
	}
	if (impact)	OnImpact.Broadcast();
}

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

void UPathDirector_Guided::Move()
{
	temp_01 = this->GetOwner()->GetRootComponent()->GetComponentLocation();
	this->GetOwner()->GetRootComponent()->SetWorldRotation(FRotationMatrix::MakeFromX(Target - temp_01).Rotator());
	temp_01 += (temp_02 * (Target - temp_01).GetSafeNormal());
	if ((FVector::Distance(Target, temp_01)) <= temp_02) {
		temp_01 = Target;
		impact = true;
	}
	this->GetOwner()->GetRootComponent()->SetWorldLocation(temp_01);
}

void UPathDirector_Guided::SetupValues(ATargetPoint* target_Point, float move_Speed) {

	if (target_Point != NULL) {
		TargetPoint = target_Point;
		Target = target_Point->GetActorLocation();
		Speed = move_Speed;
		//UE_LOG(LogTemp, Warning, TEXT("----------------------I just started running"));
		//UE_LOG(LogTemp, Error, TEXT("--- traget location: %s"), *TargetPlus.ToString());
		Active = true;
	}

}

