#include "runway_simulation.h"
#include <assert.h>
#include <cstdlib>

using namespace std;

runway::runway(int takeoff, int landing, float takeoff_rate, float landing_rate){
	landing_arrival_rate = landing_rate;
	takeoff_arrival_rate = takeoff_rate;
	land_time = landing;
	takeoff_time = takeoff;
	takeoff_counter = 0;
	landing_counter = 0;
	sum_for_landing = 0;
	sum_for_takeoff = 0;
	land_time_left = 0;
	takeoff_time_left = 0;
}
bool runway::is_airplane_comming_for_landing(){
	return (float)rand()/RAND_MAX < landing_arrival_rate;
}
bool runway::is_airplane_comming_for_takeoff(){
	return (float)rand()/RAND_MAX < takeoff_arrival_rate;
}
bool runway::is_landing(){
	return land_time_left > 0;
}
bool runway::is_takeoff(){
	return takeoff_time_left > 0;
}
void runway::one_time_unit(){
	if(is_landing()){
		land_time_left--;
	}
	if(is_takeoff()){
		takeoff_time_left--;
	}
}
void runway::start_landing(){
	assert(!is_runway_busy());
	land_time_left = land_time;
	cout<<"Landing...\n";
}
void runway::start_takeoff(){
	assert(!is_runway_busy());
	takeoff_time_left = takeoff_time;
	cout<<"Taking Off...\n";
}
bool runway::is_runway_busy(){
	if(land_time_left > 0 || takeoff_time_left > 0){
		return true;
	}else{
		return false;
	}
}
void runway::sum_landing_time(int value){
	landing_counter++;
	sum_for_landing += value;
}
void runway::sum_takeoff_time(int value){
		takeoff_counter++;
		sum_for_takeoff += value;
}
float runway::average_wait_time_for_landing(){
	if(landing_counter > 0){
		return(sum_for_landing / landing_counter);
	}
}
float runway::average_wait_time_for_takeoff(){
	if(takeoff_counter > 0){
		return (sum_for_takeoff / takeoff_counter);
	}
}
int runway::airplane_landed(){
	return landing_counter;
}
int runway::airplane_takeoff(){
	return takeoff_counter;
}
