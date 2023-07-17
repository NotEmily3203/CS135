/*
Author: Emily Lin
Course: CSCI 13500
Instructor: Genadiy Maryash
Assignment: Homework E9.3

This program gets the state of a light switch
*/

#include <iostream>

class Circuit {
	public:
		int get_first_switch_state(){
            if(first_switch % 2 == 0){
                return 0;
            }else{
                return 1;
            }
        }
		int get_second_switch_state(){
            if(second_switch % 2 == 0){
                return 0;
            }else{
                return 1;
            }
        }
		int get_lamp_state(){
            if((first_switch % 2 == 1 || second_switch % 2 == 1)&&!(first_switch % 2 == 1 && second_switch % 2 == 1)){
                return 1;
            }else{
                return 0;
            }
        }
		void toggle_first_switch(){
            first_switch++;
        }
		void toggle_second_switch(){
            second_switch++;
        }
        void get(){
            std::cout<<first_switch<<second_switch<<lamp_state<<std::endl;
        }
	private:
		int first_switch = 0;
		int second_switch = 0;
		int lamp_state = 0;
};
