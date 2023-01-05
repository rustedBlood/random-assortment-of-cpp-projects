#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <libconfig.h++>
#include "project/attributes.h"

class entity{
    public:
        entity(std::string sName);
        double accumulate_attribute(double total = 1.0, std::string classname = "");
        void print_attributes();
        void add_attribute(double value, std::string name, attribute_class attr_class);
        std::vector<attribute> get_attributes();
        double get_health();
        double get_damage();
        void set_health(double input);
        void set_damage(double input);
    private:
        std::vector<attribute> attributes;
        double health;
        double damage;
        std::string name;
};