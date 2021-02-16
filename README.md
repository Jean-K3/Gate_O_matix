  Gate sequencer by Plop

  Update 08 JAN 2021

  64 step sequencer, 8 part compatible eurorack

  ________________________________________________________________________________________________
  ________________________________________________________________________________________________
  ________________________________________________________________________________________________

  TODO :

    SOFTWARE

      -Clock multiplier/diviser per part
      -Detection Clock interne/externe
      -Reset -> interupt
      -Clock ext -> interupt
      -Choix de la paterne (shift + page nav)
      -Fonction save/Load (SD card)
  

    HARDWARE

      -Use faster microcontroler
      -Finding a way to control screen with 4 pins
      -Add switching jack
      -Add SD card
      -12v alimentation
      -"transistorisation" des entrées/sorties
      
      
    SCHEMATIC
    
      -Main_Board : Assigner empreintes Encoder, Selecter & Screen
      -Find good resistor value for green & blue LED
      -Find good value resistor for screen
      -Drawing CPU_Board
      -Check for errors
      
     OTHER
     
      -Stop speaking frenglish
      -Make pancake

  DONE :

    -Encodeur Tempo
    -Afficheur 7 segments
    -Gestion des LEDs
    -Matrice de boutons
    -Fonction de choix de la part
    -Ajout du selecteur
    -Fonction de choix de la part
    -Fonction de gestion du nombre de pas
    -Fonction Pages navigation
    -Step ON-OFF
    -Fonction sens de lecture
    -Fonction Fill/Clear
    -Fonction Copy/Past
    -Lecture des bouttons de fonctions
    -Fonction pause-lecture/stop
    -Fonction de gestion de la taille de la gate
    -Fonction Step jump
    -Reset
  

  ________________________________________________________________________________________________
  ________________________________________________________________________________________________
  ________________________________________________________________________________________________


  FUNCTIONS :
  

    Bouttons =
        -Shift + step button = step jump
        -Fill + shift = Clear
        -Copy/Paste + shift = Save
        -Pause/Play + shift = Stop
    

    Encoders =
        -Tempo + push = clock divider
        -Gate length + push = Number of step
        -Page navigation + push = Forward/Backward/Random
    

    Selecter =
        -Part choice

    Play mode =
        -Forward
        -Backward
        -Ping Pong
        -Random
        -Brownien
    

  --------------------------------------------------------------------------
