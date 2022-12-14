 #include <iostream>
 #include <cstring>
 #include <vector>
 #include <map>
 #include "room.h"

 using namespace std;

 char* room::getName() {
   return name;
 }

 void room::setName(char* addName) {
   strcpy(name, addName);
 }

 vector<char*>* room::getItems() {
   return &items;
 }

