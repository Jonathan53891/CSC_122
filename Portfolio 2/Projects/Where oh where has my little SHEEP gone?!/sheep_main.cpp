#include<iostream>

#include<fstream>

#include<ctime>

#include<cstdlib>

using namespace std;

int main()

{

    ifstream file("input.txt");

    string a1,word123[10];

    int k=0,l1=0;

    srand(time(NULL));

    while(!file.eof())

    {

        file>>a1;

        if(l1<a1.length())

            l1=a1.length();

        word123[k++]=a1;

    }

    k--;

    int size1=l1+1;

    char grid[size1][size1];

    int gridc[size1][size1];

    for(int x1=0;x1<size1;x1++)

        for(int y1=0;y1<size1;y1++)

            grid[x1][y1]='0';

  

   

    for(int k1=0;k1<k;k1++)

    {

        int length=word123[k1].length();

        int j1=rand()%3;

      

        switch(j1)

        {

          

            case 0:

                {

                    int row=rand()%size1;  

                    int col=rand()%(size1-length);

                    for(int m1=0;m1<length;m1++)

                    {

                  

                        if(grid[row][col]=='0')

                            grid[row][col++]=word123[k1][m1];

                         

                        else if(grid[row][col]==word123[k1][m1])

                        {

                            gridc[row][col]=1;

                            col++;

                        }

                        else

                        {

                           

                            for(int n=m1;n>=0;n--)

                            {

                                if(gridc[row][--col]==0)

                                    grid[row][col]='0';

                            }

                          

                            k1--;

                            break ;

                        }

                      

                    }

                    break;

                }

          

            case 1:

                {

                    int row=rand()%(size1-length);  

                    int col=rand()%size1;

                    for(int m1=0;m1<length;m1++)

                    {

                    

                        if(grid[row][col]=='0')

                            grid[row++][col]=word123[k1][m1];

                      

                        else if(grid[row][col]==word123[k1][m1])

                        {

                          gridc[row][col]=1;

                            row++;

                        }

                        else

                        {

                          

                            for(int n=m1;n>=0;n--)

                            {

                                if(gridc[--row][col]==0)

                                    grid[row][col]='0';

                            }

                            k1--;

                            break ;

                        }

                    }

                    break;

                }

            //diagonal

            case 2:

                {

                    int row=rand()%(size1-length);  

                    int col=rand()%(size1-length);

                    for(int m1=0;m1<length;m1++)

                    {

                 

                        if(grid[row][col]=='0')

                            grid[row++][col++]=word123[k1][m1];

                          

                        else if(grid[row][col]==word123[k1][m1])

                        {

                            gridc[row][col]=1;

                            row++;

                            col++;

                        }

                      

                        else

                        {

                           

                            for(int n=m1;n>=0;n--)

                            {

                                if(gridc[--row][--col]==0)

                                    grid[row][col]='0';

                            }

                            k1--;

                            break ;

                        }

                    }

                    break;

                }

        }

    }

  

    srand(time(NULL));

    for(int x1=0;x1<size1;x1++)

        for(int y1=0;y1<size1;y1++)

        {

            if(grid[x1][y1]=='0')

            {

          

                int value=rand()%26;

                value+=97;

                grid[x1][y1]=value;

            }

        }

          

    for(int x1=0;x1<size1;x1++)

    {

        cout<<endl;

        for(int y1=0;y1<size1;y1++)

            cout<<grid[x1][y1]<<" ";

    }             

    return 0;

}
