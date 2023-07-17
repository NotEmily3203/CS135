#include <iostream>
int main(){
    std::string sentence;
    std::cout<<"Input: ";
    std::getline(std::cin, sentence);
    int length = sentence.length();
    for(int i = 0; i < length; i++){
        std::cout<<sentence[i]<<" "<<int(sentence[i])<<std::endl;
    }
    return 0;
}