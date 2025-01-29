# C Stack Library

Bu, taşınabilir, tek başlık (one-header) formatında yazılmış bir Stack (Yığın) veri yapısı kütüphanesidir. Herhangi bir türdeki verilerle çalışabilir ve C dilinde genel kullanım için uygundur.

## Özellikler

- Taşınabilir: Tek bir header dosyasında yazılmıştır. Bu sayede farklı projelere kolayca entegre edilebilir.
- Dinamik Bellek Yönetimi: Yığın (stack) belleği dinamik olarak yönetir ve her tür veri tipi için uygundur.
- Inline Fonksiyonlar: Performans artırmak için fonksiyonlar inline olarak yazılmıştır.
- C Standart Kütüphaneleri Kullanımı: malloc, free, memcpy gibi standart C fonksiyonları ile bellek yönetimi sağlanır.

## Kullanım

### Başlangıç

Yığın veri yapısını kullanmak için önce ```cstack.h``` dosyasını projene dahil etmen yeterlidir.

``` c
#include "cstack.h"
```

### Stack Oluşturma

Yığın (stack) oluşturmak için ```createStack``` fonksiyonunu kullanabilirsiniz. Bu fonksiyon, her tür veri tipi için çalışacak şekilde genel olarak tasarlanmıştır.

``` c
stack_t* stack = createStack(sizeof(Data), max_size);
```

### Eleman Ekleme

Yığına eleman eklemek için ```push``` fonksiyonunu kullanabilirsiniz.

```c
push(stack, &data);
```

### Eleman Çekme

Yığından bir eleman çıkarmak için ```pop``` fonksiyonu kullanılır.

```c
pop(stack, &out_data);
```

### Yığının Zirvesindeki Elemanı Görüntüleme

Yığının zirvesindeki elemanı kontrol etmek için ```peek``` fonksiyonu kullanılır.

```c
peek(stack, &out_data);
```

### Yığının Boş Olup Olmadığını Kontrol Etme

Yığının boş olup olmadığını kontrol etmek için ```isEmpty``` fonksiyonunu kullanabilirsiniz.

```c
if (isEmpty(stack)) {
    printf("Stack is empty\n");
}
```

### Yığını Serbest Bırakma

Belleği serbest bırakmak için ```freeStack``` fonksiyonunu kullanabilirsiniz.

```c
freeStack(stack);
```

## Katkı Kılavuzu (Contributing Guidelines)

Eğer bu projeye katkıda bulunmak isterseniz, lütfen aşağıdaki adımları izleyin:

1. Fork Yapın: Projeyi GitHub üzerinde fork edin.
2. Değişiklik Yapın: Kendi kopyanızda istediğiniz değişiklikleri yapın.
3. Pull Request Gönderin: Değişikliklerinizi bu projeye dahil edilmesi için pull request olarak gönderin. Katkılarınız için teşekkür ederiz!
4. Kodunuzu Açık Kaynak Yapın: Lütfen yaptığınız değişikliklerin açık kaynak olmasını sağlayın. Bu, yazılımın herkes tarafından erişilebilir ve geliştirilebilir olmasını garanti eder.
