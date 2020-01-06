//#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>


#include <OACMJND.h>


using namespace std;

int main(int argc, char ** argv)
{
	const string usage("Usage:-m <realisations> -d <dimensions> -n <samples> -o <path>");

	uint realisations_number(1u);
	uint dimensions_number(1u);
	uint samples_number(1u);
	string output_path("out.dat");

	for(int i(1); i < argc; i++)
	{
		const string argument(argv[i]);
		//cout << argument << endl;
	
		if(argument.compare("-m") == 0)
		{
			assert(argc > ++i);
			realisations_number = stoi(argv[i]);
		}
		else if(argument.compare("-d") == 0)
		{
			assert(argc > ++i);
			dimensions_number = stoi(argv[i]);
		}
		else if(argument.compare("-n") == 0)
		{
			assert(argc > ++i);
			samples_number = stoi(argv[i]);
		}
		else if(argument.compare("-o") == 0)
		{
			assert(argc > ++i);
			output_path = string(argv[i]);
		}
		else
		{
			cout << usage << endl;
			if(argument.compare("-h") != 0) return 1;
			else return 0;
		}
	}

	cout << "Realisations:" << realisations_number << endl;
	cout << "Dimensions:" << realisations_number << endl;
	cout << "Samples:" << samples_number << endl;
	cout << "Output path:" << output_path << endl;

	std::ofstream file(output_path);

	const bool randomized(true);
	const bool jittered(false);
	CMJNDInPlace sampler(samples_number, dimensions_number, OffsetType::CENTERED, randomized, jittered);
	
	float * sample(new float[dimensions_number]);
	for(uint r(0u); r < realisations_number; r++)
	{
		for(uint s(0u); s < samples_number; s++)
		{
			sampler.sample(sample, s);
			for(uint d(0u); d < dimensions_number; d++)
			{
				if(d > 0u) file << " ";
				file << sample[d];
			}
			file << endl;
		}
		file << "#" << endl;
		//sampler.setRandomized(true);
		sampler.reset();
	}
	delete[] sample;
	file.close();

	return 0;
}

