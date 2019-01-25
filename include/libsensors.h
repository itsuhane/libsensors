#ifndef SENSORS_LIBSENSORS_H
#define SENSORS_LIBSENSORS_H

extern "C" {
typedef void (*image_handler)(double t, int width, int height, const void* bytes);
typedef void (*gyroscope_handler)(double t, double x, double y, double z);
typedef void (*accelerometer_handler)(double t, double x, double y, double z);
typedef void (*magnetometer_handler)(double t, double x, double y, double z);
typedef void (*altimeter_handler)(double t, double pressure, double elevation);
typedef void (*gps_handler)(double t, double longitude, double latitude, double altitude);
typedef void (*error_handler)(const char* error_message);

void sensors_image_handler_set(image_handler h);
void sensors_gyroscope_handler_set(gyroscope_handler h);
void sensors_accelerometer_handler_set(accelerometer_handler h);
void sensors_magnetometer_handler_set(magnetometer_handler h);
void sensors_altimeter_handler_set(altimeter_handler h);
void sensors_gps_handler_set(gps_handler h);
void sensors_error_handler_set(error_handler h);

void sensors_init();
void sensors_deinit();
void sensors_parse_data(const void* bytes, long size);
}

#endif // SENSORS_LIBSENSORS_H
