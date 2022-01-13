//Creating quiz game in C++


/*      		IT(Information Technology) Quiz: Version 1.0 

   Team Members: Ameer Sampang Rai, Badri Tamang, Sandip Shreastha
   Second Semester Project based on OOP in C++
   College: Aryan School of Engineering and Management
   Faculty: BIT 2019

*/


#include <iostream>	//C++ header file
#include<fstream>	//for file handling
#include<conio.h>	//for getch()
#include<string.h>	//for string handling
#include <iomanip>	//for output formatting
#include<windows.h> 	//for cls, pause
#include<mmsystem.h> 	//for sound


using namespace std;

//creating class QuizGame
class QuizGame
{
	private:
		//for question answer & points for score,ans1 for ans, total attempt, correct and wrong ans count
		int points,ans1,attempt,correct,wrong; 
		int x,len;	//a is x-coordinate and len is length for AnimatedTitle function
		char setop, name[20], answer,ans, FileName[20], title[50];	//player name, setop for switch case
			
		//Login part
		char pass[10];
		char un[10];
		char username[10]="admin";
		char password[10]="admin";
	
	public:
		char SetTitle[50];
		
		QuizGame()
			{  //creating constructor for setting initial points as zero
				points=0;
				attempt=0;
				correct=0;
				wrong=0;
			}
			
	
		//system co-ordinates
		COORD coord={0,0}; 
		void gotoxy(int x, int y)
			{//creating func to go on particular place witht co-ordinate values
				coord.X=x; //x co-ordinate vaneko x bata pass vayeko value
				coord.Y=y; //y co-ordinate vankeo y bata pass vayera aaune value
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord); //for setting cursor position of x & y
			}
		
		
		//function declaration or prototypes
		void AnimatedBox();
		void AnimatedTitle( char* );
		void DrawRectangle();//for outer rectangle
		void DrawLongerRectangle();
		void MainTitle();
		void ShowTitleDrawRectangle();
		int Questions( char* );
		void HomeMenu();
			void Login();
			void Help();
				void HowToUse();
				void About();
			void Support();
		void Welcome();  
		void MainMenu();
			void StartGame();
					void SubMenu();
						void SetMenus();
			void View_my_score();
			void LogOut();
};	//end of QuizGame class


//Creating class player
class player
 {
 int pid;
 char name[20], address[50],email[50], name_for_score[30];
 
 
 public: 
 			int retpid()
			 {
				return pid;
			 }
			 
			char* retname()
			 {
			 	return name;
			 }
			 
			char* return_name_for_score()
			 {
			 	return name_for_score;
			 }
			
			char* retaddress()
			 {
			 	return address;
			 }
			 
			 char* retemail()
			 {
				return email;
			 }
			 
			 	//system co-ordinates
		COORD coord={0,0}; 
		void gotoxy(int x, int y)
			{//creating func to go on particular place witht co-ordinate values
				coord.X=x; //x co-ordinate vaneko x bata pass vayeko value
				coord.Y=y; //y co-ordinate vankeo y bata pass vayera aaune value
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord); //for setting cursor position of x & y
			}
		
void Player_Menus();
	void Menu_Register();
		void read_data_registration();
	void Menu_List();			
		void display_data_list();
	void Menu_Search();
		void Search_by_ID();
		void Search_by_name();
	void Menu_Modify();			
		void read_data_modification();	
		void display_data_for_search_and_modify();		 
	void Menu_Delete(); 

}; //class ends here
	

//global declarations
QuizGame itq;

player pr;
fstream fp;
char ch, choice , name_for_score[50];
int i;

////////Functions of class QuizGame/////////////////////////////////////////////////////////////////////

void QuizGame::MainTitle()
{
	ifstream welfile("Welcome.txt");
	if(welfile.bad())
	{
		cout<<"Error in opening file....";
		getch();
		exit(1);
	}
	while(!welfile.eof())
	{
		welfile.get(ch);
		cout<<ch;
	}
	welfile.close();
}

void QuizGame::AnimatedBox()
{	
	//top left point
	gotoxy(62,16);
	cout<<char(201) <<endl;
	//top line: Direction: Left->Right
	for (i = 63; i <= 100; i++)
	{
		gotoxy(i,16);
		cout<<char(205);
		Sleep(10);
	}

	//top right point
	gotoxy(100,16);
	cout<<char(187) <<endl;
	//right side line: Direction: Up->Down
	for ( i = 17; i <=30; i++)
	{
		gotoxy(100,i);
		cout<<char(186);
		Sleep(10);
	}

	//for bottom right point
	gotoxy(100,31);
	cout<<char(188) <<endl;
	//for bottom line: Direction: Left <- Right
	for(i=99;i>=62;i--)
	{
		gotoxy(i,31);
		cout<<char(205);
		Sleep(10);
	}

	//bottom left point
	gotoxy(62,31);
	cout<<char(200) <<endl;
	//Left side Line: Direction: Down-> Up
	for(i=30;i>=17;i--)
	{
		gotoxy(62,i);
		cout<<char(186);
		Sleep(10);
	}
}


//Rectangle Box
void QuizGame::DrawRectangle()
{
	//top left point
	gotoxy(31,12);
	cout<<char(201) <<endl;
	//top line: Direction: Left->Right
	for (i = 32; i <= 135; i++)
	{
		gotoxy(i,12);
		cout<<char(205);
	}

	//top right point
	gotoxy(135,12);
	cout<<char(187) <<endl;
	//right side line: Direction: Up->Down
	for ( i = 13; i <=37; i++)
	{
		gotoxy(135,i);
		cout<<char(186);
	}

	//for bottom right point
	gotoxy(135,38);
	cout<<char(188) <<endl;
	//for bottom line: Direction: Left <- Right
	for(i=134;i>=31;i--)
	{
		gotoxy(i,38);
		cout<<char(205);
	}

	//bottom left point
	gotoxy(31,38);
	cout<<char(200) <<endl;
	//Left side Line: Direction: Down-> Up
	for(i=37;i>=13;i--)
	{
		gotoxy(31,i);
		cout<<char(186);
	}

}

//LONGER Rectangle Box for list
void QuizGame::DrawLongerRectangle()
{
	//top left point
	gotoxy(31,12);
	cout<<char(201) <<endl;
	//top line: Direction: Left->Right
	for (i = 32; i <= 135; i++)
	{
		gotoxy(i,12);
		cout<<char(205);
	}

	//top right point
	gotoxy(135,12);
	cout<<char(187) <<endl;
	//right side line: Direction: Up->Down
	for ( i = 13; i <=44; i++)
	{
		gotoxy(135,i);
		cout<<char(186);
	}

	//for bottom right point
//	gotoxy(135,45);
//	cout<<char(188) <<endl;

	//for bottom line: Direction: Left <- Right
//	for(i=134;i>=31;i--)
//	{
//		gotoxy(i,45);
//		cout<<char(205);
//	}

	//bottom left point
//	gotoxy(31,45);
//	cout<<char(200) <<endl;

	//Left side Line: Direction: Down-> Up
	for(i=44;i>=13;i--)
	{
		gotoxy(31,i);
		cout<<char(186);
	}

}


void QuizGame::ShowTitleDrawRectangle()
{
			system("cls");
			MainTitle();
			DrawRectangle(); //for drawing rectangle outer frame
}


void QuizGame::AnimatedTitle(char title[])
{
	x=72;	//a is x co-ordinate
    len=strlen(title);

		// for ======================================= before welcome message
		gotoxy(58,15);
		for(i=60;i<=110;i++)
		{
		    cout<<char(61); 	//61 is ASCII value of =
		    Sleep(10); //10 millisecond delay in each iteration for animation :D
		}
	
		//for printing welcome message with delay
		for(i=0;i<len;i++)
		{    
		    gotoxy(x,16);     //a is x co-ordinate with value 45 here
		    cout<<title[i];
		    Sleep(10);
		    x++;
		}
		gotoxy(58,17); // for second ======================================== after welcome message
		for(i=60;i<=110;i++)
		{
		    cout<<char(61);
		    Sleep(10); //10 millisecond delay in each iteration for animation :D
		}
}

//welcome part
void QuizGame::Welcome()
{
	Sleep(2000);
	MainTitle();
	Sleep(3000);
	gotoxy(40,13);
	cout<<"Starting 'IT QUIZ'. Please wait";
	for(i=0;i<3;i++)
	{
		cout<<".";
		Sleep(1000);	//function which waits for (n) seconds
	}
	
	gotoxy(40,15);
	cout<<"Loading files";
	for(i=0;i<3;i++)
	{
		cout<<".";
		Sleep(1000);
	}
	HomeMenu();
}

//Home Menu
void QuizGame::HomeMenu()
{	
	AnimatedBox();
	gotoxy(70,18);
	cout<<"=====================";
	gotoxy(70,19);
	cout<<"      HOME MENU:     ";
	gotoxy(70,20);
	cout<<"=====================";
	gotoxy(75,22);
	cout<<"1. LOGIN";
	gotoxy(75,23);
	cout<<"2. SUPPORT";
	gotoxy(75,24);
	cout<<"3. HELP";
	gotoxy(75,25);
	cout<<"4. EXIT";
	gotoxy(70,27);
	cout<<"Type your Choice==>";
	cin>>choice;
	PlaySound(NULL, 0, 0);  ///stop audio
		switch(choice)
		{
			case '1':
			Login();
			break;	
			
			case '2':
			Support();
			break;
			
			case '3':
			Help();
			break;
			
			case '4':
			ShowTitleDrawRectangle();
			gotoxy(55,16);
		    cout<<"Are you sure you want to exit the Game (y/n)? : ";
		    cin>>ch;
		    if(ch=='y'||ch=='Y')
			{
		        gotoxy(55,20);
		        cout<<"You are exiting...Hope to see you again!!!";
		        gotoxy(61,39);
		        exit(1);
		    }
		    else
			{
				system("cls");
		        Welcome();
		    }
			break;
			
			default:
					gotoxy(68,29);
					cout<<"Invalid Choice!!! Try again!!! ";
					Sleep(3000);
					system("cls");
					Welcome();	
		} //end of switch
}


//Login function
void QuizGame::Login()
{			
			ShowTitleDrawRectangle();
			i=0;
			gotoxy(66,15);
			cout<<"=====================================";
			gotoxy(66,16);
			cout<<"                LOGIN                ";
			gotoxy(66,17);
			cout<<"=====================================";
			
			gotoxy(66,19);
			cout<<"Enter username: ";
			cin>>un;
			
			gotoxy(66,21);
			cout<<"Enter Password: ";
			while(ch!=13)  //13 is Enter key
			{
				ch=getch();
				if(ch!='\r' && ch!='\b')
				{ 
				cout<<"*";
				pass[i]=ch;
				i++;
				}	
			}
			
			pass[i]='\0';
			
			//authentication
			if(strcmp(un,username)==0 && strcmp(pass,password)==0)
			{
				gotoxy(66,23);
				cout<<"Login Successful!!!";
				Sleep(3000);
				itq.MainMenu();
			}
			
			else
			{
			gotoxy(66,24);
			cout<<"\a Username and Password don't match!!! Try again.";
			Sleep(3000);
			Login();
			}	
}
	

//FUNCTIONS OF CLASS PLAYER=============================================================================		
void player::Player_Menus()
	{
		system("cls");
		itq.ShowTitleDrawRectangle();
		gotoxy(66,15);
		cout<<"************* PLAYER MENU **************";
		gotoxy(71,17);
		cout<<"[1] LIST ALL PLAYER DETAILS ";
		gotoxy(71,19);
		cout<<"[2] SEARCH PLAYER DETAILS ";
		gotoxy(71,21);
		cout<<"[3] MODIFY PLAYER DETAILS ";
		gotoxy(71,23);
		cout<<"[4] DELETE PLAYER DETAILS ";
		gotoxy(71,25);
		cout<<"[5] GO BACK ";
		gotoxy(66,27);
		cout<<"***************************************";
		gotoxy(66,29);
		cout<<"Enter your choice: ";
		cin>>choice;
		
		 switch(choice)
		 {
		 case '1':
			system("cls");
			Menu_List();
		 	break;
		 
		 case '2': 
			 system("cls");
			 Menu_Search();
			 break;
		 
		 case '3': 
			 system("cls");
			 Menu_Modify();
			 break;
		 
		 case '4':
			 system("cls");
			 Menu_Delete();
			 break;
		 
		 case '5':
		 	itq.MainMenu();
		 	break;
		 
		 default :
		 	 gotoxy(69,31);
			 cout<<"Invalid. Try Again.";
			 Sleep(3000);
			 system("cls");
		 	 Player_Menus();
		 }
		 
		getch();	
	}
	
//REGISTER	
void player::read_data_registration()
	 {
	 		gotoxy(70,14);
	 		cout<<"*******************************";
	 		gotoxy(70,15);
	 		cout<<"  PLAYER DETAILS REGISTRATION  ";
	 		gotoxy(70,16);
	 		cout<<"*******************************";
	 		gotoxy(66,18);
	 		cout<<"Please Enter Player ID(Only Number) : ";
			//only takes interger or number input
			while(!(cin>>pid))
			{
				gotoxy(66,20);
				cout<<"Enter only Interger(Number)!!! Try Again!!!";
				gotoxy(66,21);
				system("pause");
				cin.clear();	//clear previous input
				cin.ignore(INT_MAX,'\n');	//discard previous input
				system("cls");
				pr.Menu_Register();
			}
	
			fflush(stdin); //to clear buffer
			gotoxy(66,20);
			cout<<"Please Enter Player Name            : ";
			cin>>name;
			gotoxy(66,22);
			cout<<"Please Enter Player Address         : ";
			cin>>address; 
			gotoxy(66,24);
			cout<<"Please Enter Player  Email          : ";
			cin>>email;

	 }
	 
	 void player::Menu_Register()
	 {
	 	 itq.ShowTitleDrawRectangle();
		 fp.open("Player.txt",ios::app | ios::binary);
		 read_data_registration();
		 fp.seekp(0,ios::end); 
		 fp.write((char*)&pr,sizeof(pr));
		 gotoxy(66,27);
		 cout<<"The Player Details Have Been Registered "; 
		 gotoxy(66,30);
		 cout<<"WELCOME " <<name <<", Hope you will enjoy the game.";
		 strcpy(pr.return_name_for_score(),name);
		 gotoxy(66,32);
		 system("pause");
		 fp.close();
		 itq.SubMenu();
	 }

//MODIFY	 
 void player::read_data_modification()
	 {
	 		gotoxy(66,27);
	 		cout<<"Please Enter Player ID(Only Number) : ";
			while(!(cin>>pid))
				{
					gotoxy(66,29);
					cout<<"Enter only Interger(Number)!!! Try Again!!!";
					gotoxy(66,31);
					system("pause");
					cin.clear();	//clear previous input
					cin.ignore(INT_MAX,'\n');	//discard previous input
					pr.Menu_Modify();
				}
			
			
			fflush(stdin); //to clear buffer
			gotoxy(66,28);
			cout<<"Please Enter Player Name            : ";
			cin>>name;
			gotoxy(66,29);
			cout<<"Please Enter Player Address         : ";
			cin>>address;
			gotoxy(66,30);
			cout<<"Please Enter Player  Email          : ";
			cin>>email;

	 }
	
	void player::display_data_for_search_and_modify()
		 {
		 	gotoxy(66,19);
		 	cout<<"====================================";
		 	gotoxy(66,20);
		 	cout<<"Player ID      : "<<pid;
			gotoxy(66,21);
			cout<<"Player Name    : "<<name;
			gotoxy(66,22);
			cout<<"Player Address : "<<address;
			gotoxy(66,23);
			cout<<"Player Email   : "<<email;
		}
		
		
	void player::Menu_Modify()
		 {
		 		itq.ShowTitleDrawRectangle();
		 		int no;
		 		gotoxy(73,13);
	 			cout<<"*************************";
	 			gotoxy(73,14);
	 			cout<<"  MODIFY PLAYER DETAILS  ";
	 			gotoxy(73,15);
	 			cout<<"*************************";
				pr.gotoxy(60,16);
				cout<<"Please Enter ID of the player you want to modify : ";
				while(!(cin>>no))
					{
						gotoxy(66,18);
						cout<<"Enter only Interger(Number)!!! Try Again!!!";
						gotoxy(66,20);
						system("pause");
						cin.clear();	//clear previous input
						cin.ignore(INT_MAX,'\n');	//discard previous input
						system("cls");
						pr.Menu_Modify();
					}
				 fp.open("Player.txt",ios::in | ios::binary | ios::out);
				 if(! fp)
					{
						pr.gotoxy(66,25);
						cout<<"File not Found!!!";
						exit(0);
						
					}
				
						int found=0;
						fp.seekg(0,ios::beg);
						while(fp.read((char*)&pr,sizeof(pr)))
						{
							if(pr.retpid()==no)
							{
									pr.gotoxy(66,18);
									cout<<"***** THE OLD RECORD IS: ******";
									pr.display_data_for_search_and_modify();
									found=1;
									
								 pr.gotoxy(60,25);
								 cout<<"PLEASE ENTER NEW DETAILS OF PLAYER:"<<endl;
								 pr.gotoxy(60,26);
								 cout<<"----------------------------------"<<endl;
								 pr.read_data_modification();
								 fp.clear();	
								 int pos=sizeof(pr);
								 fp.seekp(-pos,ios::cur);
								 fp.write((char*)&pr,sizeof(pr));
								 pr.gotoxy(66,32);
								 cout<<"Record Updated Successfully. ";
							}
						}
				if(found==0)
				{
					gotoxy(60,30);
					cout<<"Data Not Found with ID -> "<<no;
				}		
				fp.close();
				
					gotoxy(60,32);
					cout<<"[Type 1: To go back]==>";
					cin>>choice;
					
					if(choice=='1')
					{
						system("cls");
						Player_Menus();
					}
					else
					{
						gotoxy(60,35);
						cout<<"Invalid Choice!!! Please again Type given options!!!";
						Sleep(3000);
						Menu_Modify();	
					}
				
				getch();
			 }	
			 


//LIST			 	 
	void player::display_data_list()
		 {
			cout<<endl<<endl<<"\t\t\t\t\t\t\t\t====================================";
		 	cout<<endl<<"\t\t\t\t\t\t\t\tPlayer ID: "<<pid;
			cout<<endl<<"\t\t\t\t\t\t\t\tPlayer Name: "<<name;;
			cout<<endl<<"\t\t\t\t\t\t\t\tPlayer Address: "<<address;
			cout<<endl<<"\t\t\t\t\t\t\t\tPlayer Email: "<<email;
		}	 	
		
	void player::Menu_List()
		{
			system("cls");
			itq.MainTitle();
			itq.DrawLongerRectangle(); //for drawing longer rectangle 
			gotoxy(63,13);
 			cout<<"*****************************";
 			gotoxy(63,14);
 			cout<<" LIST OF ALL PLAYER DETAILS  ";
 			gotoxy(63,15);
 			cout<<"*****************************";
			fp.open("Player.txt",ios::in | ios::binary);
			if(! fp)
			{
				cout<<"File not Found!!!";
				exit(0);
			}
		else
		{
			fp.clear();
			fp.read((char*)&pr,sizeof(pr));
			 while(! fp.eof())
				 {
					display_data_list();
					fp.read((char*)&pr,sizeof(pr));
				 } 
		}
		fp.close();
		
				gotoxy(32,32);
				Sleep(3000);
				cout<<"[Type 1: To go back]==>";
				cin>>choice;
				
				if(choice=='1')
				{
					system("cls");
					Player_Menus();
				}
				else
				{
					gotoxy(60,35);
					cout<<"Invalid Choice!!! Please again Type given options!!!";
					Sleep(3000);
					Menu_List();	
				}
		
		 getch();
		}

//SEARCH
void player::Menu_Search()
{
		itq.ShowTitleDrawRectangle();
		gotoxy(66,15);
		cout<<"************* SEARCH MENU **************";
		gotoxy(69,17);
		cout<<"[1] SEARCH PLAYER DETAILS BY ID";
		gotoxy(69,18);
		cout<<"[2] SEARCH PLAYER DETAILS  BY NAME";
		gotoxy(69,19);
		cout<<"[3] GO BACK";
		gotoxy(66,21);
		cout<<"****************************************";
		gotoxy(66,23);
		cout<<"Enter your choice: ";
		cin>>choice;
		
		 switch(choice)
		 {
		 	case '1': 
			system("cls");
			Search_by_ID();
		  	break;
		 
		 case '2':
			system("cls");
			Search_by_name();
		 	break;
		 
		 case '3':
			system("cls");
			Player_Menus();
		 	break;
		 
		 default :
		 	 gotoxy(69,26);
			 cout<<"Invalid. Try Again.";
			 Sleep(3000);
			 system("cls");
		 	 Menu_Search();
		 }
		 
		getch();
}
	
	void player::Search_by_ID()
		 {
		 		itq.ShowTitleDrawRectangle();
		 		int no;
		 		gotoxy(66,13);
	 			cout<<"********************************";
	 			gotoxy(66,14);
	 			cout<<"  SEARCH PLAYER DETAILS(BY ID) ";
	 			gotoxy(66,15);
	 			cout<<"********************************";
				gotoxy(55,16);
				cout<<"Please Enter ID of the player you want to search : ";
				while(!(cin>>no))
					{
						gotoxy(66,18);
						cout<<"Enter only Interger(Number)!!! Try Again!!!";
						gotoxy(66,20);
						system("pause");
						cin.clear();	//clear previous input
						cin.ignore(INT_MAX,'\n');	//discard previous input
						system("cls");
						pr.Search_by_ID();
					}
					
				 fp.open("Player.txt",ios::in | ios::binary | ios::out);
				 if(! fp)
					{
						pr.gotoxy(66,25);
						cout<<"File not Found!!!";
						exit(0);
						
					}
				
						int found=0;
						fp.seekg(0,ios::beg);
						while(fp.read((char*)&pr,sizeof(pr)))
						{
							if(pr.retpid()==no)
							{
									pr.gotoxy(69,18);
									cout<<"***** THE SEARCHED RECORD IS: ******";
									pr.display_data_for_search_and_modify();
									found=1;
									break;
							}
						}
				fp.clear();	
				if(found==0)
				{
					gotoxy(60,30);
					cout<<"Data Not Found with ID -> "<<no;
				}	
				fp.close();
				
				gotoxy(60,32);
					cout<<"[Type 1: To go back]==>";
					cin>>choice;
					
					if(choice=='1')
					{
						system("cls");
						Menu_Search();
					}
					else
					{
						gotoxy(60,35);
						cout<<"Invalid Choice!!! Please again Type given options!!!";
						Sleep(3000);
						system("cls");
						Search_by_ID();	
					}
				
				getch();
		 }
		 
		 
	void player::Search_by_name()
		 {
		 		itq.ShowTitleDrawRectangle();
		 		char name_for_search[50];
				gotoxy(66,13);
	 			cout<<"*********************************";
	 			gotoxy(66,14);
	 			cout<<" SEARCH PLAYER DETAILS(BY NAME) ";
	 			gotoxy(66,15);
	 			cout<<"*********************************";
				gotoxy(55,16);
				cout<<"Please Enter NAME of the player you want to search:";
				cin>>name_for_search;
				fp.open("Player.txt",ios::in | ios::binary | ios::out);
				 if(! fp)
					{
						gotoxy(66,25);
						cout<<"File not Found!!!";
						exit(0);
						
					}
				
						int found=0;
						fp.seekg(0,ios::beg);
						while(fp.read((char*)&pr,sizeof(pr)))
						{
							if(strcmp(pr.retname(),name_for_search)==0)
							{
									gotoxy(69,18);
									cout<<"***** THE SEARCHED RECORD IS: ******";
									pr.display_data_for_search_and_modify();
									found=1;
									break;
							}
						}
				fp.clear();	
				if(found==0)
				{
					gotoxy(60,30);
					cout<<"Data Not Found with NAME -> "<<name_for_search;
				}	
				fp.close();
				
				gotoxy(60,32);
					cout<<"[Type 1: To go back]==>";
					cin>>choice;
					
					if(choice=='1')
					{
						system("cls");
						Menu_Search();
					}
					else
					{
						gotoxy(60,35);
						cout<<"Invalid Choice!!! Please again Type given options!!!";
						Sleep(3000);
						system("cls");
						Search_by_name();	
					}
				
				getch();
			}
			
		 	
//DELETE		
	void player::Menu_Delete() 
		{	
					itq.ShowTitleDrawRectangle();
					int no;
					gotoxy(60,13);
		 			cout<<"*************************";
		 			gotoxy(60,14);
		 			cout<<"  DELETE PLAYER DETAILS  ";
		 			gotoxy(60,15);
		 			cout<<"*************************";
					gotoxy(60,17);
					cout<<"Please Enter ID of the player you want to delete : ";
					//only takes interger or number input
					while(!(cin>>no))
						{
							gotoxy(66,19);
							cout<<"Enter only Interger(Number)!!! Try Again!!!";
							gotoxy(66,21);
							system("pause");
							cin.clear();	//clear previous input
							cin.ignore(INT_MAX,'\n');	//discard previous input
							system("cls");
							pr.Menu_Delete();
						}
				
					fstream fp2 ;
					fp2.open("Temp.txt",ios::out | ios::binary);
					fp.open("Player.txt",ios::in | ios::binary);
					int found=0;
				 	if(! fp)
					{
						pr.gotoxy(66,20);
						cout<<"File not Found!!!";
						exit(0);
						
					}
					else if(found==0)
							{
								gotoxy(60,30);
								cout<<"Data Not Found with ID -> "<<no;
								goto Go_Back;
							}
					else
					{
						
						 fp.read((char*)&pr,sizeof(pr));
						 while(! fp.eof())
						 {
						 if(pr.retpid()!=no)
						 {
						 	fp2.write((char*)&pr,sizeof(pr));
						 }
						  fp.read((char*)&pr,sizeof(pr));
						 }
					}	
									
						fp2.close();
						fp.close();
						remove("Player.txt");
						rename("Temp.txt","Player.txt");
						sleep(3000);
						pr.gotoxy(66,23);
						cout<<"Deleting.......";
						pr.gotoxy(66,25);
						cout<<"Record Deleted Successfully..";
					
					Go_Back:	
					gotoxy(60,32);
					cout<<"[Type 1: To go back]==>";
					cin>>choice;
					
					if(choice=='1')
					{
						system("cls");
						Player_Menus();
					}
					else
					{
						gotoxy(60,35);
						cout<<"Invalid Choice!!! Please again Type given options!!!";
						Sleep(3000);
						system("cls");
						Menu_Delete();	
					}
					
						getch();
		 }



//===============CONTINUE TO FUNCTIONS OF CLASS QUIZGAME============================================
//for Main menu options
void QuizGame::MainMenu()
{		
		ShowTitleDrawRectangle();
		gotoxy(66,15);
		cout<<"********** MAIN MENU ***********";
		gotoxy(74,17);
		cout<<"[1] START GAME ";
		gotoxy(74,19);
		cout<<"[2] VIEW SCORE ";
		gotoxy(74,21);
		cout<<"[3] PLAYER MENU ";
		gotoxy(74,23);
		cout<<"[4] LOG OUT ";
		gotoxy(66,25);
		cout<<"********************************";
		gotoxy(66,27);
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
		case '1':
		{	
			pr.Menu_Register();	
			break;			
	  	}	
		
		case '2':  //for checking score menu
		{
		 	View_my_score();   
		    break;
		} 
		
		case '3':  //for checking score menu
		{
		 	pr.Player_Menus();   
		    break;
		}   

		case '4':
		{
			LogOut();
		    break;
		}
		    
		default:
		    gotoxy(51,28);
		    cout<<"Invalid Input, try again!!!";
		    Sleep(3000);
		    MainMenu();
		}	//end of switch
}	//end of MainMenu

void QuizGame::SubMenu()
{
				ShowTitleDrawRectangle();
				gotoxy(66,15);
				cout<<"*********** SUB MENU ***********";
				gotoxy(70,17);
				cout<<"[1] COMPUTER FUNDAMENTALS ";
				gotoxy(70,19);
				cout<<"[2] PROGRAMMING ";
				gotoxy(70,21);
				cout<<"[3] HARDWARE & NETWORK ";
				gotoxy(70,23);
				cout<<"[4] DATABASE";
				gotoxy(70,25);
				cout<<"[5] MISCELLANEOUS";
				gotoxy(70,27);
				cout<<"[6] GO BACK";
				gotoxy(66,29);
				cout<<"*********************************";
				gotoxy(66,31);
				cout<<"Enter your choice: ";
				cin>>choice;
						switch(choice)
						{
						case '1':
						{	
								AgainCompSet:
								SetMenus();
								if(setop=='1')	//setop is set Menus options
								{	
									ShowTitleDrawRectangle();
//									char SetTitle[50]=" Computer Fundamentals : Set A ";
									char FileName[]="CompFundSetA.txt";	//reading txt file of questions
									Questions(FileName);
								}
								else if(setop=='2')
								{
									ShowTitleDrawRectangle();
									char FileName[]="CompFundSetB.txt";
									Questions(FileName);
								}
								else if(setop=='3')
								{
									sleep(2000);
									system("cls");
									MainMenu();
									break;
								}
								else
								{
										gotoxy(51,28);
									    cout<<"Invalid Input, try again!!!";
									    Sleep(3000);
									    goto AgainCompSet;
								}
								break;
						} 	//end of case 1
						
						case '2':
						{
								AgainProgSet:
								SetMenus();
								if(setop=='1')
								{
									ShowTitleDrawRectangle();
									char FileName[]="ProgSetA.txt";	//reading txt file of questions
									Questions(FileName);
								}
								else if(setop=='2')
								{
									ShowTitleDrawRectangle();
									char FileName[]="ProgSetB.txt";	//reading txt file of questions
									Questions(FileName);
								}
								else if(setop=='3')
								{
									sleep(2000);
									system("cls");
									MainMenu();
									break;
								}
								else
								{
										gotoxy(51,28);
									    cout<<"Invalid Input, try again!!!";
									    Sleep(3000);
									    goto AgainProgSet;
								}
								break;
						}		//end of case 2
						
						case '3':
						{
								AgainNetSet:
								SetMenus();
								if(setop=='1')
								{
									ShowTitleDrawRectangle();
									char FileName[]="NetHwSetA.txt";	//reading txt file of questions
									Questions(FileName);
								}
								else if(setop=='2')
								{
									ShowTitleDrawRectangle();
									char FileName[]="NetHwSetB.txt";	//reading txt file of questions
									Questions(FileName);
								}
								else if(setop=='3')
								{
									sleep(2000);
									system("cls");
									MainMenu();
									break;
								}
								else
								{
										gotoxy(51,28);
									    cout<<"Invalid Input, try again!!!";
									    Sleep(3000);
									    goto AgainNetSet;
								}
								break;
						}	//end of case 3	
						
						case '4':
						{		
								AgainDBSet:
								SetMenus();
								if(setop=='1')
								{
									ShowTitleDrawRectangle();
									char FileName[]="DBSetA.txt";	//reading txt file of questions
									Questions(FileName);
								}
								else if(setop=='2')
								{
									ShowTitleDrawRectangle();
									char FileName[]="DBSetB.txt";	//reading txt file of questions
									Questions(FileName);
								}
								else if(setop=='3')
								{
									sleep(2000);
									system("cls");
									MainMenu();
									break;
								}
								else
								{
										gotoxy(51,28);
									    cout<<"Invalid Input, try again!!!";
									    Sleep(3000);
									    goto AgainDBSet;
								}
								break;
						}	//end of case 4
						
						case '5':
						{
								AgainMiscSet:
								SetMenus();
								if(setop=='1')
								{
									ShowTitleDrawRectangle();
									char FileName[]="MiscellSetA.txt";	//reading txt file of questions
									Questions(FileName);
								}
								else if(setop=='2')
								{
									ShowTitleDrawRectangle();
									char FileName[]="MiscellSetB.txt";	//reading txt file of questions
									Questions(FileName);
								}
								else if(setop=='3')
								{
									sleep(2000);
									system("cls");
									MainMenu();
									break;
								}
								else
								{
										gotoxy(51,28);
									    cout<<"Invalid Input, try again!!!";
									    Sleep(3000);
									    goto AgainMiscSet;
								}
								break;
						}	//end of case 5
						
						case '6':
						{
								system("cls");
								MainMenu();
								break;
						}	//end of case 6
						
						default:
							gotoxy(51,33);
						    cout<<"Invalid Input, try again!!!";
						    Sleep(3000);
						    SubMenu();
						} //end of switch case
}

//Repeated Menus of Set A and Set B for all category
void QuizGame::SetMenus()
{
					ShowTitleDrawRectangle();
					gotoxy(66,15);
					cout<<"*********** SET MENU ***********";
					gotoxy(76,17);
					cout<<"[1] SET 1 ";
					gotoxy(76,19);
					cout<<"[2] SET 2 ";
					gotoxy(76,21);
					cout<<"[3] GO BACK";
					gotoxy(66,23);
					cout<<"*********************************";
					gotoxy(66,25);
		 			cout<<"Enter your choice: ";
					cin>>setop;
					system("cls");
}

//opening many files using their filename
int QuizGame::Questions(char FileName[])
{
					//newly added : dynamic part
					ifstream file(FileName);
					if(file.bad())
					{
						cout<<"Error in opening file....";
						getch();
						exit(1);
					}
					file.clear();
					file.seekg(0,ios::beg);
						while(!file.eof())
						{
							file.get(ch);
							if(ch=='$')
							{
								file.get(ch);
								gotoxy(59,30);
								cout<<"YOUR ANSWER : ";
								cin>>answer;
								if(ch==answer)
								{
			                        PlaySound(TEXT("CorrectAnsFinal.wav"),NULL,SND_ASYNC); // for correct answer sound
									Sleep(9000);
									gotoxy(59,32);
									cout<<"CORRECT ANSWER!!!";
			                        points+=10;
							        correct+=1;
							        attempt+=1;
							        Sleep(3000);
							   		ShowTitleDrawRectangle();
									continue;
								}
								else if(answer=='q' || answer=='Q')
								{
								gotoxy(51,37);
						        cout<<"You are Exiting...Hope to see you again!!!";
								//exit(1);
								MainMenu();
								}
								else
								{
			                        PlaySound(TEXT("WrongAnsFinal.wav"),NULL,SND_ASYNC); // for Wrong answer sound
									Sleep(9000);
									gotoxy(59,32);
									cout<<"WRONG ANSWER!!!";
									gotoxy(59,34);
									cout<<"The answer is : "<<ch;
									wrong+=1;
								    attempt+=1;
								    Sleep(3000);
									ShowTitleDrawRectangle();
								    continue;
								}	//end of else
							}	//end of nested outer if
							if(!file.eof())
								cout<<ch;
						}//end of while
			   			file.close();
			   
					    //After finishing all the questions, farewell
					   	ShowTitleDrawRectangle();
					   	ofstream wr;
						wr.open("Scoretest.txt",ios::app);
						char title[]="END OF THE GAME: RESULT";
						AnimatedTitle(title);
					    gotoxy(63,19);
					    cout<<"We have come to the end of quiz.";
					    gotoxy(67,20);
					    cout<<"Thank you for playing!!!";
					    gotoxy(69,21);
					    cout<<"Hope you enjoyed it!";
					    gotoxy(67,23);
					    cout<<"Player Name              : "  <<pr.return_name_for_score();
					    gotoxy(67,24);
					    cout<<"Your Total Score is      : "  <<points;
					    gotoxy(67,25);
					    cout<<"Total questions attempt  : "  <<attempt;
					    gotoxy(67,26);
					    cout<<"Total correct answers    : "  <<correct;
					    gotoxy(67,27);
					    cout<<"Total wrong answers      : "  <<wrong;
					    
					    //storing score
						wr<<endl<<"==============================================="<<endl;
						wr<<"Player Name:             : "  <<pr.return_name_for_score()<<endl;
						wr<<"Your Total Score is      : "  <<points<<endl;
					    wr<<"Total questions attempt  : "  <<attempt<<endl;
					    wr<<"Total correct answers    : "  <<correct<<endl;
					    wr<<"Total wrong answers      : "  <<wrong<<endl;
						wr.close();
						fp.close();
					    
					    gotoxy(63,29);
					    cout<<"Do you want to play again or exit (y/n) : ";
					    cin>>ans;
					    if(ans=='y'||ans=='Y')
						{
					        MainMenu();
					    }
			
					    else
						{
					        gotoxy(60,34);
					        cout<<"You are exiting...Hope to see you again!!!";
					        gotoxy(51,38);
					        exit(0);
					    }
return 0;
}


void QuizGame::View_my_score()
{
		ShowTitleDrawRectangle();
		char title[]="      VIEW MY SCORE ";
		AnimatedTitle(title);
	    gotoxy(63,19);
	    cout<<" [10 points for every correct answer.]";
	    gotoxy(63,21);
		cout<<" -> Player Name                :     "  <<pr.return_name_for_score();
	    gotoxy(63,22);
	    cout<<" -> Your total score is        :     "<<points;
	    gotoxy(63,23);
	    cout<<" -> Total attempted question   :     "<<attempt;
	    gotoxy(63,24);
	    cout<<" -> Total correct answers      :     "<<correct;
	    gotoxy(63,25);
	    cout<<" -> Total wrong answers        :     "<<wrong;
	    
	    	gotoxy(60,30);
			cout<<"[Type 1: To go back]==>";
			cin>>ch;
			
			if(ch=='1')
			{
				system("cls");
				MainMenu();
			}
			else
			{
				gotoxy(50,35);
				cout<<"Invalid Choice!!! Please again Type given options!!!";
				Sleep(3000);
				View_my_score();
			}
}


//Log Out
void QuizGame::LogOut()
{
	
		ShowTitleDrawRectangle();
		gotoxy(50,17);
		cout<<"Do you want to Log Out? [Type 'Y/y' for Yes and 'N/n' for No]: ";
		cin>>setop;	
		switch(setop)
		{
			case 'Y': 
			gotoxy(60,21);
			cout<<"Successfully Logged Out!!!";
			Sleep(3000);
			system("cls");
			Welcome();
			break;
				
			case 'y': 
			gotoxy(60,21);
			cout<<"Successfully Logged Out!!!";
			Sleep(3000);
			system("cls");
			Welcome();
			break;
			
			case 'N': 
			system("cls");
			MainMenu();
			break;
			
			case 'n': 
			system("cls");
			MainMenu();
			break;
			
			default:
					gotoxy(50,25);
					cout<<"Invalid Choice!!! Please again Type given options!!!";
					Sleep(3000);
					LogOut();
		} //end of switch
}
					

void QuizGame::Help()
{
	ShowTitleDrawRectangle();
	char title[]="WELCOME TO HELP SECTION";
	AnimatedTitle(title);
	gotoxy(58,19);
	cout<<"1. How to use IT QUIZ?";
	gotoxy(58,20);
	cout<<"2. About IT QUIZ";
	gotoxy(58,21);
	cout<<"3. Go Back";
	gotoxy(58,23);
	cout<<"Type your Choice==>";
	cin>>choice;
	switch(choice)
		{
			case '1':
			HowToUse();
			break;	
			
			case '2':
			About();
			break;
			
			case '3':
			system("cls");
			Welcome();
			break;
			
			default:
				gotoxy(58,25);
				cout<<"Invalid Choice!!! Please again Type given options!!!";
				Sleep(3000);
				Help();
		} //end of switch

}

void QuizGame::HowToUse()
{
	ShowTitleDrawRectangle();
	char title[]="WELCOME TO HowToUse SECTION";
	AnimatedTitle(title);
	
	gotoxy(47,19);
	printf("STEPS TO FOLLOW:");
	gotoxy(47,20);
	printf("-------------------------------------------------------------------------------");
	gotoxy(47,21);
	printf("1. List of options is provided as per your choice, you read and choose.");
	gotoxy(47,22);
	printf("2. Then, you must TYPE one of the provided number to choose options.");
	gotoxy(47,23);
	printf("3. Then, you must TYPE related letter or number to go back.");
	gotoxy(47,24);
	printf("4. If you TYPE wrong choice, then you are again to TYPE correct given ");
	gotoxy(47,25);
	printf("   options to proceed further to play IT Quiz game.");
	gotoxy(47,26);
	printf("--------------------------------------------------------------------------------");
	gotoxy(47,28);
	printf("***Note: Login Username: admin and Password: admin");
	gotoxy(47,29);
	printf("***Note: Press 'Q' or 'q' to quit the game while answering the questions.");
	gotoxy(67,31);
	printf("***Thank YOU***");				

	gotoxy(50,33);
	cout<<"[Type 1: To go back]==>";
	cin>>choice;
	
	if(choice=='1')
	{
		system("cls");
		Help();
	}
	else
	{
		gotoxy(50,35);
		cout<<"Invalid Choice!!! Please again Type given options!!!";
		Sleep(3000);
		HowToUse();	
	}
}

void QuizGame::About()
{
	ShowTitleDrawRectangle();
	char title[]="WELCOME TO ABOUT SECTION";
	AnimatedTitle(title);
	
	gotoxy(47,19);
	cout<<"-------------------------------------------------------------------------";
	gotoxy(47,20);
	cout<<"|  IT QUIZ is a project based on object orientd programming(OOP) in C++. |";
	gotoxy(47,21);
	cout<<"| It is used for playing IT related quiz contest. When people need some  |";
	gotoxy(47,22);
	cout<<"| fun and general knowledge too, they can play this game by choosing the |";
	gotoxy(47,23);
	cout<<"| available questions from system list. Username and password is needed  |";
	gotoxy(47,24);
	cout<<"| to login the game. Quiz are available in different categories like:    |";
	gotoxy(47,25);
	cout<<"| Programming, Computer Fundamentals, Hardware, Networking and other IT  |";
	gotoxy(47,26);
	cout<<"| related topics having 2 sets in each category where each set has 5     |";
	gotoxy(47,27);
	cout<<"| questions. Players name and score are also recorded and updated as per |";
	gotoxy(47,28);
	cout<<"| the given answers which can be viewed later if user wishes. We record  |";
	gotoxy(47,29);
	cout<<"| total attempted questions, total correct answers, total wrong answers  |";
	gotoxy(47,30);
	cout<<"| and total marks obtained as well. We have also used audio system to let|";
	gotoxy(47,31);
	cout<<"| user know whether the answer is correct and wrong. Explore & Have fun. |";
	gotoxy(47,32);
	cout<<"-------------------------------------------------------------------------";

	gotoxy(58,35);
	cout<<"[Type 1: To go back]==>";
	cin>>choice;
	
	if(choice=='1')
	{
		Help();
	}
	else
	{
		gotoxy(58,37);
		cout<<"Invalid Choice!!! Please again Type given options!!!";
		Sleep(3000);
		About();	
	}

}

void QuizGame::Support()
{
	ShowTitleDrawRectangle();
	char title[]="WELCOME TO SUPPORT SECTION";
	AnimatedTitle(title);
	gotoxy(58,19);
	cout<<"CONTACT US:";
	gotoxy(58,20);
	cout<<"____________________________________________________________________";
	gotoxy(58,22);
	cout<<"Mobile No : 9860245202(Ameer), 9810130495(Badri), 9806101417(Sandip)";
	gotoxy(58,23);
	cout<<"Address   : New Baneshwor, Kathmandu";
	gotoxy(58,24);
	cout<<"Email     : developers.itquiz@gmail.com";
	gotoxy(58,25);
	cout<<"____________________________________________________________________";
	
	gotoxy(58,27);
	cout<<"[Type 1: To go back]==>";
	cin>>choice;
	
	if(choice=='1')
	{
		system("cls");
		Welcome();
	}
	else
	{
		gotoxy(58,29);
		cout<<"Invalid Choice!!! Please again Type given options!!!";
		Sleep(3000);
		Support();	
	}

}

//main starts---------------------------------------
int main()
{
//	int n;
//	cout<<"Enter any number:";
//	cin>>n;


    //audio test
	PlaySound(TEXT("test.wav"),NULL,SND_ASYNC); // to play sound with all functions running
    system("color 3f");	
	itq.Welcome(); //only welcome function is called and other functions are linked
	getch();
	return 0;
}
