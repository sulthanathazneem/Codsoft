#include<iostream>
int main()
{
    int num1,num2;
    char op,choice;
    do{
        std::cout<<"Enter two numbers: ";
        std::cin>>num1>>num2;
        std::cout<<"Enter the operand to be used [+,-,*,/,%]: \n";
        std::cin>>op;
        switch(op)
        {
        case '+':
            std::cout<<(num1+num2);
            break;
        case '-':
            std::cout<<(num1-num2);
            break;
        case '*':
            std::cout<<(num1*num2);
            break;
        case '/':
            std::cout<<(num1/num2);
            break;
        case '%':
            std::cout<<(num1%num2);
            break;
        default:
            break;
        }

        std::cout<<"\nDo you want to do it again?[y/n]: ";
        std::cin>>choice;
    }while(choice=='Y'||choice=='y');
    return 0;
}