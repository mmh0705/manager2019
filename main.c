#include "user.h"
#include "menu.h"

int main(int argc, char* argv[]) {
  LOGIN* userlist[100]; // 사용자목록 포인터 배열 (최대 100)
  int is_login=0; // 로그인 여부 (0 NO, 1 Yes)
  int menu_id;
  char yOrn;
  char command[20];
  if (argc != 2) {
    printf("Usage : manager <datafile>\n");
    return 0;
  }
  int count = load_file(userlist, argv[1]);
  if(count==0){
     printf("Make new? y or n: ");
     scanf("%c",&yOrn);
    if(yOrn=='y'){
      join(userlist, &count, argv[1]);
    }else if(yOrn=='n'){
    
    } 
  }
  printf("> Welcome!\n");
  
  while(1){
   if(is_login==0){
    printf("> ");
   } else {
    while(is_login !=0){
      char temp[20];
      printf("# ");
      scanf("%s",temp);
      printf("%s\n",temp); 
     if(strcmp(temp,"logout")==0){
        logout(&is_login);
        printf("> ");
     }
    }
   }
    scanf("%s",command);
    if(command=="login"){
      is_login = login(userlist, count);
     // menu_id = ask_menu(is_login); // 현재 로그인 되었는지의 여부를 파라미터로 알려야 한다.
    }else if(strcmp(command,"join")==0){
      join(userlist, &count, argv[1]);
    }else if(strcmp(command,"login")==0){
       is_login = login(userlist, count);
    }else if(strcmp(command,"logout")==0){
       logout(&is_login);
    }else if(strcmp(command,"list")==0){
       showList(userlist, count);
    } else if(strcmp(command,"exit")==0){
       break;
    }else{
     printf("wrong command!\n");
    }
 }
  save_file(userlist, count, argv[1]);
  return 0;
}

