//undcl: convert word description to declartion
int main(){
    int type;
    char temp[MAXTOKEN];

    while(gettoken() != EOF){
        strcpy(out, token);
        while((type = gettoken()) != '\n'){
            if(type == PARENS || type == BRACKETS)
                strcat(out, token);
            else if(type == '*'){
                sprintf(temp, "(*%s)", out);
                strcpy(out, temp);
            }else if(type == NAME){
                sprintf(temp, "%s %s", token, out);
            }else
                printf("invalid input as %s\n", token);
        }
        printf("%s\n", out);
    }

    return 0;
}
