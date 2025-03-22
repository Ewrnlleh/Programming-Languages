#include <stdio.h>
#define TOPLAM_TAKIM 6
#define MAX_LEN 100

typedef struct {
	int toplamAtilanIcGolSayisi;
	int toplamAtilanDisGolSayisi;
}AtilanGoller;

typedef struct {
	int toplamYenilenIcGolSayisi;
	int toplamYenilenDisGolSayisi;
}YenilenGoller;

typedef struct {
	int toplamIcPuan;
	int toplamDisPuan;
}Puanlar;

typedef struct {
	char takimIsmi[100];
	AtilanGoller atilanGoller;
	YenilenGoller yenilenGoller;
	Puanlar puanlar;
}Takim;


void takimlariIsimleriniAl(Takim takimlar[TOPLAM_TAKIM]);
void atilanYenilenIcGolleriAl(Takim takimlar[TOPLAM_TAKIM]);
int macSonucuPuani(int attigi, int yedigi);
int menuyuGoster();
void puanTablosunuGoster(Takim takimlar[TOPLAM_TAKIM]);
void icsahaPuanTablosunuGoster(Takim takimlar[TOPLAM_TAKIM]);
void deplasmanPuanTablosunuGoster(Takim takimlar[TOPLAM_TAKIM]);

int main()
{
	Takim takimlar[6];
	takimlariIsimleriniAl(takimlar);
	atilanYenilenIcGolleriAl(takimlar);
	int secim;
	while ((secim = menuyuGoster()) != 4) {
		switch (secim)
		{
		case 1:
			puanTablosunuGoster(takimlar);
			break;

		case 2:
			icsahaPuanTablosunuGoster(takimlar);
			break;

		case 3:
			deplasmanPuanTablosunuGoster(takimlar);
			break;

		default:
			break;
		}
	}

	printf("Sistem kapatiliyor!");

	return 0;
}
int menuyuGoster() {

	int secim;
	printf("\n*************************************\n");
	printf("\nMenu\n");
	printf("1-Puan Tablosu\n");
	printf("2-Ic Saha Puan Tablosu\n");
	printf("3-Deplasman Puan Tablosu\n");
	printf("4-Cikis\n");
	printf("\n*************************************\n");
	printf("Seciminizi giriniz: ");
	scanf("%d", &secim);
	
	return secim;
}

int macSonucuPuani(int attigi, int yedigi) {
	if (attigi > yedigi)
		return 3;
	if (yedigi > attigi)
		return 0;
	return 1;
}
void takimlariIsimleriniAl(Takim takimlar[TOPLAM_TAKIM])
{
	puts("Takimlari giriniz: ");
	for (int i = 0; i < TOPLAM_TAKIM; i++)
	{
		printf("%d. takim ismini giriniz: ", i + 1);
		scanf("%s", &takimlar[i].takimIsmi);

		takimlar[i].atilanGoller.toplamAtilanDisGolSayisi = 0;
		takimlar[i].atilanGoller.toplamAtilanIcGolSayisi = 0;

		takimlar[i].yenilenGoller.toplamYenilenDisGolSayisi = 0;
		takimlar[i].yenilenGoller.toplamYenilenIcGolSayisi = 0;

		takimlar[i].puanlar.toplamDisPuan = 0;
		takimlar[i].puanlar.toplamIcPuan = 0;
	}

}
void atilanYenilenIcGolleriAl(Takim takimlar[TOPLAM_TAKIM])
{
	puts("Gol Sayilarini Giriniz");
	for (int i = 0; i < TOPLAM_TAKIM; i++)
	{
		for (int j = 0; j < TOPLAM_TAKIM; j++)
		{
			if (j == i)
				continue;
			int atilanGol;
			int yenilenGol;
			printf("%s kulubunun %s kulubune attigi gol sayisini giriniz: ", takimlar[i].takimIsmi, takimlar[j].takimIsmi);
			scanf("%d", &atilanGol);
			printf("%s kulubunun %s kulubunden yedigi gol sayisini giriniz: ", takimlar[i].takimIsmi, takimlar[j].takimIsmi);
			scanf("%d", &yenilenGol);

			takimlar[i].atilanGoller.toplamAtilanIcGolSayisi += atilanGol;
			takimlar[i].yenilenGoller.toplamYenilenIcGolSayisi += yenilenGol;

			takimlar[j].atilanGoller.toplamAtilanDisGolSayisi += yenilenGol;
			takimlar[j].yenilenGoller.toplamYenilenDisGolSayisi += atilanGol;

			takimlar[i].puanlar.toplamIcPuan += macSonucuPuani(atilanGol, yenilenGol);
			takimlar[j].puanlar.toplamDisPuan += macSonucuPuani(yenilenGol, atilanGol);

		}
	}
}
void puanTablosunuGoster(Takim takimlar[TOPLAM_TAKIM])
{
	printf("\nPuan Tablosu\n\n");
	printf("[Takim]  |  [Attigi]  |  [Yedigi]  |  [Averaj]  |  [Puan]\n\n");
	for (int i = 0; i < TOPLAM_TAKIM; i++)
	{
		int puan = takimlar[i].puanlar.toplamDisPuan + takimlar[i].puanlar.toplamIcPuan;
		int atilanGolSayisi = takimlar[i].atilanGoller.toplamAtilanDisGolSayisi + takimlar[i].atilanGoller.toplamAtilanIcGolSayisi;
		int yenilenGolSayisi = takimlar[i].yenilenGoller.toplamYenilenDisGolSayisi + takimlar[i].yenilenGoller.toplamYenilenIcGolSayisi;

		printf("[%s]\t  |  %d  |  %d  |  %d  |  %d\n", takimlar[i].takimIsmi, atilanGolSayisi, yenilenGolSayisi, atilanGolSayisi-yenilenGolSayisi, puan);
	}
}
void icsahaPuanTablosunuGoster(Takim takimlar[TOPLAM_TAKIM])
{
	printf("\nIc Saha Puan Tablosu\n\n");
	printf("[Takim]  |  [Attigi]  |  [Yedigi]  |  [Averaj]  |  [Puan]\n\n");
	for (int i = 0; i < TOPLAM_TAKIM; i++)
	{
		int puan = takimlar[i].puanlar.toplamIcPuan;
		int atilanGolSayisi = takimlar[i].atilanGoller.toplamAtilanIcGolSayisi;
		int yenilenGolSayisi = takimlar[i].yenilenGoller.toplamYenilenIcGolSayisi;

		printf("[%s]\t  |  %d  |  %d  |  %d  |  %d\n", takimlar[i].takimIsmi, atilanGolSayisi, yenilenGolSayisi, atilanGolSayisi - yenilenGolSayisi, puan);
	}
}
void deplasmanPuanTablosunuGoster(Takim takimlar[TOPLAM_TAKIM])
{
	printf("\nDis Saha Puan Tablosu\n\n");
	printf("[Takim]  |  [Attigi]  |  [Yedigi]  |  [Averaj]  |  [Puan]\n\n");
	for (int i = 0; i < TOPLAM_TAKIM; i++)
	{
		int puan = takimlar[i].puanlar.toplamDisPuan;
		int atilanGolSayisi = takimlar[i].atilanGoller.toplamAtilanDisGolSayisi;
		int yenilenGolSayisi = takimlar[i].yenilenGoller.toplamYenilenDisGolSayisi;

		printf("[%s]\t  |  %d  |  %d  |  %d  |  %d\n", takimlar[i].takimIsmi, atilanGolSayisi, yenilenGolSayisi, atilanGolSayisi - yenilenGolSayisi, puan);
	}
}
