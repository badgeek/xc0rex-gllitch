#include <iostream>
using std::ios;
using std::cout;
using std::endl;
using std::cin;
using std::cerr;

#include <fstream>
using std::fstream;

#include <time.h>

int length, start, stop;
int glitchstart, glitchamount, glitchrandomness, glitchprob;

char byte;
int rnd;

int main(int argc, char* argv[])
{
	cout << "\n--------------------\n";
	cout << "xc0rex-glitcher 0.1a\n";
	cout << "--------------------\n";
	cout << "iyok@deadmediafm.org\n";
	
	
	if (!argv[1] || !argv[2] || !argv[3] || !argv[4])
	{
		//						   1       2        3              4                      5
		cout << "usage ./glitch <input> <output> <start> <optional: randomness> <optional: probability> \n\n";
		return -1;
	}
	
	glitchstart = atoi(argv[3]);
	
	int rndval = atoi(argv[4]);
	
	if (argv[5])
	{
		glitchprob = atoi(argv[5]);	
	}else{
		glitchprob = 500;	
	}
	
	fstream original(argv[1], ios::in | ios::out | ios::binary);
	fstream output(argv[2],ios::out | ios::binary);

	if (!original)
	{
		cout << "error: file not found\n\n";
	}else{
		cout << "glitching!\n\n";
		original.seekg (0, ios::end);
		length = original.tellg();
		start = 1000;
		stop = length - 1000;
		original.seekg (0, ios::beg);
		
		int chunk;
		int glitchcount;
		int bytecount;
		
		for (int i = 0; i < length; i++)
		{
			
			byte = original.get();
			
			if (i >= glitchstart && i <= (length - 1000))
			{
				bytecount = bytecount + 1;
				srand ( time(NULL) );
				if ((random() % 100000) < glitchprob)
				{
					glitchcount = glitchcount + 1;
					
					output.put(random() % rndval);
				}else{
					//cout << "real data\n";
					output.put(byte);
				}
				//output.put(byte);
			}else{
				//cout << "real data\n";
				output.put(byte);
			}
			
			
			//output.put(byte);

		}
cout << "glitch count: " << glitchcount << " bytes: " << bytecount << "\n";

	}
	
	original.close();
	output.close();
	
	return 0;
}
