#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <utility>
#include <vector>
#include <random>
#include <list>
#include <map>
using namespace std;

//number1
int countSentences(const std::string& text) {
    int sentenceCount = 0;
    bool inSentence = false;

    for (char ch : text) {
        if (ch == '.' || ch == '!' || ch == '?') {
            if (inSentence) {
                sentenceCount++;
                inSentence = false;
            }
        } else if (!isspace(ch)) {
            inSentence = true;
        }
    }

    if (inSentence) {
        sentenceCount++;
    }

    return sentenceCount;
}

void number1() {
    std::string text1, text2;

    std::cout << "Введите первый текст: ";
    std::getline(std::cin, text1);

    std::cout << "Введите второй текст: ";
    std::getline(std::cin, text2);

    int count1 = countSentences(text1);
    int count2 = countSentences(text2);

    std::cout << "Количество предложений в первом тексте: " << count1 << std::endl;
    std::cout << "Количество предложений во втором тексте: " << count2 << std::endl;
}




void number2(){
    std::string s1,s2;
    getline(cin,s1);
    for(int i=0;i<s1.length();i++){
        if(s1[i]!=' ' and s1[i]!=',' and s1[i]!='.'){
            s2+=s1[i];
        }
    }
    std::cout<<s2<<"\n";
}



std::string processLine(const std::string& line) {
    std::string result;
    for (char c : line) {
        if (c >= 'a' && c <= 'z') {
            result += c - 'a' + 'A';
        } else {
            result += c;
        }
    }
    return result;
}

int number3(){
    std::ifstream inputFile("D:/labs cLion/lab8/input.txt");
    std::ofstream outputFile("D:/labs cLion/lab8/output.txt");

    if (!inputFile) {
        std::cerr << "Ошибка при открытии файла для чтения." << std::endl;
        return 1;
    }

    if (!outputFile) {
        std::cerr << "Ошибка при отрытии файла для записи." << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(inputFile, line)) {
        std::string processedLine = processLine(line);
        outputFile << processedLine << std::endl;
    }
    inputFile.close();
    outputFile.close();
}



void print(vector<float> &s1,vector<float>&s2,vector<float>&s3){
    for(int i=0;i<s1.size();i++){
        cout<<s1[i]<<"\t"<<s2[i]<<"\t"<<s3[i]<<"\n";
    }
}

void number4(){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dis(0.0,100.0);
    vector<float> s1,s2,s3;
    int size=25;
    for(size_t i=0;i<size;i++){
        s1.push_back(static_cast<float>(dis(gen)));
        s2.push_back(static_cast<float>(dis(gen)));
    }
    for(size_t i=0;i<size;i++){
        s3.push_back(s1[i]+s2[i]);
    }
    print(s1,s2,s3);

}

//number5
class planet{
private:
    string name;
    int num_sat;
public:
    planet(std::string  name, int satelliteCount)
            : name(std::move(name)), num_sat(satelliteCount) {}
    friend void print(vector<planet> &s);
    string getname(){string _name=this->name;
    return _name;}
};
void print(vector<planet> &s){
    for (const auto& planet : s) {
        std::cout << "Planet: " << planet.name << ", Satellites: " << planet.num_sat << std::endl;
    }
}



void number6(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-100, 100);

    int count;
    list<int> general;
    for(int i=0;i<10;i++){
        general.push_back(dis(gen));
    }

    std::list<int>::iterator iter;
    int i = 0;
    if (!general.empty()) {
        for (iter = general.begin(); iter != general.end(); iter++, i++) {
            std::cout << "general[" << i << "] = " << *iter << std::endl;
        }
    } else{
        std::cout << "Список пуст!" << std::endl;
    }

    for(iter=general.begin(); iter!=general.end();iter++){
        if(*iter>0){
            count++;
        }
    }
    cout<<count<<"\n";
}


//number7
class Card {
    string title;   // заглавие книги
    string author;  // автор
    int number;     // количество имеющихся экземпляров
public:
    Card() : title(""), author(""), number(0) {}
    Card(string t, string a, int n) : title(t), author(a), number(n) {}
    friend int print(list<Card> &s, string &_author){
        list<Card>::iterator iter;
        for(iter=s.begin();iter!=s.end();iter++){
            if(iter->author==_author){
                std::cout<<"Title of book: "<<iter->title<<"\t"<<"count of books: "<<iter->number<<"\n";
                return 1;
            }
        }
        cout<<"No such author in list"<<"\n";
        return 0;

    };

};



void number8(){
    map<int,double> f;
    double j=1.1;
    for(int i=1;i<10;i++){
        f[i]=j;
        j+=1.1;
    }
    for(auto & iter : f){
        cout<<iter.first<<" - "<<iter.second<<"\n";
    }
    for(int i=1;i<10;i++){
        if(i%2==0){f.erase(i);}
    }
    cout<<"--------------------\n";
    for(auto iter:f){
        cout<<iter.first<<" - "<<iter.second<<"\n";
    }
}


void number9(){
    map<string, string> notebook;
    int size;
    cout<<"count of people: ";
    cin>>size;
    string mas[4] = { "1112233", "9871234", "5671234", "5556688" };
    string name,phone;
    for(int i=0;i<size;i++){
        cin>>phone>>name;
        notebook[phone]=name;
    }

    for(const auto& iter:notebook){
        for(const auto & ma : mas) {
            if (iter.first == ma) {
                cout << iter.second << "\n";
            }
        }
    }
}

int main(int argc, char* argv[]) {
    //system("chcp 65001>nul");
    //number1();

    //number2();

    //number3();

    //number4();



    //number5
/*    int size=9;
    vector<planet> data;
    int max_sat=0;
    int index=0;
    for(int i=0;i<size;i++){
        string _name;
        int _sat;
        cin>>_name>>_sat;
        data.emplace_back(_name,_sat);
        if(max_sat<_sat){
            max_sat=_sat;
            index=i;
        }
    }
    print(data);
    cout<<"Planet with the most satellites: "<<data[index].getname()<<" "<<max_sat<<"\n";*/


    //number6();

    //number7
    /*list<Card> Books;
    Books.emplace_back("dbch", "tor", 5);
    Books.emplace_back("fvvfcd", "fgbkt", 2);
    Books.emplace_back("dcdvfg", "fvnt", 12);
    Books.emplace_back("lkmcjdnc", "fv f", 14);
    Books.emplace_back("ddbvhdn", "szbchd", 45);
    string user;
    cin>>user;
    print(Books,user);*/


    //number8();
    number9();
}
