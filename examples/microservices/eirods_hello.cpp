// =-=-=-=-=-=-=-
// E-iRODS Includes
#include "msParam.h"
#include "reGlobalsExtern.h"
#include "eirods_ms_plugin.h"

// =-=-=-=-=-=-=-
// STL Includes
#include <iostream>

extern "C" {

    // =-=-=-=-=-=-=-
    // 1. Write a standard issue microservice
    int eirods_hello(msParam_t* _out, ruleExecInfo_t* _rei) {
    	std::string my_str = "Hello World!";
    	fillStrInMsParam(_out, my_str.c_str());

        return 0;
    }

    // =-=-=-=-=-=-=-
    // 2.  Create the plugin factory function which will return a microservice
    //     table entry
    eirods::ms_table_entry*  plugin_factory() {
        // =-=-=-=-=-=-=-
        // 3. allocate a microservice plugin which takes the number of function
        //    params as a parameter to the constructor
    	eirods::ms_table_entry* msvc = new eirods::ms_table_entry(1);

        // =-=-=-=-=-=-=-
        // 4. add the microservice function as an operation to the plugin
        //    the first param is the name / key of the operation, the second
        //    is the name of the function which will be the microservice
        msvc->add_operation("eirods_hello", "eirods_hello");

        // =-=-=-=-=-=-=-
        // 5. return the newly created microservice plugin
        return msvc;
    }

}; // extern "C"



