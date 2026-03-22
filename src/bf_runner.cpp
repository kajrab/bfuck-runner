#include <iostream>
#include <fstream>
#include <string>

unsigned char tape[10000] = {0};
int ptr = 0;

// Change if needed
std::string file_name = "../data/numbers.bf";

std::string read(const std::string& file_name){
    std::ifstream file(file_name);
    std::string content, line;
    if(file.is_open()){
        while(std::getline(file, line)){
            content += line;
        }
    }
    file.close();
    return content;
}

void scan(const std::string& content){
    for(int symbol = 0; symbol < (int)content.size(); symbol++){
        if(content[symbol] == '+'){
            tape[ptr]++;
        }else if(content[symbol] == '-'){
            tape[ptr]--;
        }else if(content[symbol] == '.'){
            std::cout << (char)tape[ptr];
        }else if(content[symbol] == ','){
            tape[ptr] = std::cin.get();
        }else if(content[symbol] == '<'){
            if(ptr > 0) ptr--;
        }else if(content[symbol] == '>'){
            if(ptr < 9999) ptr++;
        }else if(content[symbol] == '['){
            if(tape[ptr] == 0){
                int depth = 1;
                while(depth > 0 && ++symbol < (int)content.size()){
                    if(content[symbol] == '[') depth++;
                    else if(content[symbol] == ']') depth--;
                }
            }
        }else if(content[symbol] == ']'){
            if(tape[ptr] != 0){
                int depth = 1;
                while(depth > 0 && --symbol >= 0){
                    if(content[symbol] == ']') depth++;
                    else if(content[symbol] == '[') depth--;
                }
                symbol--;
            }
        }
    }
}

int main(){
    std::string content = read(file_name);
    scan(content);
    std::cout << '\n';
    return 0;
}
