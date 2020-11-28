#include<iostream>
#include<fstream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

struct f_seat{
	
	string row;
	string cls;
	string seat;
};

class flight{
	public:
		string FlightNo;
		string depDdepT;
		string depAirport;
		string arrAirport;
	    f_seat s_arr[60];
};



int main()
{
	ofstream file2("Flights.dat");    //file2 (Updated_File.txt) =  seat booking updated file
	cout<<"\n   _____________________Wellcome to Virgin Airline Seat Reservation System !!!_____________________ \n "<<endl;
	cout<<"    1.Display available flight\n    2.View flight\n    3.Seat availability\n    4.Seat booking\n    5.Exit \n"<<endl;
	                     
	ifstream file;
	string line,data;                         
	int flight_count=0;                      //flight_count= no of flight in  the file(No object)
	file.open("flight.txt");
	
	while(getline(file,line))
	{	
		if(line.empty())
		{
		flight_count++;            //count  no of objects
		} 			 
	}
	
	file.close();
	
	int n=0,count=0,i=0	;                       
	flight f_arr[flight_count];
	file.open("flight.txt");
	
	while(getline(file,data))
	{
		count++;

		   	if(count==1)
			{
				f_arr[n].FlightNo=data;

			}
			else if(count==2)
			{
				f_arr[n].depDdepT=data;	
	
			}
			
			else if(count==3)
			{
				f_arr[n].depAirport=data;

			}
			else if(count==4)
			{
				f_arr[n].arrAirport=data;
			
			}
			else
			{
				if(data.empty())
				{
					count=0;
					n++;
					i=0;
				}
				else
				{
					stringstream word(data);
					word>>f_arr[n].s_arr[i].row;
					word>>f_arr[n].s_arr[i].cls;
					word>>f_arr[n].s_arr[i].seat;
					i++;
				}
			
			}
		
	}file.close();

	int choise;
	string f;                        //f = Flight number user input
	char s;                       
	int Nos ; 
	string r; 	                     //Nos =  No of seat user require	
	
	int Bcnt=0,Ecnt=0,flag=0,flag2=0,m=0;
	string str;

	do{
	
		cout<<"    Enter your choice : ";
		cin>>choise;
		switch(choise)
		{
			
			case 1:
				cout<<"\n             __________AVAILABLE FLIGHTS__________\n"<<endl;
				for(int j=0;j<flight_count;j++)
				{
					
					for(int k=0;k<60;k++)
					{
						str=f_arr[j].s_arr[k].seat;
						if(f_arr[j].s_arr[k].cls=="B")
						{
							Bcnt=Bcnt+str.size();                  //Bcnt = no of seats in business class
						}
						else if(f_arr[j].s_arr[k].cls=="E")
						{
							Ecnt=Ecnt+str.size();                  //Ecnt  = no of seats in economic class
						}	
					}
					if(Bcnt>0 || Ecnt>0)
					{
						cout<<"\nFlight Number          ----->                      "<<f_arr[j].FlightNo<<endl;
						cout<<"Departure Date & Time  ----->                      "<<f_arr[j].depDdepT<<endl;
						cout<<"Departure Airport      ----->                      "<<f_arr[j].depAirport<<endl;
						cout<<"Arrival Airport        ----->                      "<<f_arr[j].arrAirport<<endl;
						cout<<"Available seats        ----->  Buisness Class--->  "<<Bcnt<<endl;
						cout<<"                               Economic Class--->  "<<Ecnt<<endl;
						cout<<endl;
						Bcnt=0;
						Ecnt=0;
						
					}
				
				}
				system("pause");
				break;
			case 2:
				cout<<" \n             __________VIEW FLIGHT____________ \n"<<endl;
				cout<<"\n\n   Enter flight number :  ";
				cin>>f;                                             //f = Flight number user input
				
				for(int j=0;j<flight_count;j++)
				{
					if(f_arr[j].FlightNo==f)                          
					{
						flag=1;
						for(int k=0;k<60;k++)
						{
							str=f_arr[j].s_arr[k].seat;
							if(f_arr[j].s_arr[k].cls=="B")
							{
								Bcnt=Bcnt+str.size();                  //Bcnt = no of seats in business class
							}
							else if(f_arr[j].s_arr[k].cls=="E")
							{
								Ecnt=Ecnt+str.size();                  //Ecnt  = no of seats in economic class
							}
						}
							cout<<"\nFlight Number          ----->                       "<<f_arr[j].FlightNo<<endl;
							cout<<"Departure Date & Time  ----->                       "<<f_arr[j].depDdepT<<endl;
							cout<<"Departure Airport      ----->                       "<<f_arr[j].depAirport<<endl;
							cout<<"Arrival Airport        ----->                       "<<f_arr[j].arrAirport<<endl;
							cout<<"Available seats        ----->  Buisness Class --->  "<<Bcnt<<endl;
							cout<<"                               Economic Class --->  "<<Ecnt<<endl;
							cout<<"Available seats        ----->"<<"___Row No__"<<"___Class__"<<"__Seat No___"<<endl;
							for(int k=0;k<=60;k++)
					 		{
					 			cout<<"                                  "<<f_arr[j].s_arr[k].row<<"         "<<f_arr[j].s_arr[k].cls<<"        "<<f_arr[j].s_arr[k].seat<<endl;
	                     	   if(f_arr[j].s_arr[k].row=="\0")
								{
 		                    		break;
						  	 	}
							}
						cout<<endl;	
						Bcnt=0;
						Ecnt=0;
	
					}
						
				}
				if(flag==0)
				{
					cout<<"\n    Sorry!....Flight Number is not Available..... \n"<<endl;
				}

				system("pause");
				break;
			case 3:
				cout<<"\n             _______________SEAT AVAILABILITY_______________  \n"<<endl;
				cout<<"\n    Enter flight number :";
				cin>>f;                                                    //f = Flight number user input
				cout<<"\n    Enter the no of seat you need :";
				cin>>Nos;                                                 //Nos =  No of seat user require
			    for(int j=0;j<flight_count;j++)
				{
					
					for(int k=0;k<60;k++)
					{
						str=f_arr[j].s_arr[k].seat;
						if(f_arr[j].s_arr[k].cls=="B")
						{
							Bcnt=Bcnt+str.size();                  //Bcnt = no of seats in business class
						}
						else if(f_arr[j].s_arr[k].cls=="E")
						{
							Ecnt=Ecnt+str.size();                  //Ecnt  = no of seats in economic class
						}	
					}
					if(f_arr[j].FlightNo==f)
					{
						if( (Bcnt+Ecnt) >= Nos)
						{
							cout<<"	....Seats are available...\n"<<endl;
							cout<<"Total no of available seats   ----->  Buisness Class --->  "<<Bcnt<<endl;
							cout<<"                                      Economic Class --->  "<<Ecnt<<endl;
						}
						else
						{
							cout<<".... Sorry!!!  Seats are not available... "<<endl;
						}
					
		
					}
					cout<<endl;	
					Bcnt=0;
					Ecnt=0;
				}
  
				system("pause");
				break;
			case 4:
				cout<<"\n\n        ____________SEAT BOOKING______________      \n"<<endl;
				cout<<"\n Enter flight number :";
				cin>>f;                                                       //f = Flight number user input
				cout<<" Enter seat location-> \t seat row [1-60]   : ";
				cin>>r;                                                        //r = row number user require to book seat
				cout<<" \t\t\t seat no [A-F]    :  ";
				cin>>s;                                                        //s = seat number user require to book 
				for(int j=0;j<flight_count;j++)
				{
					if(f_arr[j].FlightNo==f)
					{
						for(int k=0;k<=60;k++)
						{
							if(f_arr[j].s_arr[k].row==r) 
							{
								flag=1;
								for(int x=0;x<f_arr[j].s_arr[k].seat.length();x++)
								{
							    	if(f_arr[j].s_arr[k].seat[m]==s)
									{
										flag2=1;
										f_arr[j].s_arr[k].seat.erase(m,1);	
										cout<<"\n    Congradz!!!  Your Seat is booking  \n"<<endl;
									}
								}
							}
						}
				   }
				}
				if(flag==0||flag2==0)
				{
					cout<<" \n .......Sorry !!!  Your seat booking is failure....  \n"<<endl;
				}
				
				system("pause");
				break;
			case 5:
				
					for(int j=0;j<flight_count;j++)                            
				{
   					file2<<f_arr[j].FlightNo<<endl;;                                 //file2 (Updated_File.dat) =  seat booking updated 
   					file2<<f_arr[j].depDdepT<<endl;
   					file2<<f_arr[j].depAirport<<endl;
   					file2<<f_arr[j].arrAirport<<endl;
   					for(int k=0;k<=60;k++)
					{
   						file2<<f_arr[j].s_arr[m].row<<"  "<<f_arr[j].s_arr[m].cls<<"  "<<f_arr[j].s_arr[m].seat<<endl;
   						if(f_arr[j].s_arr[m].row=="\0")
						{
   							break;
	   					}
   					}
				}
				cout<<"...THANK YOU For joining us...\n"<<endl;
				break;
			default:
				cout<<" \n          Invalid choise !!!   \n";
				return 0;		
		}
	
	}while(choise!=5);


}

