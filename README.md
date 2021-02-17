  Gate sequencer by Plop

  Update 17 FEB 2021

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
    
      -Find good resistor value for green & blue LED
      -Find good value resistor for screen
      -Drawing CPU_Board


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
        -Step on/off
        -Shift + step button = step jump
        -Fill
        -Fill + shift = Clear
        -Copy/Paste
        -Copy/Paste + shift = Save
        -Pause/Play
        -Pause/Play + shift = Stop
    

    Encoders =
        -Tempo
        -Tempo + push = clock divider
        -Gate length
        -Gate length + push = Number of step
        -Page navigation
        -Page navigation + push = Play mode
    

    Selecter =
        -Part choice

    Play mode =
        -Forward
        -Backward
        -Ping Pong
        -Random
        -Brownien
    

  --------------------------------------------------------------------------
