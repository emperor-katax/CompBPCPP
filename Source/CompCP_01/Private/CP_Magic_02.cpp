// Fill out your copyright notice in the Description page of Project Settings.


#include "CP_Magic_02.h"

// Sets default values
ACP_Magic_02::ACP_Magic_02()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACP_Magic_02::BeginPlay()
{
	Super::BeginPlay();

	if (TargetPoint != NULL) Active = true;
	
}

// Called every frame
void ACP_Magic_02::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	temp_02 = Speed * DeltaTime;
	if (Active) {
		Target = TargetPoint->GetActorLocation();
		Move();
	}
	if (impact)	this->Destroy();

}

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

void ACP_Magic_02::Move()
{
	temp_01 = GetActorLocation();
	SetActorRotation(FRotationMatrix::MakeFromX(Target - temp_01).Rotator());
	temp_01 += (temp_02 * (Target - temp_01).GetSafeNormal());
	if ((FVector::Distance(Target, temp_01)) <= temp_02) {
		temp_01 = Target;
		impact = true;
	}
	SetActorLocation(temp_01);
}


//https://unrealcpp.com/debug-logging/
//https://docs.unrealengine.com/en-US/PythonAPI/class/Vector.html
//https://www.unrealengine.com/en-US/blog/ranged-based-for-loops


