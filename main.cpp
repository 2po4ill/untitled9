#include "iostream"

using namespace std;

class BubbleSortStrategy;
class Insertion;
class SelectionSortStrategy;
class BogoSortStrategy;

class SortStrategy {
public:
    virtual void sort(int *array, int size) = 0;
    virtual ~SortStrategy() = default;
};

class BubbleSortStrategy : public SortStrategy {
    void sort(int *array, int size) override {
        int t;
        for (int i = 0; i < size; i++) {
            for (int j = (size - 1); j > (i + 1); j--) {
                if (array[j] < array[j - 1]) {
                    t = array[j];
                    array[j] = array[j - 1];
                    array[j - 1] = t;
                }
            }
        }
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};


class Insertion : public SortStrategy {
    void sort(int *array, int size) override {
        int k, a;
        for (int i = 1; i < size; i++) {
            k = array[i];
            a = i - 1;
            while(a>=0 && array[a] > k) {
                array[a + 1] = array[a];
                a = a - 1;
                array[a + 1] = k;
            }
        }
        for (int j = 0; j < size; j++) {
            cout << array[j] << " ";
        }
        cout << endl;
    }
};

class SelectionSortStrategy : public SortStrategy {
    void sort(int *array, int size) override {
        int save, t;
        for (int i = 0; i < size; i++) {
            save = i;
            for (int j = i; j < size; j++) {
                if (array[save] > array[j]) {
                    save = j;
                }
            }
            t = array[i];
            array[i] = array[save];
            array[save] = t;
        }
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

class BogoSortStrategy : public SortStrategy {
    void sort(int *array, int size) override {
        int ran, t;
        do {
            for (int i = 0; i < size; i++) {
                ran = rand() % (size - 1) + 0;
                t = array[i];
                array[i] = array[ran];
                array[ran] = t;
            }
        } while (!isSorted(array, size));
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    static bool isSorted(const int *arr, int size) {
        for (int i = 1; i < size; i++ ) {
            if (arr[i] < arr[i - 1])
                return false;
        }
        return true;
    }
};

class Sort {
private:
    SortStrategy *sort_strategy;
public:
    Sort() {
        sort_strategy = nullptr;
    }
    ~Sort() {
        delete sort_strategy;
    }
    void SetSortStrategy(SortStrategy *sortStrategy) {
        this->sort_strategy = sortStrategy;
    }
    void execSort(int *array, int size) {
        this->sort_strategy->sort(array, size);
    }
};

int main() {
    const int size = 6;
    int *array = new int[size]{5, 10, 4, 3, 6, 12};
    Sort *sort = new Sort();
    sort->SetSortStrategy(new BogoSortStrategy());
    sort->execSort(array, size);
    sort->SetSortStrategy(new Insertion());
    sort->execSort(array, size);
    sort->SetSortStrategy(new SelectionSortStrategy());
    sort->execSort(array, size);
    sort->SetSortStrategy(new BubbleSortStrategy());
    sort->execSort(array, size);
}
