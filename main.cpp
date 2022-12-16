
 #include <vector>
 #include <cstring>
 #include <iostream>
 #include <map>
 #include <iterator>
 #include "room.h"
 using namespace std;

 int main() {

   room* lab = new room();
   lab->setName((char*)"1-20");
   lab->addItem((char*)"spider-mans dna");
   lab->setDescription((char*)"THE LABATORY");

   room* theater = new room();
   theater->setName((char*)"The OLD SHOW");
   theater->setName((char*)"script");
   theater->setDescription((char*)"THE THEATER IS OLD");

   lab->addExit("NORTH", theater);

   char followDirection[50];
   room* initialRoom = lab;
   bool trueFalse = true;
   vector<char*> inventory;

   while(trueFalse) {

   cout << "Hey player! You're in the " << initialRoom->getName() << endl;

   cout << "Let's see whats in here!: " << endl;
   for(vector<char*>::iterator run = initialRoom->getItems()->begin();run < initialRoom->getItems()->end();run++) {
     cout << (*run) << " ";
   }

   cout << initialRoom->getDescription() << endl;
   int coordinates = -1;

   for(vector<char*>::iterator run = initialRoom->getItems()->begin();run < initialRoom->getItems()->end();run++){


     coordinates++;
     char userInput[50];
     cout << "Do you want to insert this to your inventory?: " << (*run) << "y/n" << endl;
     cin >> userInput;
     if(strcmp(userInput, "y") == 0) {

       inventory.push_back((*run));
       initialRoom->getItems()->erase(run);
       break;
     } else if (strcmp(userInput, "n") == 0) {
       continue;
     } else {
       cout << "Please try again" << endl;
     }
     
   }

   if(inventory.size() == 5) {
     cout << "Items all picked up!" << endl;
     break;
   }

   if(inventory.size() > 0) {

     char remove[50];
     coordinates = -1;
     for(vector<char*>::iterator run = inventory.begin(); run != inventory.end(); run++) {

       coordinates++;
       cout << "Do you want to remove item from inventory? " << *run << "y/n" << endl;
       cin >> remove;
       if(strcmp(remove, "y") == 0) {

	 initialRoom->getItems()->push_back(*run);
	 inventory.erase(run);
	 break;
       }else if (strcmp(remove, "n") == 0) {

	 continue;
	 
       }else{
	 cout << "Invalid, please try again!" << endl;
       }
       
     }
     
   }

   cout << "Ways to go out: " << endl;
   for(map<const char*, room*>::iterator run = initialRoom->getMap()->begin();  run != initialRoom->getMap()->end(); run++) {

     cout <<run->first << ", " << run->second->getName() << endl;
     
   }

   cout << "to where shall we go?" << endl;
   cout << "one can quit as well if your tired from walking around" << endl;
   cin >> followDirection;

   for(map<const char*, room*>::iterator run = initialRoom->getMap()->begin(); run != initialRoom->getMap()->end(); run++) {

     if(strcmp(run->first, followDirection) ==0) {

       initialRoom = run->second;
       break;
     }
   }
   if(strcmp(followDirection, "quit") ==0) {

     trueFalse = false;
     
   }
  }
   return 0;
 }
  

