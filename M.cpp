// ���ڵ�� �Ƶ����� �ֹ� ����� �����  
// ���� ���� �ֹ��� �ް� �ֹ����� ������  
// txt���Ϸ� �Ȱܼ� �ֹ濡�� ���ϴ� ������� �����ټ� 
// �ְ� �ֹ� ���ΰ� ���� ���� ���� �ֽ��ϴ�. 

#include<stdio.h> 
#include<windows.h> //Ŭ���� �ڵ带 ���� ���ؼ� 

int qjrj[2][7]={{3300,5700,4400,2200,4600,2300,5500},{0,}};   //���� �迭
int tkdlem[2][7]={{1800,2200,1800,2600,2500,1200,3000},{0,}}; //���̵� �迭
int dmafy[2][7]={{1400,1400,2200,2500,1400,1500,1700},{0,}};  //���� �迭

float gkfdlsznvhs=1;  //���� ���� 1�� ������ ������ ������ ������� ���ص� �ƹ� ����� ���� ����
int qjrjc=0;          //���űݾ� �ѱݾ�
int tkdlemc=0;        //���̵�ݾ� �ѱݾ�
int dmafyc=0;         //����ݾ� �ѱݾ� 
int thssla=0;         //�մ�ī��Ʈ �ѱݾ�

int ghkaus(int);      //ȭ�� �Լ��� ������ ȭ�� �̵� 

int main(){           //main�Լ��� ������ �� 
	system("mode con:cols=26 lines=21");//�ܼ�â ũ�� ���� 
	FILE *fp;         //txt���� �̰��� �˸�����Ʈ�� �ް� �丮�� �ֹ��� �Դϴ� 
	fp = fopen("�ֹ���.txt", "w"); //���� ����� ������ ������ ���� ������ ���� 
	fprintf(fp,"\n"); //���� �ʱ�ȭ \n���� �������� ������ �� ������ ������ ���ؼ� ���� ������ Ŭ���� �ϴ� ����� ��  
	int a=0;          //������ ��ġ ���� 0�� ������ �Ƶ����尡 ������ ȭ��   a�� ���Ͽ� ȭ�� �Լ����� ����ġ �ڵ尡 ���� 
	char b;           //�Է¹޴� ��� �� ��� �޴� ��� ��  [ü��X   ĳ����]
	ghkaus(a);        //���۽� ���� ȭ������ ���� 
	while(1){         //���� �ݺ� @������ ���� 
	scanf("%c",&b);   //ȭ�� �ٲٴ� ���� 
	system("cls");    //ȭ�� Ŭ���� �Լ�
					  //�ʱ� ������ ����ġ�� ����
	
	switch(b){ //@�̸� �ޱ� ������ ���� �ݺ� 
		case '@': if(a==0){
		return 0;               //0��° �� m������ ȭ�鿡���� ������ư ��� 
		};                      //���� ��ư
		break;
		
		case '>': a++;          //�̵� ������ 
		break;
		
		case '<': a--;          //�̵� ����
		break;
		
		case 'v': if(a<4&&a>0)  // 1���� 3������ ���� ���� �Ѹ���� �ֹ� ȭ�鿡���� ���� 
		{
		a=20;
		};                     //���� ���� �̵�
		break;
		
		case 'y': if(a>9)  //���� ȭ��� ���� ȭ�鿡���� ��� ���� 
		{
		a=10; 
		};               //���� ��� ���ϰ� �ѱ��
		break;
	}
	
	switch(a){           //�������� ����ġ�� �ٲٴ� ���� �������� ������ ���� ���� �ƹ� ����� ���⶧���� ���Ƶδ� ������ ���ش� 
		case -1: a=0;    //ȭ�� ������ �ƻ� ������
		break;
		
		case 4: a=1;     //3�� ������ �̻� ������
		break;
		
		case 9: a=13;     //���� ������ �̻� ������
		break;
		
		case 14: a=10;    //����  ������ �̻� ������
		break;
		
		case 21: a=20;   //�������� ȭ�� �̻� ������ 
		break;
		
		case 19: a=20;   //�������� ȭ�� �̻� ������ 
		break;
	}

	
	if(b=='x')        //���� ���  ��� ���� �迭 �ʱ�ȭ �迭�� ���� ?�� 
	{
		for(int i=0;i<7;i++){   //Ƚ�� �ʱ�ȭ 
			qjrj[1][i]=0;
		}
		for(int i=0;i<7;i++){   //Ƚ�� �ʱ�ȭ 
			tkdlem[1][i]=0;
		}
		for(int i=0;i<7;i++){   //Ƚ�� �ʱ�ȭ 
			dmafy[1][i]=0;
		}
		gkfdlsznvhs=1; //���� ����
		qjrjc=0;       //���űݾ�
		tkdlemc=0;     //���̵�ݾ� 
		dmafyc=0;      //����ݾ� 
		a=0;           //ȭ�� �ʱ�ȭ 
	}
	if(b=='c')         //���� �ֹ� 
	{
		thssla++;      //���� �ֹ� ������ ������ ���� �մ� �ֹ� �ޱ��� �մ��� �ֹ��� �����Ѵ�
		fprintf(fp,"%d�� �մ�\n",thssla);
		fprintf(fp,"\n�ܹ���\n");
		for(int i=0;i<7;i++){
			if(0!=qjrj[1][i]){          //�ֹ����� ���� �Ŵ��� ������� �ʴ´� 
			fprintf(fp,"%d�޴� %d��\n",i+1,qjrj[1][i]);      //txt ���Ϸ� �ȱ�� 
			}
		} 
		fprintf(fp,"\n���̵�\n");
		for(int i=0;i<7;i++){
			if(0!=tkdlem[1][i]){
			fprintf(fp,"%d�޴� %d��\n",i+1,tkdlem[1][i]);
			}
		}
		fprintf(fp,"\n����\n");
		for(int i=0;i<7;i++){
			if(0!=dmafy[1][i]){
			fprintf(fp,"%d�޴� %d��\n",i+1,dmafy[1][i]);
			}
		}
		fprintf(fp,"\n");    
		//txt���Ϸ� �ȱ�� ���� ������ �ʱ�ȭ 
		for(int i=0;i<7;i++){    //Ƚ�� �ʱ�ȭ 
			qjrj[1][i]=0;
		}
		for(int i=0;i<7;i++){    //Ƚ�� �ʱ�ȭ 
			tkdlem[1][i]=0;
		}
		for(int i=0;i<7;i++){    //Ƚ�� �ʱ�ȭ 
			dmafy[1][i]=0;
		}
		gkfdlsznvhs=1;  //���� ���� 
		qjrjc=0;        //���űݾ�
		tkdlemc=0;      //���̵�ݾ� 
		dmafyc=0;       //����ݾ�
		a=0;            //ȭ�� �ʱ�ȭ 
	}
	
	if(a==20){         //���� ȭ�鿡�� ���� ���� �ۼ�Ʈ ���� 
		switch(b){
			case '1':
				gkfdlsznvhs=0.95;  //5%
				a=10;              //���� �ް� ���� ȭ������ ���� 
			break;
			
			case '2':
				gkfdlsznvhs=0.9;   //10%
				a=10;              //���� �ް� ���� ȭ������ ����
			break;
			
			case '3':
				gkfdlsznvhs=0.8;   //20%
				a=10; 		       //���� �ް� ���� ȭ������ ����
			break;	
		}
	} 
	
	if(a==1){       //���� ȭ�鿡�� ī��Ʈ 
		switch(b){
			case '1':qjrj[1][0]++;
			break;
			case '2':qjrj[1][1]++;        //0��° ���� ���� �̱� ??���� 0�� ���� �ٷ� �ؿ� ī��Ʈ 
			break;
			case '3':qjrj[1][2]++;
			break;
			case '4':qjrj[1][3]++;
			break;
			case '5':qjrj[1][4]++;
			break;
			case '6':qjrj[1][5]++;
			break;
			case '7':qjrj[1][6]++;
			break;
		}
	}
	
	if(a==2){       //���̵� ȭ�鿡�� ī��Ʈ 
		switch(b){
			case '1':tkdlem[1][0]++;
			break;
			case '2':tkdlem[1][1]++;       //0��° ���� ���� �̱� ??���� 0�� ���� �ٷ� �ؿ� ī��Ʈ 
			break;
			case '3':tkdlem[1][2]++;
			break;
			case '4':tkdlem[1][3]++;
			break;
			case '5':tkdlem[1][4]++;
			break;
			case '6':tkdlem[1][5]++;
			break;
			case '7':tkdlem[1][6]++;
			break;
		}
	}
	
	if(a==3){        //���� ȭ�鿡�� ī����
		switch(b){
			case '1':dmafy[1][0]++;
			break;
			case '2':dmafy[1][1]++;
			break;
			case '3':dmafy[1][2]++;     //0��° ���� ���� �̱� ??���� 0�� ���� �ٷ� �ؿ� ī��Ʈ 
			break;
			case '4':dmafy[1][3]++;
			break;
			case '5':dmafy[1][4]++;
			break;
			case '6':dmafy[1][5]++;
			break;
			case '7':dmafy[1][6]++;
			break;
		}
	}
	
	ghkaus(a);  //������ a�� ���� �Ѱ� �ҷ��� ȭ�� �ٲٱ� 
	}
}


int ghkaus(int a){   //ȭ�� �Լ� 
	switch(a){       //ȭ�� �ٲٴ� ����ġ
	case 0:          //ó�� ȭ�� 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);  //�ΰ� ���� ���� 15�� ȭ��Ʈ 14�� ��� 
		printf("��������������\n");
		printf("��                      ��\n");
		printf("��                      ��\n");    
		printf("��                      ��\n");   
		printf("��                      ��\n");
		printf("��                      ��\n");
		printf("��");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("    ����  ����    ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		printf("��\n��");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14); 
		printf("  ���  ����  ���  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		printf("��\n��");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("  ��      ��      �� ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		printf(" ��\n��");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("  ��      ��      �� ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		printf(" ��\n��");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("  ��      ��      ��  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		printf("��\n��");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("  ��      ��      ��  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		printf("��\n");
		printf("��                      ��\n");
		printf("��      [�Ƶ�����]      ��\n");
		printf("��                      ��\n");
		printf("��                      ��\n");
		printf("��      ȭ�� �ѱ��(>,<)��\n");
		printf("��������������\n");
		printf("����ȭ���� 1~3��������\n");
		printf("�������������� @��\n");
	break;
	
	case 1://���� ȭ�� 
		printf("��������������\n");
		printf("��        <����>        ��\n");
		printf("��  (1)��ġŲ           ��\n");
		printf("��  \\ 3,300     %4d �� ��\n",qjrj[1][0]);  //ī��Ʈ�� main���� �ϰ� ����� �޾ƿ� �� ��� 
		printf("��  (2)1955?����       ��\n");
		printf("��  \\ 5,700     %4d �� ��\n",qjrj[1][1]);
		printf("��  (3)���������     ��\n");
		printf("��  \\ 4,400     %4d �� ��\n",qjrj[1][2]);
		printf("��  (4)�Ұ�����       ��\n");
		printf("��  \\ 2,200     %4d �� ��\n",qjrj[1][3]);
		printf("��  (5)���             ��\n");
		printf("��  \\ 4,600     %4d �� ��\n",qjrj[1][4]);
		printf("��  (6)������         ��\n");
		printf("��  \\ 2,300     %4d �� ��\n",qjrj[1][5]);
		printf("��  (7)�������         ��\n");
		printf("��  \\ 5,500     %4d �� ��\n",qjrj[1][6]);
		printf("��             ������(v)��\n");
		printf("��������������\n");
		printf("����� 1 ��ȭ�� �����\n");
		printf("��������������\n");
	break;
	
	case 2://���̵� ȭ�� 
		printf("��������������\n");
		printf("��       <���̵�>       ��\n");
		printf("��  (1)�Ƴʰ�           ��\n");
		printf("��  \\ 1,800     %4d �� ��\n",tkdlem[1][0]);
		printf("��  (2)������ġŲ������ ��\n");
		printf("��  \\ 2,200     %4d �� ��\n",tkdlem[1][1]); //ī��Ʈ�� main���� �ϰ� ����� �޾ƿ� �� ��� 
		printf("��  (3)�ķ�ġ�Ķ���     ��\n");
		printf("��  \\ 1,800     %4d �� ��\n",tkdlem[1][2]);
		printf("��  (4)��¥����ġ�ƽ	��\n");
		printf("��  \\ 2,600     %4d �� ��\n",tkdlem[1][3]);
		printf("��  (5)���������÷���   ��\n");
		printf("��  \\ 2,500     %4d �� ��\n",tkdlem[1][4]);
		printf("��  (6)��������         ��\n");
		printf("��  \\ 1,200     %4d �� ��\n",tkdlem[1][5]);
		printf("��  (7)��������������   ��\n");
		printf("��  \\ 3,000     %4d �� ��\n",tkdlem[1][6]);
		printf("��             ������(v)��\n");
		printf("��������������\n");
		printf("����� 2 ��ȭ�� �����\n");
		printf("��������������\n");
	break;
	
    case 3://���� ȭ�� 
		printf("��������������\n");
		printf("��        <����>        ��\n");
		printf("��  (1)��ī-�ݶ�����    ��\n");
		printf("��  \\ 1,400     %4d �� ��\n",dmafy[1][0]);
		printf("��  (2)��ī-�ݶ�        ��\n");
		printf("��  \\ 1,400     %4d �� ��\n",dmafy[1][1]); //ī��Ʈ�� main���� �ϰ� ����� �޾ƿ� �� ��� 
		printf("��  (3)īǪġ��         ��\n");
		printf("��  \\ 2,200     %4d �� ��\n",dmafy[1][2]);
		printf("��  (4)�ٴҶ���ũ     ��\n");
		printf("��  \\ 2,500     %4d �� ��\n",dmafy[1][3]);
		printf("��  (5)��������Ʈ       ��\n");
		printf("��  \\ 1,400     %4d �� ��\n",dmafy[1][4]);
		printf("��  (6)����             ��\n");
		printf("��  \\ 1,500     %4d �� ��\n",dmafy[1][5]);
		printf("��  (7)���̽��Ƹ޸�ī�� ��\n");
		printf("��  \\ 1,700     %4d �� ��\n",dmafy[1][6]);
		printf("��             ������(v)��\n");
		printf("��������������\n");
		printf("����� 3 ��ȭ�� �����\n");
		printf("��������������\n");
	break;
	
	case 10:								//���� ȭ�� 
		qjrjc=0; //���űݾ�
		tkdlemc=0; //���̵�ݾ� 
		dmafyc=0; //����ݾ� 
		
		for(int i=0; i<7; i++){				//���� 
			for(int j=0; j<qjrj[1][i];j++){
				qjrjc+=qjrj[0][i];
			}
		}
		
		for(int i=0; i<7; i++){				//���̵� 
			for(int j=0; j<tkdlem[1][i];j++){
				tkdlemc+=tkdlem[0][i];
			}
		}
		
		for(int i=0; i<7; i++){				//���� 
			for(int j=0; j<dmafy[1][i];j++){
				dmafyc+=dmafy[0][i];
			}
		}
		
		printf("��������������\n");
		printf("��                      ��\n");
		printf("�� ���űݾ�             ��\n");
		printf("�� %17d \\  ��\n",qjrjc);					//�ݾ� �ڸ����� �þ�� ���� 
		printf("�� ���̵�ݾ�           ��\n");
		printf("�� %17d \\  ��\n",tkdlemc);
		printf("�� ����ݾ�             ��\n");
		printf("�� %17d \\  ��\n",dmafyc);
		printf("��                      ��\n");
		printf("�� ���� %12d \\  ��\n",qjrjc+tkdlemc+dmafyc);
		printf("�� ���ΰ� %10.0f \\  ��\n",(float)(qjrjc+tkdlemc+dmafyc)*(1-gkfdlsznvhs));
		printf("�� �ѱݾ� %10.0f \\  ��\n",(float)(qjrjc+tkdlemc+dmafyc)*gkfdlsznvhs);
		printf("�� ����                 ��\n");
		printf("�� 356-1525-9678-13     ��\n");
		printf("��           �ֹ����(x)��\n");
		printf("��           �ֹ��Ϸ�(c)��\n");
		printf("��         ����°�(>,<)��\n");
		printf("��������������\n");
		printf("����� �����ݾ� �����\n");
		printf("��������������\n");
	break;
	
	case 11:               //����°� 
		printf("��������������\n");
		printf("��        <����>        ��\n");
		printf("��  (1)��ġŲ           ��\n");
		printf("��  %4d ��             ��\n",qjrj[1][0]);
		printf("��  (2)1955?����       ��\n");
		printf("��  %4d ��             ��\n",qjrj[1][1]);
		printf("��  (3)���������     ��\n");
		printf("��  %4d ��             ��\n",qjrj[1][2]);
		printf("��  (4)�Ұ�����       ��\n");
		printf("��  %4d ��             ��\n",qjrj[1][3]);
		printf("��  (5)���             ��\n");
		printf("��  %4d ��             ��\n",qjrj[1][4]);
		printf("��  (6)������         ��\n");
		printf("��  %4d ��             ��\n",qjrj[1][5]);
		printf("��  (7)�������         ��\n");
		printf("��  %4d ��             ��\n",qjrj[1][6]);
		printf("��                      ��\n");
		printf("��������������\n");
		printf("����� 1 ��ȭ�� �����\n");
		printf("��������������\n");
	break;
	
	case 12:              //����°�  
		printf("��������������\n");
		printf("��       <���̵�>       ��\n");
		printf("��  (1)�Ƴʰ�           ��\n");
		printf("��  %4d ��             ��\n",tkdlem[1][0]);
		printf("��  (2)������ġŲ������ ��\n");
		printf("��  %4d ��             ��\n",tkdlem[1][1]);
		printf("��  (3)�ķ�ġ�Ķ���     ��\n");
		printf("��  %4d ��             ��\n",tkdlem[1][2]);
		printf("��  (4)��¥����ġ�ƽ	��\n");
		printf("��  %4d ��             ��\n",tkdlem[1][3]);
		printf("��  (5)���������÷���   ��\n");
		printf("��  %4d ��             ��\n",tkdlem[1][4]);
		printf("��  (6)��������         ��\n");
		printf("��  %4d ��             ��\n",tkdlem[1][5]);
		printf("��  (7)��������������   ��\n");
		printf("��  %4d ��             ��\n",tkdlem[1][6]);
		printf("��                      ��\n");
		printf("��������������\n");
		printf("����� 2 ��ȭ�� �����\n");
		printf("��������������\n");
	break;
	
    case 13:             //����°�  
		printf("��������������\n");
		printf("��        <����>        ��\n");
		printf("��  (1)��ī-�ݶ�����    ��\n");
		printf("��  %4d ��             ��\n",dmafy[1][0]);
		printf("��  (2)��ī-�ݶ�        ��\n");
		printf("��  %4d ��             ��\n",dmafy[1][1]);
		printf("��  (3)īǪġ��         ��\n");
		printf("��  %4d ��             ��\n",dmafy[1][2]);
		printf("��  (4)�ٴҶ���ũ     ��\n");
		printf("��  %4d ��             ��\n",dmafy[1][3]);
		printf("��  (5)��������Ʈ       ��\n");
		printf("��  %4d ��             ��\n",dmafy[1][4]);
		printf("��  (6)����             ��\n");
		printf("��  %4d ��             ��\n",dmafy[1][5]);
		printf("��  (7)���̽��Ƹ޸�ī�� ��\n");
		printf("��  %4d ��             ��\n",dmafy[1][6]);
		printf("��                      ��\n");
		printf("��������������\n");
		printf("����� 3 ��ȭ�� �����\n");
		printf("��������������\n");
	break;
	
	case 20:              //���� ����
		printf("��������������\n");
		printf("��      <��������>      ��\n");
		printf("��                      ��\n");
		printf("��                      ��\n");
		printf("��   (1) 5%% ����        ��\n");
		printf("��                      ��\n");
		printf("��   (2) 10%% ����       ��\n");
		printf("��                      ��\n");
		printf("��   (3) 20%% ����       ��\n");
		printf("��                      ��\n");
		printf("��  ������ ��� ���ҽ�  ��\n");
		printf("��(y)�� �ٷ� �����ּ��� ��\n");
		printf("��                      ��\n");
		printf("��                      ��\n");
		printf("��                      ��\n");
		printf("��                      ��\n");
		printf("��             ������(y)��\n");
		printf("��������������\n");
		printf("����� ����ȭ�� �����\n");
		printf("��������������\n");
	break;
	}
}


