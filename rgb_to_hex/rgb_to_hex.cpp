/*************************************
 * Program that gives hex value of   *
 * given rgb decimal value and draws *
 * a sample for that value           *
 *************************************/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>
#include <GL/freeglut.h>   //mingw gcc compiler 
// use this command line command to compile
// g++ -O0 -g3 -o rgb_to_hex rgb_to_hex.cpp -lglu32 -lopengl32 -lfreeglut


// using std::cout;
// using std::cin;
// using std::endl;
// using std::hex;     //decimal to hexadecimal
// using std::setw;    //sets digit count
// using std::setfill; //if value is 1 digit number, puts one more zero to make it look like "00" or "01"
using namespace std;

unsigned short red;
unsigned short green;
unsigned short blue;

void rectangle(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(static_cast<float>(red)/255, static_cast<float>(green)/255, static_cast<float>(blue)/255);    // coloring rect
    glBegin(GL_QUADS);
    glVertex2f(100, 100);    //sol alt
    glVertex2f(400, 100);    //sağ alt
    glVertex2f(400, 400);    //sağ üst
    glVertex2f(100, 400);    //sol üst
    glEnd();
}

void showScreen(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glLoadIdentity();
    //glViewport(0, 0, 500, 500);
    glOrtho(0.0, 500, 0.0, 500, 0.0, 1.0);
    rectangle();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    string input {};
    cout << "Choose your input method. \nType Hex if input is Hexadecimal, Dec if input is Decimal : ";
    
    cin >> input;
    
    for(auto i {0}; i < input.size(); i++)
		input.at(i) = tolower(input.at(i));
		

    if (input == "dec")
    {
        cout << "Enter the RGB value you wanted to be converted to Hex : " ;
        
        cin >> red;
        cin >> green;
        cin >> blue;

        cout << hex << "Hex Value of Given RGB Colour is : " << "#" 
                    << setw(2) << setfill('0') << std::uppercase << red
                    << setw(2) << setfill('0') << std::uppercase << green
                    << setw(2) << setfill('0') << std::uppercase << blue << endl;
    
    }
    else if(input == "hex")
    {
        cout << "Enter the Hex value you wanted to be converted to Dec : " ;
        string input {};

        cin.ignore(1, '#');
        cin  >> input;
        
        vector <unsigned int> sub_rgb (3, 0);

        for(auto i {0}; i < sub_rgb.size(); i++)
        {
            sub_rgb.at(i) = stoi(input.substr(2 * i, 2), nullptr, 16);
            cout << sub_rgb.at(i) << " ";
        }

        red = static_cast<unsigned short>(sub_rgb.at(0));
        green = static_cast<unsigned short>(sub_rgb.at(1));
        blue = static_cast<unsigned short>(sub_rgb.at(2));

        cout << endl;
    }
    else
    {
        cerr << "invalid rgb color" << endl;
        exit(EXIT_FAILURE);
    }
    

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("RGB");
    glutDisplayFunc(showScreen);
    glutIdleFunc(showScreen);
    glutMainLoop();

    return 0;
}
