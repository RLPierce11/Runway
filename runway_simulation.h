#ifndef RUN_WAY_H_
#define RUN_WAY_H_
#include <iostream>

class runway{
	public:
		runway(int, int, float, float); //constructor
		bool is_airplane_comming_for_landing(); //tells if airplane is coming in for a landing 
		bool is_airplane_comming_for_takeoff(); //tells if an airplane is comming to takeoff
		bool is_landing(); //tells if airplane is being landed
		bool is_takeoff(); //tells if airplane is being took off
		void one_time_unit();
		bool is_runway_busy(); //tells if the runway is being used
		void start_takeoff(); //tells program to start simulation of plane to takeoff
		void start_landing(); //tells program to start simulation of plane to land
		void sum_landing_time(int); //total for landing
		void sum_takeoff_time(int); //total for takeoff
		int airplane_landed(); //tells that plane finished landing
		int airplane_takeoff(); //tells that plane finished takeoff
		float average_wait_time_for_landing(); //average amount of time it took for landing
		float average_wait_time_for_takeoff(); //average amunt of time it took for takeoff

	private:
		float landing_arrival_rate; // how often to come
		float takeoff_arrival_rate; // how often to come
		int sum_for_landing; // store total time for landing
		int sum_for_takeoff; // store total time for takeoff
		int land_time; // store time used for landing
		int takeoff_time; // store time used for takeoff
		int land_time_left; // store time left for landing
		int takeoff_time_left; // store time left for takeoff
		int takeoff_counter; // store number of planes that took off
		int landing_counter; // store number of planes that landed

};
#include "runway_simulation.cpp"
#endif
