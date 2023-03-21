#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * 100 contacts list
 * add contact details
 * remove contacts
 * display contacts
*/

#define MAX_ENTRIES 100

struct phonebook_entry{
    char name[50];
    char phone_number[20];
    char email[50];
};


void add_entry(struct phonebook_entry *phonebook, int *num_entries)
{
    if (*num_entries == MAX_ENTRIES)
    {
        printf("Phonebook is full.\n");
        return;
    }

    struct phonebook_entry new_entry;

    printf("Enter name: ");
    scanf("%s", new_entry.name);
    printf("Enter phone number: ");
    scanf("%s", new_entry.phone_number);
    printf("Enter email: ");
    scanf("%s", new_entry.email);

    phonebook[*num_entries] = new_entry;
    *num_entries += 1;

    printf("Entry added successfully.\n");

}

void display_entry(struct phonebook_entry entry)
{
    printf("Name: %s\n", entry.name);
    printf("Phone number: %s", entry.phone_number);
    printf("Email: %s\n", entry.email);
}

void search_entry(struct phonebook_entry *phonebook, int num_entries)
{
    char name[50];

    printf("Enter name to search: ");
    scanf("%s",name);

    for (int i = 0; i < num_entries; i++)
    {
        if (strcmp(phonebook[i].name, name) == 0)
        {
            display_entry(phonebook[i]);
            return;
        }
    }

    printf("Entry not found.\n");

}

void edit_entry(struct phonebook_entry *phonebook, int num_entries)
{
    char name[50];

    printf("Enter name to edit: ");
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++)
    {
        if (strcmp(phonebook[i].name, name) == 0)
        {
            struct phonebook_entry new_entry;

            printf("Enter new name (leave blank to keep current):");
            scanf("%s", new_entry.name);
            printf("Enter new phone number: ");
            scanf("%s", new_entry.phone_number);
            printf("Enter new email: ");
            scanf("%s", new_entry.email);

            if (strlen(new_entry.name) > 0)
            {
                strcpy(phonebook[i].name, new_entry.name);
            }
            if (strlen(new_entry.phone_number) > 0)
            {
                strcpy(phonebook[i].phone_number, new_entry.phone_number);
            }
            if (strlen(new_entry.email) > 0)
            {
                strcpy(phonebook[i].email, new_entry.email);
            }

            printf("Entry edited successfully.\n");
            return;
        }
    }
    printf("Entry not found.\n");
}

void delete_entry(struct phonebook_entry *phonebook, int *num_entries)
{
    char name[50];

    printf("Enter name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < *num_entries; i++)
    {
        if (strcmp(phonebook[i].name, name) == 0)
        {
            for (int j = i; j < *num_entries - 1; j++)
            {
                phonebook[j] = phonebook[j + 1];
            }
            *num_entries -= 1;

            printf("Entry deleted successfully.\n");
            return;
        }
    }
    printf("Entry not found.\n");
}

void display_phonebook(struct phonebook_entry *phonebook, int size)
{
    if (size == 0)
    {
        printf("Phonebook is empty.\n");
    }
    else
    {
        printf("Contacts\n");
        for (int i = 0; i < size; i++)
        {
            printf("Name: %s\n", phonebook[i].name);
            printf("Phone number: %s\n", phonebook[i].phone_number);
            printf("Email: %s\n", phonebook[i].email);
            printf("\n");
        }
    }
}

int main(void)
{
    
    struct phonebook_entry phonebook[MAX_ENTRIES];
    int size = 0;
    int choice;

    printf("CONTACTS\n");

    while (1)
    {
        printf("\n1. Add.\n2. Remove.\n3. Display\n4. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            add_entry(phonebook, &size);
            break;

            case 2:
            delete_entry(phonebook, &size);
            break;

            case 3:
            display_phonebook(phonebook, size);
            break;

            case 4:
            printf("Exiting contacts\n");
            exit(0);

            default:
            break;
        }
    }

    return (0);
}