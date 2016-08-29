#include "header.h"
//텐서플로우의 변수 w,b를 로딩해서 답을 도출
//헤더를 읽자
// 아래 함수는, 테스트를 위해 일단 main으로 둔다.
//void read_header()

double relu (double a)
{
	if (a < 0)
		return 0;
	else
		return a;
} //Relu 함수

//X_LS 390
//LS 128

void check(double ar[])
{
	double *temp = (double *)malloc(sizeof(double) * LS);
	double *inter_01 = (double*)malloc(sizeof(double)*LS);
	double *inter_02 = (double*)malloc(sizeof(double)*LS);

	double *inter_03 = (double*)malloc(sizeof(double)*LS);
	double *inter_04 = (double*)malloc(sizeof(double)*LS);

	double *inter_05 = (double*)malloc(sizeof(double)*LS);

	double sum2 = 0;
	
	double y[10] = { 0 };
	//double *y = (double*)malloc(sizeof(double) * 10);

	if (temp == NULL)
	{
		printf("메모리 할당 실패\n");
		return -1;
	}
	
	//계산단계 (x_dat^T*w1 +b1) 
	for (int i=0; i < LS; i++)
	{
		double sum = 0;
		for (int j = 0; j < X_LS; j++)
		{
			sum += ar[j] * w1[j][i];
		}
		inter_01[i] = sum+b1[i];
	}
	//relu 

	for (int i = 0; i < LS; i++)
	{
		inter_01[i]=relu(inter_01[i]);
	}
	//계산단계 (temp*w2+b2)
	
	for (int i = 0; i < LS; i++)
	{
		double sum = 0;
		for (int j = 0; j < LS; j++)
		{
			sum += inter_01[j] * w2[j][i];
		}
		inter_02[i] = sum + b2[i];
	}
	free(inter_01);
	//relu
	for (int i = 0; i < LS; i++)
	{
		inter_02[i] = relu(inter_02[i]);
	}
	//계산단계 (temp*w3+b3)
	for (int i = 0; i < LS; i++)
	{
		double sum = 0;
		for (int j = 0; j < LS; j++)
		{
			sum+= inter_02[j] * w3[j][i];
		}
		inter_03[i]= sum+ b3[i];
	}
	//relu
	free(inter_02);
	for (int i = 0; i < LS; i++)
	{
		inter_03[i] = relu(inter_03[i]);
	}
	
	//계산단계 (temp*w4+b4)
	for (int i = 0; i < LS; i++)
	{
		double sum = 0;

		for (int j = 0; j < LS; j++)
		{
			sum+= inter_03[j] * w4[j][i];
		}
		inter_04[i] = sum + b4[i];
	}
	//relu
	free(inter_03);

	for (int i = 0; i < LS; i++)
	{
		inter_04[i] = relu(inter_04[i]);
	}
	
	//계산단계 (temp*w5 +b5) 
	for (int i = 0; i < 10; i++)
	{
		double sum = 0;
		for (int j = 0; j < LS; j++)
		{
			sum += inter_04[j] * w5[j][i];
		}
		inter_05[i] = sum+ b5[i];
	}
	free(inter_04);

	//소프트맥스 계산

	for (int i = 0; i < 10; i++)
	{
		sum2 = sum2+exp(inter_05[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		y[i] = exp(inter_05[i]) / sum2;
	}
	
	//정답 출력

	for (int i = 0; i < 10; i++)
	{
		if (y[i] > 0.5&& i==9)
		{
			printf("%d ", i-9);
		}
		else if (y[i] > 0.5)
		{
			printf("%d ", i + 1);
		}

	}
	//인식률 출력

	free(inter_05);

}

