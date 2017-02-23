#include <iostream>  
#include <fstream>  
#include <strstream>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <opencv2/objdetect/objdetect.hpp>  
#include <opencv2/ml/ml.hpp>  
#include <time.h>

//-----------------------�̳���----------------------------
//---------------------------------------------------------
//�̳���CvSVM���࣬��Ϊ����setSVMDetector()���õ��ļ���Ӳ���ʱ����Ҫ�õ�ѵ���õ�SVM��decision_func������  
//��ͨ���鿴CvSVMԴ���֪decision_func������protected���ͱ������޷�ֱ�ӷ��ʵ���ֻ�ܼ̳�֮��ͨ����������  
class MySVM : public CvSVM  
{  
public:  
	//���SVM�ľ��ߺ����е�alpha����  
	double * get_alpha_vector()  
	{  
		return this->decision_func->alpha;  
	}  

	//���SVM�ľ��ߺ����е�rho����,��ƫ����  
	float get_rho()  
	{  
		return this->decision_func->rho;  
	}  
};  

//-------����һ�����ҵ����飨��0��ʼ������������-----------------
//---------------------------------------------------------
void random(int a[], int n)
{
	for (int nu = 0;nu<n;nu++)
	{
		a[nu] = nu;
	}
	int index, tmp, i;
	srand(time(NULL));
	for (i = 0; i <n; i++)
	{
		index = rand() % (n - i) + i;
		if (index != i)
		{
			tmp = a[i];
			a[i] = a[index];
			a[index] = tmp;
		}
	}
}

//--------����Ԫ�ش�С�������ͣ�0-train,1-vaild,2-test��----------------------
//---------------------------------------------------------
void typeHandle(int arr[],int setNo,int trainNo,int vaildNo)
{
	for (int i = 0;i<setNo;i++)
	{
		if (arr[i]<trainNo)
		{
			arr[i] = 0;
		} 
		else if(arr[i]<trainNo + vaildNo)
		{
			arr[i] = 1;
		}
		else
		{
			arr[i] = 2;
		}
	}
}
