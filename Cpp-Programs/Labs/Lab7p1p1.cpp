#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{   
   int i = 0;         // Loop counter iterates numRolls times
   int numRolls = 0;  // User defined number of rolls
   int numTwos = 0;
   int numThrees = 0;
   int numFours = 0;
   int numFives = 0;
   int numSixes = 0;  // Tracks number of 6s found
   int numSevens = 0; // Tracks number of 7s found
   int numEights = 0;
   int numNines = 0;
   int numTens = 0;
   int numElevens = 0;
   int numTwelves = 0;
   int die1 = 0;      // Dice values
   int die2 = 0;      // Dice values
   int rollTotal = 0; // Sum of dice values
   
   cout << "Enter number of rolls: " << endl;
   cin >> numRolls;
   
   srand(time(0));
   
   if (numRolls >= 1) {
      // Roll dice numRoll times
      for (i = 0; i < numRolls; ++i) {
         die1 = rand() % 6 + 1;
         die2 = rand() % 6 + 1;
         rollTotal = die1 + die2;
         
         if (rollTotal == 2) {
			numTwos += 1;
		 }
		 else if (rollTotal == 3) {
            numThrees += 1;
         }
		 else if (rollTotal == 4) {
            numFours += 1;
         }
		 else if (rollTotal == 5) {
            numFives += 1;
         }
         else if (rollTotal == 6) {
            numSixes = numSixes + 1;
         }
         else if (rollTotal == 7) {
            numSevens = numSevens + 1;
         }
		 else if (rollTotal == 8) {
            numEights += 1;
         }
		 else if (rollTotal == 9) {
            numNines += 1;
         }
		 else if (rollTotal == 10) {
            numTens += 1;
         }
		 else if (rollTotal == 11) {
            numElevens += 1;
         }
		 else if (rollTotal == 12) {
            numTwelves += 1;
         }
		 
         cout << endl << "Roll " << (i + 1) << " is "
              << rollTotal << " (" << die1
              << "+" << die2 << ")";
      }
      
      // Print statistics on dice rolls
      cout << endl << endl;
      cout << "Dice roll statistics:" << endl;
	  cout << "2s: " << numTwos << endl;
	  cout << "3s: " << numThrees << endl;
	  cout << "4s: " << numFours << endl;
	  cout << "5s: " << numFives << endl;
      cout << "6s: " << numSixes << endl;
      cout << "7s: " << numSevens << endl;
	  cout << "8s: " << numEights << endl;
	  cout << "9s: " << numNines << endl;
	  cout << "10s: " << numTens << endl;
	  cout << "11s: " << numElevens << endl;
	  cout << "12s: " << numTwelves << endl;
   }
   else {
      cout << "Invalid rolls. Try again." << endl;
   }
   
   return 0;
}