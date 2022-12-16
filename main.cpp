
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
   lab-->setDescription((char*)"THE LABATORY");

   room* theater = new room();
   theater->setName((char*)"The OLD SHOW");
   theater->setName((char*)"script");
   theater-->setDescription((char*)"THE THEATER IS OLD");

   labatory->addExit("NORTH", theater);

   char followDirection[50];
   room* initialRoom = lab;
   bool trueFalse = false;
   vector<char*> inventory;

   
   
		     
 }

