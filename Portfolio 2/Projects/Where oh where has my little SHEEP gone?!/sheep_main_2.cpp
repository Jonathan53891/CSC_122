#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
   ifstream file("data.txt");
   string a,word[10];
   int i=0,l=0;
   srand(time(NULL));
   while(!file.eof())
   {
       file>>a;
       if(l<a.length()) //to find the longest word length
           l=a.length();
       word[i++]=a;
   }
   i--;
   int size=l+1; //grid size wil be length of longest word + 1
   char grid[size][size];
   int gridc[size][size]={0}; //gridc is used in order to track the letters which are crossed by other word. so that the same letter is not written and when deallocated the letter is not removed which might affect other word
   for(int x=0;x<size;x++)
       for(int y=0;y<size;y++)
           grid[x][y]='0';
  
   //placing the words in the grid word by word
   for(int k=0;k<i;k++)
   {
       int length=word[k].length();
       int j=rand()%3;
      
       switch(j)
       {
           //horizontal
           case 0:
               {
                   int r=rand()%size;   //to find the row to start the word
                   int c=rand()%(size-length); // this is find the column to start the word
                   for(int m=0;m<length;m++)
                   {
                   //if cell is empty then allocate letter
                       if(grid[r][c]=='0')
                           grid[r][c++]=word[k][m];
                           //if the cell contains the same letter of the word already then update gridc to track that letter belongs to some other word also
                       else if(grid[r][c]==word[k][m])
                       {
                           gridc[r][c]=1;
                           c++;
                       }  
                       else
                       {
                           //to deallocate the allocated letters
                           for(int n=m;n>=0;n--)
                           {
                               if(gridc[r][--c]==0)
                                   grid[r][c]='0';
                           }
                          
                           k--; //going back to the same word and processing
                           break ;
                       }
                      
                   }
                   break;
               }
           //vertical
           case 1:
               {
                   int r=rand()%(size-length);   //to find the row to start the word
                   int c=rand()%size; // this is find the column to start the word
                   for(int m=0;m<length;m++)
                   {
                       //if cell is empty then allocate letter
                       if(grid[r][c]=='0')
                           grid[r++][c]=word[k][m];
                       //if the cell contains the same letter of the word already then update gridc to track that letter belongs to some other word also
                       else if(grid[r][c]==word[k][m])
                       {
                           gridc[r][c]=1;
                           r++;
                       }  
                       else
                       {
                           //to deallocate the allocated letters
                           for(int n=m;n>=0;n--)
                           {
                               if(gridc[--r][c]==0)
                                   grid[r][c]='0';
                           }
                           k--;//going back to the same word and processing
                           break ;
                       }
                   }
                   break;
               }
           //diagonal
           case 2:
               {
                   int r=rand()%(size-length);   //to find the row to start the word
                   int c=rand()%(size-length); // this is find the column to start the word
                   for(int m=0;m<length;m++)
                   {
                   //if cell is empty then allocate letter
                       if(grid[r][c]=='0')
                           grid[r++][c++]=word[k][m];
                           //if the cell contains the same letter of the word already then update gridc to track that letter belongs to some other word also
                       else if(grid[r][c]==word[k][m])
                       {
                           gridc[r][c]=1;
                           r++;
                           c++;
                       }
                      
                       else
                       {
                           //to deallocate the allocated letters
                           for(int n=m;n>=0;n--)
                           {
                               if(gridc[--r][--c]==0)
                                   grid[r][c]='0';
                           }
                           k--;//going back to the same word and processing
                           break ;
                       }
                   }
                   break;
               }
       }
   }
   //to fill the empty cells with random letters
   srand(time(NULL));
   for(int x=0;x<size;x++)
       for(int y=0;y<size;y++)
       {
           if(grid[x][y]=='0')
           {
          
               int val=rand()%26;
               val+=97;
               grid[x][y]=val;
           }
       }
          
      
   //to print the grid puzzle  
   for(int x=0;x<size;x++)
   {
       cout<<endl;
       for(int y=0;y<size;y++)
           cout<<grid[x][y]<<" ";
   }              
   return 0;
}
