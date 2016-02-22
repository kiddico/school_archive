/*
	Nicholas Chirico
	Operating System Concepts
	11/2/15
*/
//WARNING: I use a smaller tab size than normal (it just looks so ugly!), so some things may not look quite right
//also this is waaaaaaay longer than it needs to be
#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <cmath>
//an overly complicated vector that stores whos where and when and whatnot.
std::vector<std::vector<std::string>> traffic;

//used to debug faster
bool debugging = false;

//Global Variables Used to keep things in order.
/*-------------------------------------------------------------------------------------------------------*/
std::mutex mtx; //used to protect the road, various variables, my butt, and the nation's freedom
std::condition_variable_any ped , east , west; //0
//various trackers for predefined rules
int ped_wait = 0;//amount of cards ped has waited on.
int west_wait = 0;//amount of east cars they've waited on
int east_wait = 0;//amount of west cars they've waited on
//used to tell when things are happening
int peds_crossing = 0;
int east_crossing = 0;
int west_crossing = 0;
//not sure if this will solve my problem or not.
int peds_waiting = 0;
int wests_waiting = 0;
int easts_waiting = 0;

int prevtime = 0;
/*
	sleep(prevtime+=(i1.back()-'0'));
	prevtime+=travel_time;
*/


//Various functions used in threads
/*-------------------------------------------------------------------------------------------------------*/
//sleep func I stole from the readers/writers example. I made it one line cause why not.
void sleep(int secs){std::this_thread::sleep_for(std::chrono::milliseconds(secs * 1000));}

//gets previous cars speed if it was going in the same dirrection. If there was no previous car returns 0...
//well IDK how that could happen... there's a check in the way.
//ghost car?
int speedOfLast(std::string now){
	if(now.back() == '1')
		return 0;
	else{
		//cycle through traffic vector and look to see any are the same type and came directly before them.
		for(int i = 0 ; i < traffic.size() ; i ++){
			int selected_speed = std::stoi(traffic[i][2]);
			//pretend the next line is less atrocious than it actually is
			//pretty straightforward though. 
			//			V checks if it's before now				V Checks if they're the same type
			if( (traffic[i][1].back() < now.back() ) && ( traffic[i][1].front() == now.front()) )
				return selected_speed;
		}
		return 0;
	}
}

//turns 2 ints into doubles, divides them, rounds to the nearest int 
int divideCeilInt(int first, int second){
	double f = first;
	double s = second;
	int temp = std::ceil(f/s);
	return temp;
}

//Thread Functions
/*-------------------------------------------------------------------------------------------------------*/
//Params go since last, name, speed
void pedestrian (std::string i1, std::string i2, std::string i3) {
	//if(i2.back()!='1')
	//	sleep(prevtime+=(i1.back()-'0'));
	bool already_updated = false;
	int new_speed = std::stoi(i3);
	int travel_time = 10 / new_speed;
	mtx.lock();
	//only need to check if there are cars.
	//cars are programmed to yield
	while( (east_crossing) || (west_crossing) ){
		if(!already_updated)
			peds_waiting++;
		ped.wait(mtx);
	}
	/*entering uber crit zone*/
	bool prev_crossing = peds_crossing;
	if(prev_crossing > 0){
		if(speedOfLast(i2)!=0)
			new_speed = speedOfLast(i2);
		travel_time = divideCeilInt(100 , new_speed);
	}
	//bool prev crossing
	peds_crossing++;
	std::cout<<i2<<" entering contruction"<<std::endl;
	ped_wait = 0;
	mtx.unlock();
	/*EXITING UBER CRIT ZONE*/
	if(!debugging)
		sleep(travel_time);
	//prevtime+=travel_time;
	
	mtx.lock();
	/*ENTERING UBER CRIT ZONE*/
	std::cout<<i2<<" Exiting construction"<<std::endl;
	peds_crossing--;
	west.notify_one();
	east.notify_one();
	mtx.unlock();
}


//so really pedestrians don't yeild to cars, but cars yield to impatient 
void carWest(std::string i1, std::string i2, std::string i3){
	//if(i2.back()!='1')
	//	sleep(prevtime+=(i1.back()-'0'));
	int new_speed = std::stoi(i3);
	int travel_time = 100 / new_speed;
	mtx.lock();
	while(peds_crossing || east_crossing || (east_wait > 1) || ( ped_wait > 1) ){
		//yield to any angry peds
		if(ped_wait > 1)
			ped.notify_all();
		if( (east_wait > 2) && (!ped_wait > 1))
			east.notify_one();
		west.wait(mtx);
	}
	/*ENTERING UBER CRIT ZONE*/
	bool prev_crossing = west_crossing;
	if(prev_crossing > 0){
		if(speedOfLast(i2)!=0)
			new_speed = speedOfLast(i2);
		travel_time = divideCeilInt(100 , new_speed);
	}

	travel_time = divideCeilInt(100 , new_speed);
	west_crossing++;
	//increase the amount of times peds have waited. 
	if(peds_waiting > 0)
		ped_wait++;
	std::cout<<i2<<" entering contruction"<<std::endl;
	mtx.unlock();
	/*EXITING UBER CRIT ZONE*/
	if(!debugging)
		sleep(travel_time);
	//prevtime+=travel_time;

	mtx.lock();
	/*ENTERING UBER CRIT ZONE*/
	std::cout<<i2<<" exiting contruction"<<std::endl;
	west_crossing--;
	/*EXITING UBER CRIT ZONE*/
	//let some people do thier thing
	if(ped_wait > 1)
		ped.notify_all();
	west.notify_one();
	if(!wests_waiting > 0)
		ped.notify_all();
	mtx.unlock();
}

void carEast(std::string i1, std::string i2, std::string i3){
	//if(i2.back()!='1')
	//	sleep(prevtime+=(i1.back()-'0'));
	int new_speed = std::stoi(i3);
	int travel_time = 100 / new_speed;
	mtx.lock();
	while(peds_crossing || west_crossing || (west_wait > 1) || ( ped_wait > 1) ){
		//yield to any angry peds
		if(ped_wait > 1)
			ped.notify_all();
		if( (west_wait > 2) && (!ped_wait > 1))
			west.notify_one();
		east.wait(mtx);
	}
	/*ENTERING UBER CRIT ZONE*/
	bool prev_crossing = east_crossing;
	if(prev_crossing > 0){
		if(speedOfLast(i2)!=0)
			new_speed = speedOfLast(i2);
		travel_time = divideCeilInt(100 , new_speed);
	}

	travel_time = divideCeilInt(100 , new_speed);
	east_crossing++;
	//increase the amount of times peds have waited. 
	if(peds_waiting > 0)
		ped_wait++;
	std::cout<<i2<<" entering contruction"<<std::endl;
	mtx.unlock();
	/*EXITING UBER CRIT ZONE*/
	if(!debugging)
		sleep(travel_time);
	//prevtime+=travel_time;

	mtx.lock();
	/*ENTERING UBER CRIT ZONE*/
	std::cout<<i2<<" exiting contruction"<<std::endl;
	east_crossing--;
	/*EXITING UBER CRIT ZONE*/
	//let some people do thier thing
	if(ped_wait > 1)
		ped.notify_all();
	west.notify_one();
	if(!wests_waiting > 0)
		ped.notify_all();
	mtx.unlock();
}

int main(){

	//This whole section is just to get everything out of the text file.
	//the plan was to put it in a function but for some reason it freaked out when I did that
	//so this is just how it's gonna be
	std::string temp;
	std::vector<std::string> temp_vect;
	std::ifstream file;
	file.open("traffic.txt");
	if(file.is_open()){
		while(!file.eof()){
			for(int i = 0; i < 3; i ++){
				if(!file.eof()){
					file >> temp;
					temp_vect.push_back(temp);
				}
		}
		if(temp_vect.size() > 2)
			traffic.push_back(temp_vect);
		temp_vect.clear();
		}
	}
	//vector of threads for ease of deletion
	std::vector<std::thread> threads;
	//start up our threads
	for( int i = 0 ; i < traffic.size() ; i ++){
		
		if(traffic[i][1].front() == 'W')
			threads.push_back(std::thread(carWest,traffic[i][0],traffic[i][1],traffic[i][2]));

		if(traffic[i][1].front() == 'E')
			threads.push_back(std::thread(carEast,traffic[i][0],traffic[i][1],traffic[i][2]));

		if(traffic[i][1].front() == 'P')
			threads.push_back(std::thread(pedestrian,traffic[i][0],traffic[i][1],traffic[i][2]));

	}

	//joins all our thread after they've done their thing.
	for(int i = 0 ; i < threads.size() ; i ++)
		threads[i].join();
}
