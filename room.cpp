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

 void room::addItem(char* itemsName) {
   items.push_back(itemsName);
 }

 char* room::getDescription() {
   return description;  
 }

 void room::setDescription(char* newDescription) {
   strcpy(description, newDescription); 
 }

 map<const char*, room*>* room::getMap() {
   return &exits;
 }

 void room::addExit(const char* direction, room* newRoom) {
   exits.insert(pair<const char*, room *>(direction, newRoom));
 }

