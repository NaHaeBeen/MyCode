#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *nodeptr;
typedef struct node
{
    char ch;       // character in this node
    long int bp;   // a byte position in the master file
    nodeptr right; // a horizontal pointer
    nodeptr below; // a vertical poiner
} nodetype;
typedef struct record
{
    char word[50];
    int widx;
    int wfreq;
} ty_rec;
typedef struct correct_result
{
    char word[100];     // the result of correction
    int ns, nd, ni, nt; // number of substitution, deletion, insertion, transposistion
    float penalty;      // penalty score
} ty_correction;

///////////////////////////////////////////////////////////////////////////////////////////////
// Global variables가 주어진다.
///////////////////////////////////////////////////////////////////////////////////////////////
nodeptr root = NULL;
ty_correction cwords[20000];
int nres = 0;
int found_perfect_match = 0;

///////////////////////////////////////////////////////////////////////////////////////////////
// 아래 함수는 guide로 주어지며 별도로 작성할 필요가 없다.
///////////////////////////////////////////////////////////////////////////////////////////////
void sort_results(ty_correction cwords[]);
int printed(char printed_words[][100], char aword[], int total);
// void main(); 함수 또한 별도로 작성할 필요가 없다.

///////////////////////////////////////////////////////////////////////////////////////////////
// 아래 선언된 함수는 아래 정의에서 직접 작성하거나 수정한다.
///////////////////////////////////////////////////////////////////////////////////////////////
int search_trie(char key[], nodeptr *curr, nodeptr *prev);
nodeptr hang_down(char key[], nodeptr tn, int i);
nodeptr insert_trie(char key[50]);

void transposition(nodeptr root_sub_trie, char key[], char corr_key[], int ki, int ci, int n_s, int n_d, int n_i, int n_t);
void substitution(nodeptr root_sub_trie, char key[], char corr_key[], int ki, int ci, int n_s, int n_d, int n_i, int n_t);
void deletion(nodeptr root_sub_trie, char key[], char corr_key[], int ki, int ci, int n_s, int n_d, int n_i, int n_t);
void insertion(nodeptr root_sub_trie, char key[], char corr_key[], int ki, int ci, int n_s, int n_d, int n_i, int n_t);

float get_penalty(int n_s, int n_d, int n_i, int n_t);
void find_with_spell_correction(nodeptr root_sub_trie, char key[], char corr_key[], int ki, int ci, int n_s, int n_d, int n_i, int n_t);
void output_top_corrections();

///////////////////////////////////////////////////////////////////////////////////////////////
// 아래는 위에서 선언된 함수의 정의부 이다. 직접 작성하거나 수정하여 완성한다.
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////
// 1단계: (레코드 저장) 주어진 파일의 정보를 모두 삽입하는 코드를 작성한다.
///////////////////////////////////////////////////////////////////////////////////////////////

int search_trie(char key[], nodeptr *curr, nodeptr *prev)
{
    /*
     * Fill
     * codes
     */
} // search_trie

/* Fill codes */
nodeptr hang_down(char key[], nodeptr tn, int i)
{
    nodeptr newn;
    while (key[i] != '\0')
    {
        newn = (nodeptr)malloc(sizeof(nodetype));
        /*
         * Fill
         * codes
         */
    }

    newn = (nodeptr)malloc(sizeof(nodetype));
    /*
     * Fill
     * codes
     */
    return newn;
} // hang_down

nodeptr insert_trie(char key[50])
{
    int i;
    char c;
    nodeptr tn, curr, prev, last = NULL; // used to indicate insertion position

    // if root is NULL, this is special case of empty trie.
    if (root == NULL)
    {
        // nothing in the trie. insert the first one.
        tn = (nodeptr)malloc(sizeof(nodetype));
        tn->ch = key[0];
        root = tn;
        tn->right = NULL;
        last = hang_down(key, tn, 1);
        return last;
    }

    // insert전, search를 실행하여 탐색을 진행한다.
    // curr, prev 는 탐색이 정지한 곳을 가리킨다.
    // curr, prev 새로 넣을 노드를 넣도록 한다.
    i = search_trie(key, &curr, &prev);

    // search를 수행했을때, 삽입하고자 하는 값인 key가 TRIE에서 존재하는 것을 확인한 경우 -1을 반환한다.
    // 이때, 현재 삽입하고자 하는 값인 key를 삽입하지 않고 insert를 수행하지 않고 반환한다.
    if (i == -1)
    {
        printf("insert fails since it already exists in trie. key = %s\n", key);
        return NULL; // NULL을 반환하여 삽입 실패를 알린다.
    }

    // i != -1인경우 아래 코드를 실행한다.
    // case 0
    if (prev == NULL)
    {
        /*
         * Fill
         * codes
         */
    }
    // case 1
    else if ((prev->below != NULL) && prev->below == curr)
    {
        /*
         * Fill
         * codes
         */
    }
    // case 2
    else if (prev->right == curr && curr != NULL)
    {
        /*
         * Fill
         * codes
         */
    }
    // case 3
    else if (prev->right == curr && curr == NULL)
    {
        /*
         * Fill
         * codes
         */
    }
    else
    {
        printf("Logic error in insertion. Control reaches the position where it can't.\n");
        c = getchar();
    }

    return last; // success of insertion. return pointer to the last node.
} // function  insert_trie.

///////////////////////////////////////////////////////////////////////////////////////////////
//  2단계: (기능 개발) TRIE를 탐색하는 코드를 작성한다.
///////////////////////////////////////////////////////////////////////////////////////////////
void substitution(nodeptr root_sub_trie, char key[], char corr_key[], int ki, int ci, int n_s, int n_d, int n_i, int n_t)
{
    nodeptr np, start_ptr;
    int temp;
    char new_corr_key[100];
    strcpy(new_corr_key, corr_key); // 새로운 교정된 문자열 공간을 만들어 지금까지의 결과를 저장한다.
    np = root_sub_trie;
    do
    {
        /*
         * Fill
         * codes
         */
    } while (np);
    return;
} // substitution

void deletion(nodeptr root_sub_trie, char key[], char corr_key[], int ki, int ci, int n_s, int n_d, int n_i, int n_t)
{
    nodeptr np, start_ptr;
    int temp;
    char new_corr_key[100];
    strcpy(new_corr_key, corr_key); //  corr_key string is copied to another space to protect corr_key from later change.
    np = root_sub_trie;
    do
    {
        /*
         * Fill
         * codes
         */
    } while (np);
    return;
} // deletion

void insertion(nodeptr root_sub_trie, char key[], char corr_key[], int ki, int ci, int n_s, int n_d, int n_i, int n_t)
{
    nodeptr start_ptr;
    int temp;
    char new_corr_key[100];
    strcpy(new_corr_key, corr_key); //   corr_key string is copied to another space to protect corr_key from later change.
    start_ptr = root_sub_trie;

    // ki+1 이후의 suffix 를 실패한 partial trie 에서 찾아 보도록 한다.
    /*
     * Fill
     * codes
     */
    return;
} // insertion

void transposition(nodeptr root_sub_trie, char key[], char corr_key[], int ki, int ci, int n_s, int n_d, int n_i, int n_t)
{
    nodeptr p, s;
    int temp;
    char new_corr_key[100];
    strcpy(new_corr_key, corr_key); //   corr_key string is copied to another space to protect corr_key from later change.
    p = root_sub_trie;
    do
    {
        if (p->ch == key[ki + 1])
        {
            s = p->below;
            do
            {
                /*
                 * Fill
                 * codes
                 */
            } while (s);
            break;
        }
        else
            p = p->right;
    } while (p);
    return;
} // transposition

float get_penalty(int n_s, int n_d, int n_i, int n_t)
{
    // 각 종류마다 오류 1개당 벌점을 곱해 합산한 값을 반환한다.
    ////////////////////////////////////////////////////////
    //  아래 코드를 완성한다
    ////////////////////////////////////////////////////////
    return n_s * /* Fill your code */ +n_d * /* Fill your code */ +n_i * /* Fill your code */ +n_t * /* Fill your code */;
}

void find_with_spell_correction(nodeptr root_sub_trie, char key[], char corr_key[], int ki, int ci, int n_s, int n_d, int n_i, int n_t)
{
    nodeptr curr = root_sub_trie;
    char new_corr_key[100], c;
    if (!curr)
        return; // impossible situation. So no result is registered.

    if (curr->ch == '\0' && key[ki] == '\0')
    { // a result found. So register the result.
        strcpy(cwords[nres].word, corr_key);
        cwords[nres].penalty = get_penalty(n_s, n_d, n_i, n_t);
        cwords[nres].ns = n_s;
        cwords[nres].nd = n_d;
        cwords[nres].ni = n_i;
        cwords[nres].nt = n_t;
        if (get_penalty(n_s, n_d, n_i, n_t) == 0)
            found_perfect_match = 1;
        nres++;
        if (nres >= 20000)
        {
            printf("too many possible corrections.\n");
            c = getchar();
        }
        return;
    }

    // First we try normal processing. So we try to consume key[ki] normally by trying matching.
    while (curr && curr->ch < key[ki])
        curr = curr->right;
    if (curr && curr->ch == key[ki])
    { // matching key[ki] is OK.
        strcpy(new_corr_key, corr_key);
        new_corr_key[ci] = key[ki];
        new_corr_key[ci + 1] = '\0';
        ////////////////////////////////////////////////////////
        //  아래 코드를 완성한다
        ////////////////////////////////////////////////////////
        find_with_spell_correction(/* Fill your codes */, key, /* Fill your codes */, /* Fill your codes */, /* Fill your codes */, n_s, n_d, n_i, n_t);
    }

    // Secondly, we assume all possible errors at ki.
    if (!found_perfect_match && n_s + n_d + n_i + n_t <= 2)
    { // If 3 errors found, no more attempts will be made.
        // We assume all possible situations.
        if (ki <= strlen(key) - 1)
            substitution(root_sub_trie, key, corr_key, ki, ci, n_s, n_d, n_i, n_t);
        if (ki <= strlen(key))
            deletion(root_sub_trie, key, corr_key, ki, ci, n_s, n_d, n_i, n_t);
        if (ki <= strlen(key) - 1)
            insertion(root_sub_trie, key, corr_key, ki, ci, n_s, n_d, n_i, n_t);
        if (ki <= strlen(key) - 2) // At least we need to have two or more letters left for transposition error processing.
            transposition(root_sub_trie, key, corr_key, ki, ci, n_s, n_d, n_i, n_t);
    }
    return;
} // end find_with_spell_correction

void output_top_corrections()
{
    char printed_words[500][100];
    int i, n_printed = 0, num_show = 10;
    for (i = 0; i < nres; i++)
    {
        if (!printed(printed_words, cwords[i].word, n_printed))
        { // if not printed before, print it.
            ////////////////////////////////////////////////////////
            //  아래 코드를 완성한다
            ////////////////////////////////////////////////////////
            printf("<%2d>: %s penalty:%7.3f, substi:%d,  delet:%d,  inser:%d,  transp:%d\n", n_printed, /* Fill your codes */, /* Fill your codes */, /* Fill your codes */, /* Fill your codes */, /* Fill your codes */, /* Fill your codes */);
            strcpy(printed_words[n_printed], cwords[i].word); // record a word printed now.
            n_printed++;
            if (n_printed >= num_show)
                break;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 아래 함수는 주어진 것이며 별도로 작성 및 수정할 필요가 없다.
///////////////////////////////////////////////////////////////////////////////////////////////
void sort_results(ty_correction cwords[])
{
    int i, j, midx;
    float minval;
    ty_correction temp;
    for (i = 0; i < nres - 1; i++)
    {
        minval = cwords[i].penalty;
        midx = i;
        for (j = i + 1; j < nres; j++)
        {
            if (cwords[j].penalty < minval)
            {
                minval = cwords[j].penalty;
                midx = j;
            }
        }
        temp = cwords[i];
        cwords[i] = cwords[midx];
        cwords[midx] = temp;
    }
}
int printed(char printed_words[][100], char aword[], int total)
{
    int i, found = 0;
    for (i = 0; i < total; i++)
    {
        if (strcmp(printed_words[i], aword) == 0)
            return 1;
    }
    return 0; // not found.
}

void main()
{
    int i;
    int insertion_cnt, res, widx, wcnt;
    char c, command, word[200];

    // ki: 다음 처리할 key 의 글자 인덱스; ci: 다음에 넣을 corr_key 의 인덱스.
    int ki = 0, ci = 0;

    ty_rec record;
    nodeptr last, curr, prev;

    // file open
    FILE *fpr, *fpw, *fpr1;

    fpr = fopen("Corpus_dictionary_AP_Penn_RARE.txt", "r");
    if (!fpr)
    {
        printf("file open error of file Corpus_dictionary_AP_Penn_RARE.txt.\n");
        return 0;
    }

    fpw = fopen("records.bin", "wb");
    if (!fpw)
    {
        printf("file open error of file records.bin for writing.\n");
        return 0;
    }

    // initialize correction penalties.
    for (i = 0; i < 60; i++)
    {
        cwords[i].penalty = 0;
    }

    insertion_cnt = 0;

    while (1)
    {
        res = fscanf(fpr, "%s %d %d", word, &widx, &wcnt);
        if (res != 3)
            break;

        // prepare a record in a variable
        // if length of word > 49, too long to store in a record.
        if (strlen(word) > 49)
        {
            printf("Too long word. Skip Word = <%s> \n", word);
            continue;
        }

        strcpy(record.word, word);
        record.widx = widx;
        record.wfreq = wcnt;

        last = insert_trie(word);
        if (!last)
        {
            // printf ("word insertion error. word = %s\n", word) ;
            // c = getchar () ;
        }
        else
        {
            insertion_cnt++;
            last->bp = ftell(fpw);                   // store bypt position of the data file.
            fwrite(&record, sizeof(ty_rec), 1, fpw); // store the record in the data file.
            fflush(fpw);
        }

        if (insertion_cnt > 94000) //,insertion_cnt % 5000 == 0))
        {
            printf("insertion count = %d | \t %s\n", insertion_cnt, word);
        }
    } // while

    printf("Finish recording. \n");
    fclose(fpw);
    fclose(fpr);

    char key[50], corr_key[50];

    do
    {
        nres = 0;
        printf("\nTYPE A KEY: ");
        gets(key);
        sscanf(key, "%s", key);
        if (key[0] == '$' && key[1] == '\0')
            break;

        corr_key[0] = '\0';
        found_perfect_match = 0;
        ki = 0, ci = 0;

        find_with_spell_correction(root, key, corr_key, ki, ci, 0, 0, 0, 0);
        sort_results(cwords);
        printf("total number of corrected results = %d\n\n", nres);

        output_top_corrections();
    } while (1);
}
