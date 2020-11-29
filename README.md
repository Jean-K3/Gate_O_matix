# Gate_O_matix

Gate sequencer by Jean_k<3

  Update 29 Nov 2020

  64 step sequencer, 8 part compatible eurorack

  ________________________________________________________________________________________________
  ________________________________________________________________________________________________
  ________________________________________________________________________________________________

  TODO :

  SOFTWARE :

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


  HARDWARE:
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

  Bouttons :
    Step on/off (last = selected step) + shift = step jump (1 2 3 jump 5)
    Copy/Paste + shift = Save
    Fill + shift = Clear
    Pause/Play + shift = Stop

   Encoder:
    Tempo + push = clock divider
      Tempo + shift = Forward/Backward/Random
    Page navigation + push = Number of pages
    Gate size + push = Number of step

   Selecter :
    Part choice + shift = patern choice

  --------------------------------------------------------------------------

  ANALOGUE PIN :
  1 Selecteur pour les parts
  3 encoder pour le tempo/clock divider, gate/step, page/nombre de page

  DIGITAL PIN :

  jack : 12
    OUTPUT:
      Clock out
      Reset out
      8 Gate out
      INPUT :
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
