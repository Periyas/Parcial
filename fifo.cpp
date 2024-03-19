#include<iostream>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include<iomanip>

using namespace std;

struct paciente{
    unsigned long documento = 0;
    char nombre[110];
    paciente *sig;
    unsigned long cantidad=0;
    long double precio=0;

}*aux, *aux2, *aux3;


int registrar(){
    system("cls");
    if(aux==NULL){
    aux = (struct paciente *) malloc (sizeof(struct paciente));
    aux->documento=1;
    cin.get();
    cout<<"escriba el nombre completo del producto : ";
    cin.getline(aux->nombre, 110);  
    cout<<"escriba el precio del producto: ";
    cin>>aux->precio;
    cout<<"escriba el stock disponible: ";
    cin>>aux->cantidad;
    cout<<"producto con ID:"<<aux->documento<<" ingresado con exito\n";              
    aux->sig=NULL;
    system("pause");
    } else{
        aux2 = (struct paciente *) malloc (sizeof(struct paciente));
        cin.get();
        cout<<"escriba el nombre completo del producto: ";
        cin.getline(aux2->nombre, 110);
        cout<<"escriba el precio del producto: ";
        cin>>aux2->precio;
        cout<<"escriba el stock disponible: ";
        cin>>aux2->cantidad;                    
        aux2->sig=NULL;
        aux3=aux;
        while(aux3->sig!=NULL){
            aux3=aux3->sig;
            
        }
        aux2->documento=aux3->documento+1;
        cout<<"producto con ID:"<<aux2->documento<<" ingresado con exito. \n";
        aux3->sig=aux2;   
        aux2=NULL;
        aux3=NULL;
        free(aux2);
        free(aux3); 
        system("pause"); 
        
    }
    return 0;
}



int mostrar(){
    system("cls");
    system("cls");
    if(aux!=NULL){
        long double a=0;
        long double b=0;
        long double c=0;
        long double d=0;

    for(aux2=aux; aux2!=NULL; aux2=aux2->sig){
        a=a+aux2->cantidad;
        b=b+aux2->precio;
        cout<<"el ID del producto es: "<< aux2->documento<<"\n";
        cout<<"el nombre del producto es: "<< aux2->nombre<<"\n";
        cout<<fixed;
        cout<<setprecision(3);
        cout<<"el precio del producto es: "<< aux2->precio<<"\n";
        cout<<"la cantidad de producto en stock es: "<< aux2->cantidad<<"\n\n";
        
       
    }
    c=a*b;
    d=b*a/a;
    cout<<"valor total del Stock: "<<c<<"\n\n";
    cout<<"el promedio de precios es: "<<d<<"\n\n";

    }else{
        cout<<"No hay productos en stock.\n";
    }
    system("pause");
    return 0;
}

int buscar(){
    system("cls");
    unsigned long doc;
    int i=0;
    if(aux!=NULL){
        cout<<"ingrese el ID del prpducto. ";
        cin>>doc;
        for(aux3=aux; aux3->documento!=doc; aux3=aux3->sig){
        }
        if(aux3->documento=doc){
            cout<<"el ID del producto es: "<< aux3->documento<<"\n";
            cout<<"el nombre del producto es: "<< aux3->nombre<<"\n";
            cout<<fixed;
            cout<<setprecision(3);
            cout<<"el precio del producto es: "<< aux3->precio<<"\n";
            cout<<"la cantidad de producto en stock es: "<< aux3->cantidad<<"\n\n";

            cout<<"Desea borrar el articulo? (1. Si, 2. No): ";
            cin>>i;
            if(aux3=aux){
                aux=aux->sig;
                cout<<"Se Eliminado correctamente"<<endl;
            }else{
            switch (i)
            {
            case 1:for(aux2=aux; aux2->sig!=aux3; aux2=aux2->sig);
                        aux2->sig=aux3->sig;
                        free(aux3);
                        aux2=NULL;
                        aux3=NULL;
                        free(aux3);
                        free(aux2);
                        cout<<"producto eliminado";              break;
            case 2:return 0; break;
            
            default: cout<<"opcion invalida";
                break;
            }}

        }else{
            cout<<"ese producto no esta en stock.\n";
        }


    }else{
        cout<<"No hay productos en stock.\n";
    }
    system("pause");

    return 0;    
}

int comprar(){
    system("cls");
    unsigned long doc;
    int i=0;
    int i2=0;
    int b=0;
    int t=0;
    if(aux!=NULL){
        cout<<"ingrese el ID del prpducto. ";
        cin>>doc;
        for(aux3=aux; aux3->documento!=doc; aux3=aux3->sig){
        }
        if(aux3->documento=doc){
            cout<<"el ID del producto es: "<< aux3->documento<<"\n";
            cout<<"el nombre del producto es: "<< aux3->nombre<<"\n";
            cout<<fixed;
            cout<<setprecision(3);
            cout<<"el precio del producto es: "<< aux3->precio<<"\n";
            cout<<"la cantidad de producto en stock es: "<< aux3->cantidad<<"\n\n";

            cout<<"¿Desea comprar el articulo? (1. Si, 2. No): ";
            cin>>i;
            switch (i)
            {
            case 1:
            cout<<"¿cuantas unidades del producto desea comprar? ";
            cin>>b;
            if(aux3->cantidad>=b){
                t=aux3->precio*b;
                cout<<"total a pagar: "<<t<<"\n";
                cout<<"¿confirmar transaccion? (1. Si, 2. No): ";
                cin>>i2;
                switch (i2)
                {
                case 1:if(aux3->cantidad==b){
                     if(aux3=aux){
                aux=aux->sig;
                cout<<"Compra exitosa"<<endl;
                    }else{
            
                    for(aux2=aux; aux2->sig!=aux3; aux2=aux2->sig);
                        aux2->sig=aux3->sig;
                        free(aux3);
                        aux2=NULL;
                        aux3=NULL;
                        free(aux3);
                        free(aux2);
                        cout<<"Compra exitosa"<<endl;
                    }
                }else{
                aux3->cantidad=aux3->cantidad-b;
                cout<<"compra exitosa";
                }
                    break;
                case 2:
                cout<<"Transaccion cancelada";
                return 0;
                break;
                
                default:cout<<"opcion invalida";
                    break;
                }

            }else{
                cout<<"stock insuficiente, transaccion cancelada";
                return 0;
            }
            break;
            case 2:return 0; break;
            
            default: cout<<"opcion invalida";
                break;
            }

        }else{
            cout<<"ese producto no esta en stock.\n";
        }


    }else{
        cout<<"No hay productos en stock.\n";
    }
    system("pause");

    return 0;

}


int main(){
    system("cls");
    int opc = 0;
    do{
    cout<<"menu"<<endl;
    cout<<"1. Registrar Producto"<<endl;
    cout<<"2. Mostrar stock"<<endl;
    cout<<"3. Buscar y eliminar producto"<<endl;
    cout<<"4. comprar producto"<<endl;
    cout<<"5. Salir"<<"\n";
    cout<<"Elija su opcion: ";
    cin>>opc;
        switch(opc){
            case 1: registrar();system("cls"); break;
            case 2: mostrar();system("cls"); break;
            case 3: buscar();system("cls"); break;
            case 4: comprar();system("cls"); break;
            case 5: cout<<"Adios"<<endl;
            default: cout<<"opcion invalida"<<endl;
        }
    }while(opc!=5);


}

