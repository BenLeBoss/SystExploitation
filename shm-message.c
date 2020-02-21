#include <stdio.h>
#include <time.h>

#include "shm-message.h"


int shm_message_copy(shm_message_t message_source, shm_message_t *message_target){
  for (int i=0; i<=(SHM_MESSAGE_TEXT_SIZE-1); i++){
    message_source.text[i] = message_target->text[i];
    if (message_source.text[i] != message_target->text[i])
      return -1;
  }
  for (int j=0; j<=(SHM_MESSAGE_NAME_SIZE-1); j++){
    message_source.name[j] = message_target->name[j];
    if (message_source.name[j] != message_target->name[j])
      return -1;
  }
  return 0;
}

void shm_message_empty(shm_message_t *message){
  for (int i=0; i<=(SHM_MESSAGE_NAME_SIZE-1); i++){
    message->name[i] = '\0';
  }
  for (int j=0; j<=(SHM_MESSAGE_TEXT_SIZE-1); j++){
    message->text[j] = '\0';
  }
}

int shm_message_is_empty(shm_message_t message){
  if ((message.name == NULL)&&(message.text == NULL))
    return -1;
  else
    return 0;
}

void shm_message_print(shm_message_t message){
  time_t seconds = time(NULL);
  struct tm *timeinfo = localtime(&seconds);
  printf("%04d-%02d-%02d %02d:%02d:%02d: %s\n",1900+timeinfo->tm_year,timeinfo->tm_mon+1,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,message.text);
}

int shm_message_set_name(shm_message_t *message, const char *name){
  for (int j=0; j<=(SHM_MESSAGE_NAME_SIZE-1); j++){
    message->name[j] = name[j];
  }
  return 0;
}

int shm_message_set_text(shm_message_t *message, const char *text){
  for (int i=0; i<=(SHM_MESSAGE_TEXT_SIZE-1); i++){
    message->text[i] = text[i];
  }
  return 0;
}

int main(){
  return 0;
}
