#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <libconfig.h++>

#include "project/player.h"
#include "project/attributes.h"
#include "project/baseentity.h"


int main()
{
    std::unique_ptr<player> playerOne(new player("d"));
    std::unique_ptr<attribute_handler> attribute_system(new attribute_handler);
    std::unordered_map<std::string, attribute_class> attribute_classes = attribute_system -> get_attribute_map();

    playerOne -> add_attribute(1.5, "Damage Bonus", attribute_classes["damage_mult"]);
    playerOne -> add_attribute(0.5, "Damage Penalty", attribute_classes["damage_mult"]);

    playerOne -> add_attribute(40.0, "Base Damage Bonus", attribute_classes["base_damage"]);
    playerOne -> add_attribute(75.0, "Base Damage Bonus (Class Bonus)", attribute_classes["base_damage"]);

    double damagePctMod = playerOne -> accumulate_attribute(1.0, "damage_mult");
    double damageBaseMod = playerOne -> accumulate_attribute(0.0, "base_damage");

    std::cout << damagePctMod << " Damage Multiplier\n";
    std::cout << damageBaseMod << " Base Damage Modifier\n";

    std::cout << (playerOne -> get_damage()  + damageBaseMod) * damagePctMod << " Output Damage\n";

    

    return 0;
}