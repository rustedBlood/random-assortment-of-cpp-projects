class entity{
    public:
        double accumulate_attribute(double total = 1.0, std::string classname = "");
        void print_attributes();
        void add_attribute(double value, std::string name, attribute_class attr_class);
        std::vector<attribute> get_attributes();
        double get_health();
        double get_damage();
    private:
        std::vector<attribute> attributes;
        double health;
        double damage;
};