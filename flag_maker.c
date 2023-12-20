#include <stdio.h>
#include <string.h>

const char* flag_template[] = {
    "             ##________________",
    "            //******/  /******/",
    "           //**/          /**/",
    "          //******/  /******/",
    "         //*****/    /*****/",
    "        //******/__/******/",
    "       //`````````````````",
    "      //",
    "     //",
    "    //",
    "~~~//~~~~",
};
const size_t flag_template_size = sizeof(flag_template)/sizeof(*flag_template);

int space_fill(char* buff, size_t len)
{
    int len_sum = 0;
    for (size_t s = 0; s < len && len_sum >= 0; ++s) {
        len_sum += sprintf(buff + len_sum, "%s", " ");
    }
    return len_sum;
}

int make_flag(const char* name, char* flag_buff)
{
    size_t name_len = strlen(name);

    if (name_len == 0) {
        return 0;
    }

    size_t f = 0;
    int len_sum = 0;
    for (; f < flag_template_size - 1 && len_sum >= 0; ++f) {
        len_sum += space_fill(flag_buff + len_sum, name_len);
        len_sum += sprintf(flag_buff + len_sum, "%s\n", flag_template[f]);
    }

    len_sum += sprintf(flag_buff + len_sum, "%s%s\n", name, flag_template[f]);

    return len_sum;
}

int main(int argc, char *argv[])
{
    printf("Please enter your name:\n");
    char input_buff[128];
    size_t input_buff_len = sizeof(input_buff)/sizeof(*input_buff);
    memset((void *)input_buff, 0, input_buff_len);
    scanf("%s", input_buff);

    printf("Here is your flag marker:\n\n");
    char flag_buff[1024];
    size_t flag_buff_len = sizeof(flag_buff)/sizeof(*flag_buff);
    memset((void *)flag_buff, 0, flag_buff_len);
    int make_flag_status = make_flag(input_buff, flag_buff);

    if (make_flag_status < 0) {
        return make_flag_status;
    }

    printf("%s", flag_buff);

    return 0;
}
