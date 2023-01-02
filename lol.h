using namespace std;
using namespace libconfig;

struct attribute_class{
    int id;
    string name;
    string accumulator;
};
struct attribute{
    double value;
    string name;
    attribute_class attr_class;
};

class player{
    public:
        vector<attribute> attributes;
        double health = 200.0;
        double damage = 12.0;

        double accumulate_attribute(double total = 1.0, string classname = ""){
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
        void print_attributes(){
            for(attribute iter : attributes) {
                cout << iter.name << " | " << iter.value << "\n";
            }
        }
        void add_attribute(double value, string name, attribute_class attr_class){
            attribute temp_attr;

            temp_attr.value = value;
            temp_attr.name = name;
            temp_attr.attr_class = attr_class;
            
            attributes.push_back(temp_attr);
        }
};

map<string, attribute_class> generate_attribute_classes(){
    map<string, attribute_class> attribute_map;
    Config cfg;

    try{
        cfg.readFile("attribute_classes.cfg");
    }catch(const FileIOException &fioex){
        cerr << "I/O error while reading file." << endl;
        return(attribute_map);
    }catch(const ParseException &pex){
        cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
              << " - " << pex.getError() << std::endl;
        return(attribute_map);
    }

    const Setting& root = cfg.getRoot();

    try
    {
        const Setting &attributes = root["classes"];
        int count = attributes.getLength();
        int currentID = 1;

        for(int i=0; i < count; i++)
        {
            const Setting &attribute_cfg = attributes[i];
            attribute_class temp_attr_class;


            if(!(attribute_cfg.lookupValue("class", temp_attr_class.name)
                && attribute_cfg.lookupValue("accumulator", temp_attr_class.accumulator)))
                continue;
            
            temp_attr_class.id = currentID;
            attribute_map.insert({temp_attr_class.name, temp_attr_class});

            currentID++;
        }        
    }
    catch(const SettingNotFoundException &nfex)
    {
    }

    return attribute_map;
}