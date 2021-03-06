#include <iostream>
#include <iomanip>
#include <float.h>
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
			
			if(i!=5){
				do{
					if (i<4){
						//asks for user input when adding records to the struct
						cout<<endl<<"Enter player nickname: ";
						cin.ignore(1000, '\n'); 
						getline(cin,p[i].nickname);
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
						
						//same as above, but only when max records reached
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
				}while(confirm == 'y' || confirm =='Y');
			}
			
			else{//prompts the user to go back to the menu if the records are full
				cout<<"Maximum players reached"<<endl;
				confirm = 'n';
				cout<<"Return to menu? [y/n] ";
				cin>>mainCheck;	
			}
			
			system("CLS");
			break;}
			
			case 2:{
				int n = sizeof(p)/sizeof(p[0].nickname);
				
				if(p[0].nickname==""){//checks first element if there are no records yet and returns to menu
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
						
						if(p[i].age==0){//skips the iteration if there is no input, this prevents empty records to show in the list
							continue;
						}
						
						else{//displays the records available
							cout<<i+1<<"\t\t"<<p[i].nickname<<"\t\t"<<p[i].age<<"\t\t"<<p[i].hiScore1<<" & "<<p[i].hiScore2;
							cout<<endl;
						}
					}
					system("PAUSE");
					system("CLS");
				}
				
				break;}
				
			case 3:
				if(p[0].nickname==""){//checks first element if there are no records yet and returns to menu
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
						
						if(p[i].age==0){//skips the iteration if there is no input, this prevents empty records to show in the list
							continue;
						}
						
						else{//displays the records but with average
							cout<<i+1<<"\t\t"<<p[i].nickname<<"\t\t"<<(p[i].hiScore1+p[i].hiScore2)/2;
							cout<<endl;
						}
					
					}
					system("PAUSE");
					system("CLS");
					
				}
				
				break;
			
			case 4:{
				if(p[0].nickname==""){//checks first element if there are no records yet and returns to menu
					cout<<"No records yet"<<endl;
					system("PAUSE");
					system("CLS");
					mainCheck = 'y';
				}
				
				else{
					
					float arrMax[5];//array for holding the averages
					string arrHolder[5];//array for holding the names
					
					float largest = 0.0;//variable for largest
					string titleHolder;//variable for name of high score holder
					
					float secondLargest = 0.0;//variable for second largest
					string titleHolder2;//variable for name of second high score holder
					
					for(i=0; i<5; i++){
							arrMax[i] = (p[i].hiScore1+p[i].hiScore2)/2;//computation for the average
							arrHolder[i] = p[i].nickname;
						}
						
					for(int i=0; i<5; ++i){
						
						if(largest<arrMax[i]){//if the element in the array is larger than the variable, update values in largest and secondLargest 
							
							secondLargest = largest;
							largest = arrMax[i];
							
							titleHolder2 = titleHolder;
							titleHolder = arrHolder[i];	
							 
						}
						
						else if(secondLargest<arrMax[i] || arrMax[i] == largest && titleHolder2!=titleHolder){
							//if the secondLargest value is less than or equal to the largest value, but the title holder is different, display both title holders
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
				
				if(p[0].nickname==""){//checks first element if there are no records yet and returns to menu
					cout<<"No records yet"<<endl;
					system("PAUSE");
					system("CLS");
					mainCheck = 'y';
				}
				
				else{
					
					float arrMin[5];//array for holding the averages
					string smallArrHolder[5];//array for holding the names
					
					float smallest = FLT_MAX;//variable for smallest (FLT_MAX is used to assign value to the variable)
					string smallTitleHolder;//variable for name of smallest score holder
					
					float secondSmallest = FLT_MAX;//variable for second smallest (FLT_MAX is used to assign value to the variable)
					string smallTitleHolder2;//variable for name of smallest score holder 
								
					
					for(i=0; i<5; i++){	
							arrMin[i] = (p[i].hiScore1+p[i].hiScore2)/2;//computation for the average
							smallArrHolder[i] = p[i].nickname;
						}
								
					for(int i=0; i<5; ++i){
						
						if(p[i].age==0){//skips the iteration if there is no input, this prevents empty records to show in the list
							continue;
						}
						
						else if(smallest>arrMin[i]){
							//if the element in the array is smaller than the value in the variable, the smallest and secondSmallest variables are updated
							secondSmallest = smallest;
							smallest = arrMin[i];
							
							smallTitleHolder2 = smallTitleHolder;
							smallTitleHolder = smallArrHolder[i];		 
						}
						
						else if(secondSmallest>arrMin[i] || arrMin[i] == smallest && smallTitleHolder2!=smallTitleHolder){
						//if the element in the array is smaller than or equal to the secondSmallest variable but the title holder is different, display both values 
							secondSmallest = arrMin[i];
							smallTitleHolder2 = smallArrHolder[i];	
							}
										
					}
					
					system("CLS");
					cout<<"Lowest Average: "<<endl;
					cout<<"Player Name\t\tAvg Score"<<endl;
					cout<< smallTitleHolder <<"\t\t\t"<< smallest << endl;
					cout<< smallTitleHolder2 <<"\t\t\t"<< secondSmallest << endl;
					system("PAUSE");
					system("CLS");
					
				}
				break;}
				
				case 6:{
					char exitCheck;
					cout<<"Are you sure you want to exit? [y/n] ";
					cin>>exitCheck;
					
					switch(exitCheck){//switch for exit confirmation
						case 'y': case 'Y':
							return 0;
							break;
						case 'n': case 'N':
							mainCheck = 'y';
							system("CLS");
							break;
							
						 }
				}
				
				default:{//default value (exits the program)
					cout<<"Invalid choice "<<endl;
					break;
				}
		}
	}while(mainCheck == 'y' || mainCheck == 'Y');//repeats the program as long as the user answers 'Y' or 'y' in the prompt
	return 0;
}
