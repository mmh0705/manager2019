#include "user.h"

void showList(LOGIN* list[],int count){
 int number=0;
 for(int i=0; i<count; i++){
   printf("%s %s\n",list[number]->id, list[number]->password);
   number++;
 }
#ifdef DEBUG_MODE
  printf("DEBUG>> showList\n");
#endif  
}

int load_file(LOGIN* list[], char* filename){
  int count=0;
  char check;
  FILE *datafile = fopen(filename, "r");
  while(!feof(datafile)){
    list[count]=(LOGIN*)malloc(sizeof(LOGIN));
    fscanf(datafile,"%s %s",list[count]->id,list[count]->password);
    count++;
  }
    count--;
 if(count==0){
   printf("Error no data \n");
 }else{
   printf("%d records read!\n",count);\
 }
 fclose(datafile);
#ifdef DEBUG_MODE
  printf("DEBUG>> showList\n");
#endif

  return count;
}

void join(LOGIN* list[], int* count,char* filename){
  char id[20], pass[20];
  FILE *datafile = fopen(filename, "a"); 
  while(1){
    printf("Enter new user id >> ");
    scanf("%s", id);
    int dup=0;
    for(int i=0;i<*count;i++){
      if(strcmp(id, list[i]->id)==0) {
        dup=1; break;
      }
    }
    if(dup==1){
      printf("Already exist!!\n");
    }
    else{
      printf("Enter password >> ");
      scanf("%s", pass);
      list[*count] = (LOGIN*)malloc(sizeof(LOGIN));
      strcpy(list[*count]->id, id);
        fprintf(datafile,"%s ",id );
      strcpy(list[*count]->password, pass);
        fprintf(datafile,"%s",pass );
        fprintf(datafile,"\n");
      *count=*count+1;
      printf("New user added!\n");
      break;
    }
  }
#ifdef DEBUG_MODE
  printf("DEBUG>> join\n");
#endif

}

int login(LOGIN* list[], int count){
  char id[20], pass[20];
  printf("Enter user id >> ");
  scanf("%s", id);
  int dup=0, found;
  for(int i=0;i<count;i++){
    if(strcmp(id, list[i]->id)==0) {
      dup=1;
      found = i;
      break;
    }
  }
  if(dup!=1){
    printf("No such user!!\n");
    return 0;
  }
  else{
    printf("Enter password >> ");
    scanf("%s", pass);
    if(strcmp(list[found]->password, pass)==0){
      printf("Welcome %s!!\n", id);
      return 1;
    }
    else{
      printf("Password incorrect!!\n");
      return 0;
    }
  }
#ifdef DEBUG_MODE
  printf("DEBUG>> login\n");
#endif

}

void logout(int* is_login){
  *is_login = 0;
  printf("Logout!!\n");
}

void save_file(LOGIN* list[], int count, char* filename){
  FILE *datafile = fopen(filename, "w");
  for(int i=0; i<count; i++){
    fprintf(datafile, "%s %s\n", list[i]->id, list[i]->password);
  }
  printf("%s Saved!\n", filename);
  fclose(datafile);
#ifdef DEBUG_MODE
  printf("DEBUG>> logout\n");
#endif

}
