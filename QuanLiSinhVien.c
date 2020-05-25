#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct SinhVien
{
    char MaSV[9];
    char TenSV[20];
    float dtb;
}SinhVien;

typedef struct Node
{
    SinhVien info;
    struct Node *next;
}Node;

Node *phead = NULL;

Node* MakeNode(SinhVien sv)
{
    Node *n = (Node*)malloc(sizeof(Node));
    if(n == NULL)
    {
        printf("\n Bo nho khong du ");
        return 0;
    }
    n->info = sv;
    n->next = NULL;
    return n;
}

void ThemSV(SinhVien sv);
void Nhap();
void In();
void Tim();
void Xoa();
void xuatFile();

/* int main(): Chuognw trình chính
 * p: con trỏ
 * chon: lựa chon cua bạn
 * sv: kiểu dữ liệu SinhVien
 */
int main()
{
    Node *p;
    char chon;
    SinhVien sv;
    Nhap();
    while (1)
    {
        system("cls");
        printf("\n\t\t MENU");
        printf("\n\t 1. In ds");
        printf("\n\t 2. Tim sv");
        printf("\n\t 3. Xoa sv");
        printf("\n\t 4. Them sv");
        printf("\n\t 5. xuat file sv");
        printf("\n\t Nhap 0 de thoat \n");
        printf("\nNhap lua chon cua ban: ");
        fflush(stdin);
        scanf("%d", &chon);
        if (chon == 0)
        {
            xuatFile();
            printf("\nBan da xuat file thanh cong! \n");
            printf("Cam on ban da dung chuong trinh! \n");
            printf("Chuc ban mot ngay vui ve!");
            break;
        }
        switch(chon)
        {
            case 1:
            {
                In();
                break;
            }
            case 2:
            {
                Tim();
                break;
            }
            case 3:
            {
                Xoa();
                printf("\nDs sau khi xoa: ");
                In();
                break;
            }
            case 4:
            {
                fflush(stdin);
                printf(" Nhap ma sinh vien: ");
                gets(sv.MaSV);
                printf(" Nhap ten sinh vien: ");
                gets(sv.TenSV);
                printf(" Diem trung binh: ");
                scanf("%f \n",&sv.dtb);
                fflush(stdin);
                ThemSV(sv);
                break;
            }
            case 5:
            {
                xuatFile();
                printf("Ban da xuat file thanh cong!");
                getch();
                break;
            }
        }
    }
    free(p);
    return 0;
}

/* void ThemSV(SinhVien sv): Them mot sinh vien
 * param sv: kieu du lieu SinhVien
 * p: con trỏ
 */
void ThemSV(SinhVien sv)
{
    Node *p;
    if(phead == NULL) /*Neu 1 linked list chua duoc khoi tao*/
    {
        phead = MakeNode(sv);
    }
    else
    {
        p = phead;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = MakeNode(sv);
    }
}

/* void Nhap(): Nhập danh sach sinh vien khi chương trình bắt đầu
 * sv: kieu du lieu SinhVien
 * n: số lượng sinh vien
 */
void Nhap()
{
    int n;
    SinhVien sv;
    printf("\nNhap so luong sinh vien: ");
    scanf("%d",&n);
    fflush(stdin);

    for( int i = 0; i < n; i++)
    {
        printf("Sau khi nhap xong 1 sinh vien, ban hay nham dau cham(.) va enter de tiep tuc! \n");
        printf(" Nhap ma sinh vien: ");
        fflush(stdin);
        gets(sv.MaSV);
        printf(" Nhap ten sinh vien: ");
        fflush(stdin);
        gets(sv.TenSV);
        printf(" Diem trung binh: ");
        scanf("%f \n", &sv.dtb);
        fflush(stdin);
        ThemSV(sv);
    }
}

/* void In(): In danh sach sinh vien
 * p: con trỏ
 */
void In()
{
    Node *p = phead;
    printf("\nMaSV       TenSV               dtb \n");
    while(p != NULL)
    {
        printf("%-10s %-19s %.1f \n", p->info.MaSV, p->info.TenSV, p->info.dtb);
        p = p->next;
    }
    getch();
}

/* void Tim(): Tim sinh vien
 * p: con trỏ
 * x: mã sinh vien can tim
 */
void Tim()
{
    Node *p;
    p = phead;
    char x[8];
    printf(" \n Thong tin sinh vien can tim: \n");
    printf(" Nhap ma sinh vien can tim: ");
    fflush(stdin);
    gets(x);
    printf("\nMaSV       TenSV               dtb \n");
    while(p != NULL)
    {
        if(strcmp(phead->info.MaSV, x) == 0)/*Neu muon tim sinh vien dau tien*/
        {
            printf("%-10s %-19s %.1f \n", phead->info.MaSV, phead->info.TenSV, phead->info.dtb);
            getch();
            return;
        }
        if (p->next == NULL)
        {
            printf("Khong tim thay!!!");
            getch();
            break;
        }
        if(strcmp(p->next->info.MaSV, x) == 0)
        {
            printf("%-10s %-19s %.1f \n", p->next->info.MaSV, p->next->info.TenSV, p->next->info.dtb);
            getch();
            return;
        }
        p = p->next;
    }
}

/* void Xoa(): Xoa sinh vien
 * p: con trỏ
 * x: mã sinh vien can tim
 */
void Xoa()
{
    Node *p;
    p = phead;
    printf(" \n Thong tin sinh vien can xoa: \n");
    char x[8];
    printf(" Nhap ma sinh vien can xoa: ");
    fflush(stdin);
    gets(x);
    printf("Ban se xoa sinh vien nay!");
    printf("\nMaSV       TenSV               dtb \n");
    while(p!=NULL)
    {
        if(strcmp(phead->info.MaSV, x) == 0)/*Neu muon tim sinh vien dau tien*/
        {
            printf("%-10s %-19s %.1f \n", phead->info.MaSV, phead->info.TenSV, phead->info.dtb);
            phead = phead->next;
            getch();
            return;
        }
        if (p->next == NULL)
        {
            printf("Khong tim thay!!!");
            getch();
            break;
        }
        if(strcmp(p->next->info.MaSV, x) == 0)
        {
            printf("%-10s %-19s %.1f \n", p->next->info.MaSV, p->next->info.TenSV, p->next->info.dtb);
            p->next = p->next->next;
            return;
        }
        p = p->next;
    }
}

/* void xuatFile(): Xuat vao file QuanLiSinhVien.txt
 * fp: con trỏ
 */
void xuatFile()
{
    FILE *fp;
    Node *p = phead;
    fp = fopen("C:\\Users\\BinhAn\\Desktop\\lap trinh C online\\QuanLiSinhVien.txt", "w");
    fprintf(fp, "\nMaSV       TenSV               dtb \n");
    while(p != NULL)
    {
        fprintf(fp, "%-10s %-19s %.1f \n", p->info.MaSV, p->info.TenSV, p->info.dtb);
        p = p->next;
    }
    fclose(fp);
}
