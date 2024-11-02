#include <iostream>

using namespace std;

class Cookie {
    private:
        string color;

    public:
        Cookie (string color) {
            this->color = color;
        }

        string getColor() {
            return color;
        }

        void setColor(string color){
            this->color = color;
        }
};

int main(){

    Cookie* cookieOne = new Cookie("brown");
    cookieOne->setColor("black");

    cout << "C1: " << cookieOne->getColor() << endl;
}