#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include <libconfig.h++>
#include "lol.h"

int main()
{
    unique_ptr<player> playerOne(new player);
    map<string, attribute_class> attribute_classes = generate_attribute_classes();

    playerOne -> add_attribute(1.5, "Damage Bonus", attribute_classes["damage_mult"]);
    playerOne -> add_attribute(0.5, "Damage Penalty", attribute_classes["damage_mult"]);

    playerOne -> add_attribute(40.0, "Base Damage Bonus", attribute_classes["base_damage"]);
    playerOne -> add_attribute(75.0, "Base Damage Bonus (Class Bonus)", attribute_classes["base_damage"]);

    double damagePctMod = playerOne -> accumulate_attribute(1.0, "damage_mult");
    double damageBaseMod = playerOne -> accumulate_attribute(0.0, "base_damage");

    cout << damagePctMod << " Damage Multiplier\n";
    cout << damageBaseMod << " Base Damage Modifier\n";

    cout << (playerOne -> damage + damageBaseMod) * damagePctMod << " Output Damage\n";

    playerOne -> print_attributes();

    return 0;
}