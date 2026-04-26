#include <stdio.h>
#include <string.h>

struct Leave {
    int id;
    char name[50];
    int days;
    char status[20];
};


void updateLeave() {
    FILE *fp = fopen("leave.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    struct Leave l;
    int id, found = 0, choice;

    printf("\nEnter ID to update: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %s %d %s", &l.id, l.name, &l.days, l.status) != EOF) {

        if (l.id == id) {
            found = 1;

            printf("\n1. Approve\n2. Reject\nChoose: ");
            scanf("%d", &choice);

            if (choice == 1)
                strcpy(l.status, "Approved");
            else
                strcpy(l.status, "Rejected");
        }

        fprintf(temp, "%d %s %d %s\n", l.id, l.name, l.days, l.status);
    }

    fclose(fp);
    fclose(temp);

    remove("leave.txt");
    rename("temp.txt", "leave.txt");

    if (found)
        printf(" Status Updated Successfully!\n");
    else
        printf(" Record Not Found!\n");
}

// View Leaves
void viewLeaves() {
    FILE *fp = fopen("leave.txt", "r");
    struct Leave l;

    printf("\n--- Leave Records ---\n");

    while (fscanf(fp, "%d %s %d %s", &l.id, l.name, &l.days, l.status) != EOF) {
        printf("ID: %d | Name: %s | Days: %d | Status: %s\n",
               l.id, l.name, l.days, l.status);
    }

    fclose(fp);
}

// Main Menu
int main() {
    int choice;

    while (1) {
        printf("\n===== Leave Management System =====\n");
        printf("1. Apply Leave\n");
        printf("2. View Leaves\n");
        printf("3. Approve/Reject Leave\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: applyLeave(); break;
            case 2: viewLeaves(); break;
            case 3: updateLeave(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
