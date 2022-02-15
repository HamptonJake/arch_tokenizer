/******************************************************************************
Author: Jacob Hampton
Last edit: 2/13/22
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

char* word_start(char*, char);
char* word_end(char*, char);
int calc_length(char*, char*);
int mem_size(char*, char);
char* copystr(char*, char, int);
char** tokenize(char*, char);
void printtokens(char** , char* ,char);

int main()
{

    
    //Getting delim
    char delim;
    printf("Please enter the delimter\n");
    scanf("%c", &delim);
    
    //Getting string
    char user_input[50];
    // char user_input[24] = "lo,ng,to,b";
    printf("Please enter the string to be tokenized\n");
    scanf("%s", user_input);
    
    

    //char delim = ',';
    //char user_input[25] = "test,me,te";

    


    char * pinput = user_input; //First char of whole string
    
//    char **tokens =  tokenize(pinput, delim);


    // char * memcounter = user_input;
    
    // int numtokens = mem_size(memcounter, delim);
    
    
    char** finaltokens = tokenize(pinput, delim);
    
    printtokens(finaltokens, pinput, delim);
    
    


    return 0;
}





//**********************Funkshins**********************


void printtokens(char** tokarray, char* pinput, char delim){
    int totaldelim = 0;
    while(!(*pinput == '\0')){
        if(*pinput == delim){
            totaldelim++;
        }
        pinput++;
    }
    
    for(int j = 0; j < totaldelim+1; j++){
        printf("Tokens[%d] = %s\n", j, tokarray[j]);
    }
}


char** tokenize(char* pinput, char delim){


    char *end = pinput;
    char *start;

    
    int first = 0;
    //allocate pointers with initial count
    // printf("Created pointer array of size: %d\n", mem_size(pinput, delim));
    
    
    //create the pointer array
    char **tokens;
    int allosize = mem_size(pinput, delim);
    tokens = malloc(allosize * sizeof(char *));
    
    
    //Create array incrementer
    int arraddress = 0;
    //printf("Before while\n");
 
    while(!(*end == '\0')){
	//printf("In the while\n");
        int charlength = 0;
        char* new_word;

        if(first == 0){//Will pass through the first time
            end = word_end(pinput, delim);
            charlength = calc_length(end, pinput);
            new_word = copystr(pinput, delim, charlength);

            tokens[arraddress] = new_word;

            first++;
            
        }else{
            start = word_start(end, delim);
            end++;
            end = word_end(end, delim);
            charlength = calc_length(end, start);
            new_word = copystr(start, delim, charlength);

        tokens[arraddress] = new_word;

        }//end else

        arraddress++;
        
        
    }//End of while
    return tokens;
    
}// end of tokenize


char* copystr(char* str, char delim, int charlength){
    char *copied;
    // printf("The length is: %d\n", charlength);
    copied = (char *)malloc(charlength+1 * sizeof(char));
    // printf("The charlength: %d\n", charlength+1);
    for(int i = 0; i < charlength; i++){
        // printf("Copied: %c\n", *str);
        copied[i] = *str;
        str++;
    }
    // printf("Finished function\n");
    return copied;
}


int mem_size(char* str, char delim){
    int delims = 0;
    while(!(*str == '\0')){
        if(*str == delim){
            // printf("Found delim\n");
            delims++;
        }
        str++;
        
    }
    return delims+1;
}

char* word_start(char* str, char delim){
    // char* temp = str;
    while(!(*str == delim) && !(*str == '\0')){
        // printf("start: %c\n", *str);
        str++;
    }
    str++;
    // printf("Word starts at: %c\n", *str);
    return str;
}

char* word_end(char* str, char delim){
    while(!(*str == delim) && !(*str == '\0')){
        // printf("Curr char: %c\n", *str);
        str++;
    }
    // printf("Word ends at %c\n", *str);
    return str;
}

int calc_length(char* end, char* start){
    return end-start;
}
