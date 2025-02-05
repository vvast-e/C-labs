#include "Planets/library.h"


#define n 1
int main(int argc, char* argv[]) {
    system("chcp 65001>nul");
    int choice;
    int count=0;
    Planets *obj= readfile("system.txt",count);
    bool continue_prog=true;
    while (continue_prog) {
        std::cout << "Выберете действие:" << "\n";
        std::cout << "1 - вывод в консоль" << "\n" << "2 - удаление планеты" << "\n"
        << "3 - добавление новой планеты" << "\n" << "4 - редактирование планеты" << "\n"
        << "5 - сортировка планет" << "\n" << "6 - вывод в файл" << "\n";
        std::cin >> choice;
        switch (choice) {
            case 1:                         //вывод в консоль
            print_base(count, obj);
            break;
            case 2:
                std::cout << "1 - вывод в консоль" << "\n" << "2 - вывод в файл" << "\n";
                int choice1;
                std::cin >> choice1;
                obj = delete_planet(obj, count);
                if (choice1 == 1) {
                    print_base(count, obj);
                } else {
                    write_in_file(count, obj);
                }
                break;
                case 3:
                    std::cout << "1 - вывод в консоль" << "\n" << "2 - вывод в файл" << "\n";
                    int choice2;
                    std::cin >> choice2;
                    obj = add_planet(obj, count);
                    if (choice2 == 1) { print_base(count, obj); }
                    else { write_in_file(count, obj); }
                    break;
                case 4:
                    std::cout << "1 - вывод в консоль" << "\n" << "2 - вывод в файл" << "\n";
                    int choice3;
                    std::cin >> choice3;
                    obj = edit_planet(obj, count);
                    if (choice3 == 1) { print_base(count, obj); }
                    else { write_in_file(count, obj); }
                    break;
                case 5:
                    std::cout << "1 - вывод в консоль" << "\n" << "2 - вывод в файл" << "\n";
                    int choice4;
                    std::cin >> choice4;
                    if (choice4 == 1) { print_base(count, sort_diam(obj, count, true)); }
                    else { write_in_file(count, sort_diam(obj, count, true)); }
                    obj = readfile("system.txt", count);
                    break;
                case 6:
                    write_in_file(count, obj);
                    break;
                default:
                    std::cout << "Нет такого действия";
                }std::cout<<"Продолжить? y/n"<<"\n";
                char decision;
                std::cin>>decision;
                if(decision=='y'){
                    continue_prog=true;
                }
                else{continue_prog=false;}
            }

    return 0;
}
