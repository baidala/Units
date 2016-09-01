#include <iostream>
//#include "Wizard.h"
//#include "Soldier.h"

#include <vector>
#include "Location.h"

#define SQUARE 8

int main() {
    //Wizard* merlin = new Wizard();
    //Wizard* merlock = new Wizard();
    //Soldier* soldier = new Soldier();
    
    //std::cout << merlin << std::endl;
    //std::cout << merlock << std::endl;
    //std::cout << soldier << std::endl;
    
    //std::cout << "----soldier attack----" << std::endl;
    //soldier->attack(merlin);
    
    //std::cout << merlin << std::endl;
    //std::cout << merlock << std::endl;
    //std::cout << soldier << std::endl;
    
    //BattleField* bf = new BattleField(8);
    
    //Location* loc;
    //std::list<Location*> locList;
    
    std::vector<std::vector<Location*>> array2;
    
        
    for (int i = 0 ; i < SQUARE; i++){
		for (int j = 0 ; j < SQUARE; i++) {
			array2[i][j] = new Location(i,j);;
		}
	}
    
    



    return 0;
}
