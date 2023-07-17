//This programs prints each char in a str onto a new line
#include <iostream>
int main(){
    std::string word;
    std::cout<<"Enter a word: ";
    std::cin>>word;
    int length = word.length();
    char letters[length];
    for(int i=0; i<length; i++){
        letters[i]=word[i];
        std::cout<<letters[i]<<std::endl;
    }
    return 0;
}