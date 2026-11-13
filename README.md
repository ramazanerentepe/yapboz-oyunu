# Yapboz Oyunu

> **Görsel Programlama dersi – 2. Ödev** kapsamında geliştirilmiştir.

Qt (C++) ile yazılmış sürükle-bırak bir yapboz oyunu. Resim 5×5 = 25 parçaya bölünür ve parçalar karışık olarak dizilir; parçaları sürükleyip bırakarak komşularıyla yer değiştirir ve resmi tamamlamaya çalışırsınız.

| | |
|---|---|
| **Ders** | Görsel Programlama |
| **Ödev** | Ödev 2 |
| **Geliştirici** | Ramazan Eren Tepe |
| **Dil / Çatı** | C++17, Qt 6 Widgets |
| **Derleme** | CMake, Qt Creator (Qt 6.12.0, MinGW 64-bit) |

## Oyun Kuralları ve Özellikler

- Yapboz **25 parçadan (5×5)** oluşur ve her oyun başında parçalar **rastgele karıştırılır**.
- Bir parça **sürüklenip komşu bir parçanın üzerine bırakıldığında** iki parça yer değiştirir.
  - Yatay, dikey ve çapraz komşular geçerlidir; komşu olmayan parçalarla yer değiştirilemez.
- Her başarılı yer değiştirmede **hamle sayacı** bir artar.
- Sağ panelde, hedef olarak **resmin tamamı** gösterilir.
- Tüm parçalar doğru yerine oturduğunda, kaç hamlede bitirildiğini gösteren bir **tebrik mesajı** açılır.

## Proje Yapısı

```
├── CMakeLists.txt     # CMake derleme yapılandırması
├── main.cpp           # Uygulamanın giriş noktası
├── mainwindow.h       # Ana pencere sınıf tanımı
├── mainwindow.cpp     # Arayüz düzeni, karıştırma, hamle sayacı ve bitiş kontrolü
├── mainwindow.ui      # Qt Designer arayüz dosyası
├── parca.h            # Yapboz parçası (QLabel) sınıf tanımı
├── parca.cpp          # Sürükle-bırak, komşuluk kontrolü ve yer değiştirme
├── images.qrc         # Resimlerin uygulamaya gömülmesi
└── images/            # 25 parça görseli (0–24.png) ve resmin tamamı (puzzle.jpg)
```

## Derleme ve Çalıştırma

### Depoyu klonlama
```bash
git clone https://github.com/ramazanerentepe/yapboz-oyunu.git
cd yapboz-oyunu
```

### Qt Creator ile
1. [Qt 6](https://www.qt.io/download) ve Qt Creator'ı kurun.
2. Qt Creator'da **File → Open File or Project** ile `CMakeLists.txt` dosyasını açın.
3. Bir kit seçin (ör. *Desktop Qt 6.x MinGW 64-bit*) ve **Run** (Ctrl+R) ile çalıştırın.

### Komut satırı ile
```bash
cmake -S . -B build -DCMAKE_PREFIX_PATH="<Qt kurulum yolu>/6.x/mingw_64"
cmake --build build
```

## Hazır Sürüm (Windows)

Qt kurmadan çalıştırmak için derlenmiş sürüm, deponun [**Releases**](https://github.com/ramazanerentepe/yapboz-oyunu/releases) bölümünden zip olarak indirilebilir. Zip'i açıp `YapbozOyunu.exe` dosyasını çalıştırmanız yeterlidir.

> [!WARNING]
> Uygulama dijital olarak imzalanmadığı için Windows SmartScreen ilk açılışta
> **"Windows bilgisayarınızı korudu"** uyarısı gösterebilir. Bu, imzasız uygulamalar
> için normaldir. Çalıştırmak için **Ek bilgi → Yine de çalıştır** seçeneğine tıklayın.

## Lisans

Bu proje [Apache License 2.0](LICENSE) ile lisanslanmıştır.
