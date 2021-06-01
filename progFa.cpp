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
				string arrHolder[5];
				
				float largest = 0.0;
				string titleHolder;
				
				float secondLargest = 0.0;
				string titleHolder2;
				
				for(i=0; i<5; i++){
						
						arrMax[i] = (p[i].hiScore1+p[i].hiScore2)/2;
						arrHolder[i] = p[i].nickname;
						
					}
					
				for(int i=0; i<5; ++i){
					
					if(largest<arrMax[i]){
						
						secondLargest = largest;
						largest = arrMax[i];
						
						titleHolder2 = titleHolder;
						titleHolder = arrHolder[i];	
						 
					}
					
					else if(secondLargest<arrMax[i] || arrMax[i] == largest && titleHolder2!=titleHolder){
						
						secondLargest = arrMax[i];
						titleHolder2 = arrHolder[i];
							
						}
									
				}
				
				system("CLS");
				cout<<"Highest Average: "<<endl;
				cout<<"Player Name\t\tAvg Score"<<endl;
				cout<< titleHolder <<"\t\t\t"<< largest << endl;
				cout<< titleHolder2 <<"\t\t\t"<< secondLargest << endl;
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
				string arrHolder[5];
				
				float smallest = 0.0;
				string titleHolder;
				
				float secondSmallest = 0.0;
				string titleHolder2;
							
				
				for(i=0; i<5; i++){
						
						arrMin[i] = (p[i].hiScore1+p[i].hiScore2)/2;
						arrHolder[i] = p[i].nickname;
						
					}
				
						
				for(int i=0; i<5; ++i){
					
					if(smallest>arrMin[i]){
						
						secondSmallest = smallest;
						smallest = arrMin[i];
						
						titleHolder2 = titleHolder;
						titleHolder = arrHolder[i];	
						 
					}
					
					else if(secondSmallest>arrMin[i] || arrMin[i] == smallest && titleHolder2!=titleHolder){
						
						secondSmallest = arrMin[i];
						titleHolder2 = arrHolder[i];
							
						}
									
				}
				
				system("CLS");
				cout<<"Lowest Average: "<<endl;
				cout<<"Player Name\t\tAvg Score"<<endl;
				cout<< titleHolder <<"\t\t\t"<< smallest << endl;
				cout<< titleHolder2 <<"\t\t\t"<< secondSmallest << endl;
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
			
			default:{
				cout<<"Invalid choice "<<endl;
				
				break;
			}
	}
	
	}while(mainCheck == 'y' || mainCheck == 'Y');
	return 0;
}

/*if(titleHolder2==titleHolder&&secondLargest==largest){
								continue;
							}
							else if(titleHolder2!=titleHolder&&secondLargest!=largest){
								
								secondLargest = arrMax[i];
								titleHolder2 = arrHolder[i];
								
							}*/
