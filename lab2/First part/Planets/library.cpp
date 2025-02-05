#include "library.h"

#include <iostream>

std::ostream& operator << (std::ostream &os, Planets &Planets){
    os<<Planets.getName()<<"\t"<<Planets.getDiam()<<"\t"<<Planets.getLife()<<"\t"<<Planets.getSatellites()<<std::endl;
    return os;
}

std::istream& operator>>(std::istream &in,Planets &Planets){
    char* name=new char[20];
    int diameter;
    bool life;
    int satellites;
    in>>name>>diameter>>life>>satellites;
    Planets.setAll(name,diameter,life,satellites);
    return in;
}

Planets* readfile(const char *Filename, int &count) {
    std::fstream fin(Filename, std::ios::in);
    fin.seekg(0, std::ios_base::beg);
    char name[30];
    int diameter = 0;
    bool life;
    int satellites = 0;
    if (fin.is_open()) {
        fin>>count;
        Planets *ary=new Planets[count];
        int n=0;
        while (!fin.eof()) {
            fin >> name >> diameter >> life >> satellites;
            ary[n++].setAll(name,diameter,life,satellites);
        }
        return ary;
    }
    fin.close();

}

void print_base(int count, Planets *ary) {
    for (int i = 0; i < count; i++) {
        std::cout<<ary[i];
    }

}

void write_in_file(int count,Planets *ary) {
    std::ofstream out;
    out.open("system.txt");
    if (out.is_open()) {
        out<<count<<"\n";
        for (int i = 0; i < count; i++) {
            out << ary[i];
        }
        out.close();
    }
}
int find_ind(Planets *ary, int count, const char* name) {
    int ind;
    for (int i = 0; i < count; i++) {
        if (strcmp(ary[i].getName(), name) == 0) {
            ind = i;
            return ind;
        }

    }
}

Planets *delete_planet( Planets *ary, int &count){
    char name_delete[30];
    std::cout<<"Введите название планеты"<<"\n";
    std::cin>>name_delete;
    int ind= find_ind(ary,count,name_delete);
    count-=1;
    Planets *_ary=new Planets[count];
    int j=0;
    for(int i=0;i<count+1;i++){
        if(ind!=i){
            _ary[j]=ary[i];
            j++;
        }
    }
    return _ary;
    delete [] _ary;
}

Planets *add_planet(Planets *ary,int &count){
    count+=1;
    Planets *_ary=new Planets[count];
    Planets obj[1];
    char* name=new char[30];
    int diameter;
    bool life;
    int satellites;
    std::cout<<"Введите новую планету"<<"\n";
    std::cin>>name;
    obj[0].setName(name);
    std::cin>>diameter;
    obj[0].setDiam(diameter);
    std::cin>>life;
    obj[0].setLife(life);
    std::cin>>satellites;
    obj[0].setSatellites(satellites);
    for (int i=0;i<count-1;i++){
        _ary[i]=ary[i];
    }
    _ary[count-1].setAll(obj[0].getName(),obj[0].getDiam(),obj[0].getLife(),obj[0].getSatellites());
    return _ary;
    delete[] _ary;
}



Planets *edit_planet(Planets *ary,int count){
    std::cout<<"Введите название ";
    char name_edit[30];
    std::cin>>name_edit;
    int ind= find_ind(ary,count,name_edit);
    std::cout<<"1 - изменить название"<<"\n"<<"2 - изменить диаметр"<<"\n"<<"3 - изменить наличие жизни"<<"\n"<<"4 - изменить количество спутников"<<"\n";
    int choice;
    std::cin>>choice;

    switch (choice) {
        case 1:
            char new_name[30];
            std::cout<<"Введите имя"<<"\n";
            std::cin>>new_name;
            ary[ind].setName(new_name);
            break;
        case 2:
            int new_diameter;
            std::cout<<"Введите диаметр"<<"\n";
            std::cin>>new_diameter;
            ary[ind].setDiam(new_diameter);
            break;
        case 3:
            if(ary[ind].getLife()==1){ ary[ind].setLife(false);}
            else{ary[ind].setLife(true);}
            break;
        case 4:
            int new_satellites;
            std::cout<<"Введите количество спутников"<<"\n";
            std::cin>>new_satellites;
            ary[ind].setSatellites(new_satellites);
            break;
        default:
            std::cout<<"нет такого действия";
            break;
    }
    return ary;
}

void swap(Planets* ary,int i,int j){
    Planets _ary[1];
    _ary[0].setAll(ary[i].getName(),ary[i].getDiam(),ary[i].getLife(),ary[i].getSatellites());
    ary[i].setAll(ary[j].getName(),ary[j].getDiam(),ary[j].getLife(),ary[j].getSatellites());
    ary[j].setAll(_ary[0].getName(),_ary[0].getDiam(),_ary[0].getLife(),_ary[0].getSatellites());
}

Planets *sort_diam(Planets *ary,int count, bool choice){
    for(int i=0;i<count;i++){
        for(int j=0;j<count-1;j++){
            if(choice){     //возрастание
                if(ary[j].getDiam()<ary[j+1].getDiam()) {
                    swap(ary, j, j + 1);
                }
            }
            else{
                if(ary[j].getDiam()>ary[j+1].getDiam()){
                    swap(ary,j,j+1);
                }
            }
        }
    }
    return ary;
}
