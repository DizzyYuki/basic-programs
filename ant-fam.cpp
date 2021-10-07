#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void Svijet(char svijet[][20])
{
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			svijet[i][j] = ' ';	
		}
	}
}


void Kopiranje_svjetova(char svijet[][20], char n_svijet[][20])
{
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			svijet[i][j] = n_svijet[i][j];
		}
	}
}



void Ciscenje(char n_svijet[][20])
{
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			n_svijet[i][j] = ' ';
		}
	}
}



void PopunjavanjeSvijeta(char svijet[][20], int broj_mrava, int broj_buba)
{
	int p, q;
	int pom1 = 0, pom2 = 0;
	srand(time(0));
	while(pom1 < broj_mrava)
	{
		p = rand() % 20;
		q = rand() % 20;
		if(svijet[p][q] == ' ')
		{
			svijet[p][q] = '8';
			pom1 = pom1 + 1;
		}
	}
	while(pom2 < broj_buba)
	{
		p = rand() % 20;
		q = rand() % 20;
		if(svijet[p][q] == ' ')
		{
			svijet[p][q] = '0';
			pom2 = pom2 + 1;
		}
	}
}


void Bube(char prati_b1[][20], char svijet[][20])
{
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			if(svijet[i][j] == '0')
			{
				prati_b1[i][j] = '0';
			}
			else
			{
				prati_b1[i][j] = ' ';
			}
		}
	}
}


void Printanje(char svijet[][20])
{
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			cout<<svijet[i][j];
		}
	cout<<endl;
	}
}


bool Granica(int a, int b)
{
	if(a < 0 or a > 19 or b < 0 or b > 19)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void Reprodukcija_mrava(char svijet[][20])
{
	char n_svijet[20][20];
	Ciscenje(n_svijet);
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			n_svijet[i][j] = svijet[i][j];
			if(svijet[i][j] == '8')
			{
				if(svijet[i-1][j] == ' ' and n_svijet[i-1][j] == ' ' and Granica((i-1), j) == false)
				{
					n_svijet[i-1][j] = '8';
				}
				else if(svijet[i+1][j] == ' ' and n_svijet[i+1][j] == ' ' and Granica((i+1), j) == false)
				{
					n_svijet[i+1][j] = '8';
				}
				else if(svijet[i][j-1] == ' ' and n_svijet[i][j-1] == ' ' and Granica(i, (j-1)) == false)
				{
					n_svijet[i][j+1] = '8';
				}
				else if(svijet[i][j+1] == ' ' and n_svijet[i][j+1] == ' ' and Granica(i, (j+1)) == false)
				{
					n_svijet[i][j+1] = '8';
				}
			}
		}
	}
	Kopiranje_svjetova(svijet, n_svijet);
}



void Reprodukcija_buba(char svijet[][20])
{
	char n_svijet[20][20];
	Ciscenje(n_svijet);
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			n_svijet[i][j] = svijet[i][j];
			if(svijet[i][j] == '0')
			{
				if(svijet[i-1][j] == ' ' and n_svijet[i-1][j] == ' ' and Granica((i-1), j) == false)
				{
					n_svijet[i-1][j] = '0';
				}
				else if(svijet[i+1][j] == ' ' and n_svijet[i+1][j] == ' ' and Granica((i+1), j) == false)
				{
					n_svijet[i+1][j] = '0';
				}
				else if(svijet[i][j-1] == ' ' and n_svijet[i][j-1] == ' ' and Granica(i, (j-1)) == false)
				{
					n_svijet[i][j+1] = '0';
				}
				else if(svijet[i][j+1] == ' ' and n_svijet[i][j+1] == ' ' and Granica(i, (j+1)) == false)
				{
					n_svijet[i][j+1] = '0';
				}
			}
		}
	}
	Kopiranje_svjetova(svijet, n_svijet);
}


void Kretanje(char svijet[][20], char prati_b1[][20])
{
	srand(time(0));
	int r, q;
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			q = rand() % 4 + 1;
			if(svijet[i][j] == '0')
			{
				if(prati_b1[i][j] == ' ')
				{
					prati_b1[i][j] = svijet[i][j];
				}
				if(svijet[i-1][j] == '8')
				{	
					svijet[i-1][j] = '0';
					svijet[i][j] = ' ';
					prati_b1[i-1][j] = '0';
					prati_b1[i][j] = ' ';
				}
				else if(svijet[i+1][j] == '8')
				{	
					svijet[i+1][j] = '0';
					svijet[i][j] = ' ';
					prati_b1[i+1][j] = '0';
					prati_b1[i][j] = ' ';
				}
				else if(svijet[i][j-1] == '8')
				{	
					svijet[i][j-1] = '0';
					svijet[i][j] = ' ';
					prati_b1[i][j-1] = '0';
					prati_b1[i][j] = ' ';
				}
				else if(svijet[i][j+1] == '8')
				{	
					svijet[i][j+1] = '0';
					svijet[i][j] = ' ';
					prati_b1[i][j+1] = '0';
					prati_b1[i][j] = ' ';
				}
				else
				{
					if(q == 1)
					{
						if(svijet[i-1][j] == ' ' and Granica((i-1), j) == false)
						{	
							svijet[i-1][j] = '0';
							svijet[i][j] = ' ';
							if(prati_b1[i][j] == '0')
							{
								prati_b1[i-1][j] = '1';
								prati_b1[i][j] = ' ';
							}
							else if(prati_b1[i][j] == '1')
							{
								prati_b1[i-1][j] = '2';
								prati_b1[i][j] = ' ';
							}
							else if(prati_b1[i][j] == '2')
							{
								svijet[i-1][j] = ' ';
								prati_b1[i][j] = ' ';
							}
						}
						else
						{
							if(prati_b1[i][j] == '0')
							{
								prati_b1[i][j] = '1';
							}
							else if(prati_b1[i][j] == '1')
							{
								prati_b1[i][j] = '2';
							}
							else if(prati_b1[i][j] == '2')
							{
								svijet[i][j] = ' ';
								prati_b1[i][j] = ' ';
							}
						}
					}
					else if(q == 2)
					{
						if(svijet[i+1][j] == ' ' and Granica((i+1), j) == false)
						{
							svijet[i+1][j] = '0';
							svijet[i][j] = ' ';
							if(prati_b1[i][j] == '0')
							{
								prati_b1[i+1][j] = '1';
								prati_b1[i][j] = ' ';
							}
							else if(prati_b1[i][j] == '1')
							{
								prati_b1[i+1][j] = '2';
								prati_b1[i][j] = ' ';
							}
							else if(prati_b1[i][j] == '2')
							{
								svijet[i+1][j] = ' ';
								prati_b1[i][j] = ' ';
							}
						}
						else
						{
							if(prati_b1[i][j] == '0')
							{
								prati_b1[i][j] = '1';
							}
							else if(prati_b1[i][j] == '1')
							{
								prati_b1[i][j] = '2';
							}
							else if(prati_b1[i][j] == '2')
							{
								svijet[i][j] = ' ';
								prati_b1[i][j] = ' ';
							}
						}
					}
					else if(q == 3)
					{
						if(svijet[i][j-1] == ' ' and Granica(i, (j-1)) == false)
						{
							svijet[i][j-1] = '0';
							svijet[i][j] = ' ';
							if(prati_b1[i][j] == '0')
							{
								prati_b1[i][j-1] = '1';
								prati_b1[i][j] = ' ';
							}
							else if(prati_b1[i][j] == '1')
							{
								prati_b1[i][j-1] = '2';
								prati_b1[i][j] = ' ';
							}
							else if(prati_b1[i][j] == '2')
							{
								svijet[i][j-1] = ' ';
								prati_b1[i][j] = ' ';
							}
						}
						else
						{
							if(prati_b1[i][j] == '0')
							{
								prati_b1[i][j] = '1';
							}
							else if(prati_b1[i][j] == '1')
							{
								prati_b1[i][j] = '2';
							}
							else if(prati_b1[i][j] == '2')
							{
								svijet[i][j] = ' ';
								prati_b1[i][j] = ' ';
							}
						}
					}
					else if(q == 4)
					{
						if(svijet[i][j+1] == ' ' and Granica(i, (j+1)) == false)
						{
							svijet[i][j+1] = '0';
							svijet[i][j] = ' ';
							if(prati_b1[i][j] == '0')
							{
								prati_b1[i][j+1] = '1';
								prati_b1[i][j] = ' ';
							}
							else if(prati_b1[i][j] == '1')
							{
								prati_b1[i][j+1] = '2';
								prati_b1[i][j] = ' ';
							}
							else if(prati_b1[i][j] == '2')
							{
								svijet[i][j+1] = ' ';
								prati_b1[i][j] = ' ';
							}
						}
						else
						{
							if(prati_b1[i][j] == '0')
							{
								prati_b1[i][j] = ' ';
							}
							else if(prati_b1[i][j] == '1')
							{
								prati_b1[i][j] = ' ';
							}
							else if(prati_b1[i][j] == '2')
							{
								svijet[i][j] = ' ';
								prati_b1[i][j] = ' ';
							}
						}
					}
				}
			}
		}
	}
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			r = rand() % 4 + 1;
			if(svijet[i][j] == '8')
			{
				if(r == 1)
				{
					if(svijet[i-1][j] == ' ' and Granica((i-1), j) == false)
					{
						svijet[i-1][j] = '8';
						svijet[i][j] = ' ';
					}
				}
				else if(r == 2)
				{
					if(svijet[i+1][j] == ' ' and Granica((i+1), j) == false)
					{
						svijet[i+1][j] = '8';
						svijet[i][j] = ' ';
					}
				}
				else if(r == 3)
				{
					if(svijet[i][j-1] == ' ' and Granica(i, (j-1)) == false)
					{
						svijet[i][j-1] = '8';
						svijet[i][j] = ' ';
					}
				}
				else if(r == 4)
				{
					if(svijet[i][j+1] == ' ' and Granica(i, (j+1)) == false)
					{
						svijet[i][j+1] = '8';
						svijet[i][j] = ' ';
					}
				}
			}
		}
	}
}


void Printaj(char svijet[][20])
{
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			cout<<svijet[i][j];
		}
		cout<<endl;
	}
}


void spavaj(int msekunde) 
{     
	clock_t cilj = msekunde + clock();
    while(cilj >= clock());
}


int main()
{
	char svijet[20][20], n_svijet[20][20];
	char prati_b1[20][20];
    srand(time(0));
    Svijet(svijet);
    PopunjavanjeSvijeta(svijet, 100, 5);
    Bube(prati_b1, svijet);
    for(int i = 0; i < 500; i++) 
	{
        Printanje(svijet);
        Kretanje(svijet, prati_b1);
        if(i % 3 == 0 and i != 0)
        {
        	Reprodukcija_mrava(svijet);
		}
		if(i % 8 == 0 and i != 0)
		{
			Reprodukcija_buba(svijet);
		}
        spavaj(40);
        system("cls");
    }
    return 0;
}
