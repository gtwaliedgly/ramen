/*******************************************************************************
*							PROGRAM KASIR WARUNG RAMEN ICHIRAKU                       *
*                                                                              *
*		Anggota Kelompok:                                                        *
*		-----------------                                                        *
*		- Sopian Wira Hadi(12155005),                                            *
*		- Hafiz Shahreva(12155026),                                              *
*		- Mike Santia(12155088),                                                 *
*     - Safira Mutia Arifin(12155107),       											 *
*     - Satrio Pamungkas(12155229),                                            *
*		- Walied Ghaly Damiri(12154303).            							          *
*                                                                              *
*******************************************************************************/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <iomanip.h>
#include <iostream.h>

//namaKustomer dibatasi sebesar 20.
//kenapa lebihnya 1? kenapa tidak harus 20 saja?
//karena, suatu karakter pasti akan diakhiri dengan '\0' atau NULL itupun
//kalau anda ingin menulisnya kalau tidak ikuti cara ini saja...
char namaKustomer[20] = "\0";

//i variabel yang umum dipakai.
//biasanya untuk menghitung suatu angka baik mundur maupun maju
int i;

//id variabel pembantu sekaligus pembawa identitas(jenis menu).
//jangan dirubah baik dari tipe data maupun nama dari variabel ini! kecuali
//anda bisa mengatasi resikonya sendiri...
int id[100];

//jumlahMenu dibatasi sebesar 100.
//batasan 100 karena, berpengaruh terhadap indeks array, dan juga operator
//perhitungan maju for() yang bergantung pada variabel jumlahPembelian.
int jumlahMenu[100];

//tingkatPedas dibatasi sebesar 6.
//batasan 100 karena, berpengaruh terhadap indeks array, dan juga operator
//perhitungan maju for() yang bergantung pada variabel jumlahPembelian.
int tingkatPedas[100];

//jumlahPembelian.
//jangan dirubah! kecuali jika anda ingin mengatasi resikonya sendiri...
int jumlahPembelian;

//kodeMenu dibatasi sebesar 100.
//batasan 100 karena, berpengaruh terhadap indeks array, dan juga operator
//perhitungan maju for() yang bergantung pada variabel jumlahPembelian.
char kodeMenu[100];

//pilihan.
//kenapa variabel pilihan tidak diberi batasan?
//karena, variabel ini tidak berpengaruh terhadap indeks array.
char pilihan;

//hitung.
//berperan sebagai handle dari suatu operasi penjumlahan dalam perulangan
long hitung;

//uangBayar.
//memakai tipe data long. kenapa tidak memakai tipe data int saja? karena,
//setiap inputan seperti nilai mata uang mempunyai jumlah angka yang mungkin
//sangat besar sekali contoh, 100000000
long uangBayar;

//batasan yang diberikan khusus untuk variabel namaKustomer.
//terdiri dari nilai maksimal, dan minimal. anda bisa mengubahnya sesuai
//keinginan apabila tidak setuju dengan setelan ini
const int batasMaksimalNamaKustomer = 20;
const int batasMinimalNamaKustomer = 1;

//batasan yang diberikan khusus untuk variabel jumlahPembelian.
//terdiri dari nilai maksimal, dan minimal. anda bisa mengubahnya sesuai
//keinginan apabila tidak setuju dengan setelan ini
const int batasMaksimalJumlahPembelian = 10;
const int batasMinimalJumlahPembelian = 1;

//batasan yang diberikan khusus untuk variabel jumlahMenu.
//terdiri dari nilai maksimal, dan minimal. anda bisa mengubahnya sesuai
//keinginan apabila tidak setuju dengan setelan ini
const int batasMaksimalJumlahMenu = 30;
const int batasMinimalJumlahMenu = 1;

//batasan yang diberikan khusus untuk variabel tingkatPedas.
//terdiri dari nilai maksimal, dan minimal. anda bisa mengubahnya sesuai
//keinginan apabila tidak setuju dengan setelan ini
const int batasMaksimalTingkatPedas = 6;
const int batasMinimalTingkatPedas = 1;

//bagian-bagian tampilan yang dipisah
void kepala();
void menu();
void kolomHasil();
void kolomTutup();

//fungsi kode() berguna untuk menampilkan kodeMenu[i] yang
//bersifat uppercase(huruf besar) karena, penggunaan strupr()
//dengan kodeMenu[i] tidak bisa(bersifat integer)...
void kode(int kode);

//fungsi namaJenisMenu() berguna untuk mencari nama dari jenis menu
//yang tersedia berdasarkan id
void namaJenisMenu(int kode);

//fungsi levelTingkatPedasMenu() berguna untuk mencari level tingkat pedas
//berdasarkan id
void levelTingkatPedasMenu(int level);

//fungsi hargaPerMenu() berguna untuk mencari suatu harga suatu menu
//berdasarkan id
long hargaPerMenu(int kode);

//fungsi totalHargaPerMenu() berguna untuk menghitung jumlahMenu[i] dikalikan
//dengan harga menu yang dicari berdasarkan id
long totalHargaPerMenu(int jumlah, int kode);

//fungsi uangKembalian() berguna untuk menghitung pembayaran dari kustomer
//dikurangi dengan jumlah yang harus dibayar
long uangKembalian(long jumlah, long bayar);

main()
{
   //fungsi system() ini berasal dari file header stdlib.h
   //dimana bisa diisi dengan perintah DOS yang diinginkan
   system("COLOR A");

   //operator do-while yang berguna untuk melakukan pengulangan dalam pemakaian
   //program ini(fleksibel)
   do
   {
      //bersihkan semua kegiatan program sebelumnya yang terjadi!
      //system("CLS");
   	clrscr();

      //bagian kepala program.
      //jangan dirubah!
		kepala();

      //bagian menu ramen yang disediakan.
      //jangan dirubah!
   	menu();

      nama_kustomer:
      cout<<"\n Nama Kustomer        : ";
      gets(namaKustomer);

      //apabila jumlah karakter namaKustomer kurang dari
      //batasMinimalNamaKustomer
      if(strlen(namaKustomer)<batasMinimalNamaKustomer)
      {
      	cout<<"\n Nama Kustomer tidak boleh kurang dari ";
         cout<<batasMinimalNamaKustomer<<"!\a";
         getch();

         goto nama_kustomer;
      }
      //apabila jumlah karakter namaKustomer lebih dari
      //batasMaksimalNamaKustomer
      else if(strlen(namaKustomer)>batasMaksimalNamaKustomer)
      {
         cout<<"\n Nama Kustomer tidak boleh lebih dari ";
         cout<<batasMaksimalNamaKustomer<<"!\a";
         getch();

         goto nama_kustomer;
      }
      else{
         jumlah_pembelian:
      	cout<<" Jumlah pembelian     : ";
         cin>>jumlahPembelian;

         //apabila masukan angka jumlahPembelian kurang dari
         //batasMinimalJumlahPembelian
         if(jumlahPembelian<batasMinimalJumlahPembelian)
         {
         	cout<<"\n Jumlah pembelian tidak boleh kurang dari ";
            cout<<batasMinimalJumlahPembelian<<"!\a"<<endl;
         	getch();

         	goto jumlah_pembelian;
         }
         //apabila masukan angka jumlahPembelian lebih dari
         //batasMaksimalJumlahPembelian
         else if(jumlahPembelian>batasMaksimalJumlahPembelian)
         {
         	cout<<"\n Jumlah pembelian tidak boleh lebih dari ";
            cout<<batasMaksimalJumlahPembelian<<"!\a"<<endl;
         	getch();

         	goto jumlah_pembelian;
         }
         else{
            //lakukan penginputan secara berulang sebanyak jumlahPembelian
            for(i=1; i<=jumlahPembelian; i++)
            {
               cout<<endl;

               //untuk penanda saja
            	cout<<" Urutan ke - "<<i<<endl;

               cout<<" Kode Menu    : ";
               cin>>kodeMenu[i];

               //masukan kodeMenu[i] akan diubah dengan nomor yang
               //sudah ditentukan. jangan dirubah!
               //sebenarnya kami ingin memakai operator if() tapi karena,
               //terlalu panjang jadinya, kami memutuskan untuk memakai
               //operator switch() untuk menghemat waktu. operator switch ini
               //dapat menangani huruf besar maupun huruf kecil...
      			switch(kodeMenu[i])
               {
                  case 'A':
               	case 'a':
                  id[i]=1;
                  break;

                  case 'B':
               	case 'b':
                  id[i]=2;
                  break;

                  case 'C':
               	case 'c':
                  id[i]=3;
                  break;

                  case 'D':
               	case 'd':
                  id[i]=4;
                  break;

                  case 'E':
               	case 'e':
                  id[i]=5;
                  break;

                  case 'F':
               	case 'f':
                  id[i]=6;
                  break;

                  case 'G':
               	case 'g':
                  id[i]=7;
                  break;

                  case 'H':
               	case 'h':
                  id[i]=8;
                  break;

                  case 'I':
               	case 'i':
                  id[i]=9;
                  break;

                  case 'J':
               	case 'j':
                  id[i]=10;
                  break;

                  default:
						id[i]=0;
                  break;
               }

               jumlah_banyaknya:
               cout<<" Jumlah banyaknya    : ";
               cin>>jumlahMenu[i];

               //apabila masukan angka jumlahMenu lebih dari
         		//batasMaksimalJumlahMenu
               if(jumlahMenu[i]>batasMaksimalJumlahMenu)
               {
               	cout<<"\n Jumlah Banyaknya Menu tidak boleh lebih dari ";
                  cout<<batasMaksimalJumlahMenu<<"!\a"<<endl;
         			getch();

         			goto jumlah_banyaknya;
               }
               //apabila masukan angka jumlahMenu kurang dari
         		//batasMinimalJumlahMenu
               else if(jumlahMenu[i]<batasMinimalJumlahMenu)
               {
                  cout<<"\n Jumlah Banyaknya Menu tidak boleh kurang dari ";
                  cout<<batasMinimalJumlahMenu<<"!\a"<<endl;
         			getch();

         			goto jumlah_banyaknya;
					}
               else{
                  pilihan_tingkat_pedas:
                  cout<<" Pilihan tingkat pedas : ";
               	cin>>tingkatPedas[i];

                  //apabila masukan angka tingkatPedas lebih dari
         			//batasMaksimalTingkatPedas
                  if(tingkatPedas[i]>batasMaksimalTingkatPedas)
                  {
                  	cout<<"\n Pilihan tingkat pedas tidak boleh lebih dari ";
                     cout<<batasMaksimalTingkatPedas<<"!\a"<<endl;
         				getch();

         				goto pilihan_tingkat_pedas;
                  }
                  //apabila masukan angka tingkatPedas kurang dari
         			//batasMinimalTingkatPedas
                  else if(tingkatPedas[i]<batasMinimalTingkatPedas)
                  {
                     cout<<"\n Pilihan tingkat pedas tidak boleh kurang dari ";
                     cout<<batasMinimalTingkatPedas<<"!\a"<<endl;
         				getch();

         				goto pilihan_tingkat_pedas;
                  }
                  //lain...
                  else{
                     //teruskan proses
                     continue;
                  }
					}
            }

            //kolom tabel hasil.
            //jangan dirubah!
            kolomHasil();

            //proses, dan tampilkan hasil inputan data dari perulangan
            //sebelumnya. bagian ini yang paling kami tekankan, karena sangat
            //berpengaruh besar terhadap kerapihan tampilan. jangan dirubah!
            for(i=1; i<=jumlahPembelian; i++)
            {
               //kolom No.
               cout<<setiosflags(ios::right);
               cout<<"|"<<setw(4)<<i;

               //kolom Kode
               cout<<setiosflags(ios::right);
               cout<<" |"<<setw(5);
               kode(kodeMenu[i]);
               cout<<" | ";

               //kolom Nama Jenis Menu
               cout<<setiosflags(ios::left);
               cout<<setw(3);
               namaJenisMenu(id[i]);
               cout<<"|";

               //kolom Jumlah Beli
               cout<<setiosflags(ios::right);
               cout<<setw(4)<<jumlahMenu[i]<<" | ";

               //kolom Level
               cout<<setiosflags(ios::left);
               cout<<setw(0);
               levelTingkatPedasMenu(tingkatPedas[i]);
               cout<<"| ";

               //kolom Harga
               cout<<setiosflags(ios::right);
               cout<<setw(10)<<hargaPerMenu(id[i])<<" |";

               //kolom Total
               cout<<setiosflags(ios::right);
               cout<<setw(11)<<totalHargaPerMenu(jumlahMenu[i], id[i])<<" |";

               cout<<endl;
            }
            kolomTutup(); //jangan dirubah!
            cout<<"\a";

         	cout<<"\n Total bayaran : ";

            //jumlahkan semua hasil totalHargaPerMenu()
            //sebanyak perulangan jumlahPembelian
            for(i=1; i<=jumlahPembelian; i++)
   			{
               //variabel hitung sebagai handle dari operasi hasil jumlah
               //totalHargaPerMenu()
   				hitung+=totalHargaPerMenu(jumlahMenu[i], id[i]);
   			}

            //tampilkan hasil penjumlahan
            cout<<hitung<<endl;

            uang_bayar:
            cout<<"\n Uang bayar : ";
            cin>>uangBayar;

            //apabila bayaran lebih kecil dari jumlah yang harus dibayar
				if(uangBayar<hitung)
   			{
   				cout<<"\n Maaf, uang sebesar "<<uangBayar;
               cout<<" tidak cukup untuk membayar!\a";
      			getch();

      			goto uang_bayar;
   			}

            cout<<" Kembalian  : ";
            cout<<uangKembalian(hitung, uangBayar);
            cout<<endl;

            getch();
         }
      }

      ingin_keluar:
      cout<<"\n Ingin keluar dari Program? (Y/t) ";
      cin>>pilihan;
   }
   while(pilihan=='T'||pilihan=='t');

   return 0;
}

void kepala()
{
	cout<<"------------------------------------------------"<<endl;
	cout<<" SELAMAT DATANG DI PROGRAM KASIR"<<endl;
   cout<<" WARUNG RAMEN ICHIRAKU!"<<endl;
   cout<<""<<endl;
	cout<<"------------------------------------------------"<<endl;
}

void menu()
{
	cout<<"\n   Menu Ramen\t  Harga\t\t Tingkat Pedas"<<endl;
	cout<<"\n A. Ramen Ichibi  Rp.9.000,-\t 1. Gennin"<<endl;
	cout<<" B. Ramen Nibi    Rp.12.000,-\t 2. Chunin"<<endl;
	cout<<" C. Ramen Sanbi   Rp.15.000,-\t 3. Sannin"<<endl;
	cout<<" D. Ramen Yonbi   Rp.18.000,-\t 4. Kage"<<endl;
	cout<<" E. Ramen Gobi    Rp.21.000,-\t 5. Rikudo"<<endl;
	cout<<" F. Ramen Rokubi  Rp.24.000,-\t 6. Tidak Pedas"<<endl;
	cout<<" G. Ramen Nanabi  Rp.27.000,-"<<endl;
	cout<<" H. Ramen Hachibi Rp.30.000,-"<<endl;
	cout<<" I. Ramen Kyuubi  Rp.33.000,-"<<endl;
	cout<<" J. Ramen Juubi   Rp.36.000,-"<<endl;
}

void kolomHasil()
{
   cout<<endl;
	cout<<"-------------------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t\tRAMEN ICHIRAKU"<<endl;
	cout<<"-------------------------------------------------------------------------------"<<endl;
	cout<<" Nama Kustomer : "<<strupr(namaKustomer)<<endl<<endl;
	cout<<"+-----+------+-----------------+-----+--------------+------------+------------+"<<endl;
	cout<<"| No. | Kode | Nama Jenis Menu | Qty | Level        | Harga      | Total      |"<<endl;
	cout<<"+-----+------+-----------------+-----+--------------+------------+------------+"<<endl;
}

void kolomTutup()
{
	cout<<"+-----+------+-----------------+-----+--------------+------------+------------+"<<endl;
}

void namaJenisMenu(int kode)
{
   if(kode==1)
   {
   	cout<<"Ramen Ichibi    ";
   }
   else if(kode==2)
   {
   	cout<<"Ramen Nibi      ";
   }
   else if(kode==3)
   {
   	cout<<"Ramen Sanbi     ";
   }
   else if(kode==4)
   {
   	cout<<"Ramen Yonbi     ";
   }
   else if(kode==5)
   {
   	cout<<"Ramen Gobi      ";
   }
   else if(kode==6)
   {
   	cout<<"Ramen Rokubi    ";
   }
   else if(kode==7)
   {
   	cout<<"Ramen Nanabi    ";
   }
   else if(kode==8)
	{
   	cout<<"Ramen Nachibi   ";
   }
   else if(kode==9)
   {
   	cout<<"Ramen Kyuubi    ";
   }
   else if(kode==10)
   {
   	cout<<"Ramen Juubi     ";
   }
   else if(kode==0)
   {
   	cout<<"...             ";
   }
}

void levelTingkatPedasMenu(int level)
{
   if(level==1)
   {
   	cout<<"Pedas        ";
   }
   else if(level==2)
   {
   	cout<<"Double pedas ";
   }
   else if(level==3)
   {
   	cout<<"Sangat pedas ";
   }
   else if(level==4)
   {
   	cout<<"Super pedas  ";
   }
   else if(level==5)
   {
   	cout<<"Extra pedas  ";
   }
   else if(level==6)
   {
   	cout<<"Tidak Pedas  ";
   }
}

void kode(int kode)
{
	switch(kode)
   {
   	case 'A':
      case 'a':
      cout<<"A";
      break;

      case 'B':
      case 'b':
      cout<<"B";
      break;

      case 'C':
      case 'c':
      cout<<"C";
      break;

      case 'D':
      case 'd':
      cout<<"D";
      break;

      case 'E':
      case 'e':
      cout<<"E";
      break;

      case 'F':
      case 'f':
      cout<<"F";
      break;

      case 'G':
      case 'g':
      cout<<"G";
      break;

      case 'H':
      case 'h':
      cout<<"H";
      break;

      case 'I':
      case 'i':
      cout<<"I";
      break;

      case 'J':
      case 'j':
      cout<<"J";
      break;

      default:
      cout<<"...";
      break;
   }
}

long hargaPerMenu(int kode)
{
   int harga[11]={9000, 12000, 15000, 18000, 21000, 24000, 27000, 30000, 33000, 36000, 0};
   int angka;

	if(kode==1)
   {
   	angka=harga[0];
   }
   else if(kode==2)
   {
      angka=harga[1];
   }
   else if(kode==3)
   {
      angka=harga[2];
   }
   else if(kode==4)
   {
      angka=harga[3];
   }
   else if(kode==5)
   {
      angka=harga[4];
   }
   else if(kode==6)
   {
      angka=harga[5];
   }
   else if(kode==7)
   {
      angka=harga[6];
   }
   else if(kode==8)
   {
      angka=harga[7];
   }
   else if(kode==9)
   {
      angka=harga[8];
   }
   else if(kode==10)
   {
      angka=harga[9];
   }
   else{
      angka=harga[10];
   }

   return angka;
}

long totalHargaPerMenu(int jumlah, int kode)
{
   int harga[11]={9000, 12000, 15000, 18000, 21000, 24000, 27000, 30000, 33000, 36000, 0};
   int angka;

   long hitung;

	if(kode==1)
   {
   	angka=harga[0];
   }
   else if(kode==2)
   {
      angka=harga[1];
   }
   else if(kode==3)
   {
      angka=harga[2];
   }
   else if(kode==4)
   {
      angka=harga[3];
   }
   else if(kode==5)
   {
      angka=harga[4];
   }
   else if(kode==6)
   {
      angka=harga[5];
   }
   else if(kode==7)
   {
      angka=harga[6];
   }
   else if(kode==8)
   {
      angka=harga[7];
   }
   else if(kode==9)
   {
      angka=harga[8];
   }
   else if(kode==10)
   {
      angka=harga[9];
   }
   else{
      angka=harga[10];
   }

   //apabila jumlahMenu[i] lebih dari batasMaksimalJumlahMenu
   if(jumlah>batasMaksimalJumlahMenu)
   {
		return 0;
   }
   //apabila jumlahMenu[i] kurang dari batasMaksimalJumlahMenu
   else if(jumlah<batasMinimalJumlahMenu)
   {
      return 0;
   }
   else{
      //handle angka yang sudah ditetapkan. angka dikalikan dengan jumlahMenu[i]
      hitung=angka*jumlah;

      if(!hitung)
      {
      	return 0;
      }
      else{
         return hitung;
      }
   }
}

long uangKembalian(long jumlah, long bayar)
{
   long hitung;

   //handle hitung yang sudah ditetapkan. bayaran dikurangi dengan
   //jumlah yang harus dibayar
   hitung=bayar-jumlah;

   if(!hitung)
   {
   	return false;
   }
   else{
   	return hitung;
   }
}
