#include <stdio.h>
#include <string.h>

const char* flag_template[] = {
    "             ##________________",
    "            //******/  /******/",
    "           //***/        /***/",
    "          //******/  /******/",
    "         //******/  /******/",
    "        //******/__/******/",
    "       //""""""""""""""""",
    "      //",
    "     //",
    "    //",
    "~~~//~~~~",
};
const size_t flag_template_size = sizeof(flag_template)/sizeof(*flag_template);

enum make_flag_error {
    NAME_ERROR      = 1,
    FLAG_BUFF_ERROR = 2,
    WRITE_ERROR     = 3,
};

int space_fill(char* buff, size_t len)
{
    int result = 0;
    for (size_t s = 0; s < len && result >= 0; ++s) {
        result += sprintf(buff + result, "%s", " ");
    }
    return result;
}

int make_flag(const char* name, char* flag_buff)
{
    size_t name_len = strlen(name);

    if (name_len == 0) {
        return -NAME_ERROR;
    }

    size_t f = 0;
    int len_acc = 0;
    for (; f < flag_template_size - 1 && len_acc >= 0; ++f) {
        len_acc += space_fill(flag_buff + len_acc, name_len);
        len_acc += sprintf(flag_buff + len_acc, "%s\n", flag_template[f]);
    }

    len_acc += sprintf(flag_buff + len_acc, "%s%s\n", name, flag_template[f]);

    return len_acc;
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
