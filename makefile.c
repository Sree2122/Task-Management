task_manager: main.c task_manager.c ui.c
        gcc -o task_manager main.c task_manager.c ui.c

clean:
        rm -f task_manager