
 //William Wong
 //12/16/22

 #include <iostream>
 #include <cstring>
 #include <vector>
 #include <map>
 #include "room.h"
 using namespace std;

 // Below is initializing the functions
 // Getters and setters are also put in place for name, description, etc...

 char* room::getName() {
   return name;
 }

 void room::setName(char* addName) {
   strcpy(name, addName);
 }

 // Helps to return list of items within room

 vector<char*>* room::getItems() {
   return &items;
 }

 void room::addItem(char* itemsName) {
   items.push_back(itemsName);
 }

 char* room::getDescription() {
   return description;  
 }

 void room::setDescription(char* newDescription) {
   strcpy(description, newDescription); 
 }

 // Returning exits below

 map<const char*, room*>* room::getMap() {
   return &exits;
 }

 //Below helps to create exits

 void room::addExit(const char* direction, room* newRoom) {
   exits.insert(pair<const char*, room *>(direction, newRoom));
 }

