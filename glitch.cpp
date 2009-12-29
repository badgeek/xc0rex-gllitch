#include <iostream>
using std::ios;
using std::cout;
using std::endl;
using std::cin;
using std::cerr;

#include <fstream>
using std::fstream;

int length, start, stop;
int glitchstart, glitchamount, glitchrandomness;

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
		cout << "usage ./glitch <input> <output> <start> <amount> <optional: randomness>\n\n";
		return -1;
	}
	
	glitchstart = atoi(argv[3]);
	glitchamount = atoi(argv[4]);
	
	if (argv[5])
	{
		glitchrandomness = atoi(argv[5]);	
	}else{
		glitchrandomness = 99;	
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
		
		
		for (int i = 0; i < length; i++)
		{
			if (i >= glitchstart && i <= glitchamount)
			{
				//byte = original.get();
				output.put(random() % 99);
				//cout << byte;
			}else{
				byte = original.get();
				output.put(byte);
			}

		}


	}
	
	original.close();
	output.close();
	
	return 0;
}
