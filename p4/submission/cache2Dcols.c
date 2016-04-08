//Ryan Bambrough & Cheng-Hsiang Hsu
//Section 1
int arr[3000][500];

int main (int argc, const char* argv[])
{
	int numrows = 3000;
	int numcols = 500;
		for(int i = 0; i < numcols; i++)
		{
			for(int j = 0; j < numrows; j++)
			{
				arr[j][i] = i + j;
			}
		}
}
