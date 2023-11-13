#include <stdio.h>
#include <string.h>

union user_info {
    struct {
        char username[20];
        char password[20];
        int is_active;
    } user;
    char data[40];
};

int main() {
    union user_info user;
    int is_registered = 0;

    printf("Enter 'register' to create an account or 'login' to sign in: ");
    char action[10];
    scanf("%s", action);

    if (strcmp(action, "register") == 0) {
        printf("Enter your desired username: ");
        scanf("%s", user.user.username);
        printf("Enter your desired password: ");
        scanf("%s", user.user.password);
        printf("Enter 1 if you are active, 0 otherwise: ");
        scanf("%d", &user.user.is_active);
        printf("Account created successfully!\n");
        is_registered = 1;
    } else if (strcmp(action, "login") == 0) {
        printf("Enter your username: ");
        scanf("%s", user.user.username);
        printf("Enter your password: ");
        scanf("%s", user.user.password);
        if (is_registered && strcmp(user.user.username, "admin") == 0 && strcmp(user.user.password, "password") == 0) {
            if (user.user.is_active) {
                printf("Login successful!\n");
            } else {
                printf("Your account is inactive.\n");
            }
        } else {
            printf("Invalid username or password.\n");
        }
    } else {
        printf("Invalid action.\n");
    }

    return 0;
}
