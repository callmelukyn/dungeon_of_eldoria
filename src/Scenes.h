//
// Created by Lukyn on 06.12.2024.
//

#ifndef SCENES_H
#define SCENES_H
#include <iostream>
#include "color.h"

class Scenes {
public:
    Scenes();

    //Scene text
    void continueHint() const;

    void prologText1() const;

    void prologText2() const;

    void prologText3() const;

    //Scene arts
    void prologArt1() const;

    void prologArt2() const;

    void prologArt3() const;

    //Whole cutscenes
    void sceneProlog1() const;

    void sceneProlog2() const;

    void sceneProlog3() const;

    //Menu scenes
    void sceneHeaderMenu() const;

    void sceneSmallHeaderMenu() const;

    void sceneMainSelectedPlay() const;

    void sceneMainSelectedCredits() const;

    void sceneMainSelectedHTP() const;

    void sceneMainSelectedExit() const;

    void sceneCreditsMenu() const;

    void sceneHTPMenu() const;

    void sceneRoleSelectedWarrior() const;

    void sceneRoleSelectedArcher() const;

    void sceneRoleSelectedMage() const;
};


#endif //SCENES_H
