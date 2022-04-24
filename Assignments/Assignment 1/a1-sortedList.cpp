/* Write the worst case time complexity of the constructors and methods in the SortedList and UnsortedList class (given below).
Only write the time complexity as a line comment above the constructors/methods. Example: // O(n)
No need to write anything for the main function. */

#include<iostream>
using namespace std;

class SortedList{
private:
    int length;
    int* list;
    int currentPos;
    int capacity;

public:
// O(1)
    SortedList(){
        length = 0;
        currentPos = -1;
        capacity = 10;
        list = new int[capacity];
    }
// O(1)
    SortedList(int capacity){
        length = 0;
        currentPos = -1;
        this->capacity = capacity;
        list = new int[capacity];
    }
// O(1)
    void makeEmpty(){
        length = 0;
    }
// O(1)
    bool isFull(){
        return (length == capacity);
    }
// O(1)
    int lengthIs(){
        return length;
    }
// O(1)
    void resetList(){
        currentPos = -1;
    }
// O(1)
    int getNextItem(){
        currentPos++;
        return list[currentPos];
    }
// O(1)
    void insertItem(int item){
        int location = 0;
        while (location < length){
            if(item > list[location]){
                location++;
            }else{
                break;
            }
        }
        for (int index = length; index > location; index--){
            list[index] = list[index - 1];
        }
        list[location] = item;
        length++;
    }
// O(1)
    void deleteItem(int item){
        int location = 0;
        while (item != list[location]){
            location++;
        }
        for (int index = location + 1; index < length; index++){
            list[index - 1] = list[index];
        }
        length--;
    }
// O(logN)
    bool searchItem(int item){
        int midPoint, first = 0, last = length - 1;
        while (first <= last){
            midPoint = (first + last) / 2;
            if(item < list[midPoint]){
                last = midPoint - 1;
            }else if(item > list[midPoint]){
                first = midPoint + 1;
            }else{
                return true;
            }
        }
        return false;
    }
};

int main(){
    int capacity;
    cout << "Enter list capacity: ";
    cin >> capacity;

    SortedList sl(capacity);

    cout << "Enter " << capacity << " values: ";
    int n;
    while(!sl.isFull()){
        cin>>n;
        sl.insertItem(n);
    }

    cout << "List: ";
    for(int i=0; i<sl.lengthIs(); i++){
        cout << sl.getNextItem() << ",";
    }

    cout << "\b " << endl;
    cout << "Enter a value to search: ";
    cin >> n;
    if(sl.searchItem(n)){
        cout << n << " was found" << endl;
    }else{
        cout << n << " was not found" << endl;
    }

    cout << "Enter a value to delete: ";
    cin >> n;

    if(sl.searchItem(n)){
        sl.deleteItem(n);
        cout << n << " has been deleted" << endl;
    }else{
        cout << "Delete failed: " << n << " was not found" << endl;
    }

    sl.resetList();
    cout << "List: ";
    for(int i=0; i< sl.lengthIs(); i++){
        cout << sl.getNextItem() << ",";
    }
    cout << "\b " << endl;
}
