#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHARLIMIT 150

/*
create struct named item with ff members
  itemName - *char
  quantity - int
  price    - float
  amount   - float (quantity * price)
*/
typedef struct Item {
    char *itemName;
    int quantity;
    float price, amount;
} Item;

/*
create function named readItem
  takes struct pointer of type item
  reads (from user) product name, price, quantity
  contents are stored in passed-in structure
*/
void readItem(Item *itemToRead) {
    printf("Item to be read: ");
    fgets(itemToRead->itemName, CHARLIMIT, stdin);
    itemToRead->itemName[strcspn(itemToRead->itemName, "\n")] = 0;

    printf("Qty of ""%s"": ", itemToRead->itemName);
    scanf("%d", &itemToRead->quantity);

    printf("The price of ""%s"": ", itemToRead->itemName);
    scanf("%f", &itemToRead->price);

    itemToRead->amount = itemToRead->quantity * itemToRead->price;
}

/*
create function named printItem
  takes struct pointer of type item
  prints contents of parameter
*/
void printItem(Item *itemToPrint) {
    printf("Item Name: %s\n", itemToPrint->itemName);
    printf("Quantity:  %d\n", itemToPrint->quantity);
    printf("Price:     %.2f\n", itemToPrint->price);
    printf("Amount:    %.2f\n", itemToPrint->amount);
}

/*
main function declares item and pointer to item
  you'll allocate memory for itemName pointer
  item pointer is passed into both readItem and printItem
*/
int main()
{
    Item *someItem = (Item*) malloc(sizeof(someItem));
    someItem->itemName = (char*) calloc(150, sizeof(char));

    printf("Enter the following:\n");
    readItem(someItem);
    printf("\nYou have entered:\n");
    printItem(someItem);

    printf("Have a good day.\n");
    return 0;
}
