/*

64 step sequencer, 8 part compatible eurorack
by Jean_k3

  Update 21 Nov 2020

  TODO :

  Refonte du setup
  Refonte des fonctions
  Faire une structure pour les parts ???
  Ajout du selecteur
  Ajout des encodeurs
  Ajout d'un menu deboggage
  Meilleure gestion de la fonction pause/lecture/stop

  Lecture des boutons en matrices
  Contrôle des LEDs en matrices
  Utiliser micros() plutot que millis (plus précis)
  Ajouter le tempo dans la sauvegarde
  Mode pattern & song
  Clock externe
  Reset externe

  BOM :
  1 Potentiomètre pour le tempo
  1 Selecteur pour les parts
  2 encoder pour les différents paramètres
  4 boutton de functions
  16 bouttons de pas
  32 LEDs de pas une pour l'état du pas et une pour la timeline
  3 LED de fonctions
  1 LED pour le tempo
  4 LED pour les pages
  8 LED pour les parts
  8 LED pour les patterns
  (Matrice de LED en 7x8 = 56 LEDs disponible)
  (Matrice de boutons 4x5 = 20 boutons disponible)

*/

#include <EEPROM.h>


#define NB_PART 8              // Le nombre de Relais
#define NB_STEP 64               // Le nombre de Pas

#define MIN_BPM 10
#define MAX_BPM 300             // Le nombre d'oeufs dans la pâte à crèpe

#define number_of_74hc595s 1
#define numOfRegisterPins number_of_74hc595s * 8
boolean registers[numOfRegisterPins];


//-------------------------SHIFTREGISTER-----------------
const int SER_Pin = 5;            //pin 14 sur le 75HC595
const int RCLK_Pin = 7;           //pin 12 sur le 75HC595
const int SRCLK_Pin = 6;          //pin 11 sur le 75HC595


//-------------------------Potar-------------------------
const int tempoPotPin = A0;
int tempoPotVal = 0;

//-------------------------Encodeurs---------------------

//-------------------------Selecteur---------------------

//-------------------------Parts-------------------------
const int part_outuput_pin[NB_PART] = {};
boolean step_state[NB_VOICE][NB_STEP] =  {0};
int actual_step = 0;
int selected_step = 0;
int page = 0;

//---------------------Le temps--------------------------
int BPM = 10;
int clockDivider = 4;
int step_length = 250; // 120BPM par défaut
unsigned long currentMillis = 0;
unsigned long previousMillis = 0;
unsigned long step_start = 0;
unsigned long step_end = 0;

unsigned long gate_start[NB_PART] = {0};
unsigned long gate_end[NB_PART] = {0};
unsigned long gate_length[NB_PART] = {0};
float max_gate_time = 0;
float min_gate_time = 0;

//------------------------Mémoire------------------------
int address[NB_PART][NB_STEP] = {0};
int addressNum = 0;
/*
  =========================================================================================================
  =========================================================================================================SETUP
  =========================================================================================================
*/
void setup() {
  Serial.begin(115200);

  pinMode(tempoPotPin, INPUT);

  pinMode(SER_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);
  //Reset tous les pins du 74HC595
  clearRegisters();
  writeRegisters();

  for (int V = 0; V < 4; ++V)
  {
    pinMode(voicePin[V], OUTPUT);
    digitalWrite(voicePin[V], HIGH);
    delay(150);
    digitalWrite(voicePin[V], LOW);
    delay(150);
  }

}
/*
  =========================================================================================================
  =========================================================================================================LOOP
  =========================================================================================================
*/
void loop() {

  for (actual_step = 0; actual_step < NB_STEP; ++actual_step)
  {
    step_start = millis();

    boolean myFlag = true;
    while (myFlag == true)
    {
      /*
        Pseudo code :
        On regarde si le sequencer est sur pause/stop (sur pause par défaut)
          On allume la led corespondant au pas actuel
          On regarde quel part est selectionée
          On regarde si le tempo à changé
          On regarde se des pas on étaient activer/desactiver
          On allume la led du pas actuel et on éteint celle du pas d'avant
          On regarde si la taille de la gate a changer
            step_end = step_start + step_length;
            gate_end = step_end - gate_length;
          On regarde si on utilise le copier/coller
          On regarde si on charge/sauvegarde
      */
      for (part = 0; part < NB_PART; ++part)
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
    }
  }

  currentMillis = millis();
  if (currentMillis - previousMillis >= stepLength)  // Si on dépasse la taille du STEP
  {
    previousMillis = currentMillis; // On enregistre le début du nouveau STEP
    myFlag = false; // On ferme le second process
  } //On passe au STEP suivant
}
