#include <stdio.h>
typedef struct{
    int x[5][5];
}arr2d;
arr2d merge(int d[][5], int r){
    arr2d result;
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<4;j++){
            if(d[i][j]==d[i][j+1]&&d[i][j]!=0){
                d[i][j]=d[i][j]*2;
                d[i][j+1]=0;
            }
        }
    }
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            result.x[i][j]=d[i][j];
        }
    }
    return result;
}
arr2d compress(int d[][5], int r){
    arr2d newy;
    int w[5][5]={0};
    int i,j;
    int p;
    for(i=0;i<5;i++){
        p=0;
        for(j=0;j<5;j++){
            if(d[i][j]!=0){
                w[i][p]=d[i][j];
                p=p+1;
            }
        }
    }
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            newy.x[i][j]=w[i][j];
        }
    }
    return newy;
}
arr2d mirror(int d[][5],int r){
    int p,q;
    arr2d v;
    for(p=0; p<=4;p++){
        for(q=0; q<=4;q++){
            v.x[p][4-q]=d[p][q];
        }
    }
    return v;
}
arr2d arotate(int d[][5], int r){
    int p,q;
    arr2d v;
    for(p=0;p<=4;p++){
        for(q=0;q<=4;q++){
            v.x[p][q]=d[q][4-p];

        }
    }
    return v;
}
arr2d crotate(int d[][5], int r){
    int p,q;
    arr2d v;
    for(p=0;p<=4;p++){
        for(q=0;q<=4;q++){
            v.x[p][q]=d[4-q][p];

        }
    }
    return v;

}
arr2d adding2(int d[][5], int r){
    int k,l;
    arr2d result;
    k=rand()%5;
    l=rand()%5;
    while(d[k][l]!=0){
        k=rand()%5;
        l=rand()%5;
    }
    d[k][l]=2;
    for(int i=0;i<=4;i++){
        for(int j=0;j<=4;j++){
            result.x[i][j]=d[i][j];
        }
    }
    return result;
}
void printarray(int d[][5],int r){
    int i,j;
    for(i=0;i<=4;i++){
        for(j=0;j<=4;j++){
            printf("%d\t",d[i][j]);

        }
        printf("\n");
    }

}
arr2d shiftright(int g[][5],int r){
    arr2d b,c;
    b=mirror(g,5);
    c=compress(b.x,5);
    b=merge(c.x,5);
    c=compress(b.x,5);
    b=mirror(c.x,5);
    c=adding2(b.x,5);
    printarray(c.x,5);
    return c;

}
arr2d shiftleft(int g[][5],int r){
    arr2d b,c;
    b=compress(g,5);
    c=merge(b.x,5);
    b=compress(c.x,5);
    c=adding2(b.x,5);
    printarray(c.x,5);
    return c;
}
arr2d shiftup(int g[][5], int r){
    arr2d b,c;
    b=arotate(g,5);
    c=compress(b.x,5);
    b=merge(c.x,5);
    c=compress(b.x,5);
    b=crotate(c.x,5);
    c=adding2(b.x,5);
    printarray(c.x,5);
    return c;

}
arr2d shiftdown(int g[][5],int r){
    arr2d b,c;
    b=crotate(g,5);
    c=compress(b.x,5);
    b=merge(c.x,5);
    c=compress(b.x,5);
    b=arotate(c.x,5);
    c=adding2(b.x,5);
    printarray(c.x,5);
    return c;
}
int main() {
    char move;
    char game='y';
    int r,c;
    int o[5][5]={0};
    while(game=='y'){
            char cont='y';
            arr2d t;
            for(int i=0;i<=4;i++){
                    for(int j=0;j<=4;j++){
            t.x[i][j]=o[i][j];}}
            r=rand()%5;
            c=rand()%5;
            t.x[r][c]=2;
            printarray(t.x,5);
            while(cont=='y'){

	printf("enter move \n r l u d \n");
	scanf("%s",&move);
	switch(move){
	    case 'r':
	    t=shiftright(t.x,5);

	    break;
	    case 'l':
	    t=shiftleft(t.x,5);

	    break;
	    case 'u':
	    t=shiftup(t.x,5);

	    break;
	    case 'd':
	    t=shiftdown(t.x,5);



}
int flag=1;
for(int i=0;i<=4;i++){
    for(int j=0;j<=4;j++){
        if(t.x[i][j]==0){
            flag=0;
            break;
        }
        }
    }
    if(flag!=0) break;

printf("continue y or n\n");
scanf("%s",&cont);
            }
            printf("replay: y or n \n");
            scanf("%s",&game);

    }


return 0;
}
