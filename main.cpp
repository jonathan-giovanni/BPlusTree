/*
* autor: Jonathan Geovany Hernandez Vasquez
* date : 14/3/2017
* Spanish : el siguiente código ordena bloques en jerarquias
* incrementando en uno al aumentar la profundidad (nivel)
* ademas de identificar en que nivel se encuentra una linea perteneciente a un bloque determinado
*/
#include <iostream>
#include <string>
using namespace std;
class Lista;
class Nodo{
private:
    int nivel;
    int inicio;
    int fin;
    Nodo *siguiente;
    Lista *lst;
public:
    Nodo(int n,int i,int f,Lista *l=NULL,Nodo *p=NULL){
        nivel=n;inicio=i;fin=f;
        lst=l;
        siguiente=p;
    }
    void setNivel(int n){nivel=n;}
    void setInicio(int i){inicio=i;}
    void setFin(int f){fin=f;}
    int getNivel(){return nivel;}
    int getInicio(){return inicio;}
    int getFin(){return fin;}
    Nodo* getSiguiente(){return siguiente;}
    Lista* getLista(){return lst;}
    friend class Lista;
};typedef Nodo *pNodo;


class Lista{
private:
    pNodo raiz;
    pNodo actual;
    int nivel_lst;
    int inicio_lst;
    int fin_lst;
public:
    Lista(int n=0){
        raiz=NULL;
        actual=NULL;
        nivel_lst=n;
    }
    bool listaVacia(Lista *lst){return lst->raiz==NULL;}

    void insertar(int i,int f,Lista *lst){
        if(listaVacia(lst)){
            lst->raiz=new Nodo(lst->nivel_lst,i,f);
            lst->inicio_lst=i;
            lst->fin_lst=f;
        }else{
            lst->actual=lst->raiz;
            if(i <= lst->actual->fin){
                if(!lst->actual->lst) lst->actual->lst = new Lista(lst->nivel_lst+1);
                insertar(i,f,lst->actual->lst);
                return;
            }
            while(lst->actual->siguiente){
                lst->actual = lst->actual->siguiente;
                if(i <= lst->actual->fin){
                    if(!lst->actual->lst) lst->actual->lst = new Lista(lst->nivel_lst+1);
                    insertar(i,f,lst->actual->lst);
                    return;
                }
            }
            lst->actual->siguiente=new Nodo(lst->nivel_lst,i,f);
        }
    }
    void mostrar(Lista *lst){
        lst->actual = lst->raiz;
        string tab="";
        for(int i=0;i<lst->nivel_lst;i++) tab+="\t";
        while(lst->actual){
            cout << tab<<"Nivel  : " << lst->actual->getNivel()<<endl;
            cout << tab<<"Inicio : " << lst->actual->getInicio()<<endl;
            cout << tab<<"Fin    : " << lst->actual->getFin()<<endl;
            if(lst->actual->lst) mostrar(lst->actual->lst);
            lst->actual = lst->actual->siguiente;
        }
    }
    int getTabs(Lista *lst,int linea){
        lst->actual = lst->raiz;
        while(lst->actual){
            if(linea >= lst->actual->getInicio() && linea<= lst->actual->getFin()){
                if(lst->actual->lst)
                    return getTabs(lst->actual->lst,linea)+1;
                else return 1;
            }
            lst->actual = lst->actual->siguiente;
        }
        return 0;
    }
};

int main()
{
    Lista *lst = new Lista(0);
    lst->insertar(0,30,lst);
    lst->insertar(2,5,lst);
    lst->insertar(6,10,lst);
    lst->insertar(7,9,lst);
    lst->insertar(12,20,lst);
    lst->insertar(31,40,lst);
    lst->mostrar(lst);
    int linea=8;
    cout << "\nLinea numero "<< linea << " tabs "<< lst->getTabs(lst,linea);
    return 0;
}
