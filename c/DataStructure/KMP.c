#include<string.h>
#include<stdio.h>

#define NOTEXIST 0
typedef char* String;

//暴力匹配
//P:主串
//S:模式串
//begin:开始位置
int IndexOf(String P,String S,int begin){
    int parlen=strlen(P);
    int sublen=strlen(S);

    //主串当前位置
    int i=begin;
    //子串当前位置
    int j=1;
    while( i<=parlen && j<=sublen ){
        //暴力匹配
        if( P[i-1] == S[j-1] ){
            i++;
            j++;
        }
        else{
            //主串位置回溯+1 ------ 设原来位置为x,而j为已匹配的模式串字符数，则x+(j-1)=i,即x=i-(j-1).故x+1=i-(j-1)+1=i-j+2
            i=i-j+2;
            //模式串位置回溯为1
            j=1;
        }
    }
    //j>sublen说明模式串全部匹配成功，这时j=sublen+1,即sublen=j-1
    if(j>sublen){
        ///主串位置回溯 -------- x=i-(j-1)=i-sublen
        return i-sublen;
    }
    else{
        //全部检查完毕，未在主串中找到模式串
        return NOTEXIST;
    }
}

//生成字符串S的next数组
void GetNext(String S,int* next){
    int len=strlen(S);
    int i,j;
    i=1;   //字符序号
    j=0;
    next[1]=0;  //第一个字符
    while(i<len){
        if( j==0 || S[i]==S[j]){
            ++i;
            ++j;
            //第i个字符
            next[i]=j;
        }
        else{
            //j回溯
            j=next[j];
        }
    }
}

//KMP匹配算法第一版
int KMPIndex(String P,String S,int begin){
    int parlen=strlen(P);
    int sublen=strlen(S);

    //主串当前位置
    int i=begin;
    //子串当前位置
    int j=1;

    //获取next数组
    int next[255];
    GetNext(P,next);

    while( i<=parlen && j<=sublen ){
        if( j==0 || P[i-1]==S[j-1]){
            ++i;
            ++j;
        }
        else{
            //主串位置不回溯
            //模式串位置根据next数组回溯
            j=next[j];
        }
    }
    if(j>sublen){
        ///主串位置回溯 -------- x=i-(j-1)=i-sublen
        return i-sublen;
    }
    else{
        //全部检查完毕，未在主串中找到模式串
        return NOTEXIST;
    }
}

//生成字符串S的nextvar数组
void GetNextval(String S,int* nextval){
    int len=strlen(S);
    int i,j;
    i=1;   //字符序号
    j=0;
    nextval[1]=0;
    while(i<len){
        if( j==0 || S[i]==S[j]){
            ++i;
            ++j;
            if(S[i]!=S[j]){
                nextval[i]=j;
            }
            else{
                nextval[i]=nextval[j];
            }
        }
        else{
            j=nextval[j];
        }
    }
}

//KMP匹配算法第二版
int KMPIndex2(String P,String S,int begin){
    int parlen=strlen(P);
    int sublen=strlen(S);

    //主串当前位置
    int i=begin;
    //子串当前位置
    int j=1;

    //获取nextval数组
    int nextval[255];
    GetNextval(P,nextval);

    while( i<=parlen && j<=sublen ){
        if( j==0 || P[i-1]==S[j-1]){
            ++i;
            ++j;
        }
        else{
            //主串位置不回溯
            //模式串根据nextval回溯
            j=nextval[j];
        }
    }
    if(j>sublen){
        ///主串位置回溯 -------- x=i-(j-1)=i-sublen
        return i-sublen;
    }
    else{
        //全部检查完毕，未在主串中找到模式串
        return NOTEXIST;
    }
}

int main(void){
    String a="aaabbbcccsgxsxdgwcxvdgcvdgcvedcegdvewgdvwedgweydgehwxgwdhxwhxvwegxwegvxdcvdcbdcehcdhchdvcddd";
    String b="ab";
    int c=KMPIndex2(a,b,1);
    int d=KMPIndex(a,b,1);
    int e=IndexOf(a,b,1);
    printf("%d %d %d",c,d,e);
    getchar();
}
