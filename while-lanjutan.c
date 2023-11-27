#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void mainmenu() {
	char input[100];
    int repeater = 1;
    char kelas[100];
    char nama[20];
    char result[500] = ""; // String untuk menyimpan hasil input

    printf("Masukkan Jumlah Siswa: ");
    scanf(" %[^\n]s", input);
    char *endptr;
    long menu = strtol(input, &endptr, 10); //Untuk memisahkan antara integer dengan string
    
    //Memeriksa apakah tidak ada string dalam input dan apakah input bernilai lebih besar dari 0.
    if (*endptr == '\0' && menu > 0) {
    	//Perulangan dengan kondisi jika variabel pengulang sudah mencapai total input.
        while (repeater <= menu) {
            printf("\nMasukkan Nama Siswa %i : ", repeater);
            scanf(" %[^\n]s", nama);
            printf("Masukkan Kelas Siswa %i (1.RPL/2.TKJ): ", repeater);
            scanf(" %[^\n]s", kelas);
            char *endptr2;
            long hasil = strtol(kelas, &endptr2, 10);
            
            if (*endptr2 == '\0') {
                char tempResult[100]; // String untuk menyimpan hasil sementara
                if (hasil == 1) {
                	printf("Siswa Ke %i : %s\nKelas Siswa %i : RPL\n======================\n\n", repeater, nama, repeater);
                    sprintf(tempResult, "Siswa Ke %i : %s\nKelas Siswa %i : RPL\n\n", repeater, nama, repeater);
                } else if (hasil == 2) {
                	printf("Siswa Ke %i : %s\nKelas Siswa %i : TKJ\n======================\n\n", repeater, nama, repeater);
                    sprintf(tempResult, "Siswa Ke %i : %s\nKelas Siswa %i : TKJ\n\n", repeater, nama, repeater);
                } else {
                	printf("Siswa Ke %i : %s\nKelas Kelas Tidak Terdaftar\n\n", repeater, nama);
                    sprintf(tempResult, "Siswa Ke %i : %s\nKelas Tidak Terdaftar\n\n", repeater, nama);
                }

                // Menggabungkan hasil sementara ke dalam hasil akhir
                strcat(result, tempResult);
            } else {
                system("cls");
				puts("Anda salah memasukkan input!\n\n");
				mainmenu();
            }
            repeater++;
        }

        // Menampilkan hasil input dalam MessageBox
        MessageBox(NULL, result, "Hasil Input", MB_OK | MB_ICONINFORMATION);
    } else {
        system("cls");
		puts("Anda salah memasukkan input!\n\n");
		mainmenu();
    }
}

int main() {
	puts("================================\n==While Lanjutan Oleh Daffabot==\n================================\n");
	mainmenu();
}
