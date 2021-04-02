#ifndef xrDebugH
#define xrDebugH
#pragma once

typedef	void		crashhandler	(void);
class XRCORE_API	xrDebug
{
private:
	crashhandler*	handler	;

public:
	void			_initialize		();
	void			_destroy		();
	
public:
	crashhandler*	get_crashhandler	()							{ return handler;	};
	void			set_crashhandler	(crashhandler* _handler)	{ handler=_handler;	};
	LPCSTR			error2string		(long  code	);
	void			fail				(const char *e1, const char *file, int line);
	void			fail				(const char *e1, const char *e2, const char *file, int line);
	void			fail				(const char *e1, const char *e2, const char *e3, const char *file, int line);
	void			fail				(const char *e1, const char *e2, const char *file, int line, const char *function, bool &ignore_always);
	void			fail				(const char *e1, const std::string &e2, const char *file, int line, const char *function, bool &ignore_always);
	void			error				(long  code, const char* e1, const char *file, int line);
	void _cdecl		fatal				(const char* F,...);
	void			backend				(const char* reason, const char* file, int line);
	void			backend				(const char* reason, const char* expression, const char *argument0, const char *argument1, const char* file, int line, const char *function, bool &ignore_always);
};

// warning
// this function can be used for debug purposes only
IC	std::string __cdecl	make_string		(LPCSTR format,...)
{
	va_list		args;
	va_start	(args,format);

	char		temp[4096];
	vsprintf	(temp,format,args);

	return		std::string(temp);
}

extern XRCORE_API	xrDebug		Debug;

#include "xrDebug_macros.h"

#endif
