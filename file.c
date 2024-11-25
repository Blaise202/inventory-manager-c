#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

// Structure to represent an inventory item
struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
};

// Function prototypes
void addItem(struct Item *items, int *count);
void displayItems(const struct Item *items, int count);
void updateItem(struct Item *items, int count);

int main() {
    struct Item inventory[MAX_ITEMS]; // Array of structures
    int itemCount = 0;
    int choice;

    do {
        printf("\n--- Inventory Management System ---\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Update Item\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(inventory, &itemCount);
                break;
            case 2:
                displayItems(inventory, itemCount);
                break;
            case 3:
                updateItem(inventory, itemCount);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to add an item to the inventory
void addItem(struct Item *items, int *count) {
    if (*count >= MAX_ITEMS) {
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }

    struct Item *newItem = &items[*count]; // Pointer to the new item
    printf("Enter Item ID: ");
    scanf("%d", &newItem->id);
    printf("Enter Item Name: ");
    scanf(" %[^\n]", newItem->name); // Read string with spaces
    printf("Enter Quantity: ");
    scanf("%d", &newItem->quantity);
    printf("Enter Price: ");
    scanf("%f", &newItem->price);

    (*count)++;
    printf("Item added successfully!\n");
}

// Function to display all items in the inventory
void displayItems(const struct Item *items, int count) {
    if (count == 0) {
        printf("No items in the inventory.\n");
        return;
    }

    printf("\n--- Inventory Items ---\n");
    printf("%-10s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-10d $%-9.2f\n", 
               items[i].id, items[i].name, items[i].quantity, items[i].price);
    }
}

// Function to update an item's quantity and price
void updateItem(struct Item *items, int count) {
    if (count == 0) {
        printf("No items to update.\n");
        return;
    }

    int id;
    printf("Enter Item ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (items[i].id == id) {
            printf("Updating Item: %s\n", items[i].name);
            printf("Enter New Quantity: ");
            scanf("%d", &items[i].quantity);
            printf("Enter New Price: ");
            scanf("%f", &items[i].price);
            printf("Item updated successfully!\n");
            return;
        }
    }

    printf("Item with ID %d not found.\n", id);
}
