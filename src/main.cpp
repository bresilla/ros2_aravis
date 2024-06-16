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

// #include "Camera.hpp"

// int main(int argc, char *argv[]){

//     Camera cam("TIS-11714131", false);
//     cam.setProperties("GAIN", 15.0);
//     cam.setProperties("EXP_TIME", 50000.0);
//     cam.setProperties("FPS", 30);
//     cam.start_video();
//     while(true){
//         IplImage* image;
//         image = cam.readFrameIPL();
//         cvShowImage("Image", image);
//         int keypress = cvWaitKey(1) & 0xFF;


//         /***** TO USE WITH OPENCV C++ MAT CONTAINER ****/

//         // cv::Mat m;
//         // m = cam.readFrameMat();
//         // cv::imshow("frame", m);
//         // int keypress = cv::waitKey(1) & 0xFF;
        
//         if(keypress == 27){
//             break;
//         }else if (keypress == 115){
            
//         }
//     }

//     cvDestroyAllWindows();
//     // cv::destroyAllWindows();
//     cam.disconnect();

//     return 0;
// }
