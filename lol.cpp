#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include <libconfig.h++>
#include "lol.h"

int main()
{
    unique_ptr<player> razoe(new player);
    map<string, attribute_class> attribute_classes = generate_attribute_classes();

    razoe -> add_attribute(1.5, "Damage Bonus", attribute_classes["damage_mult"]);
    razoe -> add_attribute(0.5, "Damage Penalty", attribute_classes["damage_mult"]);

    razoe -> add_attribute(40.0, "Base Damage Bonus", attribute_classes["base_damage"]);
    razoe -> add_attribute(75.0, "Base Damage Bonus (Class Bonus)", attribute_classes["base_damage"]);

    double damagePctMod = razoe -> accumulate_attribute(1.0, "damage_mult");
    double damageBaseMod = razoe -> accumulate_attribute(0.0, "base_damage");

    cout << damagePctMod << " Damage Multiplier\n";
    cout << damageBaseMod << " Base Damage Modifier\n";

    cout << (razoe -> damage + damageBaseMod) * damagePctMod << " Output Damage\n";

    razoe -> print_attributes();

    return 0;
}