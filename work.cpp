#include<iostream>
#include<vector>
#include <fstream>
#include <time.h>
#include <string>
#include<ctime>
#include<queue>
#include <typeinfo>
using namespace std ;

struct Data{
	int id ;
	int burst ;
	int arrival ;
	int priority ;
	int waiting ;
	int turnaround ;
	double response ;	
};

class FCFS{
	//vector<Data> buffer ;
	int mode ;
	int timeslice ;
	//vector<string> ans ;
	public:
		vector<Data> buffer ;
		vector<string> ans ;
		
		bool Read( string name ){
			buffer.clear() ;
			fstream infile ;
			string file = name + ".txt" ;
			infile.open(file.c_str(), ios::in) ;
			if( !infile.is_open()){
				cout << "### " << file << " does not exist! ### " << endl << endl ;
            	return false ;
			} // if
			else{
				infile >> mode ;
				infile >> timeslice ;
				
				for( int i = 0 ; i < 6 ; i++ ){
					string temp ;
					infile >> temp ;
					//cout << temp << endl;
				} // for
				
				int id ;
				int num = 1 ;
				while( infile >> id ){
					Data temp ;
					
					temp.id = id ;
					infile >> temp.burst ;
					infile >> temp.arrival ;
					infile >> temp.priority ;
					//cout << num << " " << temp.id << " " << temp.burst << " " << temp.arrival << " " << temp.priority << endl;
					buffer.push_back(temp) ;
				} // while
				
			} // else
			
			infile.close() ;
			return true ;
		} // Read()
		
		void Write( string name ){
			fstream outfile ;
			string Ofile = "out_" + name + "_method1.txt" ;
			outfile.open(Ofile.c_str(), ios::out) ;
			
			outfile << "FCFS\n" ;
			outfile << "==        FCFS==\n" ;
			for( int i = 0 ; i < ans.size() ; i++ ){
				outfile << ans[i] ;
			} // for
			outfile << "\n" ;
			outfile << "===========================================================\n\n" ;
			outfile << "Waiting Time\nID	FCFS\n" ;
			outfile << "===========================================================\n" ;
			
			int n = buffer.size() ;
			for( int pass = 1 ; pass < n ; ++pass ){
				for( int index = 0 ; index < n - pass ; index++ ){ 
					if( buffer[index].id > buffer[index+1].id )
						swap( index, index+1 );
						
				} // for
				
			} // for
			
			for( int i = 0 ; i < buffer.size() ; i++ ){
				outfile << buffer[i].id << "\t" << buffer[i].waiting << "\n" ;
			} // for
			outfile << "===========================================================\n\n" ;
			outfile << "Turnaround Time\n" ;
			outfile << "ID	FCFS\n" ;
			outfile << "===========================================================\n" ;
			for( int i = 0 ; i < buffer.size() ; i++ ){
				outfile << buffer[i].id << "\t" << buffer[i].turnaround << "\n" ;
			} // for
			outfile << "===========================================================\n\n" ;
			outfile.close() ;
		} // Write()
		
		string InttoString( int num ){
			if( num == 0 ) return "0" ;
			else if( num == 1 ) return "1" ;
			else if( num == 2 ) return "2" ;
			else if( num == 3 ) return "3" ;
			else if( num == 4 ) return "4" ;
			else if( num == 5 ) return "5" ;
			else if( num == 6 ) return "6" ;
			else if( num == 7 ) return "7" ;
			else if( num == 8 ) return "8" ;
			else if( num == 9 ) return "9" ;
			else if( num == 10 ) return "A" ;
			else if( num == 11 ) return "B" ;
			else if( num == 12 ) return "C" ;
			else if( num == 13 ) return "D" ;
			else if( num == 14 ) return "E" ;
			else if( num == 15 ) return "F" ;
			else if( num == 16 ) return "G" ;
			else if( num == 17 ) return "H" ;
			else if( num == 18 ) return "I" ;
			else if( num == 19 ) return "J" ;
			else if( num == 20 ) return "K" ;
			else if( num == 21 ) return "L" ;
			else if( num == 22 ) return "M" ;
			else if( num == 23 ) return "N" ;
			else if( num == 24 ) return "O" ;
			else if( num == 25 ) return "P" ;
			else if( num == 26 ) return "Q" ;
			else if( num == 27 ) return "R" ;
			else if( num == 28 ) return "S" ;
			else if( num == 29 ) return "T" ;
			else if( num == 30 ) return "U" ;
			else if( num == 31 ) return "V" ;
			else if( num == 32 ) return "W" ;
			else if( num == 33 ) return "X" ;
			else if( num == 34 ) return "Y" ;
			else if( num == 35 ) return "Z" ;
			else return "\0" ;
		}
		
		void bubblesort(){
			int n = buffer.size() ;
			for( int pass = 1 ; pass < n ; ++pass ){ // –Ω常穦盢程程 
				for( int index = 0 ; index < n - pass ; index++ ){ //程ぃノ浪琩﹚琌程┮–Ω浪琩Ω计搭ぶ 
					if( buffer[index].arrival > buffer[index+1].arrival )
						swap( index, index+1 );
					else if( buffer[index].arrival == buffer[index+1].arrival ){
						if( buffer[index].id > buffer[index+1].id )
							swap( index, index+1 );
					} // else if 
						
				} // for
				
			} // for
			
			
		} // end of bubblesort
		
		void swap( int num1, int num2 ){
			Data temp ; 
			temp = buffer[num1] ;
			buffer[num1] = buffer[num2] ;
			buffer[num2] = temp ;
		} // end of swap
		
		void Main( string name ){
			Read(name) ;
			bubblesort() ;
			//Display() ;
			Run() ;
			//ANS() ;
			//Write(name) ; 
		} // Main()
		
		void Run(){
			int time = 0 ;
			int num = 0 ;
			//queue<Data> q ;
			vector<Data> q ;
			int ts = 0 ;
			while( num < buffer.size() || !q.empty() ){
				//р狥﹁queue 
				while( time == buffer[num].arrival ){
					q.push_back(buffer[num]) ;
					num++ ;
				} // while
				/*
				for( int i = 0 ; i < q.size() ; i++ ){
					cout <<	q[i].id << " " ;
				} // for
				cout << "-----------" << time << endl ;
				*/
				if( num < buffer.size() && q.empty() ){
					ans.push_back("-") ;
					
				} // if
				else{
					//秨﹍衡丁
					
					Data Running = q.front() ;
					//cout << Running.id << "-------------------" << Running.burst << endl;
					Running.burst = Running.burst - 1 ;
					q[0].burst = Running.burst ;
					string sid = InttoString(Running.id) ;
					ans.push_back(sid) ;
					
					//cout << Running.id << "-------------------" << Running.burst << endl;
					ts++ ;
					
					if( Running.burst == 0 ){
						//string sid = InttoString(Running.id) ;
						//ans.push_back(sid) ;
						
						for( int k = 0 ; k < buffer.size() ; k++ ){
							if( Running.id == buffer[k].id ){
								int now = time + 1 ; 
								buffer[k].turnaround = now - buffer[k].arrival ;
								buffer[k].waiting = buffer[k].turnaround - buffer[k].burst ;
							} // if
						}
						
						q.erase(q.begin()) ;
						ts = 0 ;
					} // if
					/*
					else if( ts == timeslice ){
						string sid = InttoString(Running.id) ;
						ans.push_back(sid) ;
						
						ts = 0 ;
					} // if
					*/
					
				} // else
				
				time++ ;
			} // while
			
		}
		
		void Display(){
			cout << "mode: " << mode << endl ;
			cout << "Timeslice: " << timeslice << endl ;
			cout << "ID     CPU Burst  Arrival Time   Priority" << endl ;
			for( int i = 0 ; i < buffer.size() ; i++ ){
				cout << buffer[i].id << " " << buffer[i].burst << " " << buffer[i].arrival << " " << buffer[i].priority << endl;
			}
		}
		
		void ANS(){
			for( int i = 0 ; i < ans.size() ; i++ ){
				cout << ans[i] ;
			} // for
			cout << endl;
		}
};

class RR{
	//vector<Data> buffer ;
	int mode ;
	int timeslice ;
	//vector<string> ans ;
	public:
		vector<Data> buffer ;
		vector<string> ans ;
		
		bool Read( string name ){
			buffer.clear() ;
			fstream infile ;
			string file = name + ".txt" ;
			infile.open(file.c_str(), ios::in) ;
			if( !infile.is_open()){
				cout << "### " << file << " does not exist! ### " << endl << endl ;
            	return false ;
			} // if
			else{
				infile >> mode ;
				infile >> timeslice ;
				
				for( int i = 0 ; i < 6 ; i++ ){
					string temp ;
					infile >> temp ;
					//cout << temp << endl;
				} // for
				
				int id ;
				int num = 1 ;
				while( infile >> id ){
					Data temp ;
					
					temp.id = id ;
					infile >> temp.burst ;
					infile >> temp.arrival ;
					infile >> temp.priority ;
					//cout << num << " " << temp.id << " " << temp.burst << " " << temp.arrival << " " << temp.priority << endl;
					buffer.push_back(temp) ;
				} // while
				
			} // else
			
			infile.close() ;
			return true ;
		} // Read()
		
		void Write( string name){
			fstream outfile ;
			string Ofile = "out_" + name + "_method2.txt" ;
			outfile.open(Ofile.c_str(), ios::out) ;
			
			outfile << "RR\n" ;
			outfile << "==          RR==\n" ;
			for( int i = 0 ; i < ans.size() ; i++ ){
				outfile << ans[i] ;
			} // for
			outfile << "\n" ;
			outfile << "===========================================================\n\n" ;
			outfile << "Waiting Time\nID	RR\n" ;
			outfile << "===========================================================\n" ;
			
			int n = buffer.size() ;
			for( int pass = 1 ; pass < n ; ++pass ){
				for( int index = 0 ; index < n - pass ; index++ ){ 
					if( buffer[index].id > buffer[index+1].id )
						swap( index, index+1 );
						
				} // for
				
			} // for
			
			for( int i = 0 ; i < buffer.size() ; i++ ){
				outfile << buffer[i].id << "\t" << buffer[i].waiting << "\n" ;
			} // for
			outfile << "===========================================================\n\n" ;
			outfile << "Turnaround Time\n" ;
			outfile << "ID	RR\n" ;
			outfile << "===========================================================\n" ;
			for( int i = 0 ; i < buffer.size() ; i++ ){
				outfile << buffer[i].id << "\t" << buffer[i].turnaround << "\n" ;
			} // for
			outfile << "===========================================================\n\n" ;
			outfile.close() ;
		} // Write()
		
		string InttoString( int num ){
			if( num == 0 ) return "0" ;
			else if( num == 1 ) return "1" ;
			else if( num == 2 ) return "2" ;
			else if( num == 3 ) return "3" ;
			else if( num == 4 ) return "4" ;
			else if( num == 5 ) return "5" ;
			else if( num == 6 ) return "6" ;
			else if( num == 7 ) return "7" ;
			else if( num == 8 ) return "8" ;
			else if( num == 9 ) return "9" ;
			else if( num == 10 ) return "A" ;
			else if( num == 11 ) return "B" ;
			else if( num == 12 ) return "C" ;
			else if( num == 13 ) return "D" ;
			else if( num == 14 ) return "E" ;
			else if( num == 15 ) return "F" ;
			else if( num == 16 ) return "G" ;
			else if( num == 17 ) return "H" ;
			else if( num == 18 ) return "I" ;
			else if( num == 19 ) return "J" ;
			else if( num == 20 ) return "K" ;
			else if( num == 21 ) return "L" ;
			else if( num == 22 ) return "M" ;
			else if( num == 23 ) return "N" ;
			else if( num == 24 ) return "O" ;
			else if( num == 25 ) return "P" ;
			else if( num == 26 ) return "Q" ;
			else if( num == 27 ) return "R" ;
			else if( num == 28 ) return "S" ;
			else if( num == 29 ) return "T" ;
			else if( num == 30 ) return "U" ;
			else if( num == 31 ) return "V" ;
			else if( num == 32 ) return "W" ;
			else if( num == 33 ) return "X" ;
			else if( num == 34 ) return "Y" ;
			else if( num == 35 ) return "Z" ;
			else return "\0" ;
		}
		
		void bubblesort(){
			int n = buffer.size() ;
			for( int pass = 1 ; pass < n ; ++pass ){ // –Ω常穦盢程程 
				for( int index = 0 ; index < n - pass ; index++ ){ //程ぃノ浪琩﹚琌程┮–Ω浪琩Ω计搭ぶ 
					if( buffer[index].arrival > buffer[index+1].arrival )
						swap( index, index+1 );
					else if( buffer[index].arrival == buffer[index+1].arrival ){
						if( buffer[index].id > buffer[index+1].id )
							swap( index, index+1 );
					} // else if 
						
				} // for
				
			} // for
			
			
		} // end of bubblesort
		
		void swap( int num1, int num2 ){
			Data temp ; 
			temp = buffer[num1] ;
			buffer[num1] = buffer[num2] ;
			buffer[num2] = temp ;
		} // end of swap
		
		void Main( string name ){
			Read(name) ;
			bubblesort() ;
			//Display() ;
			Run() ;
			//ANS() ;
			//Write(name) ; 
		} // Main()
		
		void Run(){
			int time = 0 ;
			int num = 0 ;
			vector<Data> q ;
			int ts = 0 ;
			int last = 0 ;
			//cout << "QUEUE RR----------------------------" << endl;
			while( num < buffer.size() || !q.empty() ){
				//р狥﹁queue 
				while( num < buffer.size() && time == buffer[num].arrival ){
					q.push_back(buffer[num]) ;
					num++ ;
				} // while
				
				//Τ传杠ts耴0 
				if( !q.empty() && last == q.front().id ) ; 
				else ts = 0 ;
				
				/*
				for( int i = 0 ; i < q.size() ; i++ ){
					cout <<	q[i].id << " " ;
				} // for
				cout << "-----------" << time << endl ;
				*/
				if( num < buffer.size() && q.empty() ){
					ans.push_back("-") ;
					
				} // if
				else{
					//秨﹍衡丁
					
					Data Running = q.front() ;
					//cout << Running.id << "-------------------" << Running.burst << endl;
					last = Running.id ;
					Running.burst = Running.burst - 1 ;
					q[0].burst = Running.burst ;
					string sid = InttoString(Running.id) ;
					ans.push_back(sid) ;
					//cout << Running.id << "-------------------" << Running.burst << endl;
					ts++ ;
					
					if( Running.burst == 0 ){
						//string sid = InttoString(Running.id) ;
						//ans.push_back(sid) ;
						
						for( int k = 0 ; k < buffer.size() ; k++ ){
							if( Running.id == buffer[k].id ){
								int now = time + 1 ; 
								buffer[k].turnaround = now - buffer[k].arrival ;
								buffer[k].waiting = buffer[k].turnaround - buffer[k].burst ;
							} // if
						}
						
						q.erase(q.begin()) ;
						ts = 0 ;
					} // if
					else if( ts == timeslice ){
						//string sid = InttoString(Running.id) ;
						//ans.push_back(sid) ;
						
						q.erase(q.begin()) ;
						int ttime = time+1 ;
						//cout << "PUSH BACK NUM-----------------" << num << endl;
						while( num < buffer.size() && ttime == buffer[num].arrival ){
							q.push_back(buffer[num]) ;
							num++ ;
						} // while
						
						q.push_back(Running) ;
						ts = 0 ;
					} // if
					
					
				} // else
				
				time++ ;
			} // while
			
		}
		
		void Display(){
			cout << "mode: " << mode << endl ;
			cout << "Timeslice: " << timeslice << endl ;
			cout << "ID     CPU Burst  Arrival Time   Priority" << endl ;
			for( int i = 0 ; i < buffer.size() ; i++ ){
				cout << buffer[i].id << " " << buffer[i].burst << " " << buffer[i].arrival << " " << buffer[i].priority << endl;
			}
		}
		
		void ANS(){
			for( int i = 0 ; i < ans.size() ; i++ ){
				cout << ans[i] ;
			} // for
			cout << endl;
		}
};

class SJF{
	//vector<Data> buffer ;
	int mode ;
	int timeslice ;
	//vector<string> ans ;
	public:
		vector<Data> buffer ;
		vector<string> ans ;
		
		bool Read( string name ){
			buffer.clear() ;
			fstream infile ;
			string file = name + ".txt" ;
			infile.open(file.c_str(), ios::in) ;
			if( !infile.is_open()){
				cout << "### " << file << " does not exist! ### " << endl << endl ;
            	return false ;
			} // if
			else{
				infile >> mode ;
				infile >> timeslice ;
				
				for( int i = 0 ; i < 6 ; i++ ){
					string temp ;
					infile >> temp ;
					//cout << temp << endl;
				} // for
				
				int id ;
				int num = 1 ;
				while( infile >> id ){
					Data temp ;
					
					temp.id = id ;
					infile >> temp.burst ;
					infile >> temp.arrival ;
					infile >> temp.priority ;
					//cout << num << " " << temp.id << " " << temp.burst << " " << temp.arrival << " " << temp.priority << endl;
					buffer.push_back(temp) ;
				} // while
				
			} // else
			
			infile.close() ;
			return true ;
		} // Read()
		
		void Write( string name ){
			fstream outfile ;
			string Ofile = "out_" + name + "_method3.txt" ;
			outfile.open(Ofile.c_str(), ios::out) ;
			
			outfile << "SJF\n" ;
			outfile << "==         SJF==\n" ;
			for( int i = 0 ; i < ans.size() ; i++ ){
				outfile << ans[i] ;
			} // for
			outfile << "\n" ;
			outfile << "===========================================================\n\n" ;
			outfile << "Waiting Time\nID	SJF\n" ;
			outfile << "===========================================================\n" ;
			
			int n = buffer.size() ;
			for( int pass = 1 ; pass < n ; ++pass ){
				for( int index = 0 ; index < n - pass ; index++ ){ 
					if( buffer[index].id > buffer[index+1].id )
						swap( index, index+1 );
						
				} // for
				
			} // for
			
			for( int i = 0 ; i < buffer.size() ; i++ ){
				outfile << buffer[i].id << "\t" << buffer[i].waiting << "\n" ;
			} // for
			outfile << "===========================================================\n\n" ;
			outfile << "Turnaround Time\n" ;
			outfile << "ID	SJF\n" ;
			outfile << "===========================================================\n" ;
			for( int i = 0 ; i < buffer.size() ; i++ ){
				outfile << buffer[i].id << "\t" << buffer[i].turnaround << "\n" ;
			} // for
			outfile << "===========================================================\n\n" ;
			outfile.close() ;
		} // Write()
		
		string InttoString( int num ){
			if( num == 0 ) return "0" ;
			else if( num == 1 ) return "1" ;
			else if( num == 2 ) return "2" ;
			else if( num == 3 ) return "3" ;
			else if( num == 4 ) return "4" ;
			else if( num == 5 ) return "5" ;
			else if( num == 6 ) return "6" ;
			else if( num == 7 ) return "7" ;
			else if( num == 8 ) return "8" ;
			else if( num == 9 ) return "9" ;
			else if( num == 10 ) return "A" ;
			else if( num == 11 ) return "B" ;
			else if( num == 12 ) return "C" ;
			else if( num == 13 ) return "D" ;
			else if( num == 14 ) return "E" ;
			else if( num == 15 ) return "F" ;
			else if( num == 16 ) return "G" ;
			else if( num == 17 ) return "H" ;
			else if( num == 18 ) return "I" ;
			else if( num == 19 ) return "J" ;
			else if( num == 20 ) return "K" ;
			else if( num == 21 ) return "L" ;
			else if( num == 22 ) return "M" ;
			else if( num == 23 ) return "N" ;
			else if( num == 24 ) return "O" ;
			else if( num == 25 ) return "P" ;
			else if( num == 26 ) return "Q" ;
			else if( num == 27 ) return "R" ;
			else if( num == 28 ) return "S" ;
			else if( num == 29 ) return "T" ;
			else if( num == 30 ) return "U" ;
			else if( num == 31 ) return "V" ;
			else if( num == 32 ) return "W" ;
			else if( num == 33 ) return "X" ;
			else if( num == 34 ) return "Y" ;
			else if( num == 35 ) return "Z" ;
			else return "\0" ;
		}
		
		void bubblesort(){
			int n = buffer.size() ;
			for( int pass = 1 ; pass < n ; ++pass ){ // –Ω常穦盢程程 
				for( int index = 0 ; index < n - pass ; index++ ){ //程ぃノ浪琩﹚琌程┮–Ω浪琩Ω计搭ぶ 
					if( buffer[index].arrival > buffer[index+1].arrival )
						swap( index, index+1 );
					else if( buffer[index].arrival == buffer[index+1].arrival ){
						if( buffer[index].id > buffer[index+1].id )
							swap( index, index+1 );
							
						if( buffer[index].burst > buffer[index+1].burst )
							swap( index, index+1 );
					} // else if 
						
				} // for
				
			} // for
			
			
		} // end of bubblesort
		
		void swap( int num1, int num2 ){
			Data temp ; 
			temp = buffer[num1] ;
			buffer[num1] = buffer[num2] ;
			buffer[num2] = temp ;
		} // end of swap
		
		void Main( string name ){
			//cout << "0--------------" << endl;
			Read(name) ;
			//cout << "1--------------" << endl;
			bubblesort() ;
			//cout << "2--------------" << endl;
			//Display() ;
			//cout << "3--------------" << endl;
			Run() ;
			//cout << "4--------------" << endl;
			//ANS() ;
			//cout << "5--------------" << endl;
			//Write(name) ; 
			//cout << "6--------------" << endl;
		} // Main()
		
		void Run(){
			int time = 0 ;
			int num = 0 ;
			//queue<Data> q ;
			vector<Data> q ;
			int ts = 0 ;
			while( num < buffer.size() || !q.empty() ){
				//р狥﹁queue 
				while( time == buffer[num].arrival ){
					q.push_back(buffer[num]) ;
					num++ ;
				} // while
				
				/*
				for( int i = 0 ; i < q.size() ; i++ ){
					cout <<	q[i].id << " " ;
				} // for
				cout << "-----------" << time << endl ;
				*/
				if( num < buffer.size() && q.empty() ){
					ans.push_back("-") ;
					
				} // if
				else{
					//秨﹍衡丁
					
					Data Running = q.front() ;
					//cout << Running.id << "-------------------" << Running.burst << endl;
					Running.burst = Running.burst - 1 ;
					q[0].burst = Running.burst ;
					string sid = InttoString(Running.id) ;
					ans.push_back(sid) ;
					//cout << Running.id << "-------------------" << Running.burst << endl;
					ts++ ;
					
					
					if( Running.burst == 0 ){
						//string sid = InttoString(Running.id) ;
						//ans.push_back(sid) ;
						
						int now = time + 1 ; 
						for( int k = 0 ; k < buffer.size() ; k++ ){
							if( Running.id == buffer[k].id ){
								
								buffer[k].turnaround = now - buffer[k].arrival ;
								buffer[k].waiting = buffer[k].turnaround - buffer[k].burst ;
							} // if
						}
						
						q.erase(q.begin()) ;
						
						while( now == buffer[num].arrival ){
							q.push_back(buffer[num]) ;
							num++ ;
						} // while
						
						int n = q.size() ;
						for( int pass = 1 ; pass < n ; ++pass ){ // –Ω常穦盢程程 
							for( int index = 0 ; index < n - pass ; index++ ){ //程ぃノ浪琩﹚琌程┮–Ω浪琩Ω计搭ぶ 
								if( q[index].burst > q[index+1].burst ){
									Data temp ; 
									temp = q[index] ;
									q[index] = q[index+1] ;
									q[index+1] = temp ;
								}
								
							} // for
							
						} // for
						
						ts = 0 ;
					} // if
					/*
					else if( ts == timeslice ){
						string sid = InttoString(Running.id) ;
						ans.push_back(sid) ;
						
						ts = 0 ;
					} // if
					*/
					
				} // else
				
				time++ ;
			} // while
			
		}
		
		void Display(){
			cout << "mode: " << mode << endl ;
			cout << "Timeslice: " << timeslice << endl ;
			cout << "ID     CPU Burst  Arrival Time   Priority" << endl ;
			for( int i = 0 ; i < buffer.size() ; i++ ){
				cout << buffer[i].id << " " << buffer[i].burst << " " << buffer[i].arrival << " " << buffer[i].priority << endl;
			}
		}
		
		void ANS(){
			for( int i = 0 ; i < ans.size() ; i++ ){
				cout << ans[i] ;
			} // for
			cout << endl;
		}
};

class SRTF{
	//vector<Data> buffer ;
	int mode ;
	int timeslice ;
	//vector<string> ans ;
	public:
		vector<Data> buffer ;
		vector<string> ans ;
		
		bool Read( string name ){
			buffer.clear() ;
			fstream infile ;
			string file = name + ".txt" ;
			infile.open(file.c_str(), ios::in) ;
			if( !infile.is_open()){
				cout << "### " << file << " does not exist! ### " << endl << endl ;
            	return false ;
			} // if
			else{
				infile >> mode ;
				infile >> timeslice ;
				
				for( int i = 0 ; i < 6 ; i++ ){
					string temp ;
					infile >> temp ;
					//cout << temp << endl;
				} // for
				
				int id ;
				int num = 1 ;
				while( infile >> id ){
					Data temp ;
					
					temp.id = id ;
					infile >> temp.burst ;
					infile >> temp.arrival ;
					infile >> temp.priority ;
					//cout << num << " " << temp.id << " " << temp.burst << " " << temp.arrival << " " << temp.priority << endl;
					buffer.push_back(temp) ;
				} // while
				
			} // else
			
			infile.close() ;
			return true ;
		} // Read()
		
		void Write( string name ){
			fstream outfile ;
			string Ofile = "out_" + name + "_method4.txt" ;
			outfile.open(Ofile.c_str(), ios::out) ;
			
			outfile << "SRTF\n" ;
			outfile << "==        SRTF==\n" ;
			for( int i = 0 ; i < ans.size() ; i++ ){
				outfile << ans[i] ;
			} // for
			outfile << "\n" ;
			outfile << "===========================================================\n\n" ;
			outfile << "Waiting Time\nID	SRTF\n" ;
			outfile << "===========================================================\n" ;
			
			int n = buffer.size() ;
			for( int pass = 1 ; pass < n ; ++pass ){
				for( int index = 0 ; index < n - pass ; index++ ){ 
					if( buffer[index].id > buffer[index+1].id )
						swap( index, index+1 );
						
				} // for
				
			} // for
			
			for( int i = 0 ; i < buffer.size() ; i++ ){
				outfile << buffer[i].id << "\t" << buffer[i].waiting << "\n" ;
			} // for
			outfile << "===========================================================\n\n" ;
			outfile << "Turnaround Time\n" ;
			outfile << "ID	SRTF\n" ;
			outfile << "===========================================================\n" ;
			for( int i = 0 ; i < buffer.size() ; i++ ){
				outfile << buffer[i].id << "\t" << buffer[i].turnaround << "\n" ;
			} // for
			outfile << "===========================================================\n\n" ;
			outfile.close() ;
		} // Write()
		
		string InttoString( int num ){
			if( num == 0 ) return "0" ;
			else if( num == 1 ) return "1" ;
			else if( num == 2 ) return "2" ;
			else if( num == 3 ) return "3" ;
			else if( num == 4 ) return "4" ;
			else if( num == 5 ) return "5" ;
			else if( num == 6 ) return "6" ;
			else if( num == 7 ) return "7" ;
			else if( num == 8 ) return "8" ;
			else if( num == 9 ) return "9" ;
			else if( num == 10 ) return "A" ;
			else if( num == 11 ) return "B" ;
			else if( num == 12 ) return "C" ;
			else if( num == 13 ) return "D" ;
			else if( num == 14 ) return "E" ;
			else if( num == 15 ) return "F" ;
			else if( num == 16 ) return "G" ;
			else if( num == 17 ) return "H" ;
			else if( num == 18 ) return "I" ;
			else if( num == 19 ) return "J" ;
			else if( num == 20 ) return "K" ;
			else if( num == 21 ) return "L" ;
			else if( num == 22 ) return "M" ;
			else if( num == 23 ) return "N" ;
			else if( num == 24 ) return "O" ;
			else if( num == 25 ) return "P" ;
			else if( num == 26 ) return "Q" ;
			else if( num == 27 ) return "R" ;
			else if( num == 28 ) return "S" ;
			else if( num == 29 ) return "T" ;
			else if( num == 30 ) return "U" ;
			else if( num == 31 ) return "V" ;
			else if( num == 32 ) return "W" ;
			else if( num == 33 ) return "X" ;
			else if( num == 34 ) return "Y" ;
			else if( num == 35 ) return "Z" ;
			else return "\0" ;
		}
		
		void bubblesort(){
			int n = buffer.size() ;
			for( int pass = 1 ; pass < n ; ++pass ){ // –Ω常穦盢程程 
				for( int index = 0 ; index < n - pass ; index++ ){ //程ぃノ浪琩﹚琌程┮–Ω浪琩Ω计搭ぶ 
					if( buffer[index].arrival > buffer[index+1].arrival )
						swap( index, index+1 );
					else if( buffer[index].arrival == buffer[index+1].arrival ){
						if( buffer[index].id > buffer[index+1].id )
							swap( index, index+1 );
							
						if( buffer[index].burst > buffer[index+1].burst )
							swap( index, index+1 );
							
					} // else if 
						
				} // for
				
			} // for
			
			
		} // end of bubblesort
		
		void swap( int num1, int num2 ){
			Data temp ; 
			temp = buffer[num1] ;
			buffer[num1] = buffer[num2] ;
			buffer[num2] = temp ;
		} // end of swap
		
		void Main( string name ){
			//cout << "0--------------" << endl;
			Read(name) ;
			//cout << "1--------------" << endl;
			bubblesort() ;
			//cout << "2--------------" << endl;
			//Display() ;
			//cout << "3--------------" << endl;
			Run() ;
			//cout << "4--------------" << endl;
			//ANS() ;
			//cout << "5--------------" << endl;
			//Write(name) ; 
			//cout << "6--------------" << endl;
		} // Main()
		
		void Run(){
			int time = 0 ;
			int num = 0 ;
			//queue<Data> q ;
			vector<Data> q ;
			int ts = 0 ;
			int last = 0 ;
			while( num < buffer.size() || !q.empty() ){
				//р狥﹁queue 
				while( time == buffer[num].arrival ){
					q.push_back(buffer[num]) ;
					num++ ;
				} // while
				
				int n = q.size() ;
				for( int pass = 1 ; pass < n ; ++pass ){ // –Ω常穦盢程程 
					for( int index = 0 ; index < n - pass ; index++ ){ //程ぃノ浪琩﹚琌程┮–Ω浪琩Ω计搭ぶ 
						if( q[index].burst > q[index+1].burst ){
							Data temp ; 
							temp = q[index] ;
							q[index] = q[index+1] ;
							q[index+1] = temp ;
						}
						
					} // for
					
				} // for
				
				if( !q.empty() && last == q.front().id ) ;
				else ts = 0 ;
				
				/*
				for( int i = 0 ; i < q.size() ; i++ ){
					cout <<	q[i].id << " " ;
				} // for
				cout << "-----------" << time << endl ;
				*/
				if( num < buffer.size() && q.empty() ){
					ans.push_back("-") ;
					
				} // if
				else{
					//秨﹍衡丁
					
					Data Running = q.front() ;
					//cout << Running.id << "-------------------" << Running.burst << endl;
					last = Running.id ;
					Running.burst = Running.burst - 1 ;
					q[0].burst = Running.burst ;
					string sid = InttoString(Running.id) ;
					ans.push_back(sid) ;
					//cout << Running.id << "-------------------" << Running.burst << endl;
					ts++ ;
					
					if( Running.burst == 0 ){
						//string sid = InttoString(Running.id) ;
						//ans.push_back(sid) ;
						
						int now = time + 1 ; 
						for( int k = 0 ; k < buffer.size() ; k++ ){
							if( Running.id == buffer[k].id ){
								
								buffer[k].turnaround = now - buffer[k].arrival ;
								buffer[k].waiting = buffer[k].turnaround - buffer[k].burst ;
							} // if
						}
						
						q.erase(q.begin()) ;
						/*
						while( now == buffer[num].arrival ){
							q.push_back(buffer[num]) ;
							num++ ;
						} // while
						
						int n = q.size() ;
						for( int pass = 1 ; pass < n ; ++pass ){ // –Ω常穦盢程程 
							for( int index = 0 ; index < n - pass ; index++ ){ //程ぃノ浪琩﹚琌程┮–Ω浪琩Ω计搭ぶ 
								if( q[index].burst > q[index+1].burst ){
									Data temp ; 
									temp = q[index] ;
									q[index] = q[index+1] ;
									q[index+1] = temp ;
								}
								
							} // for
							
						} // for
						*/
						ts = 0 ;
					} // if
					/*
					else if( ts == timeslice ){
						string sid = InttoString(Running.id) ;
						ans.push_back(sid) ;
						
						ts = 0 ;
					} // if
					*/
					
				} // else
				
				time++ ;
			} // while
			
		}
		
		void Display(){
			cout << "mode: " << mode << endl ;
			cout << "Timeslice: " << timeslice << endl ;
			cout << "ID     CPU Burst  Arrival Time   Priority" << endl ;
			for( int i = 0 ; i < buffer.size() ; i++ ){
				cout << buffer[i].id << " " << buffer[i].burst << " " << buffer[i].arrival << " " << buffer[i].priority << endl;
			}
		}
		
		void ANS(){
			for( int i = 0 ; i < ans.size() ; i++ ){
				cout << ans[i] ;
			} // for
			cout << endl;
		}
};

class HRRN{
	
	int mode ;
	int timeslice ;
	
	public:
		vector<Data> buffer ;
		vector<string> ans ;
		
		bool Read( string name ){
			buffer.clear() ;
			fstream infile ;
			string file = name + ".txt" ;
			infile.open(file.c_str(), ios::in) ;
			if( !infile.is_open()){
				cout << "### " << file << " does not exist! ### " << endl << endl ;
            	return false ;
			} // if
			else{
				infile >> mode ;
				infile >> timeslice ;
				
				for( int i = 0 ; i < 6 ; i++ ){
					string temp ;
					infile >> temp ;
					//cout << temp << endl;
				} // for
				
				int id ;
				int num = 1 ;
				while( infile >> id ){
					Data temp ;
					
					temp.id = id ;
					infile >> temp.burst ;
					infile >> temp.arrival ;
					infile >> temp.priority ;
					//cout << num << " " << temp.id << " " << temp.burst << " " << temp.arrival << " " << temp.priority << endl;
					buffer.push_back(temp) ;
				} // while
				
			} // else
			
			infile.close() ;
			return true ;
		} // Read()
		
		void Write( string name ){
			fstream outfile ;
			string Ofile = "out_" + name + "_method5.txt" ;
			outfile.open(Ofile.c_str(), ios::out) ;
			
			outfile << "HRRN\n" ;
			outfile << "==        HRRN==\n" ;
			for( int i = 0 ; i < ans.size() ; i++ ){
				outfile << ans[i] ;
			} // for
			outfile << "\n" ;
			outfile << "===========================================================\n\n" ;
			outfile << "Waiting Time\nID	HRRN\n" ;
			outfile << "===========================================================\n" ;
			
			int n = buffer.size() ;
			for( int pass = 1 ; pass < n ; ++pass ){
				for( int index = 0 ; index < n - pass ; index++ ){ 
					if( buffer[index].id > buffer[index+1].id )
						swap( index, index+1 );
						
				} // for
				
			} // for
			
			for( int i = 0 ; i < buffer.size() ; i++ ){
				outfile << buffer[i].id << "\t" << buffer[i].waiting << "\n" ;
			} // for
			outfile << "===========================================================\n\n" ;
			outfile << "Turnaround Time\n" ;
			outfile << "ID	HRRN\n" ;
			outfile << "===========================================================\n" ;
			for( int i = 0 ; i < buffer.size() ; i++ ){
				outfile << buffer[i].id << "\t" << buffer[i].turnaround << "\n" ;
			} // for
			outfile << "===========================================================\n\n" ;
			outfile.close() ;
		} // Write()
		
		string InttoString( int num ){
			if( num == 0 ) return "0" ;
			else if( num == 1 ) return "1" ;
			else if( num == 2 ) return "2" ;
			else if( num == 3 ) return "3" ;
			else if( num == 4 ) return "4" ;
			else if( num == 5 ) return "5" ;
			else if( num == 6 ) return "6" ;
			else if( num == 7 ) return "7" ;
			else if( num == 8 ) return "8" ;
			else if( num == 9 ) return "9" ;
			else if( num == 10 ) return "A" ;
			else if( num == 11 ) return "B" ;
			else if( num == 12 ) return "C" ;
			else if( num == 13 ) return "D" ;
			else if( num == 14 ) return "E" ;
			else if( num == 15 ) return "F" ;
			else if( num == 16 ) return "G" ;
			else if( num == 17 ) return "H" ;
			else if( num == 18 ) return "I" ;
			else if( num == 19 ) return "J" ;
			else if( num == 20 ) return "K" ;
			else if( num == 21 ) return "L" ;
			else if( num == 22 ) return "M" ;
			else if( num == 23 ) return "N" ;
			else if( num == 24 ) return "O" ;
			else if( num == 25 ) return "P" ;
			else if( num == 26 ) return "Q" ;
			else if( num == 27 ) return "R" ;
			else if( num == 28 ) return "S" ;
			else if( num == 29 ) return "T" ;
			else if( num == 30 ) return "U" ;
			else if( num == 31 ) return "V" ;
			else if( num == 32 ) return "W" ;
			else if( num == 33 ) return "X" ;
			else if( num == 34 ) return "Y" ;
			else if( num == 35 ) return "Z" ;
			else return "\0" ;
		}
		
		void bubblesort(){
			int n = buffer.size() ;
			for( int pass = 1 ; pass < n ; ++pass ){ // –Ω常穦盢程程 
				for( int index = 0 ; index < n - pass ; index++ ){ //程ぃノ浪琩﹚琌程┮–Ω浪琩Ω计搭ぶ 
					if( buffer[index].arrival > buffer[index+1].arrival )
						swap( index, index+1 );
					else if( buffer[index].arrival == buffer[index+1].arrival ){
						if( buffer[index].id > buffer[index+1].id )
							swap( index, index+1 );
							
					} // else if 
						
				} // for
				
			} // for
			
			
		} // end of bubblesort
		
		void swap( int num1, int num2 ){
			Data temp ; 
			temp = buffer[num1] ;
			buffer[num1] = buffer[num2] ;
			buffer[num2] = temp ;
		} // end of swap
		
		void Main( string name ){
			//cout << "0--------------" << endl;
			Read(name) ;
			//cout << "1--------------" << endl;
			bubblesort() ;
			//cout << "2--------------" << endl;
			//Display() ;
			//cout << "3--------------" << endl;
			Run() ;
			//cout << "4--------------" << endl;
			//ANS() ;
			//cout << "5--------------" << endl;
			//Write(name) ; 
			//cout << "6--------------" << endl;
		} // Main()
		
		void Run(){
			int time = 0 ;
			int num = 0 ;
			//queue<Data> q ;
			vector<Data> q ;
			int ts = 0 ;
			while( num < buffer.size() || !q.empty() ){
				//р狥﹁queue 
				while( time == buffer[num].arrival ){
					q.push_back(buffer[num]) ;
					num++ ;
				} // while
				
				/*
				for( int i = 0 ; i < q.size() ; i++ ){
					cout <<	q[i].id << " " ;
				} // for
				cout << "-----------" << time << endl ;
				*/
				if( num < buffer.size() && q.empty() ){
					ans.push_back("-") ;
					
				} // if
				else{
					//秨﹍衡丁
					
					Data Running = q.front() ;
					//cout << Running.id << "-------------------" << Running.burst << endl;
					Running.burst = Running.burst - 1 ;
					q[0].burst = Running.burst ;
					string sid = InttoString(Running.id) ;
					ans.push_back(sid) ;
					//cout << Running.id << "-------------------" << Running.burst << endl;
					ts++ ;
					
					if( Running.burst == 0 ){
						//string sid = InttoString(Running.id) ;
						//ans.push_back(sid) ;
						
						int now = time + 1 ; 
						for( int k = 0 ; k < buffer.size() ; k++ ){
							if( Running.id == buffer[k].id ){
								
								buffer[k].turnaround = now - buffer[k].arrival ;
								buffer[k].waiting = buffer[k].turnaround - buffer[k].burst ;
							} // if
						}
						
						q.erase(q.begin()) ;
						
						while( now == buffer[num].arrival ){
							q.push_back(buffer[num]) ;
							num++ ;
						} // while
						
						for( int i = 0 ; i < q.size() ; i++ ){
							int wait = now - q[i].arrival ;
							double rt = (double)(wait+q[i].burst)/q[i].burst ;
							q[i].response = rt ;
							
						}
						
						int n = q.size() ;
						for( int pass = 1 ; pass < n ; ++pass ){ // –Ω常穦盢程程 
							for( int index = 0 ; index < n - pass ; index++ ){ //程ぃノ浪琩﹚琌程┮–Ω浪琩Ω计搭ぶ 
								if( q[index].response < q[index+1].response ){
									Data temp ; 
									temp = q[index] ;
									q[index] = q[index+1] ;
									q[index+1] = temp ;
								}
								
							} // for
							
						} // for
						/*
						cout << "RESPONSE TIME----------------------" << now << endl;
						for( int i = 0 ; i < q.size() ; i++ ){
							cout << q[i].id << " " << q[i].response << endl;
						}
						*/
						ts = 0 ;
					} // if
					/*
					else if( ts == timeslice ){
						string sid = InttoString(Running.id) ;
						ans.push_back(sid) ;
						
						ts = 0 ;
					} // if
					*/
					
				} // else
				
				time++ ;
			} // while
			
		}
		
		void Display(){
			cout << "mode: " << mode << endl ;
			cout << "Timeslice: " << timeslice << endl ;
			cout << "ID     CPU Burst  Arrival Time   Priority" << endl ;
			for( int i = 0 ; i < buffer.size() ; i++ ){
				cout << buffer[i].id << " " << buffer[i].burst << " " << buffer[i].arrival << " " << buffer[i].priority << endl;
			}
		}
		
		void ANS(){
			for( int i = 0 ; i < ans.size() ; i++ ){
				cout << ans[i] ;
			} // for
			cout << endl;
		}
};

class PPRR{
	
	int mode ;
	int timeslice ;
	
	public:
		vector<Data> buffer ;
		vector<string> ans ;
		
		bool Read( string name ){
			buffer.clear() ;
			fstream infile ;
			string file =  name + ".txt" ;
			infile.open(file.c_str(), ios::in) ;
			if( !infile.is_open()){
				cout << "### " << file << " does not exist! ### " << endl << endl ;
            	return false ;
			} // if
			else{
				infile >> mode ;
				infile >> timeslice ;
				
				for( int i = 0 ; i < 6 ; i++ ){
					string temp ;
					infile >> temp ;
					//cout << temp << endl;
				} // for
				
				int id ;
				int num = 1 ;
				while( infile >> id ){
					Data temp ;
					
					temp.id = id ;
					infile >> temp.burst ;
					infile >> temp.arrival ;
					infile >> temp.priority ;
					//cout << num << " " << temp.id << " " << temp.burst << " " << temp.arrival << " " << temp.priority << endl;
					buffer.push_back(temp) ;
				} // while
				
			} // else
			
			infile.close() ;
			return true ;
		} // Read()
		
		void Write( string name ){
			fstream outfile ;
			string Ofile = "out_" + name + "_method6.txt" ;
			outfile.open(Ofile.c_str(), ios::out) ;
			
			outfile << "Priority RR\n" ;
			outfile << "==        PPRR==\n" ;
			for( int i = 0 ; i < ans.size() ; i++ ){
				outfile << ans[i] ;
			} // for
			outfile << "\n" ;
			outfile << "===========================================================\n\n" ;
			outfile << "Waiting Time\nID	PPRR\n" ;
			outfile << "===========================================================\n" ;
			
			int n = buffer.size() ;
			for( int pass = 1 ; pass < n ; ++pass ){
				for( int index = 0 ; index < n - pass ; index++ ){ 
					if( buffer[index].id > buffer[index+1].id )
						swap( index, index+1 );
						
				} // for
				
			} // for
			
			for( int i = 0 ; i < buffer.size() ; i++ ){
				outfile << buffer[i].id << "\t" << buffer[i].waiting << "\n" ;
			} // for
			outfile << "===========================================================\n\n" ;
			outfile << "Turnaround Time\n" ;
			outfile << "ID	PPRR\n" ;
			outfile << "===========================================================\n" ;
			for( int i = 0 ; i < buffer.size() ; i++ ){
				outfile << buffer[i].id << "\t" << buffer[i].turnaround << "\n" ;
			} // for
			outfile << "===========================================================\n\n" ;
			outfile.close() ;
		} // Write()
		
		string InttoString( int num ){
			if( num == 0 ) return "0" ;
			else if( num == 1 ) return "1" ;
			else if( num == 2 ) return "2" ;
			else if( num == 3 ) return "3" ;
			else if( num == 4 ) return "4" ;
			else if( num == 5 ) return "5" ;
			else if( num == 6 ) return "6" ;
			else if( num == 7 ) return "7" ;
			else if( num == 8 ) return "8" ;
			else if( num == 9 ) return "9" ;
			else if( num == 10 ) return "A" ;
			else if( num == 11 ) return "B" ;
			else if( num == 12 ) return "C" ;
			else if( num == 13 ) return "D" ;
			else if( num == 14 ) return "E" ;
			else if( num == 15 ) return "F" ;
			else if( num == 16 ) return "G" ;
			else if( num == 17 ) return "H" ;
			else if( num == 18 ) return "I" ;
			else if( num == 19 ) return "J" ;
			else if( num == 20 ) return "K" ;
			else if( num == 21 ) return "L" ;
			else if( num == 22 ) return "M" ;
			else if( num == 23 ) return "N" ;
			else if( num == 24 ) return "O" ;
			else if( num == 25 ) return "P" ;
			else if( num == 26 ) return "Q" ;
			else if( num == 27 ) return "R" ;
			else if( num == 28 ) return "S" ;
			else if( num == 29 ) return "T" ;
			else if( num == 30 ) return "U" ;
			else if( num == 31 ) return "V" ;
			else if( num == 32 ) return "W" ;
			else if( num == 33 ) return "X" ;
			else if( num == 34 ) return "Y" ;
			else if( num == 35 ) return "Z" ;
		}
		
		void bubblesort(){
			int n = buffer.size() ;
			for( int pass = 1 ; pass < n ; ++pass ){ // –Ω常穦盢程程 
				for( int index = 0 ; index < n - pass ; index++ ){ //程ぃノ浪琩﹚琌程┮–Ω浪琩Ω计搭ぶ 
					if( buffer[index].arrival > buffer[index+1].arrival )
						swap( index, index+1 );
					else if( buffer[index].arrival == buffer[index+1].arrival ){
						/*
						if( buffer[index].id > buffer[index+1].id )
							swap( index, index+1 );
						*/
						if( buffer[index].priority > buffer[index+1].priority ){
							swap( index, index+1 ) ;
						} // if
					} // else if 
						
				} // for
				
			} // for
			
			
		} // end of bubblesort
		
		void swap( int num1, int num2 ){
			Data temp ; 
			temp = buffer[num1] ;
			buffer[num1] = buffer[num2] ;
			buffer[num2] = temp ;
		} // end of swap
		
		void Main( string name ){
			//cout << "0--------------" << endl;
			Read(name) ;
			//cout << "1--------------" << endl;
			bubblesort() ;
			//cout << "2--------------" << endl;
			//Display() ;
			//cout << "3--------------" << endl;
			Run() ;
			//cout << "4--------------" << endl;
			//ANS() ;
			//cout << "5--------------" << endl;
			//Write(name) ; 
			//cout << "6--------------" << endl;
		} // Main()
		
		void Run(){
			int time = 0 ;
			int num = 0 ;
			//queue<Data> q ;
			vector<Data> q ;
			int ts = 0 ;
			int last = 0 ;
			while( num < buffer.size() || !q.empty() ){
				//р狥﹁queue 
				while( time == buffer[num].arrival ){
					q.push_back(buffer[num]) ;
					num++ ;
				} // while
				
				int n = q.size() ;
				for( int pass = 1 ; pass < n ; ++pass ){ // –Ω常穦盢程程 
					for( int index = 0 ; index < n - pass ; index++ ){ //程ぃノ浪琩﹚琌程┮–Ω浪琩Ω计搭ぶ 
						if( q[index].priority > q[index+1].priority ){
							Data temp ; 
							temp = q[index] ;
							q[index] = q[index+1] ;
							q[index+1] = temp ;
						} // if
						/*
						else if( q[index].priority == q[index+1].priority ){
							if( q[index].id > q[index+1].id ){
								Data temp ; 
								temp = q[index] ;
								q[index] = q[index+1] ;
								q[index+1] = temp ;
							} // if
						}
						*/
					} // for
					
				} // for
				
				if( !q.empty() && last == q.front().id ) ;
				else{
					for( int k = 0 ; k < q.size() ; k++ ){
						if( q[k].id == last ){
							q.push_back(q[k]) ;
							q.erase(q.begin()+k) ;
						} // if 
					} // for
					ts = 0 ;	
				} // else
				/*
				for( int i = 0 ; i < q.size() ; i++ ){
					cout <<	q[i].id << " " ;
				} // for
				cout << "-----------" << time << " " << ts << " " << last << endl ;
				*/
				if( num < buffer.size() && q.empty() ){
					ans.push_back("-") ;
					
				} // if
				else{
					//秨﹍衡丁
					
					Data Running = q.front() ;
					//cout << Running.id << "-------------------" << Running.burst << endl;
					last = Running.id ;
					Running.burst = Running.burst - 1 ;
					q[0].burst = Running.burst ;
					string sid = InttoString(Running.id) ;
					ans.push_back(sid) ;
					//cout << Running.id << "-------------------" << Running.burst << endl;
					ts++ ;
					
					if( Running.burst == 0 ){
						//string sid = InttoString(Running.id) ;
						//ans.push_back(sid) ;
						
						for( int k = 0 ; k < buffer.size() ; k++ ){
							if( Running.id == buffer[k].id ){
								int now = time + 1 ; 
								buffer[k].turnaround = now - buffer[k].arrival ;
								buffer[k].waiting = buffer[k].turnaround - buffer[k].burst ;
							} // if
						}
						
						q.erase(q.begin()) ;
						ts = 0 ;
					} // if
					else if( ts == timeslice ){
						//string sid = InttoString(Running.id) ;
						//ans.push_back(sid) ;
						
						q.erase(q.begin()) ;
						int now = time+1 ;
						while( now == buffer[num].arrival ){
							q.push_back(buffer[num]) ;
							num++ ;
						} // while
						
						q.push_back(Running) ;
						ts = 0 ;
					} // if
					
					
				} // else
				
				time++ ;
			} // while
			
		}
		
		void Display(){
			cout << "mode: " << mode << endl ;
			cout << "Timeslice: " << timeslice << endl ;
			cout << "ID     CPU Burst  Arrival Time   Priority" << endl ;
			for( int i = 0 ; i < buffer.size() ; i++ ){
				cout << buffer[i].id << " " << buffer[i].burst << " " << buffer[i].arrival << " " << buffer[i].priority << endl;
			}
		}
		
		void ANS(){
			for( int i = 0 ; i < ans.size() ; i++ ){
				cout << ans[i] ;
			} // for
			cout << endl;
		}
};

class ALL{
	RR rr ;
	FCFS f ;
	SJF s ;
	SRTF sr ;
	HRRN hr ;
	PPRR p ;
	string name ;
	int mode, timeslice ;
	vector<Data> buffer ;
	public:
		bool Read( string name ){
			buffer.clear() ;
			fstream infile ;
			string file = name + ".txt" ;
			infile.open(file.c_str(), ios::in) ;
			if( !infile.is_open()){
				cout << "### " << file << " does not exist! ### " << endl << endl ;
            	return false ;
			} // if
			else{
				infile >> mode ;
				infile >> timeslice ;
				
				for( int i = 0 ; i < 6 ; i++ ){
					string temp ;
					infile >> temp ;
					//cout << temp << endl;
				} // for
				
				int id ;
				int num = 1 ;
				while( infile >> id ){
					Data temp ;
					
					temp.id = id ;
					infile >> temp.burst ;
					infile >> temp.arrival ;
					infile >> temp.priority ;
					//cout << num << " " << temp.id << " " << temp.burst << " " << temp.arrival << " " << temp.priority << endl;
					buffer.push_back(temp) ;
				} // while
				
			} // else
			
			infile.close() ;
			return true ;
		} // Read()
		
		void Run(){
			cout << "Please Enter File Name: " ;
			cin >> name ;
			Read(name) ;
			
			if( mode == 1 ){
				f.Main(name) ;
				f.Write(name) ;
			} // if
			else if( mode == 2 ){
				rr.Main(name) ;
				rr.Write(name) ;
			} // else if
			else if( mode == 3 ){
				s.Main(name) ;
				s.Write(name) ;
			} // else if
			else if( mode == 4 ){
				sr.Main(name) ;
				sr.Write(name) ;
			} // else if
			else if( mode == 5 ){
				hr.Main(name) ;
				hr.Write(name) ;
			} // else if
			else if( mode == 6 ){
				p.Main(name) ;
				p.Write(name) ;
			} // else if
			else if( mode == 7 ){
				f.Main(name) ;
				cout << "END FCFS------------------" << endl;
				rr.Main(name) ;
				cout << "END RR------------------" << endl;
				s.Main(name) ;
				cout << "END SJF------------------" << endl;
				sr.Main(name) ;
				cout << "END SRTF------------------" << endl;
				hr.Main(name) ;
				cout << "END HRRN------------------" << endl;
				p.Main(name) ;
				cout << "END PPRR------------------" << endl;
				Write(name) ;
			} // else if
			
		} // Run
		
		void Write( string name ){
			fstream outfile ;
			string Ofile = "out_" + name + ".txt" ;
			outfile.open(Ofile.c_str(), ios::out) ;
			
			outfile << "All\n" ;
			
			outfile << "==        FCFS==\n" ;
			for( int i = 0 ; i < f.ans.size() ; i++ ){
				outfile << f.ans[i] ;
			} // for
			outfile << "\n" ;
			
			outfile << "==          RR==\n" ;
			for( int i = 0 ; i < rr.ans.size() ; i++ ){
				outfile << rr.ans[i] ;
			} // for
			outfile << "\n" ;
			
			outfile << "==         SJF==\n" ;
			for( int i = 0 ; i < s.ans.size() ; i++ ){
				outfile << s.ans[i] ;
			} // for
			outfile << "\n" ;
			
			outfile << "==        SRTF==\n" ;
			for( int i = 0 ; i < sr.ans.size() ; i++ ){
				outfile << sr.ans[i] ;
			} // for
			outfile << "\n" ;
			
			outfile << "==        HRRN==\n" ;
			for( int i = 0 ; i < hr.ans.size() ; i++ ){
				outfile << hr.ans[i] ;
			} // for
			outfile << "\n" ;
			
			outfile << "==        PPRR==\n" ;
			for( int i = 0 ; i < p.ans.size() ; i++ ){
				outfile << p.ans[i] ;
			} // for
			outfile << "\n" ;
			
			outfile << "===========================================================\n\n" ;
			outfile << "Waiting Time\nID\tFCFS\tRR\tSJF\tSRTF\tHRRN\tPPRR\n" ;
			outfile << "===========================================================\n" ;
			
			LineUp( f.buffer ) ;
			LineUp( rr.buffer ) ;
			LineUp( s.buffer ) ;
			LineUp( sr.buffer ) ;
			LineUp( hr.buffer ) ;
			LineUp( p.buffer ) ;
			
			for( int i = 0 ; i < f.buffer.size() ; i++ ){
				outfile << f.buffer[i].id << "\t" << f.buffer[i].waiting << "\t" 
				<< rr.buffer[i].waiting << "\t" << s.buffer[i].waiting << "\t"
				<< sr.buffer[i].waiting << "\t" << hr.buffer[i].waiting << "\t"
				<< p.buffer[i].waiting << "\n";
			} // for
			
			outfile << "===========================================================\n\n" ;
			outfile << "Turnaround Time\n" ;
			outfile << "ID\tFCFS\tRR\tSJF\tSRTF\tHRRN\tPPRR\n" ;
			outfile << "===========================================================\n" ;
			
			for( int i = 0 ; i < f.buffer.size() ; i++ ){
				outfile << f.buffer[i].id << "\t" << f.buffer[i].turnaround << "\t" 
				<< rr.buffer[i].turnaround << "\t" << s.buffer[i].turnaround << "\t"
				<< sr.buffer[i].turnaround << "\t" << hr.buffer[i].turnaround << "\t"
				<< p.buffer[i].turnaround << "\n";
			} // for
			
			outfile << "===========================================================\n\n" ;
			outfile.close() ;
		} // Write()
		
		void LineUp( vector<Data> &temp ){
			int n = temp.size() ;
			for( int pass = 1 ; pass < n ; ++pass ){
				for( int index = 0 ; index < n - pass ; index++ ){ 
					if( temp[index].id > temp[index+1].id ){
						Data tmp ; 
						tmp = temp[index] ;
						temp[index] = temp[index+1] ;
						temp[index+1] = tmp ;
					} // if 
						
				} // for
				
			} // for
			
		}
		
};

int main(){
	ALL a ;
	a.Run() ;
}
