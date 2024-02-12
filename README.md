# Installation
```bash
mkdir build
cd build
CC=clang cmake ../
export OMP_TOOL_LIBRARIES=$(realpath libompt_dump.so)
```
# Example output
```
[OMPT] [INFO] OMPT_DUMP: OpenMP 201611 and runtime LLVM OMP version: 5.0.20140926
[OMPT] [INFO] Could not register callback 'ompt_callback_device_unload'
[OMPT] [INFO] Could not register callback 'ompt_callback_target_map'
[OMPT] [INFO] Could not register callback 'ompt_callback_target_map_emi'
[OMPT] [INFO] ompt_callback_thread_begin
[OMPT] [INFO] ompt_callback_implicit_task
[OMPT] [INFO] ompt_callback_parallel_begin
[OMPT] [INFO] ompt_callback_implicit_task
[OMPT] [INFO] ompt_callback_work
[OMPT] [INFO] ompt_callback_task_create
[OMPT] [INFO] ompt_callback_task_schedule
[OMPT] [INFO] ompt_callback_parallel_begin
[OMPT] [INFO] ompt_callback_implicit_task
[OMPT] [INFO] ompt_callback_parallel_begin
[OMPT] [INFO] ompt_callback_implicit_task
[OMPT] [INFO] ompt_callback_work
[OMPT] [INFO] ompt_callback_parallel_begin
[OMPT] [INFO] ompt_callback_implicit_task
[OMPT] [INFO] ompt_callback_work
[OMPT] [INFO] ompt_callback_work
[OMPT] [INFO] ompt_callback_implicit_task
[OMPT] [INFO] ompt_callback_parallel_end
[OMPT] [INFO] ompt_callback_work
[OMPT] [INFO] ompt_callback_implicit_task
[OMPT] [INFO] ompt_callback_parallel_end
[OMPT] [INFO] ompt_callback_implicit_task
[OMPT] [INFO] ompt_callback_parallel_end
[OMPT] [INFO] ompt_callback_task_schedule
[OMPT] [INFO] ompt_callback_work
[OMPT] [INFO] ompt_callback_sync_region
[OMPT] [INFO] ompt_callback_sync_region_wait
[OMPT] [INFO] ompt_callback_sync_region_wait
[OMPT] [INFO] ompt_callback_sync_region
[OMPT] [INFO] ompt_callback_sync_region
[OMPT] [INFO] ompt_callback_sync_region_wait
[OMPT] [INFO] ompt_callback_sync_region_wait
[OMPT] [INFO] ompt_callback_sync_region
[OMPT] [INFO] ompt_callback_implicit_task
[OMPT] [INFO] ompt_callback_parallel_end
[OMPT] [INFO] ompt_callback_implicit_task
[OMPT] [INFO] ompt_callback_thread_end

```
