# Conspiracy

Conspiracy is a game developed for students of the course IJE of UnB-FGA college. The game has the puzzle genre.

## History

The history of mankind goes through several mysteries, where some dare to say, that these events come from some extraterrestrial origin. Several theories arise at any moment, in the attempt to explain from the appearance of magnificent constructions until taken of the government.

In Brazil, a certain politician behaves strangely, with terrifying facial expressions and some conspiracy theorists claim that this politician is a strange being who has been infiltrating the country's political system for years. At some point of instability in the country, E. Temer, as he is called by some, decides to take for himself the political power of the country. E.Temer will count on the help of his companions from other galaxies, E.T. Bilu and E.T. De Varginha, on a mission at the farm ministry, where they will change documents that blame the current president for the execution of fiscal pedals. This audacious mission was organized with the intention of provoking the impeachment of the president, culminating in E. Temer as the new president of the country.

## GamePlay
### Description
It is possible and necessary to control three characters with different abilities. They are: E.T. Bilu, E.T. De Varginha and E.Temer. These skills are necessary to fulfill the main purpose: to change the data of the government accounts to incriminate the current president of the country. Each phase consists of several challenges where cooperation between the characters is vital. The essential purpose of each phase is to change all the documents present and position all the characters on the ladder. As the player advances through the stages, more difficult puzzles are introduced, as well as more guards and detection systems.

### Rules

There are three characters with pre-defined skills. All phases start with the characters grouped in a small space.

### Interactions

Interactions occur between a character and an element during the game. The interactions are listed below:

* Levers: Used to open doors to allow ETs to pass
* Documents: Papers are available throughout the phase that can be tampered with.
* Computers: Just like documents, computers can be tampered with.
* Security System: E.T Bilu can disarms them so that the other E.T.s can move around that place.

### Victory Condition

* All E.T.s must pass undetectable to the ladder, during which all present documents must be changed.

### Lose Condition
* If an E.T kills a human and does not end the phase in 60 seconds.
* If any E.T is detected by humans or a security system.

## Characters
The game has three alternate characters and unique abilities.

* E.T. Bilu: He is the head of the team, being responsible for the intellectual work of the coup. He also wrote the future speeches of E. Temer for the aftermath of the aliens. Bilu is able to alter documents and intrude on security systems in buildings.

* E.T de Varginha: He is less agile than the others, but, his fame amplified his powers. The E.T de Varginha is capable of lowering and being undetectable by humans, even in recorded images the human brain is not able to perceive it.

* E.Temer: This alien may not be the smartest, or even not be able to stay invisible. But his oratorical skills impress even the most elegant journalist. Despite its exotic appearance, E. Temer was able to obtain a very convincing mask for interacting with humans and distracting them during the activities of the coup.

## Enemies

The enemies are the same in all phases, changing only the amount in each of them and their positions. There are 3 types of enemies, the guards of the ministry, reporters and the local security cameras.

* Guards: They can stand or move in a fixed trajectory. If any of the aliens, except E. Temer, is seen, the player loses.
* Reporters: They can stand or move on a fixed path. If E. Temer is seen, he is talking for 20 seconds and if the other aliens are seen the player loses.
* Cameras: They can only be stopped at a fixed location, watching certain sections. The E.T. de Varginha is the only one that can not be seen by the cameras, the others, if they are seen. The player loses.

The player has the option of killing guards and reporters, but will trigger a 60 second chronometer to the end of the phase.

## Controls

| Key | Action |
|:-----:|:----:|
|![Remotos](https://raw.githubusercontent.com/wiki/IJE-Valhalla/Conspiracy/image/key_up.png)|Move character up|
|![Remotos](https://raw.githubusercontent.com/wiki/IJE-Valhalla/Conspiracy/image/key_down.png)|Move character down|
|![Remotos](https://raw.githubusercontent.com/wiki/IJE-Valhalla/Conspiracy/image/key_left.png)|Move character left|
|![Remotos](https://raw.githubusercontent.com/wiki/IJE-Valhalla/Conspiracy/image/key_right.png)|Move character right|
|![Remotos](https://raw.githubusercontent.com/wiki/IJE-Valhalla/Conspiracy/image/key_one.png)|Select the ETemer character|
|![Remotos](https://raw.githubusercontent.com/wiki/IJE-Valhalla/Conspiracy/image/key_two.png)|Select the E.T. de Varginha character|
|![Remotos](https://raw.githubusercontent.com/wiki/IJE-Valhalla/Conspiracy/image/key_three.png)|Select the E.T. Bilu character|
|![Remotos](https://raw.githubusercontent.com/wiki/IJE-Valhalla/Conspiracy/image/key_space.png)|Interaction with objects and enemies of the phase|

## Dependencies

- CMake 3.5.1
- SDL 2
- SDL\_image 2
- SDL\_ttf 2
- SDL\_mixer 2

## How to build

### Debian like OS
```
$ sudo apt-get install libsdl2-dev libsdl2-mixer-dev libsdl2-ttf-dev libsdl2-image-dev 
$ git clone https://github.com/IJE-Valhalla/Conspiracy.git
$ cd Conspiracy
$ cmake .
$ make
$ ./conspiracy
```

### Arch Linux
To install the sdl dependencies on arch linux you need those
packages:

- https://www.archlinux.org/packages/extra/x86_64/sdl2/
- https://www.archlinux.org/packages/extra/x86_64/sdl2_image/
- https://www.archlinux.org/packages/extra/x86_64/sdl2_ttf/
- https://www.archlinux.org/packages/extra/x86_64/sdl2_mixer/

After install those packages all you need to do is to open you
terminal and do:
```
$ cd Conspiracy
$ cmake .
$ make
$ ./conspiracy
```


## Authors

### Developers
- Rodrigo Oliveira Campos (@rodrigocam)
- Pablo Diego Silva da Silva (@pablodiegoss)
- Ronyell Henrique dos Santos (@Ronyell)

### Artist
 - Vitor Paz Guedes (vitor.paz.guedes@gmail.com)

### Musician
 - Daniel Gillez Araújo Silva
