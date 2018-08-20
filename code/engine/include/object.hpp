/*
* An object representation for use in a game.
* All objects in a game should be represented by this class.
*/

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <utility>

class Object {

    public:
        Object(double x = 0, double y = 0, double w = 1, double h = 1);
        virtual ~Object() = default;

        virtual void update() = 0;
        virtual void draw() = 0;

        /* Getters */
        std::pair<double, double> position() const;
        std::pair<double, double> size() const;

        bool is_active() const;
        bool is_visible() const;

        double x() const;
        double y() const;

        double w() const;
        double h() const;

        /* Setters */
        void set_position(std::pair<double, double> new_position);
        void set_size(std::pair<double, double> new_size);

        void set_x(double new_x);
        void set_y(double new_y);

        void set_w(double new_w);
        void set_h(double new_h);

        void set_active(bool status);
        void set_visible(bool status);
    
    protected:
        bool active;
        bool visible;

        // position x and y
        std::pair<double, double> m_position;
        
        // width and height
        std::pair<double, double> m_size;
};  

#endif