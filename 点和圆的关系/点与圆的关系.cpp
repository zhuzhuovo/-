#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Pointer { // 点类  
private:  
   int Pointer_x; // 坐标  
   int Pointer_y; // 坐标  
public:  
   void set_coord(int tmp_X, int tmp_Y) { // 设置坐标  
       Pointer_x = tmp_X;
       Pointer_y = tmp_Y;
   }
   void get_coord(int& tmp_X, int& tmp_Y) { // 获取坐标（引用传递）
       tmp_X = Pointer_x;
       tmp_Y = Pointer_y;
   }
};

class Circle { // 圆类
private:
    int Circle_x;
    int Circle_y;
    int Radius;
public:
    void setCenter(int tmp_x, int tmp_y) { // 设置圆心
        Circle_x = tmp_x;
        Circle_y = tmp_y;
    }
    void setRadius(int tmp_radius) { // 设置半径
        Radius = tmp_radius;
    }
    void getCenter(int& tmp_x, int& tmp_y) { // 获取圆心
        tmp_x = Circle_x;
        tmp_y = Circle_y;
    }
    int getRadius() { // 获取半径
        return Radius;
    }
};

class IsInCircle { // 判断类
private:
    Circle c1;
    Pointer p1;

public:
    void setCircle(const Circle& circle) { // 设置圆
        c1 = circle;
    }

    void setPointer(const Pointer& pointer) { // 设置点
        p1 = pointer;
    }

    int checkPosition() { // 判断点的位置
        int circle_x, circle_y, radius;
        int point_x, point_y;

        // 获取圆心和半径
        c1.getCenter(circle_x, circle_y);
        radius = c1.getRadius();

        // 获取点的坐标
        p1.get_coord(point_x, point_y);

        // 判断点的位置
        if ((point_x - circle_x) * (point_x - circle_x) +
            (point_y - circle_y) * (point_y - circle_y) > radius * radius) {
            return 1; // 点在圆外
        } else if ((point_x - circle_x) * (point_x - circle_x) +
                   (point_y - circle_y) * (point_y - circle_y) == radius * radius) {
            return 0; // 点在圆上
        } else {
            return -1; // 点在圆内
        }
    }
};

int main() {
    Pointer p1; // 新建一个点类
    int a, b;
    cout << "请输入点的坐标 (x y): ";
    cin >> a >> b;
    p1.set_coord(a, b);

    Circle c1; // 新建一个圆类
    int c, d, r;
    cout << "请输入圆心的坐标 (x y): ";
    cin >> c >> d;
    cout << "请输入圆的半径: ";
    cin >> r;
    c1.setCenter(c, d); // 给定圆心点
    c1.setRadius(r);    // 给定半径

    IsInCircle check; // 创建判断类对象
    check.setCircle(c1);
    check.setPointer(p1);
    int result = check.checkPosition();
    if (result == 1) {
        cout << "点在圆外" << endl;
    } else if (result == 0) {
        cout << "点在圆上" << endl;
    } else {
        cout << "点在圆内" << endl;
    }

    return 0;
}