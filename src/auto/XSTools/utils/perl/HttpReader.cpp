/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.24 from the
 * contents of HttpReader.xs. Do not edit this file, edit HttpReader.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "src/auto/XSTools/utils/perl/HttpReader.xs"
#include "../http-reader.h"
#include "../std-http-reader.h"
#include "../mirror-http-reader.h"

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

using namespace std;
using namespace OpenKore;


#line 23 "src/auto/XSTools/utils/perl/HttpReader.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef dVAR
#  define dVAR		dNOOP
#endif


/* This stuff is not part of the API! You have been warned. */
#ifndef PERL_VERSION_DECIMAL
#  define PERL_VERSION_DECIMAL(r,v,s) (r*1000000 + v*1000 + s)
#endif
#ifndef PERL_DECIMAL_VERSION
#  define PERL_DECIMAL_VERSION \
	  PERL_VERSION_DECIMAL(PERL_REVISION,PERL_VERSION,PERL_SUBVERSION)
#endif
#ifndef PERL_VERSION_GE
#  define PERL_VERSION_GE(r,v,s) \
	  (PERL_DECIMAL_VERSION >= PERL_VERSION_DECIMAL(r,v,s))
#endif
#ifndef PERL_VERSION_LE
#  define PERL_VERSION_LE(r,v,s) \
	  (PERL_DECIMAL_VERSION <= PERL_VERSION_DECIMAL(r,v,s))
#endif

/* XS_INTERNAL is the explicit static-linkage variant of the default
 * XS macro.
 *
 * XS_EXTERNAL is the same as XS_INTERNAL except it does not include
 * "STATIC", ie. it exports XSUB symbols. You probably don't want that
 * for anything but the BOOT XSUB.
 *
 * See XSUB.h in core!
 */


/* TODO: This might be compatible further back than 5.10.0. */
#if PERL_VERSION_GE(5, 10, 0) && PERL_VERSION_LE(5, 15, 1)
#  undef XS_EXTERNAL
#  undef XS_INTERNAL
#  if defined(__CYGWIN__) && defined(USE_DYNAMIC_LOADING)
#    define XS_EXTERNAL(name) __declspec(dllexport) XSPROTO(name)
#    define XS_INTERNAL(name) STATIC XSPROTO(name)
#  endif
#  if defined(__SYMBIAN32__)
#    define XS_EXTERNAL(name) EXPORT_C XSPROTO(name)
#    define XS_INTERNAL(name) EXPORT_C STATIC XSPROTO(name)
#  endif
#  ifndef XS_EXTERNAL
#    if defined(HASATTRIBUTE_UNUSED) && !defined(__cplusplus)
#      define XS_EXTERNAL(name) void name(pTHX_ CV* cv __attribute__unused__)
#      define XS_INTERNAL(name) STATIC void name(pTHX_ CV* cv __attribute__unused__)
#    else
#      ifdef __cplusplus
#        define XS_EXTERNAL(name) extern "C" XSPROTO(name)
#        define XS_INTERNAL(name) static XSPROTO(name)
#      else
#        define XS_EXTERNAL(name) XSPROTO(name)
#        define XS_INTERNAL(name) STATIC XSPROTO(name)
#      endif
#    endif
#  endif
#endif

/* perl >= 5.10.0 && perl <= 5.15.1 */


/* The XS_EXTERNAL macro is used for functions that must not be static
 * like the boot XSUB of a module. If perl didn't have an XS_EXTERNAL
 * macro defined, the best we can do is assume XS is the same.
 * Dito for XS_INTERNAL.
 */
#ifndef XS_EXTERNAL
#  define XS_EXTERNAL(name) XS(name)
#endif
#ifndef XS_INTERNAL
#  define XS_INTERNAL(name) XS(name)
#endif

/* Now, finally, after all this mess, we want an ExtUtils::ParseXS
 * internal macro that we're free to redefine for varying linkage due
 * to the EXPORT_XSUB_SYMBOLS XS keyword. This is internal, use
 * XS_EXTERNAL(name) or XS_INTERNAL(name) in your code if you need to!
 */

#undef XS_EUPXS
#if defined(PERL_EUPXS_ALWAYS_EXPORT)
#  define XS_EUPXS(name) XS_EXTERNAL(name)
#else
   /* default to internal */
#  define XS_EUPXS(name) XS_INTERNAL(name)
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
            Perl_croak(aTHX_ "Usage: %s::%s(%s)", hvname, gvname, params);
        else
            Perl_croak(aTHX_ "Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
        Perl_croak(aTHX_ "Usage: CODE(0x%"UVxf")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#ifdef PERL_IMPLICIT_CONTEXT
#define croak_xs_usage(a,b)    S_croak_xs_usage(aTHX_ a,b)
#else
#define croak_xs_usage        S_croak_xs_usage
#endif

#endif

/* NOTE: the prototype of newXSproto() is different in versions of perls,
 * so we define a portable version of newXSproto()
 */
#ifdef newXS_flags
#define newXSproto_portable(name, c_impl, file, proto) newXS_flags(name, c_impl, file, proto, 0)
#else
#define newXSproto_portable(name, c_impl, file, proto) (PL_Sv=(SV*)newXS(name, c_impl, file), sv_setpv(PL_Sv, proto), (CV*)PL_Sv)
#endif /* !defined(newXS_flags) */

#line 165 "src/auto/XSTools/utils/perl/HttpReader.c"

XS_EUPXS(XS_HttpReader_getStatus); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_HttpReader_getStatus)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	HttpReader *	THIS;
	HttpReaderStatus	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (HttpReader *)SvIV((SV*)SvRV( ST(0) ));
	else {
		warn( "HttpReader::getStatus() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->getStatus();
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_HttpReader_getError); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_HttpReader_getError)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	HttpReader *	THIS;
	char *	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (HttpReader *)SvIV((SV*)SvRV( ST(0) ));
	else {
		warn( "HttpReader::getError() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;
#line 22 "src/auto/XSTools/utils/perl/HttpReader.xs"
	RETVAL = (char *) THIS->getError();
#line 213 "src/auto/XSTools/utils/perl/HttpReader.c"
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_HttpReader_pullData); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_HttpReader_pullData)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "THIS, buf, size");
    {
	SV *	buf = ST(1)
;
	unsigned int	size = (unsigned int)SvUV(ST(2))
;
	HttpReader *	THIS;
	int	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (HttpReader *)SvIV((SV*)SvRV( ST(0) ));
	else {
		warn( "HttpReader::pullData() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;
#line 31 "src/auto/XSTools/utils/perl/HttpReader.xs"
	STRLEN dummy;
	char *buffer;
#line 245 "src/auto/XSTools/utils/perl/HttpReader.c"
#line 34 "src/auto/XSTools/utils/perl/HttpReader.xs"
	SvPV_force(buf, dummy);
	buffer = SvGROW(buf, size + 1);
	RETVAL = THIS->pullData(buffer, size);
	if (RETVAL < 0) {
		SvCUR_set(buf, 0);
		buffer[0] = '\0';
	} else {
		SvCUR_set(buf, RETVAL);
		buffer[RETVAL] = '\0';
	}
#line 257 "src/auto/XSTools/utils/perl/HttpReader.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_HttpReader_getData); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_HttpReader_getData)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "THIS, len");
    {
	unsigned int	len = (unsigned int)SvUV(ST(1))
;
	HttpReader *	THIS;
	char *	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (HttpReader *)SvIV((SV*)SvRV( ST(0) ));
	else {
		warn( "HttpReader::getData() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;
#line 51 "src/auto/XSTools/utils/perl/HttpReader.xs"
	RETVAL = (char *) THIS->getData(len);
#line 286 "src/auto/XSTools/utils/perl/HttpReader.c"
	sv_setuv(ST(1), (UV)len);
	SvSETMAGIC(ST(1));
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_HttpReader_getSize); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_HttpReader_getSize)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	HttpReader *	THIS;
	int	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (HttpReader *)SvIV((SV*)SvRV( ST(0) ));
	else {
		warn( "HttpReader::getSize() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->getSize();
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_HttpReader_DESTROY); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_HttpReader_DESTROY)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	HttpReader *	THIS;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (HttpReader *)SvIV((SV*)SvRV( ST(0) ));
	else {
		warn( "HttpReader::DESTROY() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	delete THIS;
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_StdHttpReader_init); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_StdHttpReader_init)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
#line 68 "src/auto/XSTools/utils/perl/HttpReader.xs"
	StdHttpReader::init();
#line 353 "src/auto/XSTools/utils/perl/HttpReader.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_StdHttpReader_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_StdHttpReader_new)
{
    dVAR; dXSARGS;
    if (items < 2 || items > 3)
       croak_xs_usage(cv,  "CLASS, url, postData = NULL");
    {
	char *	url = (char *)SvPV_nolen(ST(1))
;
	SV *	postData;
	char *	CLASS = (char *)SvPV_nolen(ST(0))
;
	StdHttpReader *	RETVAL;

	if (items < 3)
	    postData = NULL;
	else {
	    postData = ST(2)
;
	}
#line 75 "src/auto/XSTools/utils/perl/HttpReader.xs"
	if (postData == NULL) {
		RETVAL = StdHttpReader::create(url);
	} else if (!SvOK(postData)) {
		croak("Invalid postData parameter.");
	} else {
		char *postDataString;
		STRLEN len;

		postDataString = SvPV(postData, len);
		RETVAL = StdHttpReader::createAndPost(url, postDataString, len);
	}
#line 391 "src/auto/XSTools/utils/perl/HttpReader.c"
	ST(0) = sv_newmortal();
	sv_setref_pv( ST(0), CLASS, (void*)RETVAL );
    }
    XSRETURN(1);
}


XS_EUPXS(XS_MirrorHttpReader_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_MirrorHttpReader_new)
{
    dVAR; dXSARGS;
    if (items < 2 || items > 3)
       croak_xs_usage(cv,  "CLASS, urls, timeout = 0");
    {
	AV *	urls;
	unsigned int	timeout;
	char *	CLASS = (char *)SvPV_nolen(ST(0))
;
	MirrorHttpReader *	RETVAL;

	STMT_START {
		SV* const xsub_tmp_sv = ST(1);
		SvGETMAGIC(xsub_tmp_sv);
		if (SvROK(xsub_tmp_sv) && SvTYPE(SvRV(xsub_tmp_sv)) == SVt_PVAV){
		    urls = (AV*)SvRV(xsub_tmp_sv);
		}
		else{
		    Perl_croak(aTHX_ "%s: %s is not an ARRAY reference",
				"MirrorHttpReader::new",
				"urls");
		}
	} STMT_END
;

	if (items < 3)
	    timeout = 0;
	else {
	    timeout = (unsigned int)SvUV(ST(2))
;
	}
#line 97 "src/auto/XSTools/utils/perl/HttpReader.xs"
	list<const char *> urls_list;
	I32 i, len;
#line 435 "src/auto/XSTools/utils/perl/HttpReader.c"
#line 100 "src/auto/XSTools/utils/perl/HttpReader.xs"
	len = av_len(urls);
	for (i = 0; i <= len; i++) {
		SV **item;

		item = av_fetch(urls, i, 0);
		if (item && *item && SvOK(*item)) {
			char *url = SvPV_nolen(*item);
			urls_list.push_back(url);
		}
	}
	RETVAL = new MirrorHttpReader(urls_list, timeout);
#line 448 "src/auto/XSTools/utils/perl/HttpReader.c"
	ST(0) = sv_newmortal();
	sv_setref_pv( ST(0), CLASS, (void*)RETVAL );
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Utils__HttpReader); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Utils__HttpReader)
{
    dVAR; dXSARGS;
#if (PERL_REVISION == 5 && PERL_VERSION < 9)
    char* file = __FILE__;
#else
    const char* file = __FILE__;
#endif

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
#ifdef XS_APIVERSION_BOOTCHECK
    XS_APIVERSION_BOOTCHECK;
#endif
    XS_VERSION_BOOTCHECK;

        (void)newXSproto_portable("HttpReader::getStatus", XS_HttpReader_getStatus, file, "$");
        (void)newXSproto_portable("HttpReader::getError", XS_HttpReader_getError, file, "$");
        (void)newXSproto_portable("HttpReader::pullData", XS_HttpReader_pullData, file, "$$$");
        (void)newXSproto_portable("HttpReader::getData", XS_HttpReader_getData, file, "$$");
        (void)newXSproto_portable("HttpReader::getSize", XS_HttpReader_getSize, file, "$");
        (void)newXSproto_portable("HttpReader::DESTROY", XS_HttpReader_DESTROY, file, "$");
        (void)newXSproto_portable("StdHttpReader::init", XS_StdHttpReader_init, file, "");
        (void)newXSproto_portable("StdHttpReader::new", XS_StdHttpReader_new, file, "$$;$");
        (void)newXSproto_portable("MirrorHttpReader::new", XS_MirrorHttpReader_new, file, "$$;$");
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

