#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>

class Animal{
    public:
        std::string name;
        int count=25;
        int fate=-1;

        Animal(std::string name) : name(name) {}

        void applyFate(){
            if(fate==0)
                count-=5;
            else if(fate==1)
                count+=5;
            fate=-1;
        }
};

std::string winner;

bool beats(int i, int j){
    return (j - i + 3) % 3 == 1;    // Animal i beats Animal j when j is the next species after i
}

int indexOf(Animal* target, Animal* animals[], int total){
    for(int i=0;i<total;i++)
        if(animals[i]==target)
            return i;
    return -1;
}

void game(){
    Animal wildBull("Wild Bulls");
    Animal mongoose("Mongooses");
    Animal snake("Snakes");
    Animal* animals[]={&wildBull,&mongoose,&snake};
    const int total=3;

    srand(time(0));

    while(true){
        std::cout << "\nWild Bulls : "<< wildBull.count;
        std::cout << "\nMongooses : "<< mongoose.count;
        std::cout << "\nSnakes : "<< snake.count << "\n\n";

        for(int i=0;i<total;i++){
            if(animals[i]->count>=100){
                winner=animals[i]->name;
                return;
            }
        }

        std::vector<Animal*> alive;
        for(int i=0;i<total;i++)
            if(animals[i]->count>0)
                alive.push_back(animals[i]);

        if(alive.size()==1){
            winner=alive[0]->name;
            return;
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));

        int faceOff1=rand()%(int)alive.size();
        int faceOff2=rand()%(int)alive.size();
        Animal* first=alive[faceOff1];
        Animal* second=alive[faceOff2];

        if(first==second){
            first->fate=1;
        }
        else{
            int i1=indexOf(first, animals, total);
            int i2=indexOf(second, animals, total);
            if(beats(i1,i2))
                second->fate=0;
            else if(beats(i2,i1))
                first->fate=0;
        }

        wildBull.applyFate();
        mongoose.applyFate();
        snake.applyFate();
    }
}

int main(){
    std::cout << "************************************************************************************************************************\n\n";
    std::cout << "Welcome to the Jungle !!\n\n\n";
    std::cout << "Rules of the Jungle :\n\n1.Mongooses beat Snakes\n2.Snake beats Wild Bulls\n3.Wild Bulls beat Mongooses\n4.If the same animal face each other, they mate and increase their number\n5.Game ends when there is only one species left in the jungle, or one of the species become overpopulated\n\n\n";
    std::cout << "Choose your animal :\n\n1.Wild Bulls\n2.Mongooses\n3.Snakes\n";
    std::cout << "\n************************************************************************************************************************\n";
    int choice;
    std::string user;
    std::cin >> choice;
    std::cout << "************************************************************************************************************************\n\n";
    switch(choice){
        case 1: user="Wild Bulls";break;
        case 2: user="Mongooses";break;
        case 3: user="Snakes";break;
        default: user=""; std::cout << "I see you are vegetarian..........\n\n";
    }
    std::cout << "Starting population for each animal = 25\n\n";

    game();
    if(user==winner){
        std::cout<<"\n\nYou won!!\n\n";
    }
    else if(user==""){
        std::cout<<"\n\n";
    }
    else{
        std::cout<<"\n\nYou loose!!\n\n";
    }
    std::cout << "************************************************************************************************************************\n";
    std::string Ender;
    std::cin >> Ender;
    return 0;
}
