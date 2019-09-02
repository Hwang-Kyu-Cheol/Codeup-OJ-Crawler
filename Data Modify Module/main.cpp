/*
    **********************************
    *                                *
    *  Modify Raw_Data by codeup38   *
    *                                *
    **********************************
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

typedef struct __str{

    char ID[30];
    char checkSolve[7000];
    int countSuccess;
    int countFailSubmit;
    int totalSubmit;

    bool isOccupied;
    /*
        * ID = ȸ�� ID ����
        * checkSolve = �ش� ���� ��ȣ�� �ε����� ���.
        (�ش� �Ⱓ ����) 0�� Ǯ�� ������, 1�� Ǯ������ �ǹ���.
        * countSuccess = ��Ȯ�� Ǯ�̰� �� �� ���Դ����� �ǹ���.(�ش� �Ⱓ �� �ߺ� ����)
        * countFailSubmit = ��Ȯ�� Ǯ�� �̿��� ����� ���� Ƚ���� �ǹ���.
        * totalSubmit = ��� �����ߴ��� Ȯ���ϴµ� ���.
        * isOccupied = �̹� ������ �Էµ� �ε������� Ȯ���ϴ� ���� ���.
    */
}ident;

typedef struct __problem{

    int num;
    int submit;
    /*
        * num = ���� ��ȣ
        * submit = �ش� ���� ���� Ƚ��
    */
}prob;


ident check[30001]; // check[] ����
prob probSub[7000];

int idlimit;

void clearStruct() // �ʱ�ȭ ���ִ� �Լ�
{
    for(int i=0; i<30001; i++) {
        for(int k=0; k<7000; k++) {

            if(k<30) check[i].ID[k] = check[i].checkSolve[k] = 0;
            else check[i].checkSolve[k] = 0;
        }

        check[i].isOccupied = false;
        check[i].totalSubmit =
        check[i].countFailSubmit =
        check[i].countSuccess = 0;

    }

    for(int i=0; i<7000; i++) probSub[i].num = i, probSub[i].submit = 0;

    return;
}

bool compareAC(ident a, ident b)
{
    if(a.countSuccess == b.countSuccess) return a.countFailSubmit <= b.countFailSubmit;
    else return a.countSuccess > b.countSuccess;
}

bool compareSub(ident a, ident b)
{
    if(a.totalSubmit == b.totalSubmit) return a.countSuccess >= b.countSuccess;
    else return a.totalSubmit > b.totalSubmit;
}

bool compareFail(ident a, ident b)
{
    if(a.countFailSubmit == b.countFailSubmit) return a.totalSubmit >= b.totalSubmit;
    else return a.countFailSubmit > b.countFailSubmit;
}

bool compareProb(prob a, prob b) {  if(a.submit == b.submit) return a.num > b.num;
                                          else return a.submit > b.submit; }

void printAcList() // AC ���� ������� ���
{
    FILE *printAC = fopen("Rank List/AC_Rank.txt","w");

    std::sort(check, check + idlimit, compareAC);

    for(int i = 0; i < idlimit; i++) {
        if(check[i].countSuccess == 0) break;

        fprintf(printAC,"|%d|%s|%d|\n", i+1, check[i].ID, check[i].countSuccess);
    }

    fclose(printAC);

    return;
}

void printSubmitList() // ���� Ƚ�� ������� ��� (�ߺ� ����)
{
    FILE *printSub = fopen("Rank List/Total_Submit_Rank.txt","w");

    std::sort(check, check + idlimit, compareSub);

    for(int i = 0; i < idlimit; i++) {
        if(check[i].totalSubmit == 0) break;

        fprintf(printSub,"|%d|%s|%d|\n", i+1, check[i].ID, check[i].totalSubmit);
    }

    fclose(printSub);

    return;
}

void printFailList() // Ʈ�� ������� ���(Ʋ�� ���� ����)
{
    FILE *printFail = fopen("Rank List/Troll_Rank.txt","w");

    std::sort(check, check + idlimit, compareFail);

    for(int i = 0; i < idlimit; i++) {
        if(check[i].countFailSubmit == 0) break;

        fprintf(printFail,"|%d|%s|%d|\n", i+1, check[i].ID, check[i].countFailSubmit);
    }

    fclose(printFail);

    return;
}

void printProblemList() // ���� ���� �� ���� ������� ���
{
    FILE *printProblem = fopen("Rank List/Problem_Rank.txt","w");

    std::sort(probSub, probSub + 7000, compareProb);

    for(int i = 0; i < 7000; i++) {
        if(probSub[i].submit == 0) break;

        fprintf(printProblem,"|%d|%d|%d|\n", i+1, probSub[i].num, probSub[i].submit);
    }

    fclose(printProblem);

    return;
}

void printProblemSkipList() // ���� ���� �� ���� ������� ���, ** �� 1000���� ������ ���� **
{
    FILE *printSkipProblem = fopen("Rank List/Problem_Skip_Rank.txt","w");

    std::sort(probSub, probSub + 7000, compareProb);

    int ranked = 1;

    for(int i = 0; i < 7000; i++) {
        if(probSub[i].submit == 0) break;

        if(probSub[i].num >= 2000) fprintf(printSkipProblem, "|%d|%d|%d|\n", ranked++, probSub[i].num, probSub[i].submit);
    }

    fclose(printSkipProblem);

    return;
}

int main()
{
    FILE *readF = fopen("raw_data.txt","r");

    int submitNum, problemNum, memory, time, byte, submitCount = 0, index = 0;
    char inputID[30], submitRes[20], lang[10], submitTime[20];
    bool noMatch = true;

    clearStruct();

    /*
        About Variables ::

        <int>
        * submitNum = ���� ��ȣ
        * problemNum = ���� ��ȣ
        * memory = ����� �޸�
        * time = �ҽ� �ڵ� ���� �ð�
        * byte = �ҽ� �ڵ� ����(B)
        * submitCount = ũ�Ѹ��� ���� ��� ����

        <char>
        * inputID[30] = ȸ�� ID
        * submitRes[10] = ä�� ���
        * lang[7] = ��� ���
        * submitTime[8] = ���� �ð� { ** ���� time�� ȥ������ �� �� ** }
    */

    int inputDataCheck;

    puts("Input data�� ������ ������ Ȯ���Ͽ����ϱ�?\nȮ���Ͽ����� 1, Ȯ������ �ʾ����� 0�� �����ּ���.");
    printf(": "); scanf("%d", &inputDataCheck);

    if(inputDataCheck == 0) { puts("Ȯ�� ��Ź�帮��, ���α׷��� ����˴ϴ�."); fflush(stdin); getchar(); return 0; }


    while(~fscanf(readF,"%d %s  %d %s %d %d %s %d B %[^\n]s ", &submitNum, inputID, &problemNum, submitRes, &memory, &time, lang, &byte, submitTime)) {

        /*
            raw_data.txt ������ ���� Ȯ�� �ʼ�
            ���� ���� �ð��� �����Ǵ� ��� ����
        */

        probSub[problemNum].submit++;

        while(check[index].isOccupied == true) {

            if(!strcmp(check[index].ID,inputID)) {
                if(check[index].checkSolve[problemNum]) { check[index].totalSubmit++; index++; noMatch = false; break; }

                if(!strcmp(submitRes,"��Ȯ��Ǯ��")) check[index].checkSolve[problemNum] = 1, check[index].countSuccess++;
                else check[index].countFailSubmit++;


                check[index].totalSubmit++;

                index++;
                noMatch = false;
                break;
            }

            index >= 30000 ? puts("������ �Ѿ���ϴ�. Ctrl-C�� ������Ų �� check[]�� ũ�⸦ �÷��ּ���.") : index++;
        }

        if(!index || (noMatch == true)) {
            check[index].isOccupied = true;

            strcpy(check[index].ID,inputID);

            if(!strcmp(submitRes,"��Ȯ��Ǯ��")) check[index].checkSolve[problemNum] = 1, check[index].countSuccess++;
            else check[index].countFailSubmit++;


            check[index].totalSubmit++;

            idlimit = index + 1;
        }

        index = 0;
        noMatch = true;

        submitCount++;

        printf(" Now On : %d\n", submitCount);
    }

    /*
        *   while + fscanf�� �Է¹���
        *
        *   �ݺ����� ���� ������ ID�� ������ �ش� �ε������� �̹� Ǭ ��������/���� ����� ���/����̳� Ʋ�ȴ��� ���� ������ ������
        *   ù ��° ���� ���(�Է� ù��) ó���� ó�� ������ ID�� ���� ID�� �����ϰ� ���Ŀ� �̹� Ǭ ��������/���� ����� ���/����̳� Ʋ�ȴ��� ���� ������ ������

        *   �⺻���� ������
        *   ID�� �ߺ����� Ȯ�� -> �̹� Ǭ �������� Ȯ�� -> �������� Ȯ��(��Ǯ) �� ������ ��ģ��
    */

    fclose(readF);

    printf("\n�ش� �Ⱓ���� �ڵ���� �̿��� ȸ�� ���� %d������ ����Ǿ����ϴ�.\n\n", idlimit);

    printAcList();

    puts("AC ���� ��� �Ϸ�!");

    printSubmitList();

    puts("�ҽ� ���� ���� ���� ���� ��� �Ϸ�!");

    printFailList();

    puts("Ʈ�� ���� ��� �Ϸ�!");

    printProblemList();
    printProblemSkipList();

    puts("���� Ǭ ���� ���� ��� �Ϸ�!");

    puts("");

    puts("All Done!\n\nEnjoy :)");

    fflush(stdin); getchar(); // exe ���� �ٷ� �� ������

    return 0;
}
