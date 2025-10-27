#include <SoftwareSerial.h>
#include "dy_sv_utils.h"

SoftwareSerial Serial1(10, 11); // RX=10, TX=11

byte loop_mode[] = {0xAA, 0x18, 0x01, 0x02};


void setup() {
  Serial.begin(9600);   // USB debug
  Serial1.begin(9600);  // UART device
  delay(2000);
  Serial.println("Starting communication...");
//  int my_total = query_total_num_song(Serial1);
//  Serial.println(my_total);
  Serial1.write(loop_mode, sizeof(loop_mode));
}

void loop() {
  int playback_state = query_current_playback_state(Serial1);
  Serial.println(playback_state);
  control_command(Serial1);
  
  delay(1000); // wait before next command
}
