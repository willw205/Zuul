
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

   room* theater = new room();
   theater->setName((char*)"The OLD SHOW");
   theater->setName((char*)"script");

   labatory->addExit("NORTH", theater);
		     
 }

