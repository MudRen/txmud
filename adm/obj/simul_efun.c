// /adm/obj/simul_efun.c
// Modified by Find.

#pragma optimize

private inherit __DIR__ "check_config"; // add by Find.

#include "/adm/simul_efun/atoi.c"
#include "/adm/simul_efun/chinese.c"
#include "/adm/simul_efun/file.c"
#include "/adm/simul_efun/gender.c"
#include "/adm/simul_efun/wizard.c"
#include "/adm/simul_efun/object.c"
#include "/adm/simul_efun/path.c"

// This must be after gender.c
#include "/adm/simul_efun/message.c"
#include "/adm/simul_efun/shut_down.c"	// by Find.
#include "/adm/simul_efun/time.c"	// by Find.
#include "/adm/simul_efun/skill.c"	// by Find.
#include "/adm/simul_efun/bank.c"	// by Find.
#include "/adm/simul_efun/price.c"	// by Find.
#include "/adm/simul_efun/math.c"	// by Find.
#include "/adm/simul_efun/snoop.c"	// by Find.
#include "/adm/simul_efun/duplicate.c"	// by Find.
#include "/adm/simul_efun/base64.c"	// by Find.
#include "/adm/simul_efun/user.c"	// by Find.
#include "/adm/simul_efun/finance.c"	// by Find.

void create()
{
	seteuid(getuid());
	write("simul_efun loaded successfully.\n");
}
