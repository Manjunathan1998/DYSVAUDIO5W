#include "dy_sv_utils.h"
//#include <Arduino.h>

byte query_total_num_of_songs[] = {0xAA, 0x0C, 0x00, 0xB6};
byte query_play_status[] = {0xAA, 0x01, 0x00, 0xAB};
byte query_play_command[] = {0xAA, 0x02, 0x00, 0xAC};
//byte loop_mode[] = {0xAA, 0x18, 0x01, 0x02};

bool act_query_cmd = 0;
int total_song;
int playback_state;


int query_total_num_song(Stream &serial_comm) {
	//Send the 4 Byte Hexadecimal frames
	//act_query_cmd = 0;
	if (act_query_cmd == 0){
		bool act_query_cmd = serial_comm.write(query_total_num_of_songs, sizeof(query_total_num_of_songs));
		act_query_cmd = 1;
		delay(100);
	}	
	int index_frame = 0;
	while (serial_comm.available()){
		byte incoming_frame = serial_comm.read();
		index_frame++;
		if (index_frame == 5){
		  total_song = incoming_frame;
		  continue;
		}
  }
  return total_song;
}

int query_current_playback_state(Stream &serial_comm)
{
  serial_comm.write(query_play_status, sizeof(query_play_status));
  delay(100);
  int index_playback_frame = 0;
  while (serial_comm.available()){
    byte incoming_frame = serial_comm.read();
    index_playback_frame++;
    if (index_playback_frame == 4){
      playback_state = incoming_frame;
      continue;
    }
  }
  return playback_state;
}

void control_command(Stream &serial_comm){
  int plb_state = query_current_playback_state(serial_comm);
  //serial_comm.write(loop_mode, sizeof(loop_mode));
  if (plb_state == 0){
  serial_comm.write(query_play_command, sizeof(query_play_command));
  }
}
