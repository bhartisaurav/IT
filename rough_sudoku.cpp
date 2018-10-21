#include<iostream>
#include<algorithm>
#include<list>
#include<conio.h>
using namespace std;
list<int> mylist[10];                         //track of missing number in a block.
void make_list(int A[10],int index)           //preparing the list.
{

    for( int i=1;i<=9;i++)
    {
        if(A[i]!=1)
            mylist[index].push_back(i);
           A[i]=0;

    }



}

bool is_empty_list()
{


    if((!mylist[2].empty())||(!mylist[3].empty())||(!mylist[4].empty())||(!mylist[5].empty())||(!mylist[6].empty())||(!mylist[7].empty())||(!mylist[8].empty())||(!mylist[9].empty()))
        {
            return false;
        }
    else
        return true;
}
int main()
{
int matrix[10][10];            // matrix for sudoku
int poss_num[10];
fill_n(poss_num+1,9,0);
for(int i=1;i<=9;i++)          // taking input in a matrix
{
    for(int j=1;j<=9;j++)
    {
        cout<<"("<<i<<","<<j<<"): ";
        cin>>matrix[i][j];
     }
        cout<<endl;
}
cout<<"Entered Sudoku\n";
for(int i=1;i<=9;i++)          // showing matrix entered by user
{
    for(int j=1;j<=9;j++)
        cout<<matrix[i][j]<<" |";

    cout<<endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int  row=1,col=1,k=1,i,j;

for(i=row;i<row+3;i++)
{

    for( j=col;j<col+3;j++)
    {
       // cout<<"("<<i<<","<<j<<")";
        if(matrix[i][j]!=0)
        poss_num[matrix[i][j]]=1;
    }

    if((i-row+1)*(j-col)==9&&(i*(j-1)!=81))   // i-row+1=3,j-col+1=3 hence 3*3=9(no. of cells in a block),termination cond. if i=9,j=9
    {
        make_list(poss_num,k);
        if((j-1)==9&&i!=9)                  //j means columns, j-1 i.e when j gets out of loop it get incremented by 1, so subtracted it by 1.
        {                                  // if 3 blocks are accessed row wise,then check the other 3 blocks of next row.
            row+=3;
            col=1;
            i=row-1;                       //to check the next rows of blocks.
        }
        else
        {                                 //j!=9&&i!=9
            col+=3;
            i=row-1;                      ////to check the next rows of blocks.
        }
        ++k;
    }
    if(i*(j-1)==81)
        make_list(poss_num,k);
}

////////////////////////////////////////main code/////////////////////////////////////////////////////////////////////


int blk=1,count=0,it=1,m=1,n=1,flag=0,ele,pos_i,pos_j;
int high;
while(!is_empty_list())
{

blk=1;
high=mylist[blk].size();
while(it<=high)
{
    ele=mylist[blk].front();
    for(i=1;i<=3;i++)                   //1st block
    {

        for( j=1;j<=3;j++)
        {


            if(matrix[i][j]==0)
            {

                   for(int a=i,b=n;b<=9;b++)
                   {

                       if(ele==matrix[a][b])
                           flag=1;

                   }
                   if(flag==0)
                   {

                        for(int a=m,b=j;a<=9;a++)
                        {

                            if(ele==matrix[a][b])
                                flag=1;

                        }

                        if(flag==0)
                        {

                           count++;
                           pos_i=i,pos_j=j;
                        }
                        flag=0;
                   }
            }

        flag=0;
        }


    }
    if(count!=1)
            {

                mylist[blk].pop_front();
                int k=mylist[blk].front();

                mylist[blk].push_back(ele);
            }
            else
             if(count==1)
            {
                mylist[blk].pop_front();

                matrix[pos_i][pos_j]=ele;
            }
    it++;
    count=0;
    flag=0;

    if((it-1)==high)
    {

        if(high>mylist[blk].size())
            {
                it=1;
                high=mylist[blk].size();
            }
    }
}

blk=2,it=1;
high=mylist[blk].size();

while(it<=high)
{
    ele=mylist[blk].front();

    for(i=1;i<=3;i++)
    {

        for( j=4;j<=6;j++)
        {


            if(matrix[i][j]==0)
            {

                   for(int a=i,b=n;b<=9;b++)
                   {

                       if(ele==matrix[a][b])
                           flag=1;

                   }
                   if(flag==0)
                   {

                        for(int a=m,b=j;a<=9;a++)
                        {

                            if(ele==matrix[a][b])
                                flag=1;

                        }

                        if(flag==0)
                        {

                           count++;
                           pos_i=i,pos_j=j;
                        }
                        flag=0;
                   }
            }

        flag=0;
        }


    }
    if(count!=1)
            {

                mylist[blk].pop_front();
                int k=mylist[blk].front();

                mylist[blk].push_back(ele);
            }
            else
             if(count==1)
            {
                mylist[blk].pop_front();

                matrix[pos_i][pos_j]=ele;
            }
    it++;
    count=0;
    flag=0;

    if((it-1)==high)
    {

        if(high>mylist[blk].size())
            {
                it=1;
                high=mylist[blk].size();
            }
    }
}

blk=3,it=1;
high=mylist[blk].size();

while(it<=high)
{
    ele=mylist[blk].front();

    for(i=1;i<=3;i++)                   //1st block
    {

        for( j=7;j<=9;j++)
        {


            if(matrix[i][j]==0)
            {

                   for(int a=i,b=n;b<=9;b++)
                   {

                       if(ele==matrix[a][b])
                           flag=1;

                   }
                   if(flag==0)
                   {

                        for(int a=m,b=j;a<=9;a++)
                        {

                            if(ele==matrix[a][b])
                                flag=1;

                        }

                        if(flag==0)
                        {

                           count++;
                           pos_i=i,pos_j=j;
                        }
                        flag=0;
                   }
            }

        flag=0;
        }


    }
    if(count!=1)
            {

                mylist[blk].pop_front();
                int k=mylist[blk].front();

                mylist[blk].push_back(ele);
            }
            else
             if(count==1)
            {
                mylist[blk].pop_front();

                matrix[pos_i][pos_j]=ele;
            }
    it++;
    count=0;
    flag=0;

    if((it-1)==high)
    {

        if(high>mylist[blk].size())
            {
                it=1;
                high=mylist[blk].size();
            }
    }
}

blk=4,it=1;
high=mylist[blk].size();

while(it<=high)
{
    ele=mylist[blk].front();

    for(i=4;i<=6;i++)                   //1st block
    {

        for( j=1;j<=3;j++)
        {


            if(matrix[i][j]==0)
            {

                   for(int a=i,b=n;b<=9;b++)
                   {

                       if(ele==matrix[a][b])
                           flag=1;

                   }
                   if(flag==0)
                   {

                        for(int a=m,b=j;a<=9;a++)
                        {

                            if(ele==matrix[a][b])
                                flag=1;

                        }

                        if(flag==0)
                        {

                           count++;
                           pos_i=i,pos_j=j;
                        }
                        flag=0;
                   }
            }

        flag=0;
        }


    }
    if(count!=1)
            {

                mylist[blk].pop_front();
                int k=mylist[blk].front();
                mylist[blk].push_back(ele);
            }
            else
             if(count==1)
            {
                mylist[blk].pop_front();

                matrix[pos_i][pos_j]=ele;
            }
    it++;
    count=0;
    flag=0;

    if((it-1)==high)
    {

        if(high>mylist[blk].size())
            {
                it=1;
                high=mylist[blk].size();
            }
    }
}

blk=5,it=1;
high=mylist[blk].size();

while(it<=high)
{
    ele=mylist[blk].front();

    for(i=4;i<=6;i++)
    {

        for( j=4;j<=6;j++)
        {


            if(matrix[i][j]==0)
            {

                   for(int a=i,b=n;b<=9;b++)
                   {

                       if(ele==matrix[a][b])
                           flag=1;

                   }
                   if(flag==0)
                   {

                        for(int a=m,b=j;a<=9;a++)
                        {

                            if(ele==matrix[a][b])
                                flag=1;

                        }

                        if(flag==0)
                        {

                           count++;
                           pos_i=i,pos_j=j;
                        }
                        flag=0;
                   }
            }

        flag=0;
        }


    }
    if(count!=1)
            {

                mylist[blk].pop_front();
                int k=mylist[blk].front();

                mylist[blk].push_back(ele);
            }
            else
             if(count==1)
            {
                mylist[blk].pop_front();

                matrix[pos_i][pos_j]=ele;
            }
    it++;
    count=0;
    flag=0;

    if((it-1)==high)
    {
        if(high>mylist[blk].size())
            {
                it=1;
                high=mylist[blk].size();
            }
    }
}


 blk=6,it=1;
high=mylist[blk].size();

while(it<=high)
{
    ele=mylist[blk].front();

    for(i=4;i<=6;i++)
    {

        for( j=7;j<=9;j++)
        {


            if(matrix[i][j]==0)
            {

                   for(int a=i,b=n;b<=9;b++)
                   {

                       if(ele==matrix[a][b])
                           flag=1;

                   }
                   if(flag==0)
                   {

                        for(int a=m,b=j;a<=9;a++)
                        {

                            if(ele==matrix[a][b])
                                flag=1;

                        }

                        if(flag==0)
                        {

                           count++;
                           pos_i=i,pos_j=j;
                        }
                        flag=0;
                   }
            }

        flag=0;
        }


    }
    if(count!=1)
            {

                mylist[blk].pop_front();
                int k=mylist[blk].front();
                mylist[blk].push_back(ele);
            }
            else
             if(count==1)
            {
                mylist[blk].pop_front();
                matrix[pos_i][pos_j]=ele;
            }
    it++;
    count=0;
    flag=0;

    if((it-1)==high)
    {

        if(high>mylist[blk].size())
            {
                it=1;
                high=mylist[blk].size();
            }
    }
}


blk=7,it=1;
high=mylist[blk].size();

while(it<=high)
{
    ele=mylist[blk].front();

    for(i=7;i<=9;i++)                   //1st block
    {

        for( j=1;j<=3;j++)
        {


            if(matrix[i][j]==0)
            {

                   for(int a=i,b=n;b<=9;b++)
                   {

                       if(ele==matrix[a][b])
                           flag=1;

                   }
                   if(flag==0)
                   {

                        for(int a=m,b=j;a<=9;a++)
                        {

                            if(ele==matrix[a][b])
                                flag=1;

                        }

                        if(flag==0)
                        {

                           count++;
                           pos_i=i,pos_j=j;
                        }
                        flag=0;
                   }
            }

        flag=0;
        }


    }
    if(count!=1)
            {

                mylist[blk].pop_front();
                int k=mylist[blk].front();
                mylist[blk].push_back(ele);
            }
            else
             if(count==1)
            {
                mylist[blk].pop_front();

                matrix[pos_i][pos_j]=ele;
            }
    it++;
    count=0;
    flag=0;

    if((it-1)==high)
    {

        if(high>mylist[blk].size())
            {
                it=1;
                high=mylist[blk].size();
            }
    }
}


blk=8,it=1;
high=mylist[blk].size();

while(it<=high)
{
    ele=mylist[blk].front();

    for(i=7;i<=9;i++)                   //1st block
    {

        for( j=4;j<=6;j++)
        {


            if(matrix[i][j]==0)
            {

                   for(int a=i,b=n;b<=9;b++)
                   {

                       if(ele==matrix[a][b])
                           flag=1;

                   }
                   if(flag==0)
                   {

                        for(int a=m,b=j;a<=9;a++)
                        {

                            if(ele==matrix[a][b])
                                flag=1;

                        }

                        if(flag==0)
                        {

                           count++;
                           pos_i=i,pos_j=j;
                        }
                        flag=0;
                   }
            }

        flag=0;
        }


    }
    if(count!=1)
            {

                mylist[blk].pop_front();
                int k=mylist[blk].front();

                mylist[blk].push_back(ele);
            }
            else
             if(count==1)
            {
                mylist[blk].pop_front();

                matrix[pos_i][pos_j]=ele;
            }
    it++;
    count=0;
    flag=0;

    if((it-1)==high)
    {

        if(high>mylist[blk].size())
            {
                it=1;
                high=mylist[blk].size();
            }
    }
}


 blk=9,it=1;
high=mylist[blk].size();

while(it<=high)
{
    ele=mylist[blk].front();

    for(i=7;i<=9;i++)                   //1st block
    {

        for( j=7;j<=9;j++)
        {


            if(matrix[i][j]==0)
            {

                   for(int a=i,b=n;b<=9;b++)
                   {

                       if(ele==matrix[a][b])
                           flag=1;

                   }
                   if(flag==0)
                   {

                        for(int a=m,b=j;a<=9;a++)
                        {

                            if(ele==matrix[a][b])
                                flag=1;

                        }

                        if(flag==0)
                        {

                           count++;
                           pos_i=i,pos_j=j;
                        }
                        flag=0;
                   }
            }

        flag=0;
        }


    }
    if(count!=1)
            {

                mylist[blk].pop_front();
                int k=mylist[blk].front();

                mylist[blk].push_back(ele);
            }
            else
             if(count==1)
            {
                mylist[blk].pop_front();

                matrix[pos_i][pos_j]=ele;
            }
    it++;
    count=0;
    flag=0;

    if((it-1)==high)
    {

        if(high>mylist[blk].size())
            {
                it=1;
                high=mylist[blk].size();
            }
    }
}
cout<<endl;

}
cout<<"\n\nsolution of Sudoku:\n";
for(int x=1;x<=9;x++)          // showing matrix entered by user
{
    for(int y=1;y<=9;y++)
    {
        cout<<matrix[x][y];
        if((x==3||x==6)&&(y==3||y==6))
            cout<<"_||";
         else
         if(x==3||x==6)
            cout<<"_|";
         else
        if(y==3||y==6)
            cout<<" ||";
        else
            cout<<" |";
    }


    cout<<endl;
}
getch();

}
