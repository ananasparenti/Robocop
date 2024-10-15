# Robocop 🤖
[![forthebadge](http://forthebadge.com/images/badges/built-with-love.svg)](http://forthebadge.com) 

Vous trouverez dans ce repo github, tout les outils et code nécessaires à la création de votre robot télécommandé par votre propre application mobile (en BT).

### À savoir 👀
La framework Flutter utilisé permets d'utiliser ce code pour divers support tel qu'un Iphone, un Android ou encore une tablette.

Cependant si vous ne souhaitez pas développer votre propre application mobile, vous pouvez utiliser directement celles existante gratuitement :
* [Arduino Bluetooth Controller](https://play.google.com/store/apps/details?id=com.giumig.apps.bluetoothserialmonitor&hl=fr)
* [Serial Bluetooth Terminal](https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal&hl=fr)

Libre à vous de choisir !

### Pré-requis 📌
Pour commencer votre projet vous aurez besoin d'au moins :

- Avoir une petite connaissance d'Arduino.

(Faire la différence entre un port lambda et un PWM pourrait par exemple vous éviter de rester bloquer 1 heure sans comprendre POURQUOI ça ne fonctionne pas...)
- Avoir des IDE pouvant supporter du cpp ou du Dart. (Arduino, Visual Studio Code, Android Studio...)
- (Beaucoup de piles)

### Composants éléctronique du robot 🪛

- une carte Arduino
- un module bluetooth HC-05
- 2 motoréducteurs avec roues
- un pont en H, L298N
- des piles 9V
- une Led RGB
- des câbles
- un chassis

### Mise en place 🙌

- Faire le montage du robot, vous trouverez le schéma dans le dossier **ressources**.
  Laisser la carte Arduino accesible ainsi que son alimentation. (Oui le dossier ressources n'est pas encore en ligne, cela ne saurait tarder !)
- A l'aide de votre IDE téléchargez sur votre téléphone l'application qui se trouve dans le dossier **code_app**.
- Programmez la carte Arduino de votre robot en lui envoyant le programme qui se trouve dans le dossier **code_Arduino**.

- Enfin, n'hésitez pas à améliorer le programme et m'en faire un retour!

### Fabriqué avec 💡

* [VsCode](https://code.visualstudio.com/) - Visual Studio Code
* [Arduino](https://www.arduino.cc/) - Arduino

### Auteures 📝
* **Anaïs Parenti** _alias_ [@anais.parenti@epitech.eu](https://github.com/ananasparenti)
* **Sara Himmich** _alias_ [@sara.himmich@epitech.eu](https://github.com/Sara28himmich)

