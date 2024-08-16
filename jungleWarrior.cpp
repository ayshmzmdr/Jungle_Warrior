#include <iostream>
#include <ctime>
#include <unistd.h>

class Animal{
    public:
        int count=25;
        int fate=-1;
    void setCount(int fate){
        if(fate==0)
            this->count=this->count-5;
        else if(fate==1)
            this->count=this->count+5;
    }
};

std::string winner;

void game(){
    std::cout << "";
    Animal wildBull;
    Animal mongoose;
    Animal snake;
    Animal* arr[]={&wildBull,&mongoose,&snake};
    int arrSize=sizeof(arr)/sizeof(Animal);
    srand(time(0));
    int faceOff1=0;
    int faceOff2=0;
    int i=0;
    while(true){
        std::cout << "\nWild Bulls : "<< wildBull.count;
        std::cout << "\nMongooses : "<< mongoose.count;
        std::cout << "\nSnakes : "<< snake.count << "\n\n";
        if((mongoose.count==0 && snake.count==0) || wildBull.count==100){
            winner="Wild Bulls";
            break;
        }
        if((wildBull.count==0 && snake.count==0) || mongoose.count==100){
            winner="Mongooses";
            break;
        }
        if((mongoose.count==0 && wildBull.count==0) || snake.count==100){
            winner="Snakes";
            break;
        }
        sleep(1);
            wildBull.fate=-1;
            mongoose.fate=-1;
            snake.fate=-1;
            if(arr[0]==0 || arr[1]==0 || arrSize==3){
                if(mongoose.count==0){
                    arr[2]=&mongoose;
                    arr[1]=&snake;
                    arrSize--;          
                }
                
                else if(wildBull.count==0){
                    arr[2]=&wildBull;
                    arr[0]=&snake;
                    arrSize--;                   
                }
                else if(snake.count==0){
                    arrSize--;
                }
            }
            faceOff1=rand()%arrSize;
            faceOff2=rand()%arrSize;
            if(arr[faceOff1]==arr[faceOff2]){
                arr[faceOff1]->fate=1;
            }
            else{
                if(arr[faceOff1]==&wildBull && arr[faceOff2]==&mongoose){
                    arr[faceOff2]->fate=0;
                }
                
                else if(arr[faceOff1]==&wildBull && arr[faceOff2]==&snake){
                    arr[faceOff1]->fate=0;
                }
                
                else if(arr[faceOff1]==&mongoose && arr[faceOff2]==&snake){
                    arr[faceOff2]->fate=0;
                }
                else if(arr[faceOff2]==&wildBull && arr[faceOff1]==&mongoose){
                    arr[faceOff1]->fate=0;
                }
                
                else if(arr[faceOff2]==&wildBull && arr[faceOff1]==&snake){
                    arr[faceOff2]->fate=0;
                }
                
                else if(arr[faceOff2]==&mongoose && arr[faceOff1]==&snake){
                    arr[faceOff1]->fate=0;
                }
            }
            mongoose.setCount(mongoose.fate);
            wildBull.setCount(wildBull.fate);
            snake.setCount(snake.fate);
    }
    std::cout<< "Winner : "<<winner;
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