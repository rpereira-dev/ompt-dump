register_callback(ompt_callback_thread_begin);
register_callback(ompt_callback_thread_end);
register_callback(ompt_callback_parallel_begin);
register_callback(ompt_callback_parallel_end);
register_callback(ompt_callback_task_create);
register_callback(ompt_callback_task_schedule);
register_callback(ompt_callback_implicit_task);
register_callback(ompt_callback_target);
register_callback(ompt_callback_target_data_op);
register_callback(ompt_callback_target_submit);
register_callback(ompt_callback_control_tool);
register_callback(ompt_callback_device_initialize);
register_callback(ompt_callback_device_finalize);
register_callback(ompt_callback_device_load);
register_callback(ompt_callback_device_unload);
register_callback_t(ompt_callback_sync_region_wait, ompt_callback_sync_region_t);
register_callback_t(ompt_callback_mutex_released, ompt_callback_mutex_t);
register_callback(ompt_callback_dependences);
register_callback(ompt_callback_task_dependence);
register_callback(ompt_callback_work);
register_callback(ompt_callback_master); register_callback(ompt_callback_masked);
register_callback(ompt_callback_target_map);
register_callback(ompt_callback_sync_region);
register_callback_t(ompt_callback_lock_init, ompt_callback_mutex_acquire_t);
register_callback_t(ompt_callback_lock_destroy, ompt_callback_mutex_t);
register_callback(ompt_callback_mutex_acquire);
register_callback_t(ompt_callback_mutex_acquired, ompt_callback_mutex_t);
register_callback(ompt_callback_nest_lock);
register_callback(ompt_callback_flush);
register_callback(ompt_callback_cancel);
register_callback_t(ompt_callback_reduction, ompt_callback_sync_region_t);
register_callback(ompt_callback_dispatch);
register_callback(ompt_callback_target_emi);
register_callback(ompt_callback_target_data_op_emi);
register_callback(ompt_callback_target_submit_emi);
register_callback(ompt_callback_target_map_emi);
register_callback(ompt_callback_error);
