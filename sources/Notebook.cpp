#include <iostream>
#include <stdexcept>
#include "Direction.hpp"
#include "Notebook.hpp"
using namespace std;

namespace ariel{

    bool Notebook::negative_num(int num) {
        bool res = false;
        const int x = 0;
        if (num < x) {
            res = true;
        }
        return res;

    }

    void Notebook::write(int posX,int posY,int posZ, Direction pos, string data){
        const int len_max = 100;
        const int min = 32;
        const int max = 125;
        int len = data.length();
        
        if (negative_num(posZ) || great_num(posZ) || negative_num(posY) || negative_num(posX) || negative_num(data.length())) {
            throw runtime_error("Negative argument is not allowed !");
        }
        
        for (int i = 0; i < len; ++i) {
            if (data[(unsigned int)i] < min || data[(unsigned int)i] > max) {
                throw runtime_error("character invalid");
            }
        }
    
        if (pos == Direction::Horizontal) {
            if ((len + posZ) > len_max) {
                throw runtime_error(" !! ");
            }
            for (int i = posZ; i < len + posZ; i++) {
                if (myBoard[posX][posY][i] == '~') {
                    throw runtime_error("already deleted this line!");}

                if(myBoard[posX][posY][i] >= min && myBoard[posX][posY][i] < max){

                    if(myBoard[posX][posY][i]=='_'){
                        myBoard[posX][posY][i] = data[(unsigned int)(i-posZ)];
                    }
                    else
                    {
                        throw runtime_error("already written!");
                    }

                }
                else{
                    myBoard[posX][posY][i] = data[(unsigned int)(i-posZ)];
                
                }
            }
        }
        if (pos == Direction::Vertical) {
            for (int i = posY; i < len + posY; i++) {
                if (myBoard[posX][i][posZ] == '~') {
                    throw runtime_error("already deleted this line!");
                }
                if(myBoard[posX][i][posZ] >= min && myBoard[posX][i][posZ] <= max ){
                    if(myBoard[posX][i][posZ]=='_'){
                        myBoard[posX][i][posZ] = data[(unsigned int)(i-posY)];
                    }
                    else
                    {
                        throw runtime_error("already written this line!");
                    }
                }
                else{
                    myBoard[posX][i][posZ] = data[(unsigned int)(i-posY)];
                }
            }
        }
    }

    bool Notebook::great_num(int num) {
        bool res = false;
        const int x = 100;
        if (x <= num) {
            res = true;
        }
        return res;

    }

    string Notebook::read(int posX, int posY, int posZ, Direction pos, int dataNum){
        
        const int len_max = 100;
        const int min = 32;
        const int max = 125;
        string str;

        if (negative_num(dataNum) || negative_num(posZ) || great_num(posZ) || negative_num(posY) || negative_num(posX)) {
            throw invalid_argument("Negative argument is not allowed !");
        }
        if(Direction::Horizontal == pos && dataNum + posZ > len_max) {
                throw invalid_argument("Negative argument is not allowed !");
        }
        
        
        if (pos == Direction::Horizontal) {
            if ((dataNum + posZ) > len_max) {
                throw runtime_error(" !! ");
            }
            for (int i = posZ; i < dataNum + posZ; i++) {
                if(myBoard[posX][posY][i] >= min && myBoard[posX][posY][i] <= max+1) {
                    str += myBoard[posX][posY][i];
                } else {
                    str += '_';
                }
            }
        }
        if (pos == Direction::Vertical) {
            for (int i = posY; i < dataNum + posY; i++) {
                if (myBoard[posX][i][posZ] >= min && myBoard[posX][i][posZ] <= max+1) {
                    str += myBoard[posX][i][posZ];
                } else {
                    str += '_';
                }
            }
        }
        return str;
    }

    void Notebook::show(int row){
        if (negative_num(row))
        {
            throw runtime_error("Page number start from 0 !");
        }
         cout << "-------------------------------------------- Page Number: " << row
         << " --------------------------------------------" << endl;

        cout << myBoard[row][0][0] << "\n show \n";
    }

    void Notebook::erase(int posX, int posY,int posZ, Direction pos, int dataNum){
        const int len_max = 100;
        if (negative_num(dataNum) || negative_num(posZ) || great_num(posZ) || negative_num(posY) || negative_num(posX)) {
            throw invalid_argument("Negative argument is not allowed !");
        }
        if(Direction::Horizontal == pos && dataNum + posZ > len_max) {
                throw invalid_argument("Negative argument is not allowed !");
        }
        if(pos == Direction::Horizontal){
            if ((dataNum + posZ) > len_max) {
                throw runtime_error(" !! ");
            }
            for (int i = posZ; i < dataNum + posZ; i++) {
                myBoard[posX][posY][i] = '~';
            }
        }
        else{
            for (int i = posY; i < dataNum + posY; i++) {
                myBoard[posX][i][posZ] = '~';
            }
        }
    }

}