#include <iostream>
#include <iomanip>
using namespace std;

struct players{
	string nickname;
	int age;
	float hiScore1, hiScore2;
	
}p[5];


int main(int argc, char** argv) {
	
	
	
	int choice;
	char mainCheck = 'n';
	char confirm = 'n';
	
	do{	
	cout<<"=========================="<<endl;
	cout<<"\t   MENU"<<endl;
	cout<<"=========================="<<endl;
	
	cout<<"[1] Add record"<<endl;
	cout<<"[2] View players records"<<endl;	
	cout<<"[3] Compute for the average"<<endl;
	cout<<"[4] Show the player(s) who gets the max average"<<endl;
	cout<<"[5] Show the player(s) who gets the min average"<<endl;
	cout<<"[6] Exit"<<endl<<endl;
	
	cout<<"Enter choice: ";
	cin>>choice;
	
	switch(choice){
		char confirm;
		int i;
		case 1:{
			
		do{
		if (i<4){
			
			cout<<endl<<"Enter player nickname: ";
			cin>>p[i].nickname;
			cout<<"Enter age: ";
			cin>>p[i].age;
			cout<<"Enter best played score 1: ";
			cin>>p[i].hiScore1;
			cout<<"Enter best played score 2: ";
			cin>>p[i].hiScore2;
			i++;
			cout<<endl<<"Would you like to add another record? [y/n] ";
			cin>>confirm;
			mainCheck = 'y';		
		}
		
		else if (i=4){
			
			cout<<endl<<"Enter player nickname: ";
			cin>>p[i].nickname;
			cout<<"Enter age: ";
			cin>>p[i].age;
			cout<<"Enter best played score 1: ";
			cin>>p[i].hiScore1;
			cout<<"Enter best played score 2: ";
			cin>>p[i].hiScore2;
			i++;
			cout<<endl<<"Max players reached. "<<endl;
			confirm = 'n';
			cout<<"Return to menu? [y/n] ";
			cin>>mainCheck;
					
		}
	
		else if(i=5){
			cout<<"Maximum players reached"<<endl;
			confirm = 'n';
			cout<<"Return to menu? [y/n] ";
			cin>>mainCheck;
		}
		
		}while(confirm == 'y' || confirm =='Y');
		
		system("CLS");
		break;}
		
		case 2:{
			int n = sizeof(p)/sizeof(p[0].nickname);
			
			if(p[0].nickname==""){
				cout<<"No records yet"<<endl;
				system("PAUSE");
				system("CLS");
				mainCheck = 'y';
			}
			
			else{
				system("CLS");
				cout<<"Here are the players' records: "<<endl<<endl;
				cout<<setfill(' ')<<"Player no."<<setw(14)<<"Nickname"<<setw(11)<<"Age"<<"\t\t"<<"Best Played Scores"<<endl;
				
				for(i=0; i<5; i++){
					
					if(p[i].age==0){
					continue;
					}
					
					else{
					cout<<i+1<<"\t\t"<<p[i].nickname<<"\t\t"<<p[i].age<<"\t\t"<<p[i].hiScore1<<" & "<<p[i].hiScore2;
					cout<<endl;
					}
				}
				system("PAUSE");
				system("CLS");
			}
			
			break;}
			
		case 3:
			if(p[0].nickname==""){
				cout<<"No records yet"<<endl;
				system("PAUSE");
				system("CLS");
				mainCheck = 'y';
			}
			
			else{
			system("CLS");
			cout<<"Here are the averages of each player: "<<endl;
			
			cout<<setfill(' ')<<"Player no."<<setw(14)<<"Nickname"<<setw(11)<<"\tAverage"<<endl;
				for(i=0; i<5; i++){
					
					if(p[i].age==0){
					continue;
					}
					
					else{
					cout<<i+1<<"\t\t"<<p[i].nickname<<"\t\t"<<(p[i].hiScore1+p[i].hiScore2)/2;
					cout<<endl;
				}
				
				}
				system("PAUSE");
				system("CLS");
				
			}
			
			break;
		
		case 4:{
			if(p[0].nickname==""){
				cout<<"No records yet"<<endl;
				system("PAUSE");
				system("CLS");
				mainCheck = 'y';
			}
			
			else{
				
				float arrMax[5];
				float arrMax2[5];
				string arrHolder[5];
				string arrHolder2[5];
				
				for(i=0; i<5; i++){
						
						arrMax[i] = (p[i].hiScore1+p[i].hiScore2)/2;
						arrHolder[i] = p[i].nickname;
						
					}
					
				for(int i=0; i<5; ++i){
					if(arrMax[0]<arrMax[i]){
						arrMax[0] = arrMax[i];
						arrHolder[0] = arrHolder[i];
					}
				
				for(int i=0; i<5; ++i){
					if(arrMax2[0]<arrMax[i]){
						if(arrHolder2[i]==arrHolder[0]&&arrMax2[i]==arrMax[0]){
							continue;
						}
						else if(arrHolder2[i]!=arrHolder[0]&&arrMax2[i]==arrMax[0]){
							arrMax2[0] = arrMax[i];
							arrHolder2[0] = arrHolder[i];
						}
					}
				}
					
				}
				system("CLS");
				cout<<"Largest Max: "<<endl;
				cout<<"Player Name\t\tAvg Score"<<endl;
				cout<< arrHolder[0] <<"\t\t\t"<<arrMax[0] << endl;
				cout<< arrHolder2[0] <<"\t\t\t"<<arrMax2[0] << endl;
				system("PAUSE");
				system("CLS");
			
			}
			break;}
			
		case 5:{
			
			if(p[0].nickname==""){
				cout<<"No records yet"<<endl;
				system("PAUSE");
				system("CLS");
				mainCheck = 'y';
			}
			else{
				float arrMin[5];
				float arrMin2[5];
				string arrHolder[5];
				string arrHolder2[5];
				
				for(i=0; i<5; i++){
						
						arrMin[i] = (p[i].hiScore1+p[i].hiScore2)/2;
						arrHolder[i] = p[i].nickname;
						
					}
				
						
				for(int i=1; i<5; ++i){
					if(arrHolder[i]==""){
					continue;
					}
					
					else{
						if(arrMin[0]>arrMin[i]){
						arrMin[0] = arrMin[i];
						arrHolder[0] = arrHolder[i];
						}
					}
				}
				
				for(int i=0; i<5; ++i){
					if(arrMin2[0]>arrMin[i]){
						if(arrHolder2[i]==arrHolder[0]&&arrMin2[i]==arrMin[0]){
							continue;
						}
						else if(arrHolder2[i]!=arrHolder[0]&&arrMin2[i]==arrMin[0]){
							arrMin2[0] = arrMin[i];
							arrHolder2[0] = arrHolder[i];
						}
					}
				}
				
				system("CLS");
				cout<<"Largest Min: "<<endl;
				cout<<"Player Name\t\tAvg Score"<<endl;
				cout<< arrHolder[0] <<"\t\t\t"<<arrMin[0] << endl;
				system("PAUSE");
				system("CLS");
				
			}
			break;}
			
			case 6:{
				char exitCheck;
				cout<<"Are you sure you want to exit? [y/n] ";
				cin>>exitCheck;
				switch(exitCheck){
					case 'y': case 'Y':
						return 0;
						break;
					case 'n': case 'N':
						mainCheck = 'y';
						system("CLS");
						break;
						
					 }
			}
				
	}
	
	}while(mainCheck == 'y' || mainCheck == 'Y');
	return 0;
}
