#include "mat.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;
namespace ariel
{
    string mat(int c, int r, char s1, char s2)
    {

        vector<vector<char>> mat(r, vector<char> (c));
        
        char curr_s = s1;

        // the start values for the current frame
        int first_r = 0;
        int last_r = r-1;
        int first_c = 0;
        int last_c = c-1;
        int size = 1;


        //bounds for illegal arguments
        int const leftLimit = 33;
        int const rightLimit = 126;

        //checks
        if (r % 2 == 0 || c % 2 == 0)
        {
            throw invalid_argument("the rows and columns must be odd");
        }
        
        if (r <= 0 || c <= 0)
        {
            throw invalid_argument("the carpet size must be at least 1 and the rows, columns must be positive");
        }
       
        if ((s1 < leftLimit || s1 > rightLimit) || (s2 < leftLimit || s2 > rightLimit))
        {
            throw invalid_argument("invalid sign need to be between 33-126 in the ascii tabel");
        }


        // the while loop ends when the function finished to fill all the areas in the mat - the size of the carpet
        while (size <= c*r)
        {
            // fill the current frame top->right->bottom->left 
            for (int i = first_c; i <= last_c; i++)
            {
                mat.at(first_r).at(i)= curr_s;
                size++;
            }

            for (int i = first_r+1; i <= last_r-1; i++)
            {
                mat.at(i).at(last_c) = curr_s;
                size++;
            }

            for (int i = last_c; i >= first_c; i--)
            {
                mat.at(last_r).at(i)= curr_s;
                size++;
            }

             for (int i = last_r-1; i >= first_r+1; i--)
            {
                mat.at(i).at(first_c) = curr_s;
                size++;
            }
            

            first_r++; 
            last_r--; 
            first_c++; 
            last_c--;

            //change the sign  
            if (s1 == curr_s){
                curr_s = s2;
            }
            else {
                curr_s = s1;
            }
        }

        //create the carpet to print
        string carpet;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                carpet += mat.at(i).at(j);
            }
            carpet += '\n';
        }
        return carpet;
    }



};


