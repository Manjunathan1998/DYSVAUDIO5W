#ifndef DY_SV_UTILS_H
#define DY_SV_UTILS_H

#include <Arduino.h>
int query_total_num_song(Stream &serial_comm);
int query_current_playback_state(Stream &serial_comm);
void control_command(Stream &serial_comm);
#endif
