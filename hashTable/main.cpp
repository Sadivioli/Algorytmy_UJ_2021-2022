#include "hash.h"
using namespace std;

int main(){
    
    cout << endl;
    cout << "Tablica stringów: " << endl;
    HashTable<string> stringBasedHash(SIZE);
    const string fruits[]={"peach", "apple", "snozzberry", "orange", "banana", "pear", "raspberry","tangerine", "kiwi", "plum", "dragon fruit", "watermelon","grape","cherry", "blueberry", "pineapple", "strawberry", "papaya", "grapefruit","apricot", "coconut", "melon", "lychee", "star fruit", "mango",
    "tomato", "potato", "cucumber", "carrot", "onion", "broccoli", "cabbage", "spinach", "lettuce", "pea", "kale", "radish", "celery", "beet", "eggplant", "garlic", "zucchini", "bell pepper", "turnip", "corn", "parsnip", "okra","scallion", "asparagus", "leek", "green bean", "shallot", "cauliflower", "rutabaga", "watercress", "kohlrabi", "endive", "artichoke", "bean"};
    int fruitsize = sizeof(fruits)/sizeof(*fruits);
    for(int i = 0; i < fruitsize; i++){
        stringBasedHash.insert(fruits[i]);
    }
    stringBasedHash.printHashTable();

    cout << endl;
    cout << "Usuwamy 'ogórek' z listy ~ aktualnie znajduje się w środku listy o kluczach 4 ([4,cucumber])" << endl;
    stringBasedHash.remove("cucumber");
    cout << "Sprawdzamy czy element o nazwie 'cucumber' znajduje się w liście: " << stringBasedHash.contains("cucumber") << endl;
    cout << "Sprawdzamy czy element o nazwie 'rutabaga' znajduje się w liście: " << stringBasedHash.contains("rutabaga") << endl;

    cout << endl;
    cout << "Tablica intów: " << endl;

    HashTable<int> intBasedHash(SIZE);
    int upperBound = 100;
    for (int i=0;i<50;i++){
        intBasedHash.insert(rand()%upperBound);
    }
    intBasedHash.printHashTable();
    cout << "Sprawdzamy czy element o wartości [42] znajduje się w liście: " << intBasedHash.contains(42) << endl;
}