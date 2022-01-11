#include <iostream>
#include <fstream>
#include <string>

/*
Задание 25.

1. Дан символьный файл, содержащий по крайней мере один символ пробела. Удалить все его элементы, расположенные перед первым символом пробела, включая и этот пробел.
2. Дано имя файла и целые положительные числа N и K. Создать текстовый файл с указанным именем и записать в него N строк, каждая из которых состоит из K символов «*» (звездочка).
3. Даны два текстовых файла. Добавить в начало первого файла содержимое второго файла
4. Дан текстовый файл. Заменить в нем все подряд идущие пробелы на один пробел.
5. Дан текстовый файл. Найти количество абзацев в тексте, если первая строка каждого абзаца начинается с 5 пробелов («красная строка»). Пустые строки между абзацами не учитывать.


Каждая задача решена в отдельном классе
*/


class z1 {
private:
    std::string link, s = "";


public:
    z1(std::string t = "C:\\Users\\Ren\\Desktop\\Z.txt") {
        link = t;
    }

    void foo() {
        std::ifstream in(link);
        std::string c;
        while (getline(in, c)){
            s = s + c + "\n";
        }
        in.close();

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                s.erase(0, i + 1);
                break;
            }
        }
        
        std::ofstream out(link, std::ios_base::out | std::ios_base::trunc);
        out << s;
        out.close();
        

    }

};

class z2 {
private:
    std::string link;
    int n, k;


public:
    z2(std::string t = "C:\\Users\\Ren\\Desktop\\Z.txt", int h = 10, int l = 10) {
        link = t;
        n = h;
        k = l;
    }

    void foo() {
        std::ofstream out(link, std::ios_base::out | std::ios_base::trunc);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                out << '*';
            }
            out << "\n";
        }
        out.close();
    }
};

class z3 {
private:
    std::string link1, link2, s ="";


public:
    z3(std::string t = "C:\\Users\\Ren\\Desktop\\Z1.txt", std::string y = "C:\\Users\\Ren\\Desktop\\Z2.txt") {
        link1 = t;
        link2 = y;
    }

    void foo() {
        std::ifstream in(link2);
        std::string c;
        while (getline(in, c)) {
            s = s + c + "\n";
        }
        in.close();
        std::ifstream in1(link1);
        while (getline(in1, c)) {
            s = s + c + "\n";
        }
        in1.close();

        std::ofstream out(link1, std::ios_base::out);
        out << s;
        out.close();
    }

};

class z4 {
private:
    std::string link, s = "";


public:
    z4(std::string t = "C:\\Users\\Ren\\Desktop\\Z.txt") {
        link = t;
    }

    void foo() {
        std::ifstream in(link);
        std::string c;
        while (getline(in, c)) {
            s = s + c + "\n";
        }
        in.close();

        for (int i = 1; i < s.size(); i++) {
            if (s[i-1] == ' ' && s[i] == ' ') {
                s.erase(i-1, 1);
                i--;
            }
        }

        std::ofstream out(link, std::ios_base::out | std::ios_base::trunc);
        out << s;
        out.close();


    }

};

class z5 {
private:
    std::string link, s = "";


public:
    z5(std::string t = "C:\\Users\\Ren\\Desktop\\Z.txt") {
        link = t;
    }

    void foo() {
        std::ifstream in(link);
        std::string c;
        while (getline(in, c)) {
            s = s + c + "\n";
        }
        in.close();
        int n = 0, k = 0;
        for (int i = 0; i < s.size(); i++) {
            if (k == 5) {
                n++;
            }
            else if (k > 5) {
                std::cout << "FFFFFF";
            }
            if (s[i] == ' ') {
                k++;
            }
            else {
                k = 0;
            }
        }
        std::cout << "Количество абзацев " << n;
    }

};



int main()
{
    setlocale(LC_ALL, "rus");
    z5 first;
    first.foo();
}