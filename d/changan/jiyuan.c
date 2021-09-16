// design by ���ֺ�(find) . all right reserved.

// Room: /d/changan/jiyuan.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����Է");
	set("long", @LONG
������Ǿ�ʦ������һ���Ժ����֪���ٶ��鹫��Ϊһ�׷�
���һ��ǧ�����ﵽ���ŵƽ�ʣ������˱ǣ���λ��欵Ĺ���
�����Աߣ���ʱ�ĳ�����Ц�������������к��ſ��ˡ�������
�����Ϸ����ޣ����Ǳ�����֬�����з��ϣ�¥�ϲ�ʱ�ش�������
�������ε��������ſ�����һ���ľ����(pai)��
LONG
	);

// ��Ժ���ϲſ��ţ����ǰ�������������￴���ĳ�������
	set("day_long", @LONG
������Ǿ�ʦ������һ���Ժ����֪���ٶ��鹫��Ϊһ�׷�
���һ��ǧ�����ڴ������Ϣʱ�䣬�����ϱ����Ǽ���������
�ǹ�Ƥ�����ӿǣ������ͷ���Ե������ſڡ��ű�����һ���ľ
����(pai)��
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"jiyuan2",
  "north" : __DIR__"nroad7",
]));
	set("no_clean_up", 0);
	set("item_desc",([
	"pai" : "
ÿ��ҹ��Ӫҵ��

��ͨ����(putong)   ��������
��Χ����(yinwei)   ʮ������
��Χ����(jinwei) ��ʮ������

�����԰�(order)���ֻ���\n\n"
]));
	set("objects",([
	__DIR__"npc/m_boss" : 1,
]));
	set(SAFE_ENV,1);
	set("no_magic",1);
	setup();
}

int valid_leave(object ob,string dir)
{
        if ( is_day() && dir == "up" )
		return notify_fail("����������Ϣ�أ�����������������ɡ�\n");
	else return ::valid_leave(ob,dir);
}

void open_close_door(string msg,object user)
{
	// �����Ϊ���곣פӪҵԱ��
	object ob = present("m_boss",this_object());

	// user Ϊ�˷����ڵ����֮һ.
	if(!msg || !user)
		return;
	if( msg == "begin_day")
	{
		if(ob)
			tell_object(user,CYN"������˵���������ˣ�������Ҫ��Ϣ�ˣ�����λ"+
			RANK_D->query_respect(user)+"�����������ɡ�\n"NOR);
		else
			tell_object(user,CYN ""+query("short")+"��ȥ��Ϣ�ˡ�\n"NOR);
		return;
	}

	else if( msg == "begin_night")
	{
		if(ob)
			tell_object(user,CYN"��������������ѵƶ����ϣ������ǳ����ӿ�������\n"NOR);
		else
			tell_object(user,CYN ""+query("short")+"��ʼӪҵ�ˡ�\n"NOR);
		return;
	}
}