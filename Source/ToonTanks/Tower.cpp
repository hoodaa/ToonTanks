// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

void ATower::BeginPlay() 
{
	Super::BeginPlay();
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this,0));
	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATower::CheckFireCondition,FireRate,true);
}
void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
		
		if (InFireRange())
		{
			RotateTurret(Tank->GetActorLocation());
		}
		//Find The Distance to the tank
		//Check to see if the tank in range 
		//If in range,Rotate turret toward tank

}
void ATower::CheckFireCondition()
{
	if (Tank == nullptr)
	{
		return;
	}
	if (InFireRange() && Tank->bAlive )
	{
		Fire();
	}
}

bool ATower::InFireRange()
{
	if (Tank)
	{
		float FireRangeDistance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
		if (FireRangeDistance <= FireRange)
		{
			return true;
		}
	}
	return false;
}
void ATower::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}