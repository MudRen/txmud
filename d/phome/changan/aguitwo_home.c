// ��ҷ��������level four.
// by ���ֺ�(Find).

// �ȼ� 4��լԺ,�����䣬���ǵ�һ�䣬�빫������������
// �˷���ΪԺ�ӣ�ֻ�ܸı����������ܱ�����Ʒ��

#define HOME_DIR	"/d/phome/"
#define MAX_FUR		3

#include <room.h>
inherit ROOM;
inherit F_SAVE;

void get_long(string str, string text);
int home_level() { return 4; }	//���ݵȼ���
int is_player_home() { return 1; }
string home_master() { return query("master_name"); }

void create()
{
	if(!restore())
	{
	set("short", "��Ϸ�������ҵĴ�Ժ");
	set("long", @LONG
������һ��Ư���Ĵ�Ժ��
��������� changelong ����ı���ļҵ�������
��<<֣�����ѣ����뷿����������ã������κ��˾�������
  ������ķ���������ı�����Ʒ������Կ���벻Ҫ���׽�
  ������>>��
��Ҫ��Կ�׿���ȥ������ (pei key) ��
�����ķ���Ҫ���ڽ������ɣ���ʱ�䲻���ɷ��ݻᵹ����
���������ɹ黧���Ĺ��̶ӹ�������һ��ʱ���޷�������
  ����ȥ����Ԥ��(pay)���ɷѣ����̶ӻᰴʱ������ά����
  �ݡ�
������һʱ��ת���飬���԰����ķ��������С�Ǯׯ��Ѻ��
  �ڵ�Ѻ�ڼ���һ������ʹ��ά���������ڲ��꽫��û�ա�
�����üҾ߿���ȥ�Ҿ��̵꿴��������˼Ҿ߿��Է���
  (fangzhi)����ļ���Ҿ��Ժ�����㲻��Ҫ��Ҳ����
  ��������(banzou)��

ף��������죡��
LONG
);
	}

	set(SAFE_ENV,1);
	set("master_id","aguitwo");	// ������ ID��
	set("master_name","��Ϸ�������"); // ��������������
	set("exits",([
	"east" : __DIR__"aguitwo_home2",
	"west" : "/d/changan/wroad7",
	]));

	call_out("check_room",1);
	set("outdoors","playerhome");
	setup();
        create_door("west", "�������", "east", DOOR_CLOSED,LOCKED,__DIR__"aguitwo_key");
}

string query_save_file()
{
	return HOME_DIR+"changan/aguitwo_home_data";
}

void check_room()
{
	if(!query("built_time"))
	{
		set("built_time", time());
		return;
	}
	PLAYERHOME_D->check_player_room(this_object());
}

void init()
{
	add_action("do_changelong","changelong");
	add_action("do_fangzhi","fangzhi");
	add_action("do_banzou","banzou");
}

int do_changelong(string arg)
{
	string str;
	object me = this_player();

	if(me->query("id") != query("master_id"))
		return notify_fail("��������Ƿ���ר�����\n");

	write("Ϊ������������ۣ�ÿһ���벻Ҫ������ʮ��������֡�\n");
	write("��һ�е����ݳ��ȱ������еĳ��������������ֿ���ܶ��롣\n");
	this_player()->edit( (: get_long , str :) );
	return 1;
}

void get_long(string str, string text)
{
	if( sizeof( explode(text, "\n") ) > 8 )
	{
		write("�뽫���ļ�ͥ���������ڲ��������С�\n");
		return ;
	}	

	set("long",text);
	save();
	write("ok.\n");
	return;
}

int do_fangzhi(string arg)
{
	object me = this_player();
	string f;
	mapping obs,t_obs;
	int *sum,n;

	if(me->query("id") != query("master_id"))
		return 0;

	if( !(f = me->query_temp("furniture")) )
		return notify_fail("�����û�������üҾ�ѽ��\n");

	me->delete_temp("furniture");
	obs = query("objects");
	if(!obs || !sizeof(obs))
		set("objects",([f:1]));
	else
	{
		sum = values(obs);
		for(int i=0;i<sizeof(sum);i++)
			n += sum[i];
		if(n >= MAX_FUR)
			return notify_fail("�����������Ҳ���ò��¸���ļҾ��ˡ�\n");

		else if(!undefinedp(obs[f]))
			obs[f]++;
		else
			obs += ([f:1]);
		set("objects",obs);
	}

	if(mapp(t_obs = query_temp("objects")))
	{
		foreach(string file,mixed ob in t_obs)
		{
			if(objectp(ob))
				destruct(ob);
			if(arrayp(ob))
			{
				for(int i=0;i<sizeof(ob);i++)
					if(objectp(ob[i]))
						destruct(ob[i]);
			}
		}

	}
	delete_temp("objects");
	
	save();
	setup();
	write(sprintf("С��ư�%s�͵�����ڷźã�һת���ֲ����ˡ�\n",f->name()));
	return 1;
}

int do_banzou(string arg)
{
	object ob,me=this_player();
	string f;
	mapping obs,t_obs;

	if(me->query("id") != query("master_id"))
		return 0;

	if(!stringp(arg))
		return notify_fail("��Ҫ����ʲô�Ҿߣ�\n");

	ob = present(arg,this_object());
	if(!ob)
		return notify_fail("��Ҫ����ʲô�Ҿߣ�\n");

	f = base_name(ob);

	obs = query("objects");

	if(undefinedp(obs[f]) || !obs[f])
		return notify_fail("��Ҫ����ʲô�Ҿߣ�\n");

	obs[f]--;
	if(!obs[f])
		map_delete(obs,f);
	message_vision("��Ϸ��������$n�����������˳�ȥ��\n",me,ob);
	destruct(ob);
	set("objects",obs);

	if(mapp(t_obs = query_temp("objects")))
	{
		foreach(string file,mixed obj in t_obs)
		{
			if(objectp(obj))
				destruct(obj);
			if(arrayp(obj))
			{
				for(int i=0;i<sizeof(ob);i++)
					if(objectp(obj[i]))
						destruct(obj[i]);
			}
		}

	}
	delete_temp("objects");

	save();
	setup();
	return 1;
}