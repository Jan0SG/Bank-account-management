#include<iostream>
#include<cstdlib>

using namespace std;

template<typename T>
class Cuentabancaria{
	protected:
		int cuenta[8];
		int id[6];
		float saldo;
		int interesanual = 23;
		T movimiento;
	
	public:
		Cuentabancaria(){
		}
		
		Cuentabancaria(int d, float s, int a){
			setId(d);
			setSaldo(s);
			setInteresanual(a);
		}
		
		int GenerarId(){
			for(int i=0; i<6; i++){
				id[i] = rand()%10;
			}
		}
		
		int Generarnumerocuenta(){
			for(int i=0; i<8; i++){
				cuenta[i] = rand()%10;
			}
			
		}
		
		int actualizarSaldo(){
			cout<<"\nWere refreshing your balance.";
			cout<<"\n.";
			cout<<"\n.";
			cout<<"\n.";
			cout<<"\n.";
			cout<<"\n.";
			cout<<"\nDone, up next is your balance: ";
			interesanual /= 365;
			
			saldo = getSaldo()-interesanual+getMovimiento();
			setSaldo(saldo);
			cout<<"\nBalance = "<<saldo;
		}
		
		int ingresar(float m){
			cout<<"\nWrite down the amount you wish to deposit.\n";
			cout<<"Deposit amount = "; cin>>m;
			setMovimiento(m);
			
		}
		
		int retirar(float m){
			cout<<"\nWrite down the amount you wish to withdraw.\n";
			cout<<"Withdrawal amount = "; cin>>m;
			if(saldo - m <0){
				cout<<"\nWere sorry but you can't withdraw that amount.";
				setMovimiento(0);
			}
			else if(saldo - m >=0){
				setMovimiento(-m);
			}
		}
		
		void MostrarInformacion(){
			cout<<"\nYour information is up next: ";
			cout<<"\nAccount number: ";
			for(int i=0; i<8; i++){
				cout<<cuenta[i];
			}
			cout<<"\nClient ID: ";
			for(int i=0; i<6; i++){
				cout<<id[i];
			}
			cout<<"\nBalance: "<<this->getSaldo();
			cout<<"\nAnnual interest rate: 2.3%";
		}
		
		void ingresarcuenta(){
			int n;
			cout<<"\nPlease enter your account number.\n";
			cout<<"Enter here: ";
			for(int i=0; i<8; i++){
				cin>>n;
				cuenta[i] = n;
			}
		}
		
	void setMovimiento(T m){movimiento = m;}
	T getMovimiento(){return movimiento;}
		
	void setSaldo(float s){saldo = s;}
	float getSaldo(){return saldo;}
	
	void setId(int d){id[6] = d;}
	int getId(){return id;}
	
	void setInteresanual(int a){interesanual = a;}
	int getInteresanual(){return interesanual;}
	
};

template <typename T>
class recompensas : public Cuentabancaria<T>{
	private:
		T bono;
		
	public:
		recompensas(){
		}
		
		recompensas( float a) : Cuentabancaria<T>(a){
		
			this->getInteresanual(a);
		}
		
		void programarecompensas(){
			int opcion;
			do{
			
				cout<<"\nWelcome to our rewards program!";
				cout<<"\nWould you like to enter the rewards program?";
				cout<<"\n1- Yes";
				cout<<"\n2- No";
			
				cout<<"\n\nYour choice: "; cin>>opcion;
				if(opcion==1){
					cout<<"\nCONGRATULATIONS, you didn't win anything but welcom to the rewards program!";
					cout<<"\nBy being a new program, we haven't registered any prizes so please be pacient, soon we will!";
					cout<<"\nFor now, by joining our rewards program, a reduction of your annual interest rate will be done next year!";
					
					
				}
				if(opcion==2){
					cout<<"Don't worry, you can always be part of the program anytime you want.";
				}
			}while(opcion<1 or opcion>2);
			cout<<endl;
		}
		
};

int main(){
	float saldobienvenida = 200;
	int d, a = 23;
	float m;
	int n, o;
	
			Cuentabancaria<float> cuenta1(d, saldobienvenida, a);
			cuenta1.GenerarId();
			cuenta1.Generarnumerocuenta();
			recompensas<float> cuenta11;
			
			Cuentabancaria<int> cuenta2(d, saldobienvenida, a);
			cuenta2.GenerarId();
			cuenta2.Generarnumerocuenta();
			recompensas<int> cuenta22;

	
			cout<<"\n\nWelcome to your trustworthy bank!";
			cout<<"\nWould you like to see your cents during the operations?";
			cout<<"\n1- Yes";
			cout<<"\n2- No";
			cout<<"\n\nYour choice: ";
			cin>>o;
	do{
		do{
		
		
			if(o==1){
				
				
				cout<<"\n\nHow can we help you today?";
				cout<<"\n1- Show bank account information";
				cout<<"\n2- Deposit money";
				cout<<"\n3- Witdrawal money";
				cout<<"\n4- Rewards program";
				cout<<"\n5- Exit";
				cout<<"\nYour choice: "; cin>>n;
				
					
				if(n==1){
					cuenta1.MostrarInformacion();
				}
				if(n==2){
					cuenta1.ingresar(m);
					cuenta1.actualizarSaldo();
				}
				if(n==3){
					cuenta1.retirar(m);
					cuenta1.actualizarSaldo();
				}
				if(n==4){
					cuenta11.programarecompensas();
				}
		
			}
			if(o==2){

				
				cout<<"\n\nHow can we help you today?";
				cout<<"\n1- Show bank account information";
				cout<<"\n2- Deposit money";
				cout<<"\n3- Witdrawal money";
				cout<<"\n4- Rewards program";
				cout<<"\n5- Exit";
				cout<<"\nYour choice: "; cin>>n;
				
					
				if(n==1){
					cuenta2.MostrarInformacion();
				}
				if(n==2){
					cuenta2.ingresar(m);
					cuenta2.actualizarSaldo();
				}
				if(n==3){
					cuenta2.retirar(m);
					cuenta2.actualizarSaldo();
				}
				if(n==4){
					cuenta22.programarecompensas();
				}
		
			}
		}while(o<1 or o>2);
		
	}while(n!=5);
	cout<<"Thank you for choosing us, have an excellent day!";
	return 0;
}
