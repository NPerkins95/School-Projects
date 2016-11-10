#include <iostream>
#include <string>
using namespace std;

int main() {
   string origTweet;
   string knownTweet[] = {"LOL","BFN","FTW","IRL","BFF","CYA","ILY","BTW","THX","GTG"};
   string knownFull[] = {"laugh out loud","for the win","in real life","best friend forever",
						 "see ya","i love you","by the way","thanks","got to go"};
   string test1;
   string test2; 
   int i = 0;
   
   cout << "Enter a tweet: ";
   cin >> origTweet;
   cout << endl;
   
   if (origTweet == "LOL") {
	  cout << "LOL = laughing out loud" << endl;
   }
   else if (origTweet == "BFN") {
	  cout << "BFN = bye for now" << endl;
   }
   else if (origTweet == "FTW") {
	  cout << "FTW = for the win" << endl;
   }
   else if (origTweet == "IRL") {
	  cout << "IRL = in real life" << endl;
   }
   else if (origTweet == "BFF") {
	  cout << "BFF = best friends forever" << endl;
   }
   else if (origTweet == "CYA") {
	  cout << "CYA = see ya" << endl;
   }
   else if (origTweet == "ILY") {
	  cout << "ILY = I love you" << endl;
   }
   else if (origTweet == "BTW") {
	  cout << "BTW = by the way" << endl;
   }
   else if (origTweet == "THX") {
	  cout << "THX = thanks" << endl;
   }
   else if (origTweet == "GTG") {
	  cout << "GTG = got to go" << endl;
   }
   else
   {
		test1 = origTweet.at(0) + origTweet.at(1) + origTweet.at(2);
   
		for(i = 0; i < 10 ; i++)
		{
			test2 = knownTweet[i].at(0) + knownTweet[i].at(1) + knownTweet[i].at(2);
	   
			if(test1 == test2)
			{
				cout << "Did you mean " << knownTweet[i] << "? " << knownFull[i];
				origTweet = knownTweet[i];
				break;
			}
		}
		if(test1 != test2)
		{
			cout << "Sorry, don't know that one." << endl;
		}
	}
   
   return 0;
}
