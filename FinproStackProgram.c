#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct 
{
    char username[50];
    char password[50];
} Akun;

typedef struct 
{
    Akun data[100];
    int top;
} AkunStack;

void initializeAkunStack(AkunStack *akunStack) 
{
    akunStack->top = -1;
}

int isAkunStackFull(AkunStack *akunStack) 
{
    return akunStack->top == 99;
}

int isAkunStackEmpty(AkunStack *akunStack) 
{
    return akunStack->top == -1;
}

void loadAkunStackFromFile (AkunStack *akunStack);

void saveAkunStackToFile(AkunStack *akunStack);

void pushAkun(AkunStack *akunStack, Akun newAkun) 
{
    if (isAkunStackFull(akunStack)) 
    {
        printf("Akun stack is full\n");
    } 
    else 
    {
        akunStack->top++;
        akunStack->data[akunStack->top] = newAkun;
    }
}

Akun popAkun(AkunStack *akunStack) 
{
    Akun emptyAkun = { "", "" };

    if (isAkunStackEmpty(akunStack)) 
    {
        printf("Akun stack is empty\n");
        return emptyAkun;
    } 
    else 
    {
        Akun poppedAkun = akunStack->data[akunStack->top];
        akunStack->top--;
        return poppedAkun;
        saveAkunStackToFile(&akunStack);
    }
}

void displayAkun(AkunStack *akunStack) 
{
    if (isAkunStackEmpty(akunStack)) 
    {
        printf("Akun stack is empty\n");
    } 
    else 
    {
        printf("Akun List\n");
        printf("======================\n");
        printf("| No. |   Username   |\n");
        printf("======================\n");
        for (int i = akunStack->top; i >= 0; i--) 
        {
            printf("| %-3d | %-12s |\n", i+1, akunStack->data[i].username);
        }
        printf("======================\n");
    }
}

int searchAkun(AkunStack *akunStack, char *akunUsername)
{
    int found = 0;
        printf("Search Result\n");
        printf("======================\n");
        printf("| No. |   Username   |\n");
        printf("======================\n");
    for (int i = akunStack->top; i >= 0; i--) 
    {
        if (strcmp(akunStack->data[i].username, akunUsername) == 0) 
        {
            printf("| %-3d | %-12s |\n", i+1, akunStack->data[i].username);
            found = 1;
        }
    }
    printf("======================\n");
    if (!found) 
    {
        printf("No akun found for username: %s\n", akunUsername);
    }

    return found;
}

typedef struct 
{
    char pengirim[50];
    char alamat_pengirim[100];
    char penerima[50];
    char alamat_penerima[100];
    char nomor_penerima[50];
    float berat;
} Paket;

typedef struct 
{
    Paket data[100];
    int top;
} Stack;

void initialize(Stack *paketStack) 
{
    paketStack->top = -1;
}

int isFull(Stack *paketStack) 
{
    return paketStack->top == 99;
}

int isEmpty(Stack *paketStack) 
{
    return paketStack->top == -1;
}

void savePaketStackToFile(Stack *paketStack);

void loadPaketStackFromFile(Stack *paketStack);

void push(Stack *paketStack, Paket newPaket) 
{
    if (isFull(paketStack)) 
    {
        printf("Stack is full\n");
    } else 
    {
        paketStack->top++;
        paketStack->data[paketStack->top] = newPaket;
    }
}

Paket pop(Stack *paketStack) 
{
    Paket poppedPaket;
    if (isEmpty(paketStack)) 
    {
        printf("Stack is empty\n");
        strcpy(poppedPaket.pengirim, "");
    } else 
    {
        poppedPaket = paketStack->data[paketStack->top];
        paketStack->top--;
        savePaketStackToFile(paketStack);
    }
    return poppedPaket;
}

void displayPaket(Stack *paketStack) 
{
    if (isEmpty(paketStack)) 
    {
        printf("No paket\n");
    } else 
    {
        printf("Paket List:\n");
        printf("============================================================================================================================================================\n");
        printf("| No. |    Pengirim    |             Alamat Pengirim            |   Penerima   |             Alamat Penerima           |    No.HP Penerima   | Berat Paket |\n");
        printf("============================================================================================================================================================\n");
        for (int i = paketStack->top; i >= 0; i--) 
        {
        printf("| %-3d | %-14s | %-38s | %-12s | %-37s | %-19s | %-8.2f kg |\n", i + 1, paketStack->data[i].pengirim, paketStack->data[i].alamat_pengirim, paketStack->data[i].penerima, paketStack->data[i].alamat_penerima, paketStack->data[i].nomor_penerima, paketStack->data[i].berat);
        }
        printf("============================================================================================================================================================\n");
    }
}

void searchPaket(Stack *paketStack, char *namaPengirim) 
{
    int found = 0;

    for (int i = paketStack->top; i >= 0; i--) 
    {
        if (strcmp(paketStack->data[i].pengirim, namaPengirim) == 0) 
        {
        printf("Search Result:\n");
        printf("============================================================================================================================================================\n");
        printf("| No. |    Pengirim    |             Alamat Pengirim            |   Penerima   |             Alamat Penerima           |    No.HP Penerima   | Berat Paket |\n");
        printf("============================================================================================================================================================\n");
        printf("| %-3d | %-14s | %-38s | %-12s | %-37s | %-19s | %-8.2f kg |\n", i + 1, paketStack->data[i].pengirim, paketStack->data[i].alamat_pengirim, paketStack->data[i].penerima, paketStack->data[i].alamat_penerima, paketStack->data[i].nomor_penerima, paketStack->data[i].berat);
        found = 1;
        }
    }
        printf("============================================================================================================================================================\n");
    if (!found) 
    {
        printf("No paket found for sender: %s\n", namaPengirim);
    }
}

int main() 
{
    AkunStack akunStack;
    initializeAkunStack(&akunStack);
    loadAkunStackFromFile(&akunStack);

    char username[50];
    char password[50];
    int loginSuccess = 0;

    while (!loginSuccess) 
    {
        printf("Enter username: ");
        scanf("%s", username); 

        printf("Enter password: ");
        scanf("%s", password);

        for (int i = 0; i <= akunStack.top; i++) 
        {
            if (strcmp(akunStack.data[i].username, username) == 0 && strcmp(akunStack.data[i].password, password) == 0) 
            {
                printf("\nLogin successful!\n");
                loginSuccess = 1;
                break;
            }
        }

        if (!loginSuccess) 
        {
            printf("Invalid username or password\n");
        }
    }

    Stack paketStack;
    initialize(&paketStack);
    loadPaketStackFromFile(&paketStack);

    int choice;
    
    do 
    {
        printf("\n");
        printf("========== MENU ==========\n");
        printf("1. Kelola Paket\n");
        printf("2. Kelola Akun\n");
        printf("0. Keluar\n");
        printf("===========================\n");
        printf("Pilih menu: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1: 
            {
                int paketChoice;
                do 
                {
                    printf("\nMenu Kelola Paket:\n");
                    printf("1. Tambah Paket\n");
                    printf("2. Hapus Paket\n");
                    printf("3. Display Paket\n");
                    printf("4. Search Paket\n");
                    printf("0. Kembali\n");
                    printf("Pilihan Anda: ");
                    scanf("%d", &paketChoice);
                    getchar();
                    switch (paketChoice) 
                    {
                        case 1: 
                        {
                            Paket newPaket;
                            printf("Masukkan nama pengirim: ");
                            scanf("%[^\n]", newPaket.pengirim);
                            getchar();
                            printf("Masukkan alamat pengirim: ");
                            scanf("%[^\n]", newPaket.alamat_pengirim);
                            getchar();
                            printf("Masukkan nama penerima: ");
                            scanf("%[^\n]", newPaket.penerima);
                            getchar();
                            printf("Masukkan alamat penerima: ");
                            scanf("%[^\n]", newPaket.alamat_penerima);
                            getchar();
                            printf("Masukkan nomor penerima: ");
                            scanf("%[^\n]", newPaket.nomor_penerima);
                            getchar();
                            printf("Masukkan berat paket (kg): ");
                            scanf("%f", &newPaket.berat);

                            push(&paketStack, newPaket);
                            savePaketStackToFile(&paketStack);
                            printf("Paket berhasil ditambahkan\n");
                            break;
                        }
                        case 2: 
                        {
                            Paket poppedPaket = pop(&paketStack);
                            if (strcmp(poppedPaket.pengirim, "") != 0) 
                            {
                                printf("\nPaket berhasil diambil\n");
                                printf("Pengirim        : %s\n", poppedPaket.pengirim);
                                printf("Alamat Pengirim : %s\n", poppedPaket.alamat_pengirim);
                                printf("Penerima        : %s\n", poppedPaket.penerima);
                                printf("Alamat Penerima : %s\n", poppedPaket.alamat_penerima);
                                printf("Nomor Penerima  : %s\n", poppedPaket.nomor_penerima);
                                printf("Berat Paket     : %.2f kg\n\n", poppedPaket.berat);
                            }
                            break;
                        }
                        case 3:
                            displayPaket(&paketStack);
                            break;
                        case 4: 
                        {
                            char namaPengirim[50];
                            printf("Masukkan nama pengirim yang dicari: ");
                            scanf("%[^\n]", namaPengirim);
                            searchPaket(&paketStack, namaPengirim);
                            break;
                        }
                        case 0:
                            printf("Kembali ke menu utama\n");
                            break;
                        default:
                            printf("Pilihan tidak valid\n");
                            break;
                    }
                } while (paketChoice != 0);

                break;
            }
            case 2: 
            {
                int akunChoice;
                do 
                {
                    printf("\n");
                    printf("Menu Kelola Akun:\n");
                    printf("1. Tambah Akun\n");
                    printf("2. Display Akun\n");
                    printf("3. Delete Akun\n");
                    printf("4. Search Akun\n");
                    printf("0. Kembali\n");
                    printf("Pilihan Anda: ");
                    scanf("%d", &akunChoice);

                        switch (akunChoice) 
                        {
                            case 1: 
                            {
                                Akun newAkun;
                                printf("Masukkan username: ");
                                scanf("%s", newAkun.username);
                                getchar();
                                printf("Masukkan password: ");
                                scanf("%s", newAkun.password);
                                getchar();

                                pushAkun(&akunStack, newAkun);
                                saveAkunStackToFile(&akunStack);
                                printf ("Akun berhasil ditambah\n");
                                break;
                            }
                            case 2:
                            {
                                displayAkun(&akunStack);
                                break;
                            }
                            case 3 :
                            {
                                Akun poppedAkun = popAkun(&akunStack);
                                printf("Username akun '%s' telah dihapus\n", poppedAkun.username);
                                break;
                            }
                            case 4:                         
                            {
                                char akunUsername[50];
                                printf("Masukkan username yang dicari: ");
                                scanf("%s", akunUsername);
                                searchAkun(&akunStack, &akunUsername);
                                break;
                            }
                            case 0:
                                printf("Terima kasih, program selesai.\n");
                                break;
                            default:
                                printf("Pilihan tidak valid\n");
                        }
                } while (akunChoice != 0);

                  break;
            }
            case 0:
                printf("\nTerima kasih !!!\n\n");
                printf("Program telah berakhir.\n");
                break;
            default:
                printf("Pilihan menu tidak valid\n");
                break;
        }

    
    } while (choice != 0);

    return 0;
}


/* Function - function Untuk file proccesing */

void saveAkunStackToFile(AkunStack *akunStack) {
    FILE *file = fopen("akun.txt", "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    for (int i = 0; i <= akunStack->top; i++) {
        fprintf(file, "%s %s\n", akunStack->data[i].username, 
                                 akunStack->data[i].password);
    }

    fclose(file);
}

void savePaketStackToFile(Stack *paketStack) 
{
    FILE *file = fopen("paket.txt", "w");
    if (file == NULL) 
    {
        printf("Error opening file\n");
        return;
    }

    for (int i = 0; i <= paketStack->top; i++) 
    {
        fprintf(file, "%s;%s;%s;%s;%s;%.2f\n",  paketStack->data[i].pengirim,
                                                paketStack->data[i].alamat_pengirim,
                                                paketStack->data[i].penerima,
                                                paketStack->data[i].alamat_penerima,
                                                paketStack->data[i].nomor_penerima,
                                                paketStack->data[i].berat);
    }
    fclose(file);
}

void loadPaketStackFromFile(Stack *paketStack) 
{
    FILE *file = fopen("paket.txt", "r");
    if (file == NULL) 
    {
        printf("Error opening file\n");
        return;
    }

    paketStack->top = -1;
    while (fscanf(file, "%[^;];%[^;];%[^;];%[^;];%[^;];%f\n",   paketStack->data[paketStack->top + 1].pengirim,
                                                                paketStack->data[paketStack->top + 1].alamat_pengirim, 
                                                                paketStack->data[paketStack->top + 1].penerima,
                                                                paketStack->data[paketStack->top + 1].alamat_penerima, 
                                                                paketStack->data[paketStack->top + 1].nomor_penerima,
                                                                &paketStack->data[paketStack->top + 1].berat) != EOF) 
    {
        paketStack->top++;
    }

    fclose(file);
}

void loadAkunStackFromFile (AkunStack *akunStack)
{
    FILE *file;
    file = fopen("akun.txt", "r");
    if (file == NULL) 
    {
        printf("Error opening file\n");
    }
    while (fscanf(file, "%s %s\n",  akunStack->data[akunStack->top + 1].username, 
                                    akunStack->data[akunStack->top + 1].password) != EOF) 
    {
        akunStack->top++;
    }
    fclose(file);
}