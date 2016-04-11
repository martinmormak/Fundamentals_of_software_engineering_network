#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "wall.h"

void empty_input_buffer() {
    int buf;
    while ((buf = getchar()) != '\n') { }
}

void show_wall_ui(wall_t *wall) {
    char buf[30];
    post_t *post;
    
    for (int i = 1; i <= wall->num_posts; i++) {
        post = get_post(wall, i);
        printf("%d\t%s (%s)\n", i, post->text, like_count_text(post, buf));
    }
}

void write_post_ui(wall_t *wall) {
    char *text = NULL;
    size_t length = 0;
    int read;
    
    printf("Enter your post:\n");
    read = getline(&text, &length, stdin);
    text[read - 1] = '\0'; // remove the trailing newline
    post_t *post = create_post(text);
    free(text);
    if (post != NULL) {
        add_post(wall, post);
    } else {
        printf("Try to fit your post into %d characters.", MAX_POST_LENGTH);
    }
}

void like_post_ui(wall_t *wall) {
    int number;
    post_t *post;
    
    show_wall_ui(wall);
    printf("Which post would you like to like? Enter number: ");
    scanf("%d", &number);
    empty_input_buffer();
    if ((post = get_post(wall, number)) != NULL) {
        like_post(post);
    } else {
        printf("Invalid post number.\n");
    }
}

void main_ui(wall_t *wall) {
    int input;
    
    do {
        printf("(S)how wall / (W)rite post / (L)ike post / (E)xit: ");
        input = getchar();
        empty_input_buffer();
        input = toupper(input);
        
        switch (input) {
            case 'S':
                show_wall_ui(wall);
                break;
            case 'W':
                write_post_ui(wall);
                break;
            case 'L':
                like_post_ui(wall);
                break;
        }
    } while (input != 'E');
}

int main(int argc, char** argv) {
    printf("Notwork - An offline social network\n");
    wall_t *wall = create_wall();
    main_ui(wall);
    destroy_wall(wall);
    return (EXIT_SUCCESS);
}

