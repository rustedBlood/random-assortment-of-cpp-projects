#include "project/attributes.h"

std::unordered_map<std::string, attribute_class> attribute_handler::get_attribute_map(){
    return attribute_map;
}

std::unordered_map<std::string, attribute_class> generate_attribute_map(){
    std::unordered_map<std::string, attribute_class> attribute_map;
    libconfig::Config cfg;

    try{
        cfg.readFile("attribute_classes.cfg");
    }catch(const libconfig::FileIOException &fioex){
        std::cerr << "I/O error while reading file." << std::endl;
        return(attribute_map);
    }catch(const libconfig::ParseException &pex){
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
              << " - " << pex.getError() << std::endl;
        return(attribute_map);
    }

    const libconfig::Setting& root = cfg.getRoot();

    try
    {
        const libconfig::Setting &attributes = root["classes"];
        int count = attributes.getLength();
        int currentID = 1;

        for(int i=0; i < count; i++)
        {
            const libconfig::Setting &attribute_cfg = attributes[i];
            attribute_class temp_attr_class;


            if(!(attribute_cfg.lookupValue("class", temp_attr_class.name)
                && attribute_cfg.lookupValue("accumulator", temp_attr_class.accumulator)))
                continue;
            
            temp_attr_class.id = currentID;
            attribute_map.insert({temp_attr_class.name, temp_attr_class});

            currentID++;
        }        
    }
    catch(const libconfig::SettingNotFoundException &nfex)
    {
    }

    return attribute_map;
}

attribute_handler::attribute_handler():
    attribute_map(generate_attribute_map())
{}