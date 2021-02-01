#ifndef HM_DEFINITONS_HPP
#define HM_DEFINITONS_HPP
#include <Tone.h>

/*
   please keep this reference in this file when using this code anywhere
   https://github.com/DelTa-B/hook-matching/
   I would be glad if you give this link when you take part of this file :)
*/
//typedef uint8_t effects;
#define effects uint8_t
#define NOTE_IS_SILENCE 1
#define NOTE_STICKS_TO_NEXT 2
#define NOTE_FORCE_SHARP 4
#define NOTE_FORCE_FLAT 8
#define NOTE_FORCE_NATURAL 16

#define NOTE_DO 0
#define NOTE_RE 1
#define NOTE_MI 2
#define NOTE_FA 3
#define NOTE_SOL 4
#define NOTE_LA 5
#define NOTE_SI 6

#define NOTE_C NOTE_DO
#define NOTE_D NOTE_RE
#define NOTE_E NOTE_MI
#define NOTE_F NOTE_FA
#define NOTE_G NOTE_SOL
#define NOTE_A NOTE_LA
#define NOTE_B NOTE_SI


#define NOTE_TONIQUE 0
#define NOTE_SECONDE 1
#define NOTE_TIERCE 2
#define NOTE_QUARTE 3
#define NOTE_SOUS_DOMINANTE NOTE_QUARTE
#define NOTE_QUINTE 4
#define NOTE_DOMINANTE NOTE_QUINTE
#define NOTE_SIXTE 5
#define NOTE_SEPTIEME 6
#define NOTE_SENSIBLE NOTE_SEPTIEME
#define NOTE_OCTAVE 7;

extern float LA4_REF;

typedef uint8_t note_duration;  // 24 for a black, 48 for a white, handles triolets
typedef uint8_t note;           // 0 for C, 1 for D, etc.


/** scale is a description of the rule on which the note walks.
   Definition is made taking the C major scale as reference, which is what you get by only playing white notes on a piano
*/
// TODO ref1 scale class
struct scaleDeprecated {
  uint8_t sharps;        // binary map from right to left, starting from do: 1 if sharp
  uint8_t flats;         // binary map from right to left, starting from do: 1 if flat
  note note_base;        // the NOTE_something telling which note is the Tonic
  const char *display_name;    // a fancy name to display
};

struct note_info {
  int8_t degreeOffset;
  uint8_t octaveOffset;
  note_duration duration;
  effects flags;
};
// TODO ref1
float getFrequency(const int8_t degree, const uint8_t octave,  struct scaleDeprecated const *g);




typedef int (*PLAY_CB)(void * context, float freq, uint32_t duration);

#endif // HM_DEFINITONS_HPP
