#include <boost/program_options.hpp>
using namespace boost::program_options;

#include <iostream>
// using namespace std;

int main(int argc, char* argv[])
{
    std::string server_addr = "172.17.0.3:8500";
    std::string model_name = "Toy";
    int model_version = -1;
    std::string model_version_label = "";

    options_description desc("Allowed options");
    desc.add_options()
        // First parameter describes option name/short name
        // The second is parameter to option
        // The third is description
        ("help,h", "print usage message")
        ("server_addr,s", value(&server_addr)->default_value(server_addr),
                "the destination address host:port")
        ("model_name,m", value(&model_name)->default_value(model_name), 
                "the mode name for prediction")
        ("model_version,v", value<int>(&model_version)->default_value(model_version), 
                "the model version for prediction")
        ("model_version_label,l", value(&model_version_label)->default_value(model_version_label), 
                "the annotation name of model version for prediction")
        ;

    variables_map vm;
    store(parse_command_line(argc, argv, desc), vm);

    if (vm.count("help")) {  
        std::cout << desc << "\n";
        return 0;
    }
    server_addr = vm["server_addr"].as<std::string>();
    model_name = vm["model_name"].as<std::string>();
    model_version = vm["model_version"].as<int>();
    model_version_label = vm["model_version_label"].as<std::string>();

    std::cout << server_addr << '\n';
    std::cout << model_name << '\n';
    std::cout << model_version << '\n';
    std::cout << model_version_label << '\n';
}