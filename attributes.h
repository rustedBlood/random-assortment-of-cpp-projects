#include <iostream>
#include <vector>
#include <unordered_map>
#include <libconfig.h++>


struct attribute_class{
    int id;
    std::string name;
    std::string accumulator;
};
struct attribute{
    double value;
    std::string name;
    attribute_class attr_class;
};

class attribute_handler{
    public:
        std::unordered_map<std::string, attribute_class> get_attribute_map();
    private:
        std::unordered_map<std::string, attribute_class> attribute_map;
};