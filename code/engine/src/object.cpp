/*
* Implementation of the class that represents an object
* in a game.
*/

#include "object.hpp"
#include "log.h"


Object::Object(double x, double y, double w, double h) {
    set_position(std::make_pair(x, y));
    set_size(std::make_pair(w, h));
}

std::pair<double, double> Object::position() const {
    return m_position;
}

std::pair<double, double> Object::size() const {
    return m_size;
}

bool Object::is_active() const {
    return active;
}

bool Object::is_visible() const {
    return visible;
}

double Object::x() const {
    return m_position.first;
}

double Object::y() const {
    return m_position.second;
}

double Object::w() const {
    return m_size.first;
}

double Object::h() const {
    return m_size.second;
}

void Object::set_position(std::pair<double, double> new_position) {
    m_position = new_position;
}

void Object::set_size(std::pair<double, double> new_size) {
    m_size = new_size;
}

void Object::set_x(double new_x) {
    m_position.first = new_x;
}

void Object::set_y(double new_y) {
    m_position.second = new_y;
}

void Object::set_w(double new_w) {
    m_size.first = new_w;
}

void Object::set_h(double new_h) {
    m_size.second = new_h;
}

void Object::set_active(bool status) {
    active = status;
}

void Object::set_visible(bool status) {
    visible = status;
}
