/*
  =====================================================
  Gate sequencer by Jean_k<3

  Update 29 Nov 2020

  64 step sequencer, 8 part compatible eurorack
  =====================================================

  ________________________________________________________________________________________________
  ________________________________________________________________________________________________
  ________________________________________________________________________________________________

  TODO :

  SOFTWARE

  Fonction de choix de la part
  Fonction pause-lecture/stop

  Fonction Tempo/Clock divider
  Fonction Pages navigation/Nombre de pages
  Fonction de gestion de la taille de la gate/ Nombre de pas

  

  Fonction Copy/Past
  Fonction Fill/Clear
  Plusieurs mode de lecture (forward backward random)
  Fonction Step jump

  Clock in/out
  Reset in/out
  
  Choix de la paterne
  Fonction save/Load (SD card)
  Ajout d'un menu deboggage


  HARDWARE
  Ajout du selecteur
  Ajout des encodeurs
  Matrice de boutons
  Matrice de leds
  Afficheur 7 segments
  Carte SD



  DONE :

  Lecture des bouttons

   Step ON-OFF
    Selected step
  ________________________________________________________________________________________________
  ________________________________________________________________________________________________
  ________________________________________________________________________________________________


  FUNCTION :

  Bouttons
    Step on/off (last = selected step) + shift = step jump (1 2 3 jump 5)
    Copy/Paste + shift = Save
    Fill + shift = Clear
    Pause/Play + shift = Stop

   Encoder
    Tempo + push = clock divider
      Tempo + shift = Forward/Backward/Random
    Page navigation + push = Number of pages
    Gate size + push = Number of step

   Selecter
    Part choice + shift = patern choice

  --------------------------------------------------------------------------

  ANALOGUE PIN
  1 Selecteur pour les parts
  3 encoder pour le tempo/clock divider, gate/step, page/nombre de page

  DIGITAL PIN

  jack : 12
    output
      Clock out
      Reset out
      8 Gate out

     input
        Clock in
        Reset in

  Boutons : 24
    16 bouttons de pas
    5 boutton pour Shift, Copy-Paste, Save/Load, Fill/Clear, Play-Pause/Stop
    3 boutton d'encoder
  (Matrice de boutons 5x5 = 25 boutons disponible)

  Leds : 43
    16 leds de pas
    16 leds timeline
    3 leds de fonctions (une par encoder pour savoir sa fonction actuelle)
    1 led pour le BPM
    Afficheur 3x7 segments 11 pin (7 chathodes+ / 3 anodes-)
  (Matrice de LED en 6*6 = 36 LEDs)
  ( + 7 pour l'afficheur)


*/

#include <EEPROM.h>


#define NB_PART 8              // Le nombre de Relais
#define NB_STEP 64               // Le nombre de Pas
#define NB_BUTTON 24
#define NB_MOMENTARY_BUTTON 19

#define MAX_PAGE 4

#define MIN_BPM 10
#define MAX_BPM 300             // Le nombre d'oeufs dans la pâte à crèpe

#define number_of_74hc595s 1
#define numOfRegisterPins number_of_74hc595s * 8
boolean registers[numOfRegisterPins];


//-------------------------SHIFTREGISTER-----------------
const int SER_Pin = 5;            //pin 14 sur le 75HC595
const int RCLK_Pin = 7;           //pin 12 sur le 75HC595
const int SRCLK_Pin = 6;          //pin 11 sur le 75HC595

//-------------------------Boutons-----------------------
int button_pin[NB_BUTTON];
boolean button_state[NB_MOMENTARY_BUTTON];// Un tableau pour tous les bouttons, de 0 à 15 = step / de 16 à 18 = encodeurs / 19 = copy/save
boolean reading_button_state[NB_MOMENTARY_BUTTON];
boolean last_button_state[NB_MOMENTARY_BUTTON];
boolean shift_state;
const int shift_pin;

unsigned long debounceDelay;
unsigned long lastDebounceTime;

//-------------------------Encodeurs---------------------

//-------------------------Selecteur---------------------

//-------------------------Parts-------------------------
const int gate_out[NB_PART];
boolean step_state[NB_PART][NB_STEP];
boolean jump[NB_PART][NB_STEP];
int selected_step; // de 0 à 15
int actual_part;
int actual_step;
int active_step;
int page;

//---------------------Le temps--------------------------
int BPM = 120;
int clockDivider = 4;
unsigned long step_length = 250; // 120BPM par défaut
unsigned long currentMillis;
unsigned long previousMillis;
unsigned long step_start;
unsigned long step_end;

unsigned long gate_start[NB_PART];
unsigned long gate_end[NB_PART];
unsigned long gate_length[NB_PART];
float max_gate_time;
float min_gate_time;

//------------------------Mémoire------------------------
int address[NB_PART][NB_STEP];
int addressNum;
/*
  =========================================================================================================
  =========================================================================================================SETUP
  =========================================================================================================
*/
void setup() {
  Serial.begin(115200);

  pinMode(SER_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);
  //Reset tous les pins du 74HC595
  //  clearRegisters();
  //  writeRegisters();

  for (int x = 0; x < NB_PART; ++x)
  {
    pinMode(gate_out[x], OUTPUT);
    digitalWrite(gate_out[x], LOW);
  }

}
/*
  =========================================================================================================
  =========================================================================================================LOOP
  =========================================================================================================
*/
void loop() {

  for (actual_step = 0; actual_step < active_step; ++actual_step)
  {
    step_start = millis();

    boolean Flag = true;
    while (Flag == true)
    {
      /*
        Pseudo code :
        On regarde si le sequencer est sur pause/stop (sur pause par défaut)
          On allume la led corespondant au pas actuel
          On regarde quel part est selectionée
          On regarde si le tempo à changé
          On regarde si des pas on étaient activer/desactiver
          On allume la led du pas actuel et on éteint celle du pas d'avant
          On regarde si la taille de la gate a changer
            step_end = step_start + step_length;
            gate_end = step_end - gate_length;
          On regarde si on utilise le copier/coller
          On regarde si on charge/sauvegarde
      */
      for (actual_part = 0; actual_part < NB_PART; ++actual_part)
      {
        /*
          Pseudo code :
          Si l'état du pas est à 1
            La gate s'ouvre
            Si millis() dépasse gate_end
              la gate se ferme
          Si l'état du pas est à 0
            On ferme la gate
          
        */
      }

      currentMillis = millis();
      if (currentMillis - previousMillis >= step_length)  // Si on dépasse la taille du STEP
      {
        previousMillis = currentMillis; // On enregistre le début du nouveau STEP
        Flag = false; // On ferme le second process
      } //On passe au STEP suivant
    }
  }
}

//_________________________________________________________
//--------------------UPDATE BUTTON STATE------------------
//_________________________________________________________
void update_buttons_state() {

  shift_state = digitalRead(shift_pin);

  currentMillis = millis();
  for (int i = 0; i < NB_MOMENTARY_BUTTON ; ++i)
  {
    reading_button_state[i] = digitalRead(button_pin[i]);

    if (reading_button_state[i] != last_button_state[i]) lastDebounceTime = millis();
    if ((millis() - lastDebounceTime) > debounceDelay)
    {
      if (reading_button_state[i] != button_state[i])
      {
        button_state[i] = reading_button_state[i];
        if ( i <= 15)
        {
          selected_step = i;
        }
      }
    }
    last_button_state[i] = reading_button_state[i];
  }
}
//_________________________________________________________
//--------------------UPDATE STEP STATE--------------------
//_________________________________________________________
void update_step_state() {

  for (int i = 0; i < active_step; ++i)
  {
    step_state[actual_part][i] = button_state[i];
  }
}
