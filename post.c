#include <string.h>
#include <stdio.h>
#include <stdlib.h>
# include "post.h"

post_t *create_post(char *text) {
    if (strlen(text) <= MAX_POST_LENGTH) {
        post_t *post = malloc(sizeof(post_t));
        strcpy(post->text, text);
        post->num_likes = 0;
        return post;
    } else {
        return NULL;
    }
}

void destroy_post(post_t *post) {
    free(post);
}

void like_post(post_t *post) {
    post->num_likes++;
}

void unlike_post(post_t *post) {
    if (post->num_likes > 0)
        post->num_likes--;
}

/* The buffer must be at least ... bytes long. */
char *like_count_text(post_t *post, char *buf) {
    if (post->num_likes == 1) {
        sprintf(buf, "1 like");
    } else {
        sprintf(buf, "%d likes", post->num_likes);
    }
    return buf;
}
