#include "Interr.h";
#include <stdlib.h>;

device_t* new_device() {
  device_t* device;
  device = malloc(sizeof *device * 1);
  if (device==NULL) 
    return;
  device->pin=0;
  device->ip="";
  device->path="";
  device->action="";
  device->next=NULL;
  device->previous=NULL;
  return device;
}

jb_error_t set_device(device_t* device, uint8_t pin, char* ip, char* path, char* action){
  device->pin=pin;
  device->ip=ip;
  device->path=path;
  device->action=action;
} 

jb_error_t delete_device(device_t* device){
  free(device);
  device=NULL;
}

list_devices_t new_list_device(){
  list_devices_t list;
  list.first=NULL;
  list.last=NULL;
}

jb_error_t append_device(list_devices_t *list, device_t *device){
  list.last->next=device;
  device->previous =list.last;
  list.last = device;
}

jb_error_t remove_device(list_devices_t *list){
  device_t *dev=list.last;
  list.last=dev->previous;
  list.last->next=NULL;
  delete_device(dev);
}

jb_error_t load_config(device_t* device, char* cssStr){
  int lenStr = sizeof *cssStr / sizeof(char);
}