// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values for current location, count of events, and total distance traveled
AMyActor::AMyActor() : currentLocation({ 0.f, 0.f }), eventCount(0), totalDist(0.f) {}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("BEGIN: Actor spawned at (0, 0).")); // Starting location
	for (int i = 0; i < 10; i++) move(); // Call move() 10 times
	UE_LOG(LogTemp, Warning, TEXT("END: Total distance traveled: %f / Total number of events: %d"), totalDist, eventCount);
}

void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyActor::move()
{
	FVector2D newLocation = { currentLocation.X + step(), currentLocation.Y + step() }; // new location = (x+step, y+step)
	
	float dist = distance(currentLocation, newLocation); // Distance traveled for this move
	totalDist += dist; // Accumulate distance traveled

	currentLocation = newLocation; // Update current location
	UE_LOG(LogTemp, Warning, TEXT("MOVE: Actor moved to location (%d, %d). Distance: %f."), (int) currentLocation.X, (int) currentLocation.Y, dist);
	
	if (FMath::FRand() >= 0.5) createEvent(); // Randomly create an event (probability 0.5)
}

int32_t AMyActor::step()
{
	return FMath::RandRange(0, 1);
}

float AMyActor::distance(FVector2D first, FVector2D second)
{
	return sqrt(pow(second.X - first.X, 2) + pow(second.Y - first.Y, 2));
}

void AMyActor::createEvent()
{
	UE_LOG(LogTemp, Warning, TEXT("EVENT: Random event occurred!!"));
	eventCount++;
}