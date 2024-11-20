
#include <iostream>
#include <chrono>

using namespace std;

void hanoi_towers(int size, int from, int to, int buf_peg)
//quantity-число колец, from-начальное положение колец(1-3),to-конечное положение колец(1-3)
{//buf_peg - промежуточный колышек(1-3)
    if (size >= 1)
    {
        hanoi_towers(size - 1, from, buf_peg, to);

        cout << "перемещаем диск " << size << " c " << from << " на " << to << " колышко" << endl;
        
        hanoi_towers(size - 1, buf_peg, to, from);
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int start_peg = 1, destination_peg, buffer_peg = 2, plate_quantity;
    while (true) {
        cout << "номер первого колышка:" << endl;
        cin >> start_peg;
        if (start_peg == 0) {
            cout << "данные неправильные((\n попробуйте ещё раз\n" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            continue;
        }
        if (cin.get() != (int)'\n') {
            cout << "данные неправильные((\n попробуйте ещё раз\n" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            continue;
        }
        cout << "номер конечного колышка:" << endl;
        cin >> destination_peg;
        if (destination_peg == 0) {
            cout << "данные неправильные((\n попробуйте ещё раз\n" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            continue;
        }
        if (cin.get() != (int)'\n') {
            cout << "данные неправильные((\n попробуйте ещё раз\n" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            continue;
        }
        cout << "номер промежуточного колышка:" << endl;
        cin >> buffer_peg;
        if (buffer_peg == 0) {
            cout << "данные неправильные((\n попробуйте ещё раз\n" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            continue;
        }
        if (cin.get() != (int)'\n') {
            cout << "данные неправильные((\n попробуйте ещё раз\n" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            continue;
        }
        cout << "количество колышков(они распределены по колышку сверху вниз):" << endl;
        cin >> plate_quantity;
        if (cin.get() != (int)'\n') {
            cout << "данные неправильные((\n попробуйте ещё раз\n" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            continue;
        }
        else if (plate_quantity <= 0 || plate_quantity > 1000) {
            cout << "данные неправильные((\n попробуйте ещё раз\n" << endl;
            continue;
        }
        if (start_peg == destination_peg || start_peg == buffer_peg || buffer_peg == destination_peg) {
            cout << "данные неправильные((\n попробуйте ещё раз\n" << endl;
            continue;
        }
        else {
            auto start = chrono::high_resolution_clock::now();
            hanoi_towers(plate_quantity + 1, start_peg, destination_peg, buffer_peg);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            cout << "Время: " << duration.count() << " микросекунд" << endl;
            break;
        }
    }
    cout << "количество ходов: " << pow(2, plate_quantity) - 1;

    return 0;
}
