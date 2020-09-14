#include <iostream>
using namespace std;
struct Student{
 int total_students;
 int roll;
 string name;
 int sgpa;
};
void swap(int* xp, int* yp)
{
 int temp = *xp;
 *xp = *yp;
 *yp = temp;
}
void bubbleSort(Student s[], int n)
{
 int i, j;
 for (i = 0; i < n-1; i++)
 for (j = 0; j < n-i-1; j++)
 if (s[j].roll > s[j+1].roll)
 swap(&s[j].roll, &s[j+1].roll);
}

void printArray1(Student s[], int size)
{
 int i;
 for (i = 0; i < size; i++)
 cout << s[i].roll<< " --- " << s[i].name<< " --- "<< s[i].sgpa << " "<< endl;
 cout << endl;
}


void Insertion_Sort(Student s[],int n){ 
 int minIndex;
 Student temp;
 for (int i=0;i<n-1;i++){
    minIndex=i;
    for(int j=i+1;j<n;j++){
    if (s[j].name<s[minIndex].name){
        temp=s[j];
        s[j]=s[minIndex];
        s[minIndex]=temp;
 }
 }
 temp=s[i];
 s[i]=s[minIndex];
 s[minIndex]=temp;
 }
 int i;
 for (i = 0; i < n; i++)
 cout << s[i].roll<< " --- " << s[i].name<< " --- "<< s[i].sgpa << " "<< endl;
}


void swapThe(int* a, int* b)
{
 int t = *a;
 *a = *b;
 *b = t;
}

int partition (Student s[], int low, int high)
{
 int pivot = s[high].sgpa; 
 int i = (low - 1); 
 
 for (int j = low; j <= high- 1; j++)
 {
 if (s[j].sgpa >= pivot)
 {
 i++; 
 swap(&s[i].sgpa, &s[j].sgpa);
 }
 }
 swapThe(&s[i + 1].sgpa, &s[high].sgpa);
 return (i + 1);
}
void quickSort(Student s[], int low, int high)
{
 if (low < high)
 {

 int pi = partition(s, low, high);


 }
}
void printArray(Student s[], int n) 
{
 cout << "List of top 10 students according to their marks " << endl;
 int i;
 for (i=0; i < 10; i++){
 cout << s[i].roll << ") " << s[i].name << "--->" <<
s[i].sgpa << endl;
 }

} 



void Search_sgpa(Student s[], int sgpa1, int n)
{
 int c=0;
 for(int i=0; i<n ; i++)
 {
 if(s[i].sgpa == sgpa1)
 cout<< s[i].roll<<"---"<<s[i].sgpa << " ---> "<< s[i].name << endl;
 c++;
 }
 if(c==0)
 cout << "No Student with given SGPA found"<< endl;
}

void binarySearch(Student s[], int n){

 string key;
 int loc;

 cout<<"Enter the student name to be searched : "; cin>>key;
 for (int i = 0; i< n; i++)
 {
 if(s[i].name == key)
 {
 loc = i+1;
 break;
 }
 else
 loc = 0;
 }
 if(loc != 0)
 {
 cout<<"Student found at position "<<loc<<" in the structure" <<endl;
 cout << s[loc-1].roll << ") " << s[loc-1].name << "--->"<<s[loc-1].sgpa << endl;
 }
 else
 {
 cout<<"Could not found the student details in the structure ,Please enter the right name";
 }
}




int main()
{
cout<<"enter number of records of Students: ";
int n;
int x;
cin>>n;
cout << "--------------------------------------------"<< endl;
Student s[n];
do
{
cout<<"1. Insert Record"<<"\n"<<"2. Bubble sort for sorting according to roll number"<<"\n"<<"3.Insertion Sort for sorting according to Alphabetical order of names"<<"\n"<<"4. Quick sort according to SGPA"<<"\n"<<"5. Search student by SGPA"<<"\n"<<"6. Search Student by Name"<<"\n";
cout << "--------------------------------------------"<< endl;
int m;
cout<<"Enter your choice ";
cin>>m;
cout << "--------------------------------------------"<< endl;
switch(m)
{
 case 1:
 {
 cout << "Enter information of students: " << endl;
 for(int i = 0; i < n; ++i)
 {
 cout << "Enter roll number of "<<i+1<<" student: ";
 cin >> s[i].roll;
 cout << "---------------------"<< endl;
 cout << "Enter name: ";
 cin >> s[i].name;
 cout << "---------------------"<< endl;
 cout << "Enter SGPA: ";
 cin >> s[i].sgpa;
 cout << "---------------------"<< endl;
 cout << endl;
 }
 cout << "-------------------------------------------------------------"<< endl;
 break;
 }
 case 2:
 {
//bubble sort
 cout << "Sorted List According to RollNumbers is: "<< endl;
 bubbleSort(s, n);
 printArray1(s, n);
 cout << "-------------------------------------------------------------"<< endl;
 break;
 }
 case 3:
 {
//insertion sort
 cout << "Sorted List According to Alphabetical order is: "<< endl;
 Insertion_Sort(s, n);
 cout << "-------------------------------------------------------------"<< endl;
 break;
 }
//quick sort
 case 4:
 quickSort(s,0,n-1);
 cout<< "sorted according to sgpa: "<<endl;
 printArray(s,n);
 cout << "-------------------------------------------------------------"<< endl;
 break;
 case 5:
{
// Search SGPA
 int SGPA;
 cout << "Enter SGPA to Search: "<< endl;
 cin >> SGPA ;
 Search_sgpa(s,SGPA,n);
 cout << "--------------------------------------------"<< endl;
 break;
}
//Name Search(Binary Search)
 case 6:
{
 
 binarySearch(s,n);
 cout << "--------------------------------------------"<< endl;
 break;
}
}
cout<<"enter 1 to continue or 0 to end: ";
cin>>x;
cout << "--------------------------------------------"<< endl;
}while(x!=0);
 return 0;
}


