/* 
Enter list capacity: 3
Enter 3 values: 1 2 3
List: 1,2,3 
Enter a value to search: 2
2 was found
Enter a value to delete: 1
1 has been deleted
List: 2,3 */

#include <iostream>
using namespace std;

template <class ItemType>
class SortedList
{
private:
    int length;
    ItemType *list;
    int currentPos;
    int capacity;

public:
    SortedList()
    {
        length = 0;
        currentPos = -1;
        capacity = 10;
        list = new ItemType[capacity];
    }

    SortedList(int capacity)
    {
        length = 0;
        currentPos = -1;
        this->capacity = capacity;
        list = new ItemType[capacity];
    }

    void makeEmpty()
    {
        length = 0;
    }

    bool isFull()
    {
        return (length == capacity);
    }

    int lengthIs()
    {
        return length;
    }

    void resetList()
    {
        currentPos = -1;
    }

    int getNextItem()
    {
        currentPos++;
        return list[currentPos];
    }

    void insertItem(int item)
    {
        int location = 0;
        while (location < length)
        {
            if (item > list[location])
            {
                location++;
            }
            else
            {
                break;
            }
        }
        for (int index = length; index > location; index--)
        {
            list[index] = list[index - 1];
        }
        list[location] = item;
        length++;
    }

    void deleteItem(int item)
    {
        int location = 0;
        while (item != list[location])
        {
            location++;
        }
        for (int index = location + 1; index < length; index++)
        {
            list[index - 1] = list[index];
        }
        length--;
    }

    bool searchItem(int item)
    {
        int midPoint, first = 0, last = length - 1;
        while (first <= last)
        {
            midPoint = (first + last) / 2;
            if (item < list[midPoint])
            {
                last = midPoint - 1;
            }
            else if (item > list[midPoint])
            {
                first = midPoint + 1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    int capacity;
    cout << "Enter list capacity: ";
    cin >> capacity;

    SortedList<char> sl(capacity);

    cout << "Enter " << capacity << " values: ";
    char n, a;
    while (!sl.isFull())
    {
        cin >> n;
        sl.insertItem(n);
    }

    cout << "List: ";
    for (int i = 0; i < sl.lengthIs(); i++)
    {
        a = sl.getNextItem();
        cout << a << ",";
    }

    cout << "\b " << endl;
    cout << "Enter a value to search: ";
    cin >> n;
    if (sl.searchItem(n))
    {
        cout << n << " was found" << endl;
    }
    else
    {
        cout << n << " was not found" << endl;
    }

    cout << "Enter a value to delete: ";
    cin >> n;

    if (sl.searchItem(n))
    {
        sl.deleteItem(n);
        cout << n << " has been deleted" << endl;
    }
    else
    {
        cout << "Delete failed: " << n << " was not found" << endl;
    }

    sl.resetList();
    cout << "List: ";
    for (int i = 0; i < sl.lengthIs(); i++)
    {
        a = sl.getNextItem();
        cout << a << ",";
    }
    cout << "\b " << endl;
}
