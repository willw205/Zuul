 #include <iostream>
 #include <cstring>
 #include <vector>
 #include <map>
 #include <iterator>

 #ifndef ROOM_H
 #define ROOM_H

 using namespace std;

 class room{
  public:

   char* getName();
   void setName(char* addName);
   vector<char*>* getItems();
   void addItem(char* itemName);
   map<const char*, room*>* getMap();
   void addExit(const char* direction, room* newRoom);

  private:
   
   map<const char*, room*> exits;
   char name[50];
   vector<char*> items;
 };
 #endif

