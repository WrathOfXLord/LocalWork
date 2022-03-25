#pragma once

//abstract shape class
class Shape {
protected:
    double size;
public:
    virtual void draw(double size) = 0; //pure virtual function
};

//abstract open shape class
class OpenShape: public Shape {
    //another abstract class for classification
};

//abstract close shape class
class CloseShape: public Shape {
    //another abstract class for classification
};

//concreate line shape class
class Line: public OpenShape {
public:
    virtual void draw(double size) override;
};

//concrete square shape class
class Square: public CloseShape {
public:
    virtual void draw(double size) override;
};
