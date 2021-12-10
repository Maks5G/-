#include <iostream>
#include "complex.cpp"

int main(int argc, char* argv[]){

    setlocale (LC_CTYPE, "ukr");
    int choice;
    std::cout << "What type of problems you want to solve?(Enter 2, 3 or 4)"  << std::endl; // 2 - квадратне рівняння. 3 - кубічне рівняння. 4 - рівняння 4-го степеня. 0 - вихід.
    std::cin >> choice;
    while(choice!=0){
        switch(choice){
            case 2:{
                //Complex a, b, c;
                double im, re;                                                    
                std::cout << "Enter a" << std::endl;
                //std::cin >> a;
                std::cout << "Введіть дійсну і уявну частини: " << std::endl;
                std::cin >> re >> im;
                std::complex< double > a(re, im);   
                
                std::cout << "Enter b" << std::endl;
                //std::cin >> b;
                std::cout << "Введіть дійсну і уявну частини: " << std::endl;
                std::cin >> re >> im;
                std::complex< double > b(re, im);

                std::cout << "Enter c" << std::endl;
                //std::cin >> c;
                std::cout << "Введіть дійсну і уявну частини: " << std::endl;
                std::cin >> re >> im;
                std::complex< double > c(re, im);

                quadric(a, b, c);
                break;
            }
            case 3:{
                double im, re;                                                    
                std::cout << "Enter a" << std::endl;
                std::cout << "Введіть дійсну і уявну частини: " << std::endl;
                std::cin >> re >> im;
                std::complex< double > a1(re, im);   
                
                std::cout << "Enter b" << std::endl;
                std::cout << "Введіть дійсну і уявну частини: " << std::endl;
                std::cin >> re >> im;
                std::complex< double > b1(re, im);
                
                std::cout << "Enter c" << std::endl;
                std::cout << "Введіть дійсну і уявну частини: " << std::endl;
                std::cin >> re >> im;
                std::complex< double > c1(re, im);

                std::cout << "Enter d" << std::endl;
                std::cout << "Введіть дійсну і уявну частини: " << std::endl;
                std::cin >> re >> im;
                std::complex< double > d(re, im);

                cubic(a1, b1, c1, d);
                break;
            }
            case 4:{
                double im, re;                                                    
                std::cout << "Enter a" << std::endl;
                std::cout << "Введіть дійсну і уявну частини: " << std::endl;
                std::cin >> re >> im;
                std::complex< double > a4(re, im);   

                std::cout << "Enter b" << std::endl;
                std::cout << "Введіть дійсну і уявну частини: " << std::endl;
                std::cin >> re >> im;
                std::complex< double > b4(re, im);
                
                std::cout << "Enter c" << std::endl;
                std::cout << "Введіть дійсну і уявну частини: " << std::endl;
                std::cin >> re >> im;
                std::complex< double > c4(re, im);

                std::cout << "Enter d" << std::endl;
                std::cout << "Введіть дійсну і уявну частини: " << std::endl;
                std::cin >> re >> im;
                std::complex< double > d4(re, im);

                std::cout << "Enter e" << std::endl;
                std::cout << "Введіть дійсну і уявну частини: " << std::endl;
                std::cin >> re >> im;
                std::complex< double > e4(re, im);

                ferrari(a4, b4, c4, d4, e4);
                break;
            }
            case 0:{
                exit (0);
            }
            default:
                break;
        }
        std::cout << "What type of problems you want to solve?(Enter 2, 3 or 4)"  << std::endl;
        std::cin >> choice;
    }
}

//Завдання 8. Комплексні числа. Спеціальність Електроніка. Пушкаренко Максим.
