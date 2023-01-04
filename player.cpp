#include "player.h"

player::player():
    health(30.0),
    damage(1.0)
{}

double player::accumulate_attribute(double total = 1.0, std::string classname = ""){
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

void player::print_attributes(){
    for(attribute iter : attributes) {
        std::cout << iter.name << " | " << iter.value << "\n";
    }
}

void player::add_attribute(double value, std::string name, attribute_class attr_class){
    attribute temp_attr;

    temp_attr.value = value;
    temp_attr.name = name;
    temp_attr.attr_class = attr_class;
    
    attributes.push_back(temp_attr);
}

std::vector<attribute> player::get_attributes(){
    return attributes;
}
double player::get_damage(){
    return damage;
}
double player::get_health(){
    return health;
}