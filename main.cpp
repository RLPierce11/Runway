#include <time.h>
#include "runway_simulation.h"
#include <queue>
#include <stdlib.h>

using namespace std;

int main(){
	queue <int> landing, takeoff;
	int cur, next,land_time, takeoff_time, s_len;
	float land_rate, takeoff_rate;
	char answer;

	do{ // starts first loop for simulation
		cout<<"\nEnter simulation length: "; //Question and input for the simulation length 
		cin>>s_len; 
		cout<<"\nEnter Landing Arrival Rate: "; //Question and input for landing arrival rate
		cin>>land_rate;
		cout<<"\nEnter Takeoff Arrival Rate: "; //Question and input for takeoff arrival rate
		cin>>takeoff_rate;
		cout<<"\nEnter Landing Time for Airplane: "; //Question and input for landing time
		cin>>land_time;
		cout<< "\nEnter Takeoff Time for Airplane: "; //Question and input for takeoff time
		cin>> takeoff_time;

		runway mine_landing(land_time, takeoff_time, land_rate, takeoff_rate); //runway used for landing
		runway mine_takeoff(land_time, takeoff_time, land_rate, takeoff_rate); //runway used for takeoff

		srand(time(NULL));

		for(cur = 1; cur < s_len; cur++){
			if(mine_landing.is_airplane_comming_for_landing()){ //if statement used to tell if airplane coming then put on landing queue
				cout<<"\nAn Airplane is comming for landing...\n";
				landing.push(cur);
			}
			if(mine_takeoff.is_airplane_comming_for_takeoff()){ //if statement used to tell if airplane coming then put on takeoff queue
				cout<<"\nAn Airplane is comming for taking off...\n";
				takeoff.push(cur);
			}
			if(!mine_landing.is_runway_busy() && !landing.empty()){ //if landing queue is not empty and landing runway isnt busy then start landing
				next = landing.front();
				cout<<endl<<cur<<" "<<next<<endl;
				landing.pop();
				mine_landing.sum_landing_time(cur-next);
				mine_landing.start_landing();
			}
			if(!mine_takeoff.is_runway_busy() && !takeoff.empty()){ //if takeoff queue is not empty and takeoff runway isnt busy then start takeoff
				next = takeoff.front();
				cout<<endl<<cur<<" "<<next<<endl;
				takeoff.pop();
				mine_takeoff.sum_takeoff_time(cur-next);
				mine_takeoff.start_takeoff();
			}
			
			mine_landing.one_time_unit();
			mine_takeoff.one_time_unit();
		}
		cout<<"\nAirplanes were tookoff: "<<mine_takeoff.airplane_takeoff()<<endl;
		cout<<"\nAirplanes were Landed: "<<mine_landing.airplane_landed()<<endl;
		cout<<"\nAverage waiting for landing: "<<mine_landing.average_wait_time_for_landing()<<endl;
		cout<<"\nAverage waiting for taking off: "<<mine_takeoff.average_wait_time_for_takeoff()<<endl;
		cout<<"\nUnlanded airplanes: "<<endl;
		int cnt_landing = 0;
		while(!landing.empty()){
			cout<<landing.front()<<" ";
			cnt_landing++;
			landing.pop();
		}
		cout<<cnt_landing<<" airplanes were denied for landing"<<endl;
		int cnt_takeoff = 0;
		while(!takeoff.empty()){
			cout<<takeoff.front()<<" ";
			cnt_takeoff++;
			takeoff.pop();
		}
		cout<<endl<<cnt_takeoff<< " airplanes were denied for takeoff"<<endl;

		cout<<"\nDo it again y for yes: "; //statement that if y then starts back simultion
		cin>>answer;
		cout<<endl<<endl;
	}while(answer == 'y');
}
