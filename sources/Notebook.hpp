#include <iostream>
#include <stdexcept>
#include "Direction.hpp"
#include <unordered_map>
using namespace std;

namespace ariel{
    class Notebook{

      private:
      unordered_map <int ,unordered_map <int , char[100]>> myBoard;

      public:
      void write(int posX,int posY,int posZ, Direction pos, string data);
      string read(int posX, int posY,int posZ, Direction pos, int dataNum);
      void erase(int posX, int posY,int posZ, Direction pos, int dataNum);
      void show(int row);
      static bool negative_num(int num);
      static bool great_num(int num);
    };
    
}