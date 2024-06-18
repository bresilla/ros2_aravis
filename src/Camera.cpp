#include "ros2_aravis/Camera.hpp"


namespace cam{
    Camera::Camera(std::string camera_id, unsigned int index){
        camera = arv_camera_new(camera_id.c_str(), NULL);
        if(camera != NULL){
            std::cout << "Initialized Camera" << std::endl;
            return;
        }
        camera = NULL;
        return;
    }

    Camera::Camera(ArvDevice *device, unsigned int index){
        camera = arv_camera_new_with_device(device, NULL);
        if(camera != NULL){
            std::cout << "Initialized Camera"<< std::endl;
            return;
        }
        camera = NULL;
        return;
    }

    Camera::~Camera(){}

    void Camera::init_camera(){
        if(camera != NULL){
            caminfo = new CameraInfo();
            caminfo->id = arv_camera_get_device_id(camera, NULL);
            
        }
    }


    void Camera::setProperties(std::string property_name, double property_value){
        if(property_name == "GAIN"){
            arv_camera_set_gain(camera, property_value, NULL);
        }else if(property_name == "EXP_TIME"){
            arv_camera_set_exposure_time(camera, property_value, NULL);
        }else if(property_name == "FPS"){
            arv_camera_set_frame_rate(camera, property_value, NULL);
        }
        return ;
    }

    void Camera::start_stream(int buffer_queue_size){
    }
}