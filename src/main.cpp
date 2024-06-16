#include <iostream>
#include <aravis-0.8/arv.h>


int main(int argc, char **argv){
    arv_update_device_list();
    //get num devices
    int num_devices = arv_get_n_devices();
    for(unsigned int i = 0; i < num_devices; i++){
        std::cout << "Device: " << arv_get_device_id(i) << std::endl;
        std::cout << "Physical ID: " << arv_get_device_physical_id(i) << std::endl;
        std::cout << "Address: " << arv_get_device_address(i) << std::endl;
        std::cout << "Vendor: " << arv_get_device_vendor(i) << std::endl;

        const char *device_id = arv_get_device_id(i);
        ArvDevice *device = arv_open_device(device_id, NULL);

        if(device == NULL){
            std::cerr << "Failed to open device" << std::endl;
            return 1;
        }

        ArvGc *gc = arv_device_get_genicam(device);

        if(gc == NULL){
            std::cerr << "Failed to get Genicam" << std::endl;
            return 1;
        }
        
    }


}