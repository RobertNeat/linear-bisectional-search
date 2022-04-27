#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
using namespace std;
struct student
{
    string name;
    string surname;
    int points;
};
void QuickSort(student* &arr, int left, int right);
void loadStudents(student*& arr, int n);
void deleteStudentsArray(student*& arr);
void displayStudents(student*& arr, int n);
void linearSearch(student*& arr, int n, int value);
void bisectionSearch(student*& arr,int n, int value);
int menu();
int value();
void line();
int main()
{
    student *t;
    int n=14;
    loadStudents(t, n);

    cout<<"#students.csv:"<<endl;
    displayStudents(t,n);

    switch(menu())
    {
    case 1:

            linearSearch(t, n, value());
           break;
    case 2:
            QuickSort(t, 0, n-1);

            bisectionSearch(t,n,value());
            break;

    }

    deleteStudentsArray(t);
    return 0;
}
void linearSearch(student*& arr, int n, int value)
{
    int counter = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i].points==value)
        {
            cout<<arr[i].name<<" "<<arr[i].surname<<endl;
            counter++;
        }

    }
    if(counter==0){
        cout<<"There is no student with that amount of points";
    }

}
void bisectionSearch(student*& arr, int n, int value)
{
    int l = 0;
    int p = n-1;
    int center;
    int counter=0;
    ofstream write;
    write.open("results.csv");
    while(l<=p){
        center=(int)(l+p)/2;

        if (arr[center].points==value){
            write<<arr[center].name<<";"<<arr[center].surname<<endl;
            cout<<arr[center].name<<" "<<arr[center].surname<<endl;
            counter++;
        }
        if (value < arr[center].points){
            p = center -1;
        }
        else{
            l = center +1;
        }

    }
    if(counter == 0){
        cout<<"There is no student with that amount of points";
        write<<"There is no student with that amount of points";
    }
    write.close();
}
void QuickSort(student *&x, int left, int right)
{

    if (right <= left) return;

    int i = left - 1, j = right + 1,
    center = (int)(left+right)/2;
    student pivot = x[center];

    while (i<=j){
        while(pivot.points > x[++i].points);
        while(pivot.points < x[--j].points);

        if ( i <= j ){
            swap(x[i], x[j]);
        }
        else{
            break;
        }
    }

    if ( j > left )
        QuickSort(x,left,j);

    if ( i < right )
        QuickSort(x,i,right);
}

void loadStudents(student *&arr, int n)
{
    int studentCount;
    string line,pomoc;
    fstream plik;
    char colons;

    plik.open("students.csv");
    plik>>studentCount;

    arr = new student[studentCount];
    for (int i =0; i < 2; i++)
        plik>>colons;

    for (int i=0; i<studentCount; i++){
        plik>>line;
        istringstream ss(line);
        getline(ss, arr[i].name, ';');
        getline(ss, arr[i].surname, ';');
        getline(ss, pomoc);
        arr[i].points=atoi(pomoc.c_str());
    }
    plik.close();

}
void displayStudents(student*& arr, int n){
    for (int i = 0; i < n; i++){
        cout<<arr[i].name<<" "<<arr[i].surname<<" "<<arr[i].points<<endl;
    }
}
void deleteStudentsArray(student*& arr){
    delete [] arr;
}
void line(){
    cout<<"\n-----------------------------------------------\n";
}
int menu(){
    int choice;
    line();
    cout<<"Menu:"<<endl<<"1. Linear search"<<endl<<"2. Bisection search"<<endl<<"Choosing:";
    cin>>choice;
    line();
    return choice;
}
int value(){
    int value;
    cout<<"What points record are you interested in: ";
    cin>>value;
    return value;
}