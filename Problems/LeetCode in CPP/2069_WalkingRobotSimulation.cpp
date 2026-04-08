#include<iostream>
#include<vector>
using namespace std;

class Robot {
private:
    int w, h;
    int x, y;
    int d; // 0=East, 1=North, 2=West, 3=South
    vector<vector<int>> dirs;

public:
    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        d = 0; // East

        dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    }
    
    void step(int num) {
        int perimeter = 2 * (w + h - 2);
        num %= perimeter;

        if (num == 0) {
            if (x == 0 && y == 0) d = 3;   // South
            return;
        }

        while (num > 0) {
            if (d == 0) {                  // East
                int move = min(num, w - 1 - x);
                x += move;
                num -= move;
                if (num > 0) d = 1;
            }
            else if (d == 1) {             // North
                int move = min(num, h - 1 - y);
                y += move;
                num -= move;
                if (num > 0) d = 2;
            }
            else if (d == 2) {             // West
                int move = min(num, x);
                x -= move;
                num -= move;
                if (num > 0) d = 3;
            }
            else {                         // South
                int move = min(num, y);
                y -= move;
                num -= move;
                if (num > 0) d = 0;
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        if (d == 0) return "East";
        if (d == 1) return "North";
        if (d == 2) return "West";
        if (d == 3) return "South";

        return "";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */

/* Helper function */
void print(vector<int> arr){
    cout << "[";
    for (int i = 0; i < arr.size(); i++){
        if (i == arr.size()-1) {
            cout << arr[i];
        } else {
            cout << arr[i] << ", ";
        }
    }
    cout << "]" << endl;
}

int main(){
    Robot* obj = new Robot(6,3);

    obj->step(2);
    obj->step(2);
    print(obj->getPos());
    cout << obj->getDir() << endl;

    obj->step(2);
    obj->step(1);
    obj->step(4);
    print(obj->getPos());
    cout << obj->getDir() << endl;

    return 0;
}