// Deklarasi pin lampu tiap arah (merah, kuning, hijau)
int utara[]  = {13,12,11};
int timur[]  = {4,3,2};
int selatan[] = {7,6,5};
int barat[]  = {10,9,8};

// Fungsi untuk kondisi semua lampu merah
void semuaMerah(){
  // Matikan semua lampu dulu
  for(int i=0; i<3; i++){
    digitalWrite(utara[i], LOW);
    digitalWrite(timur[i], LOW);
    digitalWrite(selatan[i], LOW);
    digitalWrite(barat[i], LOW);
  }

  // Nyalakan semua lampu merah
  digitalWrite(utara[0], HIGH);
  digitalWrite(timur[0], HIGH);
  digitalWrite(selatan[0], HIGH);
  digitalWrite(barat[0], HIGH);
}

// Fungsi untuk mengaktifkan satu arah
void aktifkanSimpang(int arah[]){
  semuaMerah(); // kondisi default

  // Lampu hijau menyala 5 detik
  digitalWrite(arah[0], LOW);   // merah mati
  digitalWrite(arah[2], HIGH);  // hijau nyala
  delay(5000);

  // Lampu kuning kedip 3x (total ±2 detik)
  digitalWrite(arah[2], LOW);
  for(int i=0; i<3; i++){
    digitalWrite(arah[1], HIGH);
    delay(333);
    digitalWrite(arah[1], LOW);
    delay(333);
  }

  // Kembali ke merah
  digitalWrite(arah[0], HIGH);
}

void setup(){
  // Set semua pin sebagai output
  for(int i=0; i<3; i++){
    pinMode(utara[i], OUTPUT);
    pinMode(timur[i], OUTPUT);
    pinMode(selatan[i], OUTPUT);
    pinMode(barat[i], OUTPUT);
  }

  semuaMerah(); // kondisi awal semua merah
  delay(1000);  // biar terlihat jelas
}

void loop(){
  aktifkanSimpang(utara);   // Utara
  aktifkanSimpang(timur);   // Timur
  aktifkanSimpang(selatan); // Selatan
  aktifkanSimpang(barat);   // Barat
}
