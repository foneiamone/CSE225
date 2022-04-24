/* Write the worst case time complexity of the constructors and methods in the SortedList and UnsortedList class (given below).
Only write the time complexity as a line comment above the constructors/methods. Example: // O(n)
No need to write anything for the main function. */

#include<iostream>
using namespace std;

class UnsortedList{
private:
    int length;
    int* list;
    int currentPos;
    int capacity;

public:
// O(1)
    UnsortedList(){
        length = 0;
        currentPos = -1;
        capacity = 10;
        list = new int[capacity];
    }
// O(1)
    UnsortedList(int capacity){
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
        list[length] = item;
        length++;
    }
// O(1)
    void deleteItem(int item){
        int location = 0;
        while (item != list[location]){
            location++;
        }
        list[location] = list[length - 1];
        length--;
    }
// O(N)
    bool searchItem(int item){
        for(int i=0; i<length; i++){
            if(item == list[i]){
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

    UnsortedList ul(capacity);

    cout << "Enter " << capacity << " values: ";
    int n;
    while(!ul.isFull()){
        cin>>n;
        ul.insertItem(n);
    }

    cout << "List: ";
    for(int i=0; i<ul.lengthIs(); i++){
        cout << ul.getNextItem() << ",";
    }

    cout << "\b " << endl;
    cout << "Enter a value to search: ";
    cin >> n;
    if(ul.searchItem(n)){
        cout << "Found" << endl;
    }else{
        cout << "Not found" << endl;
    }

    cout << "Enter a value to delete: ";
    cin >> n;

    if(ul.searchItem(n)){
        ul.deleteItem(n);
        cout << "Deleted" << endl;
    }else{
        cout << "Delete failed: Value not found" << endl;
    }

    ul.resetList();
    cout << "List: ";
    for(int i=0; i< ul.lengthIs(); i++){
        cout << ul.getNextItem() << ",";
    }
    cout << "\b " << endl;
}
