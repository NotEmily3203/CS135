/*
Author: Emily Lin
Course: CSCI 13500
Instructor: Genadiy Maryash
Assignment: Homework E9.5

This program gets the perimeter and area of a rectangle and resizes it
*/

class Rectangle {
	public:
		Rectangle(double input_w, double input_h){
            width = input_w;
            height = input_h;
        }
		double get_perimeter(){
            float sum = 0;
            sum += 2*width + 2*height;
            return sum;
        }
		double get_area(){
            float area = 0;
            area += width*height;
            return area;
        }
		void resize(double factor){
            width = width*factor;
            height = height*factor;
        }
	private:
		double width;
		double height;
};