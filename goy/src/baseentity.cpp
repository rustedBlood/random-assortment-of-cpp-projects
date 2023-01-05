#include "project/baseentity.h"

entity::entity(std::string sName):
    health(30.0),
    damage(1.0),
    name(sName)
{}

double entity::accumulate_attribute(double total, std::string classname){
    for(attribute iter : attributes) {
        if(iter.attr_class.name != classname)
            continue;

        if(iter.attr_class.accumulator == "additive"){
            total+= iter.value;
        }
        else if(iter.attr_class.accumulator == "multiplicative"){
            total *= iter.value;
        }
    }
    return total;
}

void entity::print_attributes(){
    std::cout << "Attributes of " + name;
    for(attribute iter : attributes) {
        std::cout << iter.name << " | " << iter.value << "\n";
    }
}

void entity::add_attribute(double value, std::string name, attribute_class attr_class){
    attribute temp_attr;

    temp_attr.value = value;
    temp_attr.name = name;
    temp_attr.attr_class = attr_class;
    
    attributes.push_back(temp_attr);
}

std::vector<attribute> entity::get_attributes(){
    return attributes;
}
double entity::get_damage(){
    return damage;
}
double entity::get_health(){
    return health;
}

void entity::set_health(double input){
    health = input;
}

void entity::set_damage(double input){
    damage = input;
}