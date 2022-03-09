#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "Position.hpp"
#include "object.hpp"

Object::Object(ALLEGRO_BITMAP *image,int x, int y):
    _position(x,y), _image(image){};

Object::~Object(){}

void Object::change_image(ALLEGRO_BITMAP *image){
    _image = image;
}
