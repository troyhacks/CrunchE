#ifndef Voice_h
#define Voice_h
class Voice {
public:

  int arpNum;
  int delay;
  int octave;
  Voice();
  int UpdateVoice();

  void SetNote(int val, bool delay, int optOctave,int optInstrument);
  void SetVolume(int val);
  void SetOctave(int val);
  void SetDelay(int val);
  void SetEnvelopeNum(int val);
  void SetEnvelopeLength(int val);
  void SetArpNum(int val);

private:
  int effect;
  int sampleLen;
  bool isDelay;
  int arpCount;
  int arps[4][4];
  int envelopeLength;
  int envelope;
  int envelopeNum;
  int voiceNum;
  int output;
  int note;
  int sampleHistory[2000];
  int sampleHistoryIndex=0;

  float baseFreq;
  float sampleIndex;
  float sampleIndexNext;
  float volume;
  
  int ReadWaveform();
  int ReadDrumWaveform();
  int ReadSfxWaveform();
  float GetBaseFreq(int val,int ioctave);
  float GetVolumeRatio();
  void SetupArps();
  float LerpSample(int sampleA, int sampleB, float ratio);
  void UpdateHistory(int);
  int GetHistorySample(int backOffset);
};
#endif