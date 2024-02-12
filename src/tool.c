# include <assert.h>
# include <omp.h>
# include <ompt.h>
# include <stdio.h>
# include <stdatomic.h>

# define TOOL_NAME "OMPT_DUMP"

static volatile int mtx = 0;

# define INFO(...)                                                  \
    do {                                                            \
        int zero = 0;                                               \
        while (__sync_val_compare_and_swap(&mtx, zero, 1) == 1);    \
        fprintf(stdout, "[OMPT] [INFO] ");                          \
        fprintf(stdout, __VA_ARGS__);                               \
        fprintf(stdout, "\n");                                      \
        __sync_fetch_and_xor(&mtx, mtx);                            \
    } while (0)

# define register_callback_t(name, type)                                            \
    do {                                                                            \
        type f_##name = &on_##name;                                                 \
        if (ompt_set_callback(name, (ompt_callback_t)f_##name) == ompt_set_never)   \
            INFO("Could not register callback '" #name "'");                        \
    } while(0)
# define register_callback(name) register_callback_t(name, name##_t)

# include "callback-impl.h"

void
ompt_finalize(ompt_data_t * tool_data)
{
    (void)tool_data;
}

int ompt_initialize(
    ompt_function_lookup_t lookup,
    int initial_device_num,
    ompt_data_t * tool_data)
{
    (void) initial_device_num;
    (void) tool_data;
    ompt_set_callback_t ompt_set_callback = (ompt_set_callback_t) lookup("ompt_set_callback");
    # include "callback-register.h"
    return 1;
}

ompt_start_tool_result_t *
ompt_start_tool(
    unsigned int omp_version,
    const char * runtime_version)
{
    static ompt_start_tool_result_t data = {&ompt_initialize, &ompt_finalize, (ompt_data_t) NULL};
    INFO("%s: OpenMP %d and runtime %s", TOOL_NAME, omp_version, runtime_version);
    return &data;
}
