#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
/*
* autor   : Jonathan Geovany Hernandez Vasquez
* country : El Salvador   - C.A
* date    : 14/3/2017
* spanish : el siguiente código ordena bloques en jerarquias
* incrementando en uno al aumentar la profundidad (nivel)
* ademas de identificar en que nivel se encuentra una linea perteneciente a un bloque especifico
*/
class Tree;
class Node{
private:
    int level;
    int startScope;
    int endScope;
    Node *next;
    Tree *tree;
public:
    Node(int lvl,int _start,int _end,Tree *t=NULL,Node *p=NULL){
        level=lvl;startScope=_start;endScope=_end;
        tree=t;
        next=p;
    }
    void setLevel(int n){level=n;}
    void setStart(int s){startScope=s;}
    void setEnd(int e){endScope=e;}
    int getLevel(){return level;}
    int getStart(){return startScope;}
    int getEnd(){return endScope;}
    Node* getNext(){return next;}
    Tree* getTree(){return tree;}
    friend class Tree;
};typedef Node *pNodo;

class Tree{
private:
    pNodo root;
    pNodo current;
    int tree_level;
    int tree_start;
    int tree_end;
public:
    Tree(int n=0){
        root=NULL;
        current=NULL;
        tree_level=n;
    }
    bool listaVacia(Tree *tree){return tree->root==NULL;}
    void insertar(int _start,int _end,Tree *tree){
        if(listaVacia(tree)){
            tree->root=new Node(tree->tree_level,_start,_end);
            tree->tree_start=_start;
            tree->tree_end=_end;
        }else{
            tree->current=tree->root;
            if(_start <= tree->current->endScope){
                if(!tree->current->tree) tree->current->tree = new Tree(tree->tree_level+1);
                insertar(_start,_end,tree->current->tree);
                return;
            }
            while(tree->current->next){
                tree->current = tree->current->next;
                if(_start <= tree->current->endScope){
                    if(!tree->current->tree) tree->current->tree = new Tree(tree->tree_level+1);
                    insertar(_start,_end,tree->current->tree);
                    return;
                }
            }
            tree->current->next=new Node(tree->tree_level,_start,_end);
        }
    }
    void showTree(Tree *tree){
        tree->current = tree->root;
        string tab="";
        for(int i=0;i<tree->tree_level;i++) tab+="\t";
        while(tree->current){
            cout << tab<<"Level : " << tree->current->getLevel()<<endl;
            cout << tab<<"Start : " << tree->current->getStart()<<endl;
            cout << tab<<"End   : " << tree->current->getEnd()<<endl;
            if(tree->current->tree) showTree(tree->current->tree);
            tree->current = tree->current->next;
        }
    }
    int getTabs(Tree *tree,int lineNumber){
        tree->current = tree->root;
        while(tree->current){
            if(lineNumber >= tree->current->getStart() && lineNumber<= tree->current->getEnd()){
                if(tree->current->tree)
                    return getTabs(tree->current->tree,lineNumber)+1;
                else return 1;
            }
            tree->current = tree->current->next;
        }
        return 0;
    }
};

#endif // TREE_H_INCLUDED
