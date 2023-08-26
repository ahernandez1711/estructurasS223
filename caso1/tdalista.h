#include <iostream>
using namespace std;

class nodo { public:  nodo(int v)   {      valor = v;       siguiente = NULL;    } //temporalmente voy a tratar de usarlo con una lista circular, de no funcionar bien cambiare el TDA

nodo(int v, nodo * signodo)
    {
       valor = v;
       siguiente = signodo;
    }

   private:
    int valor;
    nodo *siguiente;
    
        
   friend class listaC;
};

typedef nodo *pnodo; //alias

class listaC { //lista de metodos de insercion, borrado 
   public:
    listaC() { primero = actual = NULL; }
    ~listaC();
    
    void InsertarInicio(int v);
    void InsertarFinal(int v);
    void InsertarPos (int v, int pos);
    void EliminarInicio();
    void EliminarFinal();
    void EliminarPos(int pos);
    bool ListaVacia() { return primero == NULL; } //metodo de revisar si la lista esta vacia para verificacion de otros metodos, y si es true entonces llama al constructor para crear una lista/devuelve un resultado inmediatamente
    void Imprimir();
    void Borrar(int v);
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();
    
   private:
    pnodo primero;
    pnodo actual;
};

listaC::~listaC() //constructor
{
   pnodo aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   actual = NULL;
}

int listaC::largoLista(){ //contador para el largo de la lista con un ciclo
    int cont=0;

    pnodo aux= primero;
    if(ListaVacia())
        return cont;
    else
    {
      while(aux->siguiente!=primero)
      {
        cont++;        
       aux=aux->siguiente;
      }
      cont=cont+1;
      return cont;
     }
}

void listaC::InsertarInicio(int v) //si la lista no esta vacia, entonces se reordenan los punteros de los nodos para 'empujar' el valor a la 'izquierda'. si esta vacia entonces solamente agrega el valor
{
   if (ListaVacia())
   {
     pnodo nuevo= new nodo(v);
     primero = nuevo;
     nuevo->siguiente=primero;
   }  
   else
   {
    pnodo nuevo= new nodo(v);
    pnodo aux=primero;
    while (aux->siguiente!=primero)
       aux= aux->siguiente;
    nuevo->siguiente=primero;   
    aux->siguiente=nuevo;
    primero=nuevo;   
   } 
}
 
void listaC::InsertarFinal(int v) //parecido al del inicio pero para insertar al final (este apunta al inicio por ser circular, no apunta a null
{
   if (ListaVacia())
   {
     pnodo nuevo= new nodo(v);
     primero = nuevo;
     nuevo->siguiente=primero;
   }  
   else
   { 
      pnodo nuevo=new nodo(v);
      pnodo aux = primero;
      while (aux->siguiente!=primero)  
         aux= aux->siguiente;
      nuevo->siguiente= primero;
      aux->siguiente= nuevo; 
      
   }    
}


void listaC::InsertarPos(int v,int pos) //insercion a una posicion directa 'indexada' relativa al resto de la lista y sus valores
{
   if (ListaVacia())
   {
     pnodo nuevo= new nodo(v);
     primero = nuevo;
     nuevo->siguiente=primero;
   } 
   else
   {
     if(pos <=1)
     {
       InsertarInicio(v);
     }      
     else
     {
       pnodo aux= primero;
       int i =2;
       while((i != pos )&&(aux->siguiente!= primero))
       {
          i++;
          aux=aux->siguiente;
       }
       pnodo nuevo= new nodo(v);
       nuevo->siguiente=aux->siguiente;
       aux->siguiente=nuevo;
      }
     }
}
      
void listaC::BorrarFinal() //metodos de borrado
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
      if (primero->siguiente == primero)
      {
        pnodo temp= primero;
        primero= NULL;
        delete temp;
      }
      else 
      {
         pnodo aux = primero;
         while (aux->siguiente->siguiente != primero)
              aux = aux->siguiente;
         pnodo temp = aux->siguiente;
         aux->siguiente= primero;
         delete temp;
      }
    }
}

void listaC::BorrarInicio()
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
     if (primero->siguiente == primero)
     {
        pnodo temp= primero;
        primero= NULL;
        delete temp;
     }
     else
     {
        pnodo aux = primero;
        pnodo temp= primero;
        while (aux->siguiente!=primero)
            aux= aux->siguiente;
        primero=primero->siguiente;                
        aux->siguiente=primero;
        delete temp;
      }
    }
}

void listaC:: borrarPosicion(int pos)
{
  if(ListaVacia())
    cout << "Lista vacia" <<endl;
  else
  {
   if((pos>largoLista())||(pos<=0))
     cout << "Error en posicion" << endl;
   else
    {
      if(pos==1)
        BorrarInicio();
      else
      {
       int cont=2;
       pnodo aux=  primero;
       while(cont<pos)
       {
         aux=aux->siguiente;
         cont++;
       }
       pnodo temp = aux->siguiente;
       aux->siguiente=aux->siguiente->siguiente;
       delete temp;
     }
    }
  }
}
 
void listaC::Mostrar() //impresion 
{
   pnodo aux=primero;
   while(aux->siguiente!=primero)
     {
                                
      cout << aux->valor << "-> ";
      aux = aux->siguiente;
     }
     cout<<aux->valor<<"->";
     cout<<endl;
}   








