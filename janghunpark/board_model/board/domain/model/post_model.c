#include "post_model.h"

#include <stdio.h>
#include <stdlib.h>

post_model *init_post_model_object(void)
{
    post_model *tmp_post = (post_model *)malloc(sizeof(post_model));

    tmp_post->unique_id = unique_count++; // 생성할 때마다 unique_id 1씩 증가

    return tmp_post;
}

post_model *put_data_into_post_model(post_model *test_post, char* char_info)
{
    // 이런 식으로 작성하면 안됨
    // 동적 할당을 해야만 저장 공간을 변형하기 용이하게 함
    int char_info_length = strlen(char_info) + 1;
    test_post->title = (char*)malloc(sizeof(char) * char_info_length);
    strncpy(test_post->title,char_info,char_info_length);
    return test_post;
}

void print_post_model(post_model *test_post)
{
    printf("unique_id: %d\ntitle: %s\nwritter: %s\ncontents: %s\n", 
        test_post->unique_id, test_post->title, test_post->writter, test_post->contents);
}
