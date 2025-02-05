#include "apartments/library.h"
#define n 9
int main(int argc, char* argv[]) {
    system("chcp 65001>nul");

    Aparts *obj=new Aparts[n];
    int count = readfile("AllApartments.txt",obj);
    int choice;
    bool continue_prog=true;;
    while (continue_prog) {
        std::cout<<"Выберете действие:"<<"\n";
        std::cout<<"1 - вывод в консоль"<<"\n"<<"2 - удаление квартиры"<<"\n"<<"3 - добавление новой квартиры"<<"\n"<<"4 - редактирование квартиры"<<"\n"
                 <<"5 - сортировка квартиры"<<"\n"<<"6 - вывод в файл"<<"\n";;
        std::cin>>choice;
        switch (choice) {
            case 1:                         //вывод в консоль
                print_base(count, obj);
                std::cout<<"\n";
                break;
            case 2:
                obj= delete_aparts(obj,count);
                print_base(count, obj);
                std::cout<<"\n";
                break;
            case 3:
                obj= add_aparts(obj,count);
                print_base(count, obj);
                std::cout<<"\n";
                break;
            case 4:
                obj= edit_aparts(obj,count);
                print_base(count, obj);
                std::cout<<"\n";
                break;
            case 5:
                obj= sort_square(obj,count);
                print_base(count, sort_square(obj, count));
                std::cout<<"\n";
                break;
            case 6:
                write_in_file(count,obj);
                std::cout<<"\n";
                break;
            default:
                std::cout << "Нет такого действия";
        }
        std::cout<<"Продолжить? y/n"<<"\n";
        char decision;
        std::cin>>decision;
        if(decision=='y'){
            continue_prog=true;
        }
        else{continue_prog=false;}
    }
    delete[] obj;
    return 0;
}