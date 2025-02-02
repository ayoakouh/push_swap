#include "push_swap.h"

typedef struct s_list
{
    char            *operation;
    struct s_list   *next;
}   t_list;

void add_operation(t_list **ops, char *line)
{
    t_list *new_node = malloc(sizeof(t_list));
    if (!new_node)
        return;
    new_node->operation = line;
    new_node->next = NULL;
    if (!*ops)
        *ops = new_node;
    else
    {
        t_list *tmp = *ops;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new_node;
    }
}

void execute_operations(t_list *ops, t_stack *a, t_stack *b)
{
    while (ops)
    {
        execute_operation(ops->operation, a, b);
        ops = ops->next;
    }
}

void free_operations(t_list *ops)
{
    t_list *tmp;
    while (ops)
    {
        tmp = ops;
        ops = ops->next;
        free(tmp->operation);
        free(tmp);
    }
}

int main(int argc, char **argv)
{
    t_stack a, b;
    t_list *operations = NULL;
    char *line;

    if (argc < 2)
        return (0);
    init_stacks(&a, &b, argc, argv); // تحويل المدخلات إلى stack

    // قراءة جميع العمليات وتخزينها
    while ((line = get_next_line(0)))
        add_operation(&operations, line);

    // تنفيذ جميع العمليات
    execute_operations(operations, &a, &b);

    // التحقق من النتيجة
    if (is_sorted(&a) && is_empty(&b))
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);

    // تحرير الذاكرة
    free_operations(operations);
    free_stacks(&a, &b);
    return (0);
}
