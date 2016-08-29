#define _CRT_SECURE_NO_WARNINGS

#include <string.h> // For memset

//숫자음성인식기를 GUI로 구
#include "tensorflow.h"
#include "test.h"
#include "stdio.h"
#include "stdlib.h"
///#include "header.h"
//double x_dat[390] = { 85.72992,14.03022,-39.06149,-8.171786,-20.90829,12.92959,24.98476,-9.680866,-10.20126,17.54624,-16.55013,-3.244338,-19.86294,86.84012,12.01482,-40.35707,-5.952518,-23.21716,14.20873,23.80965,-7.168104,-14.29277,19.24661,-17.47318,-4.406952,-17.74798,88.10234,10.11302,-42.49134,-3.434503,-25.61612,14.50554,27.69655,-13.12231,-12.15694,17.58902,-16.93546,-1.479189,-25.0305,88.56429,8.601204,-41.30292,-3.730858,-27.69134,16.70499,28.99251,-16.20374,-10.26153,14.99587,-15.27553,-1.465171,-26.52761,89.47159,5.905918,-38.42413,-5.694589,-27.59247,16.70942,29.95077,-18.15355,-9.506822,14.13613,-14.1612,-4.191567,-23.39307,90.09008,4.404604,-36.86321,-7.590559,-27.68175,17.46875,29.48806,-19.28408,-8.063648,14.80015,-17.11564,-4.395831,-21.96703,90.46165,3.443125,-35.93764,-8.789815,-27.04568,16.64477,30.47475,-23.05849,-2.003577,10.5235,-17.34959,-5.729112,-21.63607,90.26225,3.152086,-35.37601,-8.293564,-26.71606,16.51746,29.97189,-25.78762,2.815591,8.523576,-16.32267,-10.24547,-19.03633,89.90185,3.582564,-35.08021,-7.248717,-28.61089,17.91975,27.87386,-24.21888,2.297211,9.703327,-17.7087,-10.4695,-18.75559,89.5163,3.70522,-34.22928,-6.762478,-30.0581,20.43817,25.91045,-23.13798,1.238479,10.27033,-16.32352,-11.52108,-19.2996,89.05833,3.82577,-33.01879,-6.921279,-31.26746,22.67748,23.2749,-20.87411,-1.89925,13.63666,-17.08124,-10.30676,-20.70664,88.82052,3.081328,-30.91276,-8.165425,-30.77741,23.40987,21.31506,-18.65637,-5.346733,17.05342,-18.311,-10.15909,-19.02363,88.24601,3.399824,-30.88881,-7.252019,-31.16035,21.56322,24.49833,-22.23517,-3.799193,15.92828,-16.82547,-10.15373,-18.95366,87.35555,4.54736,-30.90265,-7.459904,-32.95018,23.79094,22.84957,-22.95742,-4.990714,17.16285,-16.37081,-8.470891,-20.17719,86.72174,4.835169,-29.76514,-7.913774,-34.43221,24.0308,20.50696,-21.80762,-7.152735,20.28646,-17.92648,-6.732501,-20.1579,86.27917,3.755685,-26.66029,-10.91257,-32.29662,20.38661,18.63836,-21.45721,-3.113485,17.80676,-20.55649,-6.393212,-16.66155,85.23005,3.881392,-23.94084,-13.4906,-31.66285,16.45877,20.72465,-22.33549,1.944674,13.77458,-23.76567,-5.863458,-14.94928,84.88305,2.583833,-21.63455,-16.48503,-32.32826,20.09331,20.29559,-19.71576,-2.372564,13.77191,-24.08555,-6.534137,-14.12229,84.03804,2.248154,-20.61405,-19.86268,-29.07437,21.89313,23.93228,-25.5272,-3.672181,12.98783,-21.67148,-8.652639,-15.55503,82.35334,2.654756,-18.86775,-20.43596,-28.09797,24.90394,21.66922,-27.99276,-2.988989,14.54404,-22.0712,-8.126245,-18.51752,79.86423,3.447082,-15.72816,-16.65723,-32.89021,26.0193,21.74229,-30.71811,0.3108532,12.63847,-18.99322,-7.456837,-18.55199,78.06213,2.410442,-11.83785,-14.90015,-34.23326,22.08808,25.83206,-31.03245,1.520386,12.52175,-15.98174,-8.111959,-19.53644,75.77702,3.383197,-11.1302,-13.63727,-33.20621,19.63036,25.25352,-28.21431,3.382805,16.71525,-18.29004,-9.926922,-19.75682,73.33662,4.584521,-9.783037,-13.81809,-33.82331,23.13723,24.10751,-26.55006,1.195332,19.36551,-20.23823,-8.859362,-20.57203,69.67344,7.021626,-8.787768,-10.12752,-36.14075,22.87795,20.21853,-23.06938,0.5626748,20.5748,-19.51008,-6.066472,-17.09406,67.77584,7.89164,-13.2045,-13.27941,-28.09059,24.72085,15.48943,-19.22921,0.7078232,25.15251,-24.48904,-5.462122,-19.66784,64.83962,9.652575,-18.39938,-9.733779,-21.2918,23.20429,17.65347,-24.75252,1.418536,24.65003,-22.33131,-8.180407,-15.55747,61.63001,2.912956,-4.320922,-6.586229,-11.59419,29.30882,19.30895,-15.51012,-7.594078,28.35478,-35.65274,-2.401063,-15.26689,60.8326,3.936371,-8.834564,-5.740626,-15.41258,29.84826,14.96563,-21.14556,-8.05662,26.52522,-30.17319,3.39521,-14.24589,55.26895,12.04406,0.9519482,-17.59342,-2.023696,28.17793,11.27232,-13.21728,-5.747818,25.66322,-25.02913,-7.897266,-8.696137 };


void short2double(short ar[], double ar2[])
{
	for (int i=0; i < sizeof(ar); i++)
	{
		ar2[i] = ar[i];	//double로 바꾸는함수.
	}
}

int main()
{
	


	// Read in sample data from sample.dat
	// sample.dat contains an 8192-point spectrum from a sine wave at 440Hz (A) in double precision
	// Spectrum was computed using FFTW (http://www.fftw.org/)
	// Data was not windowed (rectangular)

	// Holds the spectrum data to be analyzed
	double spectrum[400];
	short buf[400];
	double buf2[400];
	int junk[11];
	// Pointer to the sample data file
	FILE *fp;

	// Index counter - used to keep track of which data point is being read in
	int i = 0;

	// Determine which MFCC coefficient to compute
	unsigned int coeff;

	// Holds the value of the computed coefficient
	double mfcc_result;

	// Initialize the spectrum
	//memset(&buf2, 0, sizeof(buf2));
	
	// Open the sample spectrum data	
	fp = fopen("001.wav", "rb");

	// Read in the contents of the sample file
	for (int i = 0; i < 11; i++)
	{
		fread(junk, sizeof(int), sizeof(junk), fp);
	}
	while (1)
	{
		fread(buf, sizeof(short), sizeof(buf), fp);
		for (int i = 0; i < 400; i++)
		{
			buf2[i] = (double)buf[i];
		}
		for (coeff = 0; coeff < 13; coeff++)
		{
			mfcc_result = GetCoefficient(buf2, 16000, 48, 400, coeff);
			printf("%i %f\n", coeff, mfcc_result);
		}
		getchar();
	//	if (fread == 0)
		//	break;
	}

	// Close the sample file
	fclose(fp);

	// Compute the first 13 coefficients
	
	
	check(test_000);
	check(test_001);
	check(test_002);
	check(test_003);
	check(test_004);
	check(test_005);
	check(test_006);
	check(test_007);
	check(test_008);
	check(test_009);
	check(test_010);
	check(test_011);
	check(test_012);
	check(test_013);
	check(test_014);
	check(test_015);
	check(test_016);
	check(test_017);
	check(test_018);
	check(test_019);
	check(test_020);
	check(test_021);
	check(test_022);
	check(test_023);
	check(test_024);
	check(test_025);
	check(test_026);
	check(test_027);
	check(test_028);
	check(test_029);
	check(test_030);
	check(test_031);
	check(test_032);
	check(test_033);
	check(test_034);
	check(test_035);
	check(test_036);
	check(test_037);
	check(test_038);
	check(test_039);
	check(test_040);
	check(test_041);
	check(test_042);
	check(test_043);
	check(test_044);
	check(test_045);
	check(test_046);
	check(test_047);
	check(test_048);
	check(test_049);
	check(test_050);
	check(test_051);
	check(test_052);
	check(test_053);
	check(test_054);
	check(test_055);
	check(test_056);
	check(test_057);
	check(test_058);
	check(test_059);
	check(test_060);
	check(test_061);
	check(test_062);
	check(test_063);
	check(test_064);
	check(test_065);
	check(test_066);
	check(test_067);
	check(test_068);
	check(test_069);
	check(test_070);
	check(test_071);
	check(test_072);
	check(test_073);
	check(test_074);
	check(test_075);
	check(test_076);
	check(test_077);
	check(test_078);
	check(test_079);
	check(test_080);
	check(test_081);
	check(test_082);
	check(test_083);
	check(test_084);
	check(test_085);
	check(test_086);
	check(test_087);
	check(test_088);
	check(test_089);
	check(test_090);
	check(test_091);
	check(test_092);
	check(test_093);
	check(test_094);
	check(test_095);
	check(test_096);
	check(test_097);
	check(test_098);
	check(test_099);
	check(test_100);
	check(test_101);
	check(test_102);
	check(test_103);
	check(test_104);
	check(test_105);
	check(test_106);
	check(test_107);
	check(test_108);
	check(test_109);
	check(test_110);
	check(test_111);
	check(test_112);
	check(test_113);
	check(test_114);
	check(test_115);
	check(test_116);
	check(test_117);
	check(test_118);
	check(test_119);
	check(test_120);
	check(test_121);
	check(test_122);
	check(test_123);
	check(test_124);
	check(test_125);
	check(test_126);
	check(test_127);
	check(test_128);
	check(test_129);
	check(test_130);
	check(test_131);
	check(test_132);
	check(test_133);
	check(test_134);
	check(test_135);
	check(test_136);
	check(test_137);
	check(test_138);
	check(test_139);
	check(test_140);
	check(test_141);
	check(test_142);
	check(test_143);
	check(test_144);
	check(test_145);
	check(test_146);
	check(test_147);
	check(test_148);
	check(test_149);



	return 0;
}

