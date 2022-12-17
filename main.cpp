
 #include <vector>
 #include <cstring>
 #include <iostream>
 #include <map>
 #include <iterator>
 #include "room.h"
 using namespace std;

 int main() {

   //Initializing all rooms below

   room* lab = new room();
   lab->setName((char*)"1-20");
   lab->addItem((char*)"spider-mans dna");
   lab->setDescription((char*)"THE ANCIENT LABATORY. Soon to have classes like AI!");
   room* theater = new room();
   theater->setName((char*)"Movie Theater");
   theater->addItem((char*)"script");
   theater->setDescription((char*)"The new Avatar will be premiering soon! Get your popcorn ready!");
   room* gym = new room();
   gym->setName((char*)"Gym");
   gym->setDescription((char*)"Lets get this workout going!");
   room* cafeteria = new room();
   cafeteria->setName((char*)"Cafeteria");
   cafeteria->addItem((char*)"spoon");
   cafeteria->setDescription((char*)"PROTEIIIN!!!");
   room* spa = new room();
   spa->setName((char*)"Spa");
   spa->setDescription((char*)"A relaxing sensation");
   room* library = new room();
   library->setName((char*)"Library");
   library->addItem((char*)"The Codex Leicester");
   library->setDescription((char*)"Seems like da vinci was here...");
   room* attic = new room();
   attic->setName((char*)"Attic");
   attic->setDescription((char*)"Uh its getting a little high up here...");
   room* cleaningroom = new room();
   cleaningroom->setName((char*)"Cleaning Room");
   cleaningroom->setDescription((char*)"Moppity boppity boop");
   room* history = new room();
   history->setName((char*)"History");
   history->setDescription((char*)"To what extent...");
   room* pool = new room();
   pool->setName((char*)"Pool");
   pool->addItem((char*)"Submarine");
   pool->setDescription((char*)"Why is there a metal surface under me?");
   room* artclass = new room();
   artclass->setName((char*)"Art class");
   artclass->addItem((char*)"Mona Lisa");
   artclass->setDescription((char*)"I smell da vinci somewhere...");
   room* shelter = new room();
   shelter->setName((char*)"Shelter");
   shelter->setDescription((char*)"Looks like we'll be safe from North Korea for a while...");
   room* pets = new room();
   pets->setName((char*)"Pets Room");
   pets->setDescription((char*)"WHO LET THE DOGS OUT! Who, who, who?");
   room* math = new room();
   math->setName((char*)"Math");
   math->setDescription((char*)"Women = Time * Money --> Time is also equal to Money --> Women = M^2 --> What is the root of all our problems? Its Money! So root of p = M! Then we square both sides so problem is equal to M^2. What is M^2 also equal to? Women. So Women = Problem?.... JK");
   room* museum = new room();
   museum->setName((char*)"Museum");
   museum->setDescription((char*)"The Rosetta Stone is somewhere near!");
   

   //Helps program to find where to go --> exits
   
   lab->addExit("NORTH", theater);
   lab->addExit("WEST", library);
   lab->addExit("SOUTH", gym);
   lab->addExit("EAST", artclass);

   gym->addExit("NORTH", lab);
   gym->addExit("EAST", pool);
   gym->addExit("SOUTH", cafeteria);
   gym->addExit("WEST", cleaningroom);

   cafeteria->addExit("NORTH", gym);
   cafeteria->addExit("EAST", history);
   cafeteria->addExit("WEST", spa);

   spa->addExit("NORTH", cleaningroom);
   spa->addExit("EAST", cafeteria);

   cleaningroom->addExit("NORTH", library);
   cleaningroom->addExit("SOUTH", spa);
   cleaningroom->addExit("EAST", gym);

   library->addExit("NORTH", attic);
   library->addExit("EAST", lab);
   library->addExit("SOUTH", cleaningroom);

   attic->addExit("EAST", theater);
   attic->addExit("SOUTH", library);

   theater->addExit("WEST", attic);
   theater->addExit("EAST", shelter);
   theater->addExit("SOUTH", lab);

   shelter->addExit("NORTH", pets);
   shelter->addExit("EAST", math);
   shelter->addExit("SOUTH", artclass);
   shelter->addExit("WEST", theater);

   pets->addExit("SOUTH", shelter);

   math->addExit("WEST", shelter);

   museum->addExit("NORTH", math);
   museum->addExit("WEST", artclass);

   artclass->addExit("NORTH", shelter);
   artclass->addExit("SOUTH", pool);
   artclass->addExit("WEST", lab);
   artclass->addExit("EAST", museum);

   pool->addExit("NORTH", artclass);
   pool->addExit("SOUTH", gym);
   pool->addExit("WEST", history);

   history->addExit("NORTH", pool);
   history->addExit("WEST", cafeteria);
   
   char theDirections[50];
   room* initialRoom = lab;
   bool trueFalse = true;
   vector<char*> inventory;

   //while loop allows user to keep playing if conidtions or quit hasnt been put in place

   while(trueFalse) {

   //Tells users where they are including printing name, description, and items

   cout << endl;
   cout << "Hey player! You're in the " << initialRoom->getName() << endl;
   cout << "Let's see whats in here!: " << endl;
   for(vector<char*>::iterator run = initialRoom->getItems()->begin();run < initialRoom->getItems()->end();run++) {
     cout << (*run) << " ";
   }
   cout << endl;
   cout << initialRoom->getDescription() << endl;
   int coordinates = -1;

   for(vector<char*>::iterator run = initialRoom->getItems()->begin();run < initialRoom->getItems()->end();run++){

     coordinates++;
     char userInput[50];
     cout << "Do you want to insert this to your inventory?: " << (*run) <<  endl;
     cout << "y or n" << endl;
     cin >> userInput;

     //Below if the user wants to insert, we put to their list and remove from room
     
     if(strcmp(userInput, "y") == 0) {

       inventory.push_back((*run));
       initialRoom->getItems()->erase(run);
       break;
     } else if (strcmp(userInput, "n") == 0) {
       continue;
     } else {
       cout << "Please try again. Quickly remove yourself from the room and go back." << endl;
     }
     
   }

   //If user picks up all 5 items the game is complete!

   if(inventory.size() == 5) {
     cout << "Items all picked up!" << endl;
     break;
   }

   if(inventory.size() > 0) {

     char remove[50];
     coordinates = -1;
     for(vector<char*>::iterator run = inventory.begin(); run != inventory.end(); run++) {

       coordinates++;
       cout << "Do you want to remove item from inventory? " << *run <<  endl;
       cout << "y or n" << endl;
       cin >> remove;

       //If user removes item from list, its removed and placed to the room they are in
       
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

   //Display to users where are the possible locations to go out

   cout << "Ways to go out: " << endl;
   for(map<const char*, room*>::iterator run = initialRoom->getMap()->begin();  run != initialRoom->getMap()->end(); run++) {

     cout <<run->first << ", " << run->second->getName() << endl;
     
   }

   //Asking users for directions and giving them options to end game as well

   cout << "To where shall we go?" << endl;
   cout << "One can quit as well if your tired from walking around" << endl;
   cout << endl;								       
   cin >> theDirections;

   for(map<const char*, room*>::iterator run = initialRoom->getMap()->begin(); run != initialRoom->getMap()->end(); run++) {

     if(strcmp(run->first, theDirections) ==0) {

       initialRoom = run->second;
       break;
     }
   }

   //If game is ended, then stop
   
   if(strcmp(theDirections, "quit") ==0) {

     cout << "Thank you for playing Zuul" << endl;
     trueFalse = false;
     
   }
  }
   return 0;
 }
  

