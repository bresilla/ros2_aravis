#include <iostream>
#include <aravis-0.8/arv.h>


int main(int argc, char **argv){
    arv_update_device_list();
    //get num devices
    int num_devices = arv_get_n_devices();
    std::cout << "Number of devices: " << num_devices << std::endl;
    return 0;
}