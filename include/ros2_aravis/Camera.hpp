#include "unistd.h"
#include "arv.h"
#include "opencv2/opencv.hpp"

namespace cam{

	struct CameraInfo{
		std::string id;
		std::string physical_id;
		std::string address;
		std::string vendor;
		std::string manufacturer_info;
		std::string model;
		std::string serial_nbr;
		std::string protocol;
	};

	class Camera{
		public:
			Camera(std::string camera_id, unsigned int index);
			Camera(ArvDevice *device, unsigned int index);
			~Camera();
			CameraInfo *caminfo = NULL;
			void init_camera();
			void start_stream(int buffer_queue_size=50);
			void setProperties(std::string property_name, double property_value);
			
		private:
			ArvCamera *camera = NULL;
			ArvStream *stream = NULL;
			ArvBuffer *buffer = NULL;
			ArvBuffer *_buffer = NULL;
			void* framebuffer;
	};
}