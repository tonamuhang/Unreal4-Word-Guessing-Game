// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    GameInit();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if(bGameOver)
    {
        ClearScreen();
        GameInit();
    }
    else
    {
        if(LivesRemain >= 0)
        {
            if(Input == HiddenWord)
            {
                PrintLine(TEXT("You have won"));
                GameEnd();
            }
            else
            {
                LivesRemain --;
                PrintLine(TEXT("Wrong guess"));
                PrintLine(TEXT("You have %i lives"), LivesRemain);
            }        
        }
        else
        {
            PrintLine(TEXT("You have lost"));
            GameEnd();
        }
        

    }
    
    
}

void UBullCowCartridge::GameInit()
{
    HiddenWord = TEXT("Pow");
    LivesRemain = 3;
    bGameOver = false;
    
    PrintLine(TEXT("Hello There!"));
    PrintLine(TEXT("You have %i lives"), LivesRemain);
    PrintLine(TEXT("Please enter a word"));
}

void UBullCowCartridge::GameEnd()
{
    bGameOver = true;
}