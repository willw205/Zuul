 #include <iostream>
 #include <cstring>
 #include <vector>
 #include <map>
 #include <iterator>

 #ifndef ROOM_H
 #define ROOM_H
 using namespace std;

 //Below we create function prototypes

 class room{
  public:

   char* getName();
   void setName(char* addName);
   char* getDescription();
   void setDescription(char* newDescription);
   vector<char*>* getItems();
   void addItem(char* itemName);
   map<const char*, room*>* getMap();
   void addExit(const char* direction, room* newRoom);

  //private variables added below
   
  private:
   
   map<const char*, room*> exits;
   char description[100];
   char name[50];
   vector<char*> items;
 };
 #endif

