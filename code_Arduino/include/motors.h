/*
** EPITECH PROJECT, 2024
** .h
** File description:
** for robocop project
*/

#ifndef MOTORS_H_
    #define MOTORS_H_

enum EDirection {
    FORWARD,
    BACKWARD,
    STOP
};

class Motors {
    private:
        int sens_horaire = 0; //pin number gpio port entrée sortie
        int sens_anti_horaire = 0;
        int enable = 0;
        EDirection direction;
        int vitesse = 0;
        const char *motors;
        void SetSpeed();
    public:
        void accelerate();
        void decelerate();
        void horaire();
        void anti_horaire();
        void stop();
        Motors(); // je triche 
        Motors(int horaire, int anti_horaire, int enable, const char *motors);
};

#endif /* !MOTORS_H_ */
