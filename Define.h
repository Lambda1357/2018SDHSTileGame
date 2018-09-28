#pragma once

// Global Variable

#define g_Device DXUTGetD3D9Device()
#define g_hWnd	 DXUTGetHWND()

// Debuging Tool

#if defined(DEBUG) | defined(_DEBUG)
#define DEBUG_LOG(log) cout << log << endl;
#else
#define DEBUG_LOG(log)  
#endif

#define SAFE_DESTROY(p) { if(p) { p->Destroy(); delete p;} p = nullptr; }

// Message Additional Type

#define NO_ADDITIONAL_INFO (void*)nullptr