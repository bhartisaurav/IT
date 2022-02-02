#include<iostream>
using namespace std;

float calMarks(float num)
{
   float minValue=1.5;
   float maxValue=2.4;

   float minMarks=7.5;
   float maxMarks=15.0;
  // cout<< num-minValue<<endl;
  // cout<<(num-minValue)/(maxValue-minValue)<<endl;
   float marks = minMarks+ ((num-minValue)/(maxValue-minValue))*(maxMarks-minMarks);
   //cout<<"Marks: "<<marks<<endl;

   return marks;
}
int main()
{
    int n; //number of student.
    cout<<"number of student: ";
    cin>>n;
    float arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"\n\nMarks:\n";
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=0)
            cout<<"0\n";
        else
        if(arr[i]<=1.50)
            cout<<"7.5\n";
        else
        if(arr[i]>=2.25)
            cout<<"15\n";
        else
        printf("%.2f\n",calMarks(arr[i]));
    }

}
