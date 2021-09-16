// /adm/obj/check_config.c
// by Find.

#define need(x) badness += x+"\n"

#define FOOTER "�֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡֡�\n"
#define IMPOSSIBLE_TO_MISS_HEADER \
               FOOTER \
               "�� ���������е� MudOS driver �����ò��������ʺ� ��\n" \
               "�� �� Mudlib, ��� driver ԭ���ڵ� 'options.h'  ��\n" \
               "�� �����µĵ���Ȼ�����±���.                    ��\n" \
               FOOTER

private
void create()
{
	string badness = "";
	string version = __VERSION__;

	seteuid(getuid());
	switch (version[0..8])
	{
		case "MudOS 0.9":
		case "MudOS v20":
		case "MudOS v21":
		badness += "��� MudOS driver �汾��ʱ��,��ʹ�� MudOS v22 ���Ժ�İ汾.\n";
	}

#ifdef __CAST_CALL_OTHERS__
	need("��Ҫ: #undef CAST_CALL_OTHERS");
#endif

#ifdef __NO_ADD_ACTION__
	need("��Ҫ: #undef NO_ADD_ACTION");
#endif

#ifdef __NO_ENVIRONMENT__
	need("��Ҫ: #undef NO_ENVIRONMENT");
#endif

#ifdef __NO_WIZARDS__
	need(��Ҫ: "#undef NO_WIZARDS");
#endif

#ifndef __OLD_ED__
	need("��Ҫ: #define OLD_ED");
#endif
/*
#ifdef __MUDLIB_ERROR_HANDLER__
	need("��Ҫ: #undef MUDLIB_ERROR_HANDLER");
#endif
*/
#ifdef __NO_RESETS__
	need("��Ҫ: #undef NO_RESETS");
#endif

#ifdef __LAZY_RESETS__
	need("��Ҫ: #undef LAZY_RESETS");
#endif

#ifndef __TRAP_CRASHES__
	need("��Ҫ: #define TRAP_CRASHES");
#endif

#ifndef __THIS_PLAYER_IN_CALL_OUT__
	need("��Ҫ: #define THIS_PLAYER_IN_CALL_OUT");
#endif

#ifndef __CALLOUT_HANDLES__
	need("��Ҫ: #define CALLOUT_HANDLES");
#endif

#ifdef __PRIVS__
	need("��Ҫ: #undef PRIVS");
#endif

#ifndef __PACKAGE_UIDS__
	need("��Ҫ: #define PACKAGE_UIDS"");
#endif

#ifndef __AUTO_SETEUID__
	need("��Ҫ: #define AUTO_SETEUID");
#endif

#ifndef __AUTO_TRUST_BACKBONE__
	need("��Ҫ: #define AUTO_TRUST_BACKBONE");
#endif

    if (strlen(badness))
	error("\n\ndriver ���ô���:\n" + IMPOSSIBLE_TO_MISS_HEADER + badness + FOOTER+"\n\n");
}
