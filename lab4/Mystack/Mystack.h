

#ifndef LAB4_MYSTACK_H
#define LAB4_MYSTACK_H

// Шаблонный класс ListNode (узел односвязного списка)
template<class INF, class FRIEND>
class ListNode              // узел списка
{
private:
    INF d;                  // информационная часть узла
    ListNode *next;         // указатель на следующий узел списка
    ListNode(void) { next = nullptr; } //конструктор
    friend FRIEND;
public:
    ListNode& operator=(const ListNode& other) {
        if (this != &other) {
            d = other.d;
            next = new ListNode(*other.next); // Копируем следующий узел, если он существует
        }
        return *this;
    };
};

// Шаблонный класс MyStack на основе односвязного списка.
template<class INF>
class MyStack {
    typedef class ListNode<INF, MyStack<INF>> Node;
    Node *top;
public:
    MyStack(void){
      top= nullptr;
    };         // конструктор
    ~MyStack(void){
        while (!empty()) {
            pop();
        }
    };
    MyStack(const MyStack& other) {
        top = nullptr;
        Node* temp = other.top;
        Node** current = &top;
        while (temp != nullptr) {
            *current = new Node;
            (*current)->d = temp->d;
            (*current)->next = nullptr;
            current = &((*current)->next);
            temp = temp->next;
        }
    }
    MyStack& operator=(const MyStack& other) {
        if (this != &other) {
            // Освобождаем текущий стек
            while (!empty()) {
                pop();
            }
            // Копируем стек
            Node* temp = other.top;
            Node** current = &top;
            while (temp != nullptr) {
                *current = new Node;
                (*current)->d = temp->d;
                (*current)->next = nullptr;
                current = &((*current)->next);
                temp = temp->next;
            }
        }
        return *this;
    }
    bool empty();        // стек пустой?
    bool push(INF n);        // добавить узел в вершину стека
    bool pop();          // удалить узел из вершины стека
    INF top_inf();// считать информацию из вершины стека
    void print();
    void printback();
    int size();
};




template<class INF>
bool MyStack<INF>::empty() {
    if(top==nullptr){
        return true;
    }
    else{
        return false;
    }
}

template<class INF>
bool MyStack<INF>::push(INF n) {

        Node *temp=new Node;
        temp->d=n;
        temp->next=top;
        top=temp;
        return true;

}

template<class INF>
bool MyStack<INF>::pop() {
    Node *temp = top->next;
    delete top;
    top=temp;
    return true;
}

template<class INF>
INF MyStack<INF>::top_inf() {
    Node *temp=top;
    return temp->d;
}

template<class INF>
int MyStack<INF>::size() {
    int size=0;
    Node *temp=top;
    while(temp!= nullptr) {
        size++;
        temp = temp->next;
    }
    return size;
}

template<class INF>
void MyStack<INF>::print() {
    Node* temp=this->top;
    while(temp != nullptr){
        if(temp->next== nullptr) {
            std::cout << temp->d;
        }
        else{
            std::cout << temp->d<<" * ";
        }
        temp = temp->next;
    }
}
template<class INF>
void MyStack<INF>::printback(){
    int count=size();
    while(count>0) {
        Node *temp=top;
        for (int i = 0; i < count-1; i++) {
            temp = temp->next;

        }
        if(count==1) {
            std::cout << temp->d;
        }
        else{
            std::cout << temp->d<<" * ";

        }
        count--;
    }

}

#endif //LAB4_MYSTACK_H
