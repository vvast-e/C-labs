#include "library.h"

std::ostream& operator << (std::ostream &os, Aparts &Aparts){
    os<<std::setw(10)<<Aparts.getName()<<"\t"<<Aparts.getsquare()<<"\t"<<Aparts.getmetro()<<"\t"<<Aparts.getprice();
    return os;
}
std::istream& operator>>(std::istream &in,Aparts &Aparts){
    char* name=new char[20];
    int square;
    bool metro;
    int price;
    in>>name>>square>>metro>>price;
    Aparts.setAll(name,square,metro,price);
    return in;
}
int readfile(const char *Filename, Aparts *&ary) {
    int n = 0;
    std::fstream fin(Filename, std::ios::in);
    fin.seekg(0, std::ios_base::beg);
    char name[30];
    int square = 0;
    bool metro;
    int price = 0;
    int count=0;
    if (fin.is_open()) {

        fin>>count;
        while (!fin.eof()) {
            fin >> name >> square >> metro >> price;
            ary[n++].setAll(name, square, metro, price);
        }
    }
    fin.close();
    return count;
}

void print_base(int count, Aparts *ary) {
    for (int i = 0; i < count; i++) {
        if(i!=count-1) {
            std::cout << ary[i] << "\n";
        }
        else{
            std::cout<<ary[i];
        }
    }
}

void write_in_file(int count,Aparts *ary){
    std::ofstream out;
    out.open("AllApartments.txt");
    if(out.is_open()){
        out<<count<<"\n";
        for(int i=0;i<count;i++){
            if (i!=count-1) {
                out << ary[i] << "\n";
            }
            else{
                out<<ary[i];
            }
        }
    }
    out.close();
}

int find_ind(Aparts *ary, int count, const char* name){
    int ind;
    for(int i=0;i<count;i++){
        if(strcmp(ary[i].getName(),name)==0) {
            ind = i;
            return ind;
        }

    }
}

Aparts *delete_aparts( Aparts *ary, int &count){
    char name_delete[30];
    std::cout<<"Введите название района"<<"\n";
    std::cin>>name_delete;
    int ind= find_ind(ary,count,name_delete);
    count-=1;
    Aparts *_ary=new Aparts[count];
    int j=0;
    for(int i=0;i<count+1;i++){
        if(ind!=i){
            _ary[j]=ary[i];
            j++;
        }
    }
    return _ary;
}

Aparts *add_aparts(Aparts *ary,int &count){
    count+=1;
    Aparts *_ary=new Aparts[count];
    std::cout<<"Введите новую квартиру"<<"\n";
    for (int i=0;i<count-1;i++){
        _ary[i]=ary[i];
    }
    std::cin>>_ary[count-1];
    return _ary;
}



Aparts *edit_aparts(Aparts *ary,int count){
    std::cout<<"Введите название ";
    char name_edit[30];
    std::cin>>name_edit;
    int ind= find_ind(ary,count,name_edit);
    std::cout<<"1 - изменить название района"<<"\n"<<"2 - изменить площадь"<<"\n"<<"3 - изменить наличие метро поблизости"<<"\n"<<"4 - изменить цену"<<"\n";
    int choice;
    std::cin>>choice;

    switch (choice) {
        case 1:
            char new_name[30];
            std::cout<<"Введите название района"<<"\n";
            std::cin>>new_name;
            ary[ind].setName(new_name);
            break;
        case 2:
            int new_square;
            std::cout<<"Введите площадь"<<"\n";
            std::cin>>new_square;
            ary[ind].setsquare(new_square);
            break;
        case 3:
            if(ary[ind].getmetro()==1){ ary[ind].setmetro(false);}
            else{ary[ind].setmetro(true);}
            break;
        case 4:
            int new_price;
            std::cout<<"Введите цену"<<"\n";
            std::cin>>new_price;
            ary[ind].setprice(new_price);
            break;
        default:
            std::cout<<"нет такого действия";
            break;
    }
    return ary;
}

void swap(Aparts* ary,int i,int j){
    Aparts _ary[1];
    _ary[0].setAll(ary[i].getName(),ary[i].getsquare(),ary[i].getmetro(),ary[i].getprice());
    ary[i].setAll(ary[j].getName(),ary[j].getsquare(),ary[j].getmetro(),ary[j].getprice());
    ary[j].setAll(_ary[0].getName(),_ary[0].getsquare(),_ary[0].getmetro(),_ary[0].getprice());
}

Aparts *sort_square(Aparts *ary,int count){
    for(int i=0;i<count;i++){
        for(int j=0;j<count-1;j++){//возрастание
            if(ary[j].getsquare()<ary[j+1].getsquare()) {
                    swap(ary, j, j + 1);
            }
        }
    }
    return ary;
}
