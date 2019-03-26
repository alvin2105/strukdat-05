/*
Nama program	: EXERCISE-05 ( DOUBLE linked list)
Nama			: Alvin
NPM				: 140810180013
tanggal			: 26 Maret 2019
Deskripsi		: DOUBLEList
tahun			: 2019
*/

#include<iostream>
using namespace std;

struct Pembalap {
   int nomor;
   char nama[20];
   int waktu;
   Pembalap* next;
   Pembalap* prev;
};
void createNode(Pembalap* &p,  int nomor, char nama){
	p= new Pembalap;
	cout<<"Masukkan nomor	: ";
	cin>>p->nomor;
	cout<<"Masukkan nama: ";
	cin>>p->nama;
	cout<<"masukan waktu : ";
	cin>>p->waktu;
	p->next=NULL;
	p->prev=NULL;
}
void insertFirst(Pembalap* &head, Pembalap* node){
	 if (head==NULL){
        head=node;
    }
    else {
        node->next=head;
        head=node;
    }
}

// delete a node that have the key
void deleteByKey(Pembalap* &head, int nomorKey, Pembalap* &deletedNode);
void search(Pembalap* &firstNode, int nomorKey, Pembalap* &pToUpdate){
	 pToUpdate=firstNode;
    while(pToUpdate->nomor!=nomorKey){
        pToUpdate=pToUpdate->next;
    }
}
// insert before a node
void insertBefore(Pembalap* &head, int nomorKey, Pembalap* node){
	  Pembalap* searching;
    search(head,nomorKey,searching);
    if (head==NULL){
        head=node;
    }
    else {
        node->next=searching;
        node->prev=searching->prev;
        searching->prev->next=node;
        searching->prev=node;   
    }
}
void traversal(Pembalap* head){
	  Pembalap* help;
    if (head==NULL){
        cout<<"***LIST KOSONG***\n";
    }
    else {
        help=head;
        while(help!=NULL){
            cout<<"Nomor: "<<help->nomor<<endl;
            cout<<"Nama: "<<help->nama<<endl;
            cout<<"Waktu: "<<help->waktu<<endl;
            cout<<endl;
            help=help->next;
        }
    }
}
// sorting ascending
void sortingByNomor(Pembalap* &head);
// update Pembalap from user input
void update(Pembalap* firstNode, int nomorKey);



int main() {
 Pembalap* head = NULL;
 Pembalap* pBaru = NULL;
 Pembalap* pToUpdate = NULL;

 char nama = 'a';

 for (int i = 0; i < 4; i++) {
   createNode(pBaru, i+1, nama++);
   insertFirst(head, pBaru);
 }

 cout << "\n>>> List" << endl;
 traversal(head);

 int keyNomor = 2;

 cout << "\n>>> Insert Before nomor " << keyNomor << endl;
 createNode(pBaru, 99, 'z');
 insertBefore(head, keyNomor, pBaru); 
 traversal(head);
 /*cout << "\n>>> SortingByNomor" << endl;
 sortingByNomor(head);
 traversal(head);

 keyNomor = 3;
 cout << "\n>>> Delete nomor " << keyNomor << endl;
 Pembalap* pHapus = NULL;
 deleteByKey(head, keyNomor, pHapus);
 traversal(head);

 keyNomor = 4;
 cout << "\n>>> Update nomor " << keyNomor << endl;
 update(head, keyNomor);

 cout << "\n>>> Updated list\n";
 traversal(head);
 */
}
