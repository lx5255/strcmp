
/*----------------------------------------------------------------------------*/
/** @brief: 比较字符串 
    @param: uch:结束字符，不需要可选0 
    @return: 赐
    @note: 支持'?' 和 '*'模糊比较
*/
/*----------------------------------------------------------------------------*/
u32 my_strcmp(char *str1, char *str2, char uch)
{
    u32 scnt = 0;
    while (1) {
        scnt++;
        if ((*str1 == '\0') && (*str2 == '\0')) {			//同时结束
            return 0;
        }
        if ((*str1 == uch) && (*str2 == uch)) {			//同时结束
            return 0;
        }

        if ((*str1 == '\0') || (*str2 == '\0')) {	//有一方提前结束
            return scnt;
        }

        if (*str1 != *str2) {						//比较不相等
            if ((*str2 != '?')&& (*str1 != '?')) {
                if ((*str2 != '*')&& (*str1 != '*')) {
                    return scnt;
                }else{
                    if(*str1 == '*'){
                        if((*(str1+1) == '\0')||(*(str1+1) == uch)){
                            return 0;
                        }
                        if(*(str1+1) != *str2){
                            str2++; 
                            if(*(str1+1) == '*'){
                                str1++; 
                            }
                            continue;
                        }else{
                            str1++; 
                        }
                    }

                    if(*str2 == '*'){
                        if((*(str2+1) == '\0')||(*(str2+1) == uch)){
                            return 0;
                        }
                        if(*(str2+1) != *str1){
                            str1++; 
                            if(*(str2+1) == '*'){
                                str2++; 
                            }
                            continue;
                        }else{
                            str2++; 
                        }

                    }

                }
            }
        }
        str1++;
        str2++;
    }
}


