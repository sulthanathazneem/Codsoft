#include<iostream>
#include<random>

int main(){
    char choice;
    do{
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(1,100);

        int randomNumber=dist(gen);
        int guess,count=0;
        

        do{ 
            std::cout<<"Enter a number: ";
            std::cin>>guess;
            count++;
            if(guess>randomNumber)
            {
                std::cout<<"Too large!\n";
            }
            else if(guess<randomNumber)
            {
                std::cout<<"Too small!\n";
            }
            else
            {
                std::cout<<"That's right! You got it in "<<count<<" tries.\n";
            }
        }while(guess!=randomNumber);

        std::cout<<"Do you want to play again? (y/n) : ";
        std::cin>>choice;
    }while(choice=='Y'||choice=='y');
    
    std::cout<<"Goodbye!";
    return 0;
}
