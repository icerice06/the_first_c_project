// 이코드는 맥도날드 주문 기계의 기능을  
// 따라 만들어서 주문을 받고 주문받은 내용을  
// txt파일로 옴겨서 주방에서 일하는 사람에게 보여줄수 
// 있고 주문 할인과 가격 등을 볼수 있습니다. 

#include<stdio.h> 
#include<windows.h> //클리어 코드를 쓰기 위해서 

int qjrj[2][7]={{3300,5700,4400,2200,4600,2300,5500},{0,}};   //버거 배열
int tkdlem[2][7]={{1800,2200,1800,2600,2500,1200,3000},{0,}}; //사이드 배열
int dmafy[2][7]={{1400,1400,2200,2500,1400,1500,1700},{0,}};  //음료 배열

float gkfdlsznvhs=1;  //할인 쿠폰 1인 이유는 할인을 원하지 않을경우 곱해도 아무 상관이 없기 때문
int qjrjc=0;          //버거금액 총금액
int tkdlemc=0;        //사이드금액 총금액
int dmafyc=0;         //음료금액 총금액 
int thssla=0;         //손님카운트 총금액

int ghkaus(int);      //화면 함수의 역할은 화면 이동 

int main(){           //main함수의 역할은 비교 
	system("mode con:cols=26 lines=21");//콘솔창 크기 고정 
	FILE *fp;         //txt파일 이것은 알르바이트가 받고 요리할 주문서 입니다 
	fp = fopen("주문서.txt", "w"); //파일 만들기 위에서 설명한 것을 저장할 파일 
	fprintf(fp,"\n"); //파일 초기화 \n으로 한이유는 이전에 쓴 파일을 지위기 위해서 아직 파일을 클리어 하는 방법을 모름  
	int a=0;          //페이지 위치 변수 0인 이유는 맥도날드가 나오는 화면   a로 인하여 화면 함수에서 스위치 코드가 사용됨 
	char b;           //입력받는 모든 값 명령 받는 모든 값  [체어X   캐릭터]
	ghkaus(a);        //시작시 매인 화면으로 시작 
	while(1){         //무한 반복 @받으면 멈춤 
	scanf("%c",&b);   //화면 바꾸는 변수 
	system("cls");    //화면 클리어 함수
					  //초기 설정을 끝마치면 실행
	
	switch(b){ //@이를 받기 전까지 무한 반복 
		case '@': if(a==0){
		return 0;               //0번째 즉 m도날드 화면에서만 전원버튼 사용 
		};                      //전원 버튼
		break;
		
		case '>': a++;          //이동 오른쪽 
		break;
		
		case '<': a--;          //이동 왼쪽
		break;
		
		case 'v': if(a<4&&a>0)  // 1부터 3페이지 까지 가능 한마디로 주문 화면에서만 가능 
		{
		a=20;
		};                     //할인 쿠폰 이동
		break;
		
		case 'y': if(a>9)  //쿠폰 화면과 결제 화면에서만 사용 가능 
		{
		a=10; 
		};               //쿠폰 사용 안하고 넘기기
		break;
	}
	
	switch(a){           //페이지를 스위치로 바꾸다 보니 페이지를 만들지 않은 곳은 아무 출력이 없기때문에 막아두는 역할을 해준다 
		case -1: a=0;    //화면 페이지 아상 가지마
		break;
		
		case 4: a=1;     //3번 페이지 이상 가지마
		break;
		
		case 9: a=13;     //결제 페이지 이상 가지마
		break;
		
		case 14: a=10;    //결제  페이지 이상 가지마
		break;
		
		case 21: a=20;   //할인쿠폰 화면 이상 가지마 
		break;
		
		case 19: a=20;   //할인쿠폰 화면 이상 가지마 
		break;
	}

	
	if(b=='x')        //결제 취소  모든 변수 배열 초기화 배열은 가겨 ?馨 
	{
		for(int i=0;i<7;i++){   //횟수 초기화 
			qjrj[1][i]=0;
		}
		for(int i=0;i<7;i++){   //횟수 초기화 
			tkdlem[1][i]=0;
		}
		for(int i=0;i<7;i++){   //횟수 초기화 
			dmafy[1][i]=0;
		}
		gkfdlsznvhs=1; //할인 쿠폰
		qjrjc=0;       //버거금액
		tkdlemc=0;     //사이드금액 
		dmafyc=0;      //음료금액 
		a=0;           //화면 초기화 
	}
	if(b=='c')         //다음 주문 
	{
		thssla++;      //다음 주문 실행을 받으면 다음 손님 주문 받기전 손님의 주문을 저장한다
		fprintf(fp,"%d번 손님\n",thssla);
		fprintf(fp,"\n햄버거\n");
		for(int i=0;i<7;i++){
			if(0!=qjrj[1][i]){          //주문하지 않은 매뉴는 출력하지 않는다 
			fprintf(fp,"%d메뉴 %d개\n",i+1,qjrj[1][i]);      //txt 파일로 옴기기 
			}
		} 
		fprintf(fp,"\n사이드\n");
		for(int i=0;i<7;i++){
			if(0!=tkdlem[1][i]){
			fprintf(fp,"%d메뉴 %d개\n",i+1,tkdlem[1][i]);
			}
		}
		fprintf(fp,"\n음료\n");
		for(int i=0;i<7;i++){
			if(0!=dmafy[1][i]){
			fprintf(fp,"%d메뉴 %d개\n",i+1,dmafy[1][i]);
			}
		}
		fprintf(fp,"\n");    
		//txt파일로 옴기고 난후 데이터 초기화 
		for(int i=0;i<7;i++){    //횟수 초기화 
			qjrj[1][i]=0;
		}
		for(int i=0;i<7;i++){    //횟수 초기화 
			tkdlem[1][i]=0;
		}
		for(int i=0;i<7;i++){    //횟수 초기화 
			dmafy[1][i]=0;
		}
		gkfdlsznvhs=1;  //할인 쿠폰 
		qjrjc=0;        //버거금액
		tkdlemc=0;      //사이드금액 
		dmafyc=0;       //음료금액
		a=0;            //화면 초기화 
	}
	
	if(a==20){         //할인 화면에서 할인 받을 퍼센트 저장 
		switch(b){
			case '1':
				gkfdlsznvhs=0.95;  //5%
				a=10;              //할인 받고 결제 화면으로 가기 
			break;
			
			case '2':
				gkfdlsznvhs=0.9;   //10%
				a=10;              //할인 받고 결제 화면으로 가기
			break;
			
			case '3':
				gkfdlsznvhs=0.8;   //20%
				a=10; 		       //할인 받고 결제 화면으로 가기
			break;	
		}
	} 
	
	if(a==1){       //버거 화면에서 카운트 
		switch(b){
			case '1':qjrj[1][0]++;
			break;
			case '2':qjrj[1][1]++;        //0번째 줄은 가격 이기 ??문에 0줄 가격 바로 밑에 카운트 
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
	
	if(a==2){       //사이드 화면에서 카운트 
		switch(b){
			case '1':tkdlem[1][0]++;
			break;
			case '2':tkdlem[1][1]++;       //0번째 줄은 가격 이기 ??문에 0줄 가격 바로 밑에 카운트 
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
	
	if(a==3){        //음료 화면에서 카운터
		switch(b){
			case '1':dmafy[1][0]++;
			break;
			case '2':dmafy[1][1]++;
			break;
			case '3':dmafy[1][2]++;     //0번째 줄은 가격 이기 ??문에 0줄 가격 바로 밑에 카운트 
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
	
	ghkaus(a);  //위에서 a값 저장 한것 불러와 화면 바꾸기 
	}
}


int ghkaus(int a){   //화면 함수 
	switch(a){       //화면 바꾸는 스위치
	case 0:          //처음 화면 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);  //로고 색깔 변경 15는 화이트 14는 노랑 
		printf("■■■■■■■■■■■■■\n");
		printf("■                      ■\n");
		printf("■                      ■\n");    
		printf("■                      ■\n");   
		printf("■                      ■\n");
		printf("■                      ■\n");
		printf("■");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("    ■■■  ■■■    ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		printf("■\n■");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14); 
		printf("  ■■  ■■■  ■■  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		printf("■\n■");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("  ■      ■      ■ ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		printf(" ■\n■");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("  ■      ■      ■ ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		printf(" ■\n■");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("  ■      ■      ■  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		printf("■\n■");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("  ■      ■      ■  ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		printf("■\n");
		printf("■                      ■\n");
		printf("■      [맥도날드]      ■\n");
		printf("■                      ■\n");
		printf("■                      ■\n");
		printf("■      화면 넘기기(>,<)■\n");
		printf("■■■■■■■■■■■■■\n");
		printf("■■■화면은 1~3까지■■■\n");
		printf("■■■■■■■■■전원 @■\n");
	break;
	
	case 1://버거 화면 
		printf("■■■■■■■■■■■■■\n");
		printf("■        <버거>        ■\n");
		printf("■  (1)맥치킨           ■\n");
		printf("■  \\ 3,300     %4d 개 ■\n",qjrj[1][0]);  //카운트는 main에서 하고 여기는 받아온 값 출력 
		printf("■  (2)1955?버거       ■\n");
		printf("■  \\ 5,700     %4d 개 ■\n",qjrj[1][1]);
		printf("■  (3)더블띠드버거     ■\n");
		printf("■  \\ 4,400     %4d 개 ■\n",qjrj[1][2]);
		printf("■  (4)불고기버거       ■\n");
		printf("■  \\ 2,200     %4d 개 ■\n",qjrj[1][3]);
		printf("■  (5)빅맥             ■\n");
		printf("■  \\ 4,600     %4d 개 ■\n",qjrj[1][4]);
		printf("■  (6)띠드버거         ■\n");
		printf("■  \\ 2,300     %4d 개 ■\n",qjrj[1][5]);
		printf("■  (7)슈비버거         ■\n");
		printf("■  \\ 5,500     %4d 개 ■\n",qjrj[1][6]);
		printf("■             결제는(v)■\n");
		printf("■■■■■■■■■■■■■\n");
		printf("■■■■ 1 번화면 ■■■■\n");
		printf("■■■■■■■■■■■■■\n");
	break;
	
	case 2://사이드 화면 
		printf("■■■■■■■■■■■■■\n");
		printf("■       <사이드>       ■\n");
		printf("■  (1)맥너겟           ■\n");
		printf("■  \\ 1,800     %4d 개 ■\n",tkdlem[1][0]);
		printf("■  (2)상하이치킨스낵랩 ■\n");
		printf("■  \\ 2,200     %4d 개 ■\n",tkdlem[1][1]); //카운트는 main에서 하고 여기는 받아온 값 출력 
		printf("■  (3)후렌치후라이     ■\n");
		printf("■  \\ 1,800     %4d 개 ■\n",tkdlem[1][2]);
		printf("■  (4)모짜렐라치즈스틱	■\n");
		printf("■  \\ 2,600     %4d 개 ■\n",tkdlem[1][3]);
		printf("■  (5)오레오맥플러리   ■\n");
		printf("■  \\ 2,500     %4d 개 ■\n",tkdlem[1][4]);
		printf("■  (6)애플파이         ■\n");
		printf("■  \\ 1,200     %4d 개 ■\n",tkdlem[1][5]);
		printf("■  (7)오레오아포가토   ■\n");
		printf("■  \\ 3,000     %4d 개 ■\n",tkdlem[1][6]);
		printf("■             결제는(v)■\n");
		printf("■■■■■■■■■■■■■\n");
		printf("■■■■ 2 번화면 ■■■■\n");
		printf("■■■■■■■■■■■■■\n");
	break;
	
    case 3://음료 화면 
		printf("■■■■■■■■■■■■■\n");
		printf("■        <음료>        ■\n");
		printf("■  (1)코카-콜라제로    ■\n");
		printf("■  \\ 1,400     %4d 개 ■\n",dmafy[1][0]);
		printf("■  (2)코카-콜라        ■\n");
		printf("■  \\ 1,400     %4d 개 ■\n",dmafy[1][1]); //카운트는 main에서 하고 여기는 받아온 값 출력 
		printf("■  (3)카푸치노         ■\n");
		printf("■  \\ 2,200     %4d 개 ■\n",dmafy[1][2]);
		printf("■  (4)바닐라쉐이크     ■\n");
		printf("■  \\ 2,500     %4d 개 ■\n",dmafy[1][3]);
		printf("■  (5)스프라이트       ■\n");
		printf("■  \\ 1,400     %4d 개 ■\n",dmafy[1][4]);
		printf("■  (6)우유             ■\n");
		printf("■  \\ 1,500     %4d 개 ■\n",dmafy[1][5]);
		printf("■  (7)아이스아메리카노 ■\n");
		printf("■  \\ 1,700     %4d 개 ■\n",dmafy[1][6]);
		printf("■             결제는(v)■\n");
		printf("■■■■■■■■■■■■■\n");
		printf("■■■■ 3 번화면 ■■■■\n");
		printf("■■■■■■■■■■■■■\n");
	break;
	
	case 10:								//결제 화면 
		qjrjc=0; //버거금액
		tkdlemc=0; //사이드금액 
		dmafyc=0; //음료금액 
		
		for(int i=0; i<7; i++){				//버거 
			for(int j=0; j<qjrj[1][i];j++){
				qjrjc+=qjrj[0][i];
			}
		}
		
		for(int i=0; i<7; i++){				//사이드 
			for(int j=0; j<tkdlem[1][i];j++){
				tkdlemc+=tkdlem[0][i];
			}
		}
		
		for(int i=0; i<7; i++){				//음료 
			for(int j=0; j<dmafy[1][i];j++){
				dmafyc+=dmafy[0][i];
			}
		}
		
		printf("■■■■■■■■■■■■■\n");
		printf("■                      ■\n");
		printf("■ 버거금액             ■\n");
		printf("■ %17d \\  ■\n",qjrjc);					//금액 자리수가 늘어나도 고정 
		printf("■ 사이드금액           ■\n");
		printf("■ %17d \\  ■\n",tkdlemc);
		printf("■ 음료금액             ■\n");
		printf("■ %17d \\  ■\n",dmafyc);
		printf("■                      ■\n");
		printf("■ 원가 %12d \\  ■\n",qjrjc+tkdlemc+dmafyc);
		printf("■ 할인가 %10.0f \\  ■\n",(float)(qjrjc+tkdlemc+dmafyc)*(1-gkfdlsznvhs));
		printf("■ 총금액 %10.0f \\  ■\n",(float)(qjrjc+tkdlemc+dmafyc)*gkfdlsznvhs);
		printf("■ 농협                 ■\n");
		printf("■ 356-1525-9678-13     ■\n");
		printf("■           주문취소(x)■\n");
		printf("■           주문완료(c)■\n");
		printf("■         뭘샀는가(>,<)■\n");
		printf("■■■■■■■■■■■■■\n");
		printf("■■■■ 결제금액 ■■■■\n");
		printf("■■■■■■■■■■■■■\n");
	break;
	
	case 11:               //뭘샀는가 
		printf("■■■■■■■■■■■■■\n");
		printf("■        <버거>        ■\n");
		printf("■  (1)맥치킨           ■\n");
		printf("■  %4d 개             ■\n",qjrj[1][0]);
		printf("■  (2)1955?버거       ■\n");
		printf("■  %4d 개             ■\n",qjrj[1][1]);
		printf("■  (3)더블띠드버거     ■\n");
		printf("■  %4d 개             ■\n",qjrj[1][2]);
		printf("■  (4)불고기버거       ■\n");
		printf("■  %4d 개             ■\n",qjrj[1][3]);
		printf("■  (5)빅맥             ■\n");
		printf("■  %4d 개             ■\n",qjrj[1][4]);
		printf("■  (6)띠드버거         ■\n");
		printf("■  %4d 개             ■\n",qjrj[1][5]);
		printf("■  (7)슈비버거         ■\n");
		printf("■  %4d 개             ■\n",qjrj[1][6]);
		printf("■                      ■\n");
		printf("■■■■■■■■■■■■■\n");
		printf("■■■■ 1 번화면 ■■■■\n");
		printf("■■■■■■■■■■■■■\n");
	break;
	
	case 12:              //뭘샀는가  
		printf("■■■■■■■■■■■■■\n");
		printf("■       <사이드>       ■\n");
		printf("■  (1)맥너겟           ■\n");
		printf("■  %4d 개             ■\n",tkdlem[1][0]);
		printf("■  (2)상하이치킨스낵랩 ■\n");
		printf("■  %4d 개             ■\n",tkdlem[1][1]);
		printf("■  (3)후렌치후라이     ■\n");
		printf("■  %4d 개             ■\n",tkdlem[1][2]);
		printf("■  (4)모짜렐라치즈스틱	■\n");
		printf("■  %4d 개             ■\n",tkdlem[1][3]);
		printf("■  (5)오레오맥플러리   ■\n");
		printf("■  %4d 개             ■\n",tkdlem[1][4]);
		printf("■  (6)애플파이         ■\n");
		printf("■  %4d 개             ■\n",tkdlem[1][5]);
		printf("■  (7)오레오아포가토   ■\n");
		printf("■  %4d 개             ■\n",tkdlem[1][6]);
		printf("■                      ■\n");
		printf("■■■■■■■■■■■■■\n");
		printf("■■■■ 2 번화면 ■■■■\n");
		printf("■■■■■■■■■■■■■\n");
	break;
	
    case 13:             //뭘샀는가  
		printf("■■■■■■■■■■■■■\n");
		printf("■        <음료>        ■\n");
		printf("■  (1)코카-콜라제로    ■\n");
		printf("■  %4d 개             ■\n",dmafy[1][0]);
		printf("■  (2)코카-콜라        ■\n");
		printf("■  %4d 개             ■\n",dmafy[1][1]);
		printf("■  (3)카푸치노         ■\n");
		printf("■  %4d 개             ■\n",dmafy[1][2]);
		printf("■  (4)바닐라쉐이크     ■\n");
		printf("■  %4d 개             ■\n",dmafy[1][3]);
		printf("■  (5)스프라이트       ■\n");
		printf("■  %4d 개             ■\n",dmafy[1][4]);
		printf("■  (6)우유             ■\n");
		printf("■  %4d 개             ■\n",dmafy[1][5]);
		printf("■  (7)아이스아메리카노 ■\n");
		printf("■  %4d 개             ■\n",dmafy[1][6]);
		printf("■                      ■\n");
		printf("■■■■■■■■■■■■■\n");
		printf("■■■■ 3 번화면 ■■■■\n");
		printf("■■■■■■■■■■■■■\n");
	break;
	
	case 20:              //할인 쿠폰
		printf("■■■■■■■■■■■■■\n");
		printf("■      <할인쿠폰>      ■\n");
		printf("■                      ■\n");
		printf("■                      ■\n");
		printf("■   (1) 5%% 할인        ■\n");
		printf("■                      ■\n");
		printf("■   (2) 10%% 할인       ■\n");
		printf("■                      ■\n");
		printf("■   (3) 20%% 할인       ■\n");
		printf("■                      ■\n");
		printf("■  쿠폰을 사용 안할시  ■\n");
		printf("■(y)를 바로 눌려주세요 ■\n");
		printf("■                      ■\n");
		printf("■                      ■\n");
		printf("■                      ■\n");
		printf("■                      ■\n");
		printf("■             결제는(y)■\n");
		printf("■■■■■■■■■■■■■\n");
		printf("■■■■ 쿠폰화면 ■■■■\n");
		printf("■■■■■■■■■■■■■\n");
	break;
	}
}


