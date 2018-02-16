#pragma once

// burn core x api
// 假设很多复杂的函数

int burncorex_init();
int burncorex_uninit();

void* burncorex_opendisc(char letter);
int burncorex_burnfiles(void * disc_handle,const char * files);
void burncorex_close(void* disc_handle);

//...