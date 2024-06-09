#include "Voice.h"
#ifndef Tracker_h
#define Tracker_h


class Tracker {
public:
  bool isPlaying;
  float tempoBlink;
  int selectedTrack;
  bool allPatternPlay;
  int currentPattern;
  Tracker();
  int UpdateTracker();
  void SetCommand(char command, int val);
 
private:
  float bpm;
  float bps;
  float beatTime;
  float noteTime;
  int barCount;
  int trackIndex;
  float lastMillis;
  int patternLength;
  
  Voice voices[4];
  float soundVelocity;
  int currentVoice=0;

  int bpms[4];
  int tracks[4][256];
  int trackOctaves[4][256];
  int trackInstruments[4][256];
  int patternCopy[4][64];
  int patternCopyOctaves[4][64];
  int patternCopyInstruments[4][64];
 
  void SetNote(int val,int track);
  void SetArp(int val);
  void SetBPM(int val);
  void SetDelay(int val);
  void SetEnvelopeNum(int val);
  void SetVoice(int val);
  void SetEnvelopeLength(int val);
  void SetOctave(int val);
  void SetVolume(int val);
  void SetTrackNum(int val);
  void ClearTrackNum(int val);
  void SetPatternNum(int val);
  void ClearPatternNum(int val);
  void TogglePlayStop();
  void CopyTrack();
  void PasteTrack();
  void CopyPattern();
  void PastePattern();
  void SetPatternLength(int val);
  void SaveDefaultSong();
  void ClearAll(int val);
  int UpdateVoices();
  int heldNotes[4];
  int heldInsturments[4];
};

#endif