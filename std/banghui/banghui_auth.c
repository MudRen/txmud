// banghui_auth.c
// BANGHUI_MASTER
// by Find.

// ��Ȩ�޵ȼ�����

#include <banghui.h>

// bid, bname һ���趨�����ٸ��ġ�
protected string bname, out_room, dir;
protected nosave string bid;
protected mapping
 
protected nosave string *banghui_levels = ({
"a_master",
"b_master",
"c_master",
"z_master",
});

protected mapping chinese_banghui_level = ([
"a_master" : "����",
"b_master" : "����",
"c_master" : "����",
"z_master" : "����",
]);

string query_chinese_banghui_level(string level)
{
	if(!undefinedp(chinese_banghui_level[level]))
		return chinese_banghui_level[level];
	else
		return "����";
}

string query_player_bh_level(string id)
{


}

protected void get_banghui_id()	// ������ʱ���� create() ����
{
	string id;

	if(bid || clonep())
		return;

	if(sscanf(base_name(this_object()), BANGHUI_DIR"%s/%*s", id ) != 2)
		return;

	bid = id;
}

protected int set_banghui_name(string name)
{
	int i;
	string tmp;

	if( clonep() || bname || !stringp(name) || !(i = sizeof(name)) )
		return 0;

	tmp = clr_ansi(name);

	if((i < 2) || (i > 12))
		return notify_fail("�������ֱ���ʹ�� 1-6 �����֡�\n");

	while(i--)
	{
		int section;

                if( tmp[i]<128 )
			return notify_fail("�������ֱ���ʹ�� *����*��\n");

		if( i%2==0 )
		{
			section = tmp[i] - 160;

			if( (section < 16)
			|| (section > 87) )
				return notify_fail("�������ֱ���ʹ�� *����* ���֡�\n");
		}
	}

	if(!BANGHUI_D->register_banghui_name(tmp))
		return notify_fail("��������Ѿ�����ʹ���ˣ�������һ����\n");

	bname = name;
	save();

	return 1;
}

string query_banghui_id() { return bid; }
string query_banghui_name() { return bname; }

/*
varargs protected int set_banghui_id(string id, string ref err)
{
	if(!stringp(id) || !sizeof(id))
		return 0;

	if(!regexp(id, "^[a-zA-Z]+$"))
	{
		err = "���� ID ֻ����СдӢ�ĵ�����ɡ�\n";
		return 0;
	}

	id = lower_case(id);

	if(file_size(dir_pre+id) != -1)
	{
		err = sprintf("[%s] ��� ID �Ѿ�����ʹ���ˣ�����ѡһ����\n", id);
		return 0;
	}
}
*/
