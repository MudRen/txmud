// /feature/banghui.c
// by Find.

#include <ansi.h>

protected string banghui_id;
protected nosave string banghui_name, cbanghui_level;
protected nosave object bh_master_ob;

// ���ú���
void set_banghui_id(string str)
{
	if(userp(this_object())
	&& previous_object()
	&& (geteuid(previous_object()) != ROOT_UID) )
		return;

	banghui_id = str;
}

void init_banghui_data()
{
	if(!banghui_id)
	{
		banghui_name = 0; cbanghui_level = 0; bh_master_ob = 0;
		return;
	}

	if(!bh_master_ob && !objectp(bh_master_ob = BANGHUI_D->query_bh_master_ob(banghui_id)))
		return;

	banghui_name = bh_master_ob->query_banghui_name();
	cbanghui_level = bh_master_ob->query_player_bh_level(this_object()->query("id"));
}

// ���ܺ���
int leave_from_banghui()
{
	
}

// ��ѯ������
object query_bh_master_ob()
{
	return bh_master_ob;
}

string query_banghui_title()
{
	if(banghui_name && cbanghui_level)
		return sprintf("%s %s",banghui_name, HIB+BWHT+cbanghui_level+NOR);
	else
		return 0;
}

string query_cbanghui_level()
{
	return cbanghui_level;
}

string query_banghui_id()
{
	return banghui_id;
}

string query_banghui_name()
{
	return banghui_name;
}
