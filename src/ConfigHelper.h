//
// Created by yot on 25/02/23.
//

#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class ConfigHelper {

public:
    static ConfigHelper& getInstance()
    {
        static ConfigHelper instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return instance;
    }

    /**
     * Initialize void function
     * @brief This function is used to intialize the JSON and read it to a file
     * @return Returns a bool that is true if the initialization succeeded 
     */
    bool Initialize();

    /**
     * SaveJson void function
     * @brief This function is used to save the JSON file with the updated values
     * @return void
     */
    void SaveJson();

    /**
     * GetThing void function
     * @brief This function is used to parse an object from the JSON
     * @return void
     */
    int GetThing();

private:
    ConfigHelper() = default;

    json data;

public:
    ConfigHelper(ConfigHelper const&) = delete;
    void operator=(ConfigHelper const&) = delete;
};