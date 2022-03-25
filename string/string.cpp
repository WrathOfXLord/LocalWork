#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    //Strings are dynamic. They can extend, shrink
    //Strings have member functions like .at() , .size() similar to vectors

    string str_1;               //initiliased empty string object

    string str_2 {"Ali Firat"}; //initialised string object with
                                //any string

    string str_3 {str_2};       //initialised string obj with another one

    string str_4 (10, 'x');     //initialised 10 character length string object
                                //with "xxxxxxxxx" via constructor using (), not {}.

    str_4 = "abcdefghijk";      //str_4's length's extended.

    string str_5 (10, 120);     //initialised 10 character length string object
                                //with x's ascii value which equals to x. Same with str_4
    
    string str_6 {str_2, 5};    //initialised via copy constructor with given length

    string str_7 {str_2, 1, 4}; //first parameter gets string, second one gets starting offset
                                //third one gets length. i.e. str_7 equals to "li F"

    cout << "size of str_7 is : " << str_7.size() << endl;

    string str_8 {str_2.begin(), str_2.begin() + 2};    //copies part of a string with iterators
                                                        //i.e. str_8 equals to "Al"

    string str_9 {str_2 + " " + str_8}; //initialised with 2 string objects and 1 c-style string with + operator

    //string str_err {"ali " + "fırat"}; //compile error: cannot concatenate 2 c-style string with +
    
    string str_10 {"ali " + str_1 + "firat"}; //this one can be compiled without errors. since str_1 is empty
                                              //str_10 equals to "ali fırat" 
    
    string str_11 {static_cast<string>("ali ") + "firat"};  //better solution for concatenating 2 c-style strings
                                                            //not covering redundant space also not relying on a variable

    cout << "3rd char of str_2 is : " << str_2.at(2)  << endl;      //prints 3rd element of str_2, i.e. str_2.at(2) equals to i.
    cout << "size of str_2 is : " << str_2.size() << endl;          //prints size of string in the string object, i.e. str_2.size() equals to 9.
    cout << "length of str_2 is : " << str_2.length() << endl;      //the same with size. two are synonymous with each other. equals to 9.

    cout << "capacity of str_2 is : " << str_2.capacity() << endl;  //str_2.capacity() returns allocated space size of str_2 
                                                                    //may be equal to size or more than size

    cout << "Enter your string : " ;
    getline(cin, str_1);    //reads user input into str_1. getline reads the whole line until sees '\n' character.

    cout << "str_1 is now : " << str_1 << endl;

    str_2.push_back('x');   //adds a character at the end of the string. i.e. str_2 is now "Ali Firatx"

    cout << str_2 << endl;

    str_2.pop_back();       //removes the last character from the string. str_2 is "Ali Firat" again.

    cout << str_2 << endl;

    str_2.resize(18);       //resizes string. size can be increased or decreased. i.e. str_2 resized to 18.
    
    cout << "str_2's size is now : " << str_2.size() << endl;                 //capacity increased as well.

    //str_2.shrink_to_fit();  //this function decreases the capacity to minimum capacity of the string
                              //be sure no character addition after performing this. useful to save additional memory.

    cout << "str_2's first character is : " << *(str_2.begin()) << endl;      //str_2.begin() returns an iterator to the beginning of the string object
                                                                              //to the first character of str_2 which equals to "A"

    cout << "str_2's last character is : " << *(str_2.end()) << endl;        //str_2.end() returns an iterator to the end of the string object
                                                                              //there might not be a character at the end because we changed size
                                                                

    char charArr[25] {0};
    string str_12;

    str_1.copy(charArr, 24, 1);     //copies str_1 to charArr.This one is simply copy(destination_char_array, reading_length, start_position)
    //doesn't work for string to string. to string to string we should use substring method
    
    str_12 = str_1.substr(0, str_1.size());   //First parameter is start_position, second one is reading_length 
    //read all str_1 to str_12  

    cout << "charArr after copying from str_12 is : " << charArr << endl;
    cout << endl << "str_12 is : " << str_12 << endl;                                         
    
    //swapping two strings each other
    cout << endl << "Going to swap str_2 with str_12" << endl;
    cout << "Before swap str_2 was " << "\"" << str_2 << "\"" << " and str_12 was " << "\"" << str_12 << "\"" << endl;

    str_2.swap(str_12);
    
    cout << "str_2 is now " << "\"" <<(str_2) << "\"" << " and str_12 is now " << "\"" << str_12 << "\"" <<  endl;

    str_12.erase(1, 4); //erases characters. first parameter is starting point, second one is length.

    cout << endl << "--------------------------" << endl;

    cout << "str_12 after erase 1-4 is " << str_12 << endl;
    cout << endl << "--------------------------" << endl;
    str_12.clear();     //removes the string inside of string object. size or length is 0 now.
    cout << "str_12 is now : " << str_12 << " and now have " << str_12.length() << " characters." << endl;

    size_t result {str_2.find("hey")};
    
    if(result == string::npos)  //if string.find(argument) fails then it returns string::npos
        cout << "Didn't find it. I'm sorry." << endl;
    else                        //else returns offset of given argument
    {
        cout << "Yesss ! Found \"hey\" at index " << result << endl;
    }

    size_t result2 {str_2.find("hey", result + 3)};  //now starts from the index 5 to search "hey". 
    if(result2 == string::npos)  //if string.find(argument) fails then it returns string::npos
        cout << "Didn't find it. I'm sorry." << endl;
    else                        //else returns offset of given argument
    {
        cout << "Yesss ! Found \"hey\" at index " << result2 << endl;
    }

    str_2.insert(7, " ");   //string.insert() inserts given string into the string object with given position
                            //first parameter is starting position, second is given array to insert.
   
    return 0;
}