#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

// magacin/ stack

struct stack{

    int top;
    int array[100];
    void init(){top==-1;};
    bool isEmpty(){return (top==-1);};
    bool isFull(){return (top==100-1);};
    void push(int el){
        if(isFull()){
            cout<<"Full e!!!";
            return;
        }
        array[++top]=el;
    };
    int pop(){
        if(isEmpty()){
            cout<<"Empty e!!!";
            exit(-1);
        }
        return array[top--];
    };
    int peek(){
           if(isEmpty()){
            cout<<"Empty e!!!";
            exit(-1);
        }
        return array[top];
    };
    void print(){
        if(isEmpty()){
            cout<<"Empty e!!!";
            exit(-1);
        }
        for(int i=0;i<top;i++){
            cout<<array[i]<<" ";
        }

    };



};
// queue/ red

struct queue{

    char array[30];
    int front, rear;
    void init(){
        front=0;
        rear=-1;
    }
    bool isFull(){
        return (rear=30-1);
    }
    bool isEmpty(){
        return (rear==-1);
    }
    void enqueue(char c){
        if(isFull()){
            cout<<"Full e!!!";
            return;
        }
        array[++rear]=c;
    }
    char dequeue(){
        if(isEmpty()){
            cout<<"Empty e!!!";
            exit(-1); // return{};
        }
        char pom;
        pom=array[front];
        for(int i=front;i<rear;i++){
            array[i]=array[i+1];
        }
        rear--;
        return pom;
    }
    char peek(){
        if(isEmpty()){
            cout<<"Empty e!!!";
            exit(-1); // return{};
        }
        return array[front];
    }
    void print(){
        if(isEmpty()){
            cout<<"Empty e!!!";
            exit(-1); // return{};
        }
        for(int i=0;i<=rear;i++){
            cout<<array[i]<<" ";
        }
    }

};
// lists/ Edinechni listi

struct Jazol{

    int info;
    Jazol *link;

};

struct ELista{

    Jazol *head;
    void init();
    void insertFirst(int j);
    void insertLast(int J);
    void createList(int el);
    void deleteFirst();
    void deleteLast();
    void print();
    void deleteList();

};

void ELista::init(){

    head==NULL;

}

void ELista::createList(int el){

    head= new Jazol;
    head->info=el;
    head->link=NULL;

}

void ELista::insertFirst(int element){

    
    Jazol *pom= new Jazol;
    pom->info=element;
    pom->link=head;
    head=pom;

}

void ELista::insertLast(int Element){

    Jazol *pom= new Jazol, *dvizhi=head;
    pom->info=Element;
    if(head==NULL){
        head=pom;
    }else{
    while(dvizhi->link!=NULL){
        dvizhi=dvizhi->link;
    }
    dvizhi->link=pom;
    }
    pom->link=NULL;
}

void ELista::deleteFirst(){
    if(head!=NULL){
        if(head->link==NULL){
            delete head;
            head=NULL;
        }else{
            Jazol *pom=head;
            head=head->link;
            delete pom;
        }
    }
}

void ELista::deleteLast(){
    if(head!=NULL){
        if(head->link==NULL){
            delete head;
            head=NULL;
        }else{
            Jazol *dvizhi, *pom=head;
            while(pom->link->link!=NULL){
                pom=pom->link;
            }
            dvizhi=pom->link;
            delete dvizhi;
            pom->link=NULL;
        }
    }
}

void ELista::deleteList(){

    while(head!=NULL){
        deleteLast();
    }

}

void ELista::print(){
    Jazol *pom=head;
        while(pom!=NULL){
            cout<<pom->info<<"\t";
            pom=pom->link;
        }
        cout<<endl;
}

// Kruzhni Listi

struct jazol{

    int info;
    jazol *link;

};

struct KLista{

    jazol *head, *tail;
    int numEl;
    void init();
    void insertFirst(int j);
    void insertLast(int J);
    void createList(int el);
    void deleteFirst();
    void deleteLast();
    void print();
    void deleteList();

};
void KLista::init(){

    head==tail==NULL;
    numEl=0;

}

void KLista::createList(int el){

    jazol *pom= new jazol;
    pom->info=el;
    pom->link=pom;
    head=tail=pom;
    numEl=1;

}

void KLista::insertFirst(int element){
 
    jazol *pom= new jazol;
    pom->info=element;
    if(head==NULL){
        pom->link=pom;
        head=tail=pom;
    }else{
        pom->link=head;
        head=pom;
        tail->link=head;
    }
    numEl++;
}

void KLista::insertLast(int Element){

     jazol *pom= new jazol;
    pom->info=Element;
    if(head==NULL){
        pom->link=pom;
        head=tail=pom;
    }else{
        tail->link=pom;
        tail=pom;
        pom->link=head;
    }
    numEl++;
}

void KLista::deleteFirst(){

    if(head->link==head){
    delete head;
    head=tail=NULL;
    }else{
       tail->link=head->link;
       delete head;
       head=tail->link;
    }
    numEl--;    

}

void KLista::deleteLast(){

   if(head->link==head){
    delete head;
    head=tail=NULL;
    }else{
        jazol *dvizhi=head;
        while(dvizhi->link!=tail){
            dvizhi=dvizhi->link;
        }
        delete tail;
        tail=dvizhi;
        dvizhi->link=head;
        numEl--;
    }
}

void KLista::deleteList(){

    while(head!=NULL){
        deleteLast();
    }

}

void KLista::print(){
    jazol *pom=head;
       if(head!=NULL){
            do{
                cout<<pom->info<<"\t";
                pom=pom->link;
            }while(pom!=head);
       }else{
        cout<<"The End!!!"<<endl;
       }
       cout<<endl;
}
