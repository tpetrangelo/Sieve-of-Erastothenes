/*  Sieve of Eratosthenes - Find all primes between one and a user-imput number */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    //Initial values for user choice of max number
    int numChoice = 2;
    int multiplier = 2;
    cout << endl << "Please enter a  maximum number to find the primes from two to n, where n is your input" << endl << endl << "Number : ";
    cin >> numChoice;
    cout << "------------------------------------" << endl;

    //Create vector to hold all numbers between 1 and numChoice
    vector<int> sieveArray;

    //Push all number between 1 and numChoice to sieveArray
    for (int i = 1; i <= numChoice; i++){
        sieveArray.push_back(i);
    }

    //Loop through all numbers from 2 to numChoice
    for (int j = 2; j <= numChoice; j++){

        //Using binary search, if the value of j is in the vector then start erasing multiples
        if(binary_search(sieveArray.begin(),sieveArray.end(),j)){
            while(j * multiplier <= numChoice){
                
                //erase(remove) finds a value (current number * multiplier) in the vector and moves it to the end of the vector and removes it from the end
                sieveArray.erase(remove(sieveArray.begin(), sieveArray.end(), j * multiplier), sieveArray.end());
                multiplier += 1;
            }
            
            //reset multiplier for next number
            multiplier = 2;
        }    
    }
    
    //Print out all primes, dropping down a line every ten primes
    for (int k = 0; k < sieveArray.size(); k++){
        cout << sieveArray[k] << " ";
        if(k % 10 == 0 && k != 0){
            cout << endl;
        }
    }
    
    cout << endl << "------------------------------------" << endl;
    return 0;
}