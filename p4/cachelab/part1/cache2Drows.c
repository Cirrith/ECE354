int arr[3000][500];

int main (int argc, const char* argv[])
{
	int numrows = 3000;
	int numcols = 500;
		for(int i = 0; i < numrows; i++)
		{
			for(int j = 0; j < numcols; j++)
			{
				arr[i][j] = i + j;
			}
		}
}