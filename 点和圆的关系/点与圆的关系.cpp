#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Pointer { // ����  
private:  
   int Pointer_x; // ����  
   int Pointer_y; // ����  
public:  
   void set_coord(int tmp_X, int tmp_Y) { // ��������  
       Pointer_x = tmp_X;
       Pointer_y = tmp_Y;
   }
   void get_coord(int& tmp_X, int& tmp_Y) { // ��ȡ���꣨���ô��ݣ�
       tmp_X = Pointer_x;
       tmp_Y = Pointer_y;
   }
};

class Circle { // Բ��
private:
    int Circle_x;
    int Circle_y;
    int Radius;
public:
    void setCenter(int tmp_x, int tmp_y) { // ����Բ��
        Circle_x = tmp_x;
        Circle_y = tmp_y;
    }
    void setRadius(int tmp_radius) { // ���ð뾶
        Radius = tmp_radius;
    }
    void getCenter(int& tmp_x, int& tmp_y) { // ��ȡԲ��
        tmp_x = Circle_x;
        tmp_y = Circle_y;
    }
    int getRadius() { // ��ȡ�뾶
        return Radius;
    }
};

class IsInCircle { // �ж���
private:
    Circle c1;
    Pointer p1;

public:
    void setCircle(const Circle& circle) { // ����Բ
        c1 = circle;
    }

    void setPointer(const Pointer& pointer) { // ���õ�
        p1 = pointer;
    }

    int checkPosition() { // �жϵ��λ��
        int circle_x, circle_y, radius;
        int point_x, point_y;

        // ��ȡԲ�ĺͰ뾶
        c1.getCenter(circle_x, circle_y);
        radius = c1.getRadius();

        // ��ȡ�������
        p1.get_coord(point_x, point_y);

        // �жϵ��λ��
        if ((point_x - circle_x) * (point_x - circle_x) +
            (point_y - circle_y) * (point_y - circle_y) > radius * radius) {
            return 1; // ����Բ��
        } else if ((point_x - circle_x) * (point_x - circle_x) +
                   (point_y - circle_y) * (point_y - circle_y) == radius * radius) {
            return 0; // ����Բ��
        } else {
            return -1; // ����Բ��
        }
    }
};

int main() {
    Pointer p1; // �½�һ������
    int a, b;
    cout << "������������ (x y): ";
    cin >> a >> b;
    p1.set_coord(a, b);

    Circle c1; // �½�һ��Բ��
    int c, d, r;
    cout << "������Բ�ĵ����� (x y): ";
    cin >> c >> d;
    cout << "������Բ�İ뾶: ";
    cin >> r;
    c1.setCenter(c, d); // ����Բ�ĵ�
    c1.setRadius(r);    // �����뾶

    IsInCircle check; // �����ж������
    check.setCircle(c1);
    check.setPointer(p1);
    int result = check.checkPosition();
    if (result == 1) {
        cout << "����Բ��" << endl;
    } else if (result == 0) {
        cout << "����Բ��" << endl;
    } else {
        cout << "����Բ��" << endl;
    }

    return 0;
}