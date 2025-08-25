# 🛠️ Custom Malloc (mymalloc & myfree)

Bu proje, C dilinde basit bir `malloc` ve `free` implementasyonu sunar.  
Amacım heap memory’nin **teorik çalışma mantığını bildiğim halde**, bunun **uygulamada nasıl işlediğini** öğrenmekti.  

## 🚀 Özellikler
- `mymalloc(size_t size)` → Heap’ten yeni bir blok ayırır.
- `myfree(void *ptr)` → Ayrılan bloğu serbest bırakır.
- Bellek bloklarının önünde metadata tutulur (`size`, `free`, `next`).
- Basit linked list yapısı ile serbest/dolu bloklar yönetilir.
- `sbrk` kullanılarak heap genişletilir.

## 📂 Proje Yapısı

custom-malloc/

│── src/

│ └── my_malloc.c

│── include/

│ └── my_malloc.h

│── test/

│ └── simple_usage.c

│── README.md

│── Makefile

## 🔧 Derleme ve Çalıştırma
```bash
make
./example
```
📌 Örnek Kullanım

#include "my_malloc.h"
#include <stdio.h>

int main() {
    int *arr = (int *)mymalloc(10 * sizeof(int));

    for (int i = 0; i < 10; i++) arr[i] = i * 2;

    for (int i = 0; i < 10; i++) printf("%d ", arr[i]);

    myfree(arr);
    return 0;
}

Çıktı:

0 2 4 6 8 10 12 14 16 18

🎯 Neden Bu Projeyi Yaptım?

Heap memory’nin teorik olarak nasıl çalıştığını bilsem de, uygulamada kendi bellek yöneticimi yazarak daha derin bir anlayış kazanmak istedim.
Bu proje sayesinde:

    Bellek yönetimi algoritmalarının nasıl çalıştığını,

    malloc/free arka planda neler yaptığını,

    Bellek parçalanmasının (fragmentation) neden oluştuğunu

deneyimleme fırsatı buldum.

