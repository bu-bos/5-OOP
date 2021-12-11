#include <iostream>
#include <cstring>

class File {
public:

    void open(const char *name, const char *mode);

    bool is_open() const { return _is_open; }

    void close();

    void read(void *buff, size_t size_of_elem, size_t count);

    void write(const void *buff, size_t size_of_elem, size_t count);

private:
    bool _is_open{};
    FILE *steam{};
};

void File::open(const char* name, const char* mode) {
    steam = fopen(name, mode);
    _is_open = steam;
}

void File::close() {
    if (steam) {
        fclose(steam);
        steam = nullptr;
    }
}

void File::write(const void* buff, size_t size_of_elem, size_t count) {
    fwrite(buff, size_of_elem, count, steam);
}

void File::read(void* buff, size_t size_of_elem, size_t count) {
    fread(buff, size_of_elem, count, steam);
}

//open(путь к файлу, модификация) - открывает файл
//close() - закрывает файл
//write(строка, длина переменной, кол-во символов)
//read(символьный массив, длина переменной, кол-во символов)

using namespace std;
int main() {
    File file;
    file.open(R"(C:\Users\huawei\CLionProjects\5\file.txt)", "w");
    if (!file.is_open())
        return 1;
    char s[] = "the program work correctly";
    file.write(s, sizeof(char), strlen(s));
    file.close();

    file.open(R"(C:\Users\huawei\CLionProjects\5\file.txt)", "r");
    char r[0];
    file.read(r, sizeof(char), strlen(r));
    cout << r << endl;
    file.close();

    return 0;
}