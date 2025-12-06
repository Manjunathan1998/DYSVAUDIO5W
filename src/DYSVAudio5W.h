/*
  DYSVAudio5W - Arduino Library (Beta)
  ------------------------------------
  This library allows control of the DYSVAudio5W MP3 Player module over SoftwareSerial.
  
  Features:
    - Start and stop playback
    - Set volume and increment/decrement
    - Mute/unmute
    - Set loop mode
    - Get current volume and mute status
    - And much more

  Note: This is a beta release. Some functions may change in future versions.
  Author: Manjunathan
  Version: 1.0.0-Beta-01
*/


#ifndef DYSVAUDIO5W_H
#define DYSVAUDIO5W_H

#include <Arduino.h>

class DYSVAudio5W {
  private:
    Stream &uart_port;
    Stream &stream_out;
    unsigned int baud_rate;

  public:
    DYSVAudio5W(Stream &uart_port, unsigned int baud_rate, Stream &stream_out);
    int begin(); //Begin the comm and set the volume to 20 grade by default
    int queryEngine(int frame_index); //This will read the serial port
    int queryTotalSongs(); //This will query the total number of songs in the root(/)
    int getPlaybackState(); //Returns playback state binary 1 = Playing & 0 = Not Playing
    int getCurrentSongIndex(); //Returns the current playing song number

    void DYSVAudio5W::startPlayback(); //Start playback
    void DYSVAudio5W::pausePlayback(); //Pause playback
    void DYSVAudio5W::stopPlayback(); //Stops playback
    void DYSVAudio5W::resumePlayback(); //Resume playback
    void DYSVAudio5W::prevPlayback(); //Previous Song
    void DYSVAudio5W::nextPlayback();// Next Song

    void DYSVAudio5W::playTrack(byte song_number); //Play Selected song
    void DYSVAudio5W::setEqualizer(byte eq_mode); //Set Equalizer Mode
    void DYSVAudio5W::setLoopMode(byte loop_mode_select); //Set Looping state
    int DYSVAudio5W::setVolume(byte volume); //Set Volume 0 - 30, 
    int DYSVAudio5W::volumeIncrement(); //Increment the volume by 1 count
    int DYSVAudio5W::volumeDecrement(); //Decrement the volume by 1 count
    int DYSVAudio5W::toggleMute(bool mute_state); //Mute and Unmute

    int query_result = 0;
    int play_state = 0;
    int dynamic_volume_grade = 20;
    int *volume_ptr = &dynamic_volume_grade;
    int volume_state;
};

#endif
