#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX			1024
#define DIR_MAX		20
#define FILE_MAX	100

int line_cnt = -1;

void rec_lsR(const char *name)
{
    DIR		*dir;
    char	tmp[DIR_MAX][FILE_MAX];
    char	*dir_path[DIR_MAX];
    int		idx=0, pidx=0;
    
    struct dirent	*directory;
    
    for(int i = 0; i < DIR_MAX; i++)
    {
    	dir_path[i] = NULL;
        for(int j = 0; j < FILE_MAX; j++)	tmp[i][j] = NULL;
    }
    
    if (!(dir = opendir(name)))	return;
    printf("%s: \n", name);
    
    while ((directory = readdir(dir)) != NULL)
    {
        if (directory->d_type == DT_DIR)
        {
            char path[1024];
            if (strcmp(directory->d_name, ".") == 0 || strcmp(directory->d_name, "..") == 0)	continue;
            
            snprintf(path, sizeof(path), "%s/%s", name, directory->d_name);
            
            for(int l = 0; l < strlen(path); l++)	tmp[idx][l] = path[l];
            
            dir_path[idx] = tmp[idx];
            printf("%s\t", dir_path[idx]);
            idx++;
        }
        else	printf("%s\t", directory->d_name);
        
        line_cnt++;
        if(line_cnt > 5){
        	printf("\n");
        	line_cnt = 1;
        }
    }  
    
    printf("\n\n");
    
    while(dir_path[pidx] != NULL)
    {
        if(dir_path[pidx] == NULL)	break;
        rec_lsR(dir_path[pidx]);
        pidx++;
    }
    
    closedir(dir);
}

int main(int argc, char *argv[]) {
	char dir[1024];
	
	if(argc == 1)	strcpy(dir, ".");
	else			strcpy(dir, argv[1]);
	
	//rec_lsR(dir);
    rec_lsR(".");
    return 0;
}
