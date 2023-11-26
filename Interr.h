#include <stdint.h>

typedef enum jb_error {
  jb_ok,
  jb_error
} jb_error_t;

// devices
typedef struct device_t {
  uint8_t pin;
  char* ip;
  char* path;
  char* action;
  struct device_t *previous;
  struct device_t *next;
} device_t;

typedef struct list_devices_t {
  device_t* first;
  device_t* last;
} list_devices_t

device_t* new_device();

jb_error_t set_device(device_t *device, uint8_t pin, char* ip, char* path, char* action);

jb_error_t delete_device(device_t *device);

list_devices_t new_list_device();

jb_error_t append_device(list_devices_t *list, device_t *device);

jb_error_t remove_device(list_devices_t *list);

jb_error_t load_config(device_t* device, char* cssStr);

jb_error_t save_config(device_t* device);
