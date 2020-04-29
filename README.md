# Náplň cvičenia
- pokračovť v plnení úloh z predchádzajúceho cvičenia (vrs_cvicenie_2)
- spresnenie úlohy č. 2 

# Zadanie
### Vytvorťe funkciu na detekciu hrany:

```javascript
EDGE_TYPE edge_detect(uint8_t pin_state, uint8_t samples);
```

- definujte enum "EDGE_TYPE", ktorý bude mať 3 prvky: 0 - žiadna hrana (NONE), 1 - nábežna hrana (RISE), 2 -dobežna hrana (FALL)
- definovaný enum bude slúžiť ako návratová hodnota funkcie "edge_detect"
- vstupný parameter "pin_state" je aktuálny stav vstupného pinu (hodnota 0,1), na ktorom sa deteguje hrana 
- vstupný parameter "samples" definuje, koľkokrát v rade musí byť detegovaný nový stav vstupného pinu, aby sa to považovalo za hranu
  - Príklad: 
    - predchádzajúci stav = 0, aktuálny stav = 1, samples = 5
    - aby bola detegovaná hrana, musí sa 5-krát v rade prečítať rovnaký stav tj. 0,1,1,1,1,1 - nábežná hrana bola detegovaná
    - ak by pri čítaní zo vstupného pinu nastala situácia 0,1,1,1,0,1 - pri zmene stavu z 0 na 1 sa na vstupe vyčítala hodnota 1 len 3-krát v rade, vyhodnotí sa to ako "žiadna hrana" pretože nebola splnená podmienka

- po zdetegovaní hrany(nábežnej alebo dobežnej) zmente stav LED z vypnutej na zapnutú a opačne
- ##### ako vstup využite GPIOA pin 3

#### Zadania odovzdávajte na e-mail: predmet.vrs@gmail.com
#### Odovzdáva sa subor "main.c".


#### Do point 1 - 4 in exact order.
#### Clone branch of required library version from git repository.
#### Build and install from cloned repository.

1. Install FCL dependencies:
    - Eigen library: https://gitlab.com/libeigen/eigen.git (version 3.3.7)
    - OctoMap: https://github.com/OctoMap/octomap.git (version 1.8)
    - libccd: https://github.com/danfis/libccd.git (master branch)
    
2. Install FCL (flexible collision library):
    - https://github.com/flexible-collision-library/fcl.git (version fcl-0.5)

3. Install/check OMPL dependencies:
    - chcek BOOST version (enter into terminal): "dpkg -S /usr/include/boost/version.hpp"
    - BOOST (version 1.54 or higher) - https://www.boost.org/

4. OMPL (open motion library):
    - https://github.com/ompl/ompl.git (version 1.4.2)
    
5. Required ROS packages:
    - clone repositories to the catkin workspace and build them
	  - octomap_ros: https://github.com/OctoMap/octomap_ros.git
	  - octomap_msgs: https://github.com/OctoMap/octomap_msgs.git
