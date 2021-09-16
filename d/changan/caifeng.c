// Room: /d/changan/caifeng.c

#include <ansi.h>

inherit ROOM;

string look_sign(object me);

void create()
{
	set("short", "�ļ��÷���");
	set("long", @LONG
�����Ǿ�������ļ��÷��̣�������ϰ���ɩ�������ɡ�Զ
����������˵���ϻ�Ϊ����������ۣ�������·���������
�������Խ��Խ�󣬴�ٹ������������Ҳ���������������
���⣬�۸�Ȼ�����ˡ���̨�Ϸ���һ�����ĺ�ľ��(sign)��
LONG
	);

	set("night_long", @LONG
�����Ǿ�������ļ��÷��̣������Ѿ������ˣ���̨�Ϸ���
һ�����ĺ�ľ��(sign)��
LONG
	);

	set("item_desc",([
		"sign" : (: look_sign :),
	]));

	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"sroad2",
]));
	set("objects",([
		__DIR__"npc/zhang_sao" : 1,
]));

	setup();
}

string look_sign(object me)
{
	return "������۸�ʽ��Ů��װ��Ҳ������(ding)����\n";
}

void open_close_door(string msg,object user)
{
	object ob = present("boss zhang",this_object());

        if(!msg || !user)
                return;
	if( msg == "begin_day")
        {
                if(ob)
                        tell_object(user,CYN"�Ŵ�ɩЦӯӯ�Ķ���˵������ʼӪҵ�ˣ���"+
                        RANK_D->query_respect(user)+"����㿴����\n"NOR);
                else
                        tell_object(user,CYN ""+query("short")+"��ʼӪҵ�ˡ�\n"NOR);
                return;
        }

	else if( msg == "begin_night")
        {
                if(ob)
                        tell_object(user,CYN"�Ŵ�ɩ˵������λ"+
                        RANK_D->query_respect(user)+"�Բ��𣬱ɵ�����ˣ��������������ɡ�\n"NOR);
                else
                        tell_object(user,CYN ""+query("short")+"�����ˡ�\n"NOR);
                return;
        }
}