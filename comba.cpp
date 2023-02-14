#include <iostream>
#include <vector>

void op_1() {
    std::cout << "комбинаторное правило суммы (либо, либо)\n";
    int n;
    int ans = 0;
    std::cout << "Количество объектов: ";
    std::cin >> n;
    std::cout << "Сколькими способами можно выбрать объекты? ";
    for (int i = 0; i < n; ++i) {
        int num = 0;
        std::cin >> num;
        ans = ans + num;
    }
    std::cout << "Ответ: " << ans;
}

void op_2() {
    std::cout << "комбинаторное правило произведения (кол-во упорядоченных наборов)\n";
    int n;
    int ans = 1;
    std::cout << "Количество объектов: ";
    std::cin >> n;
    std::cout << "Сколькими способами можно выбрать объекты? ";
    for (int i = 0; i < n; ++i) {
        int num = 0;
        std::cin >> num;
        ans = ans * num;
    }
    std::cout << "Ответ: " << ans;
}

void op_3() {
    std::cout << "число сочетаний без повторений из n объектов по k\n";
    int n, k;
    int ans = 1;
    std::cout << "n = ";
    std::cin >> n;
    std::cout << "k = ";
    std::cin >> k;
    // ans = C(k,n)
    // ans = n!/((n-k)!*k!)
    std::cout << "Ответ: " << ans;

    // Например, есть три (n=3) объекта{ 1,2,3 }, составляем сочетания по k = 2 объекта в каждом.
    // Тогда выборки{ 1,2 } и{ 2,1 } - это одно и то же сочетание(так как комбинации отличаются лишь порядком).
    // А всего различных сочетаний из 3 объектов по 2 будет три : {1, 2}, { 1,3 }, { 2,3 }.
}

void op_4() {
    std::cout << "число сочетаний с повторениями из n объектов по k\n";
    int n, k;
    int ans = 1;
    std::cout << "n = ";
    std::cin >> n;
    std::cout << "k = ";
    std::cin >> k;
    // C(-k,n) = C(k, k+n-1)
    // ans = (k+n-1)!/((n-1)!*k!)
    std::cout << "Ответ: " << ans;

    // В магазине продаются булочки трех видов: с маком, изюмом и повидлом. 
    // Мама послала Колю купить 6 булочек. Сколько возможных вариантов выбора у него есть?
}

void op_5() {
    std::cout << "число размещений без повторений из n объектов в группы по k\n";
    int n, k;
    int ans = 1;
    std::cout << "n = ";
    std::cin >> n;
    std::cout << "k = ";
    std::cin >> k;
    // ans = A(k,n) = C(k,n)*k! = C(k,n)*P(k)
    // ans = n!/(n-k)!
    std::cout << "Ответ: " << ans;
}

void op_6() {
    std::cout << "число размещений с повторениями из n объектов по k\n";
    long n, k;
    std::cout << "n = ";
    std::cin >> n;
    std::cout << "k = ";
    std::cin >> k;
    // ans = A(-k,n)
    // ans = n^k
    long ans = 1;
    while (k) {
        if (k % 2 == 0) {
            k /= 2;
            n *= n;
        }
        else {
            k--;
            ans *= n;
        }
    }
    std::cout << "Ответ: " << ans;

    // В лифт 8-этажного дома вошли 4 пассажира. 
    // Сколькими способами они могут выйти (выход возможен на любом этаже, начиная со второго).
}

void op_7() {
    std::cout << "число перестановок без повторений из n элементов\n";
    int n;
    int ans = 1;
    std::cout << "n = ";
    std::cin >> n;
    // ans = n!
    for (int i = 1; i <= n; i++) {
        ans = ans + i;
    }
    std::cout << "Ответ: " << ans;
}

void op_8() {
    std::cout << "число перестановок с повторениями\n";
    int k, n = 0;
    int ans = 1;
    std::cout << "Число типов объектов: ";
    std::cin >> k;
    std::vector <int> num(k);
    std::cout << "Количество объектов каждого типа: ";
    for (int i = 0; i < k; ++i) {
        std::cin >> num[i];
        n = n + num[i];
    }
    //ans = n!/(n1!*n2!*...)
    std::cout << "Ответ: " << ans;

    // Сколькими способами можно разбить группу 10 друзей на команды из 2 бандитов, 2 полицейских, 1 сыщика и 5 прохожих для игры?
}

int main()
{
    int n;
    setlocale(LC_ALL, "Russian");
    std::cout << "Выберите операцию\n";
    std::cout << "1 - комбинаторное правило суммы\n";
    std::cout << "2 - комбинаторное правило произведения\n";
    std::cout << "3 - число сочетаний без повторений\n";
    std::cout << "4 - число сочетаний с повторениями\n";
    std::cout << "5 - число размещений без повторений\n";
    std::cout << "6 - число размещений с повторениями\n";
    std::cout << "7 - число перестановок без повторений\n";
    std::cout << "8 - число перестановок с повторениями\n";
    std::cout << "0 - ЗАКРЫТЬ ПРОГРАММУ\n";
    bool operatorClicked = 1;
    while (operatorClicked) {
        std::cout << "\n\n";
        std::cout << "Операция: ";
        std::cin >> n;
        switch (n) {
        case 0: operatorClicked = 0; break;
        case 1: op_1(); break;
        case 2: op_2(); break;
        case 3: op_3(); break;
        case 4: op_4(); break;
        case 5: op_5(); break;
        case 6: op_6(); break;
        case 7: op_7(); break;
        case 8: op_8(); break;
        default: std::cout << "Вы ввели что-то не то:(";
        }
        if (operatorClicked == 0) {
            return 0;
        }
    }
    return 0;
}