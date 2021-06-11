#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <time.h>

class Encryptor{
public:
    Encryptor(const std::string& message)
    : m_message(message)
    {}
public:
    std::string getMessage() const{for(auto& i : m_cubes){std::cout << i << "       ";}}
    void tokenization();
    void rotate      (size_t up, size_t down, size_t left, size_t right, size_t i);
    void upRotate    (size_t i);
    void downRotate  (size_t i);
    void leftRotate  (size_t i);
    void rightRotate (size_t i); 
    void encrypt();
    std::vector<int> generateMoves();
private:
    std::vector<std::string> m_cubes;
    std::string m_message{};
    std::string m_password{};
};

void Encryptor::upRotate (size_t i){
    for (int j = 0; j < 8; j += 4){
        std::swap(m_cubes[i][j], m_cubes[i][j+1]);
        std::swap(m_cubes[i][j+1], m_cubes[i][j+3]);
    }
}
void Encryptor::downRotate (size_t i){
    for (int j = 0; j < 8; j += 4){
        std::swap(m_cubes[i][j],m_cubes[i][j+2]);
        std::swap(m_cubes[i][j+1],m_cubes[i][j+3]);
        std::swap(m_cubes[i][j+1],m_cubes[i][j+2]);
    }   
}
void Encryptor::leftRotate (size_t i){
    std::swap(m_cubes[i][0], m_cubes[i][1]);
    std::swap(m_cubes[i][2], m_cubes[i][3]);
    std::swap(m_cubes[i][0], m_cubes[i][4]);
    std::swap(m_cubes[i][2], m_cubes[i][6]);
    std::swap(m_cubes[i][4], m_cubes[i][5]);
    std::swap(m_cubes[i][6], m_cubes[i][7]);
}
void Encryptor::rightRotate (size_t i){
    std::swap(m_cubes[i][0], m_cubes[i][1]);
    std::swap(m_cubes[i][2], m_cubes[i][3]);
    std::swap(m_cubes[i][1], m_cubes[i][5]);
    std::swap(m_cubes[i][3], m_cubes[i][7]);
    std::swap(m_cubes[i][4], m_cubes[i][5]);
    std::swap(m_cubes[i][6], m_cubes[i][7]);
}
void Encryptor::tokenization(){ 
    std::string str = "";
    size_t count = 0;

    for (auto i = 0; i < m_message.size(); ++i){
        if(count < 8){
            str += m_message[i];
            ++count;
        }else{
                m_cubes.push_back(str);
                str = "";
                count = 0;
        }
    }
    if (str.size()){
        m_cubes.push_back(str);
    }
}
void Encryptor::rotate (size_t up, size_t down, size_t left, size_t right, size_t i){
    while(up--){
        upRotate(i);
    }
    while(down--){
        downRotate(i);
    }
    while(left--){
        leftRotate(i);
    }
    while(right--){
        rightRotate(i);
    }
}
void Encryptor::encrypt(){
    if (m_message.size() > 24) { std::cout << "No no no, only < 24" << std::endl; abort(); }

    tokenization();

    for (int i = 0; i < m_cubes.size(); ++i){
        auto moves = generateMoves();
        auto up    = moves[0];
        auto down  = moves[1];
        auto left  = moves[2];
        auto right = moves[3];
        rotate(up, down, left, right, i);
    }
    
}
std::vector<int> Encryptor::generateMoves(){ 
    int a = rand()%4;
    int b = rand()%4;
    int c = rand()%4;
    int d = rand()%4;

    m_password += a;
    m_password += b;
    m_password += c;
    m_password += d;

    return {a,b,c,d};
}

int main(){
    srand(time(NULL));
    Encryptor enc("hello vortablefxzhaeaa");
    enc.encrypt();
    enc.getMessage();
}