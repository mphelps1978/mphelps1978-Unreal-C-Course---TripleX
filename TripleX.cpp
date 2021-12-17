#include <iostream>

void PrintIntroduction(int Difficulty)
{
  //Welcome message - print to terminal
  std::cout << "\n\nLEVEL " << Difficulty;
  std::cout << "\nWith the guards down, you breach the doors into the vault room. \n";
  std::cout << "In front of you stands a very large door, with a keypad combination lock. \n";
  std::cout << "You'll need to guess the combination before you can enter the vault. \n\n";
}

bool PlayGame(int Difficulty)
{
  PrintIntroduction(Difficulty);

  //Initialize our 3 codes
  const int CodeA = 2;
  const int CodeB = 3;
  const int CodeC = 4;

  //Prepare the "hints" for the codes
  const int CodeSum = CodeA + CodeB + CodeC;
  const int CodeProduct = CodeA * CodeB * CodeC;

  //Print out the hints to the terminal
  std::cout << "* There are 3 numbers in the combination: \n";
  std::cout << "* The codes add up to: " << CodeSum << "\n";
  std::cout << "* The codes multiply to give: " << CodeProduct << "\n";

  //Store players guesses from terminal entry
  int GuessA, GuessB, GuessC;

  // Prompt player to enter their guesses
  std::cout << "Enter the three numbers, separated by a space: ";
  std::cin >> GuessA >> GuessB >> GuessC;

  // Calculate the Sum and Product of the players guesses
  int GuessSum = GuessA + GuessB + GuessC;
  int GuessProduct = GuessA * GuessB * GuessC;

  // Check sum and product of guess against sum and product of code
  if (GuessSum == CodeSum && GuessProduct == CodeProduct)
  {
    // Win condition - print victory message to terminal
    std::cout << "A green light illuminates the room. \n";
    std::cout << "The vault doors open, revealing another layer of secure doors \n";
    return true;
    
  }
  else
  {
    // Lose condition - print failure message to terminal
    std::cout << "A buzzer sounds. You have entered the incorrect combination. \n";
    return false;
  }
}

int main()
{
  int LevelDifficulty = 1;
  const int MaxLevel = 5;

  while (LevelDifficulty <= MaxLevel) // Game Loop until all levels complete
  {
    bool bLevelComplete = PlayGame(LevelDifficulty);
    std::cin.clear();  // Clear errors from input
    std::cin.ignore(); // Discard input buffer
    
    if (bLevelComplete)
    {
      // Increase the level difficulty
      ++LevelDifficulty;
    }
    
  }
    std::cout << "A green light illuminates the room. \n";
    std::cout << "As the massive steel slab swings open, you are greeted by mountains of cash! \n";
    std::cout << "Congratulations! You have breached the vault! You make off with as much cash as you can carry. \n";
    return 0;
}
