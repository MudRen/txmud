// citang.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������԰�����������ڡ������ǰ���̤ѩɽׯ��������������λ�ĵط�
�����ζ�����Ϊ�ɾ����������������������ɨ������ׯ�������ӣ�û����
������飬��Ҫ�����������Ժ�������������������о��Լ���������
��Ҳ���������������λ(lingwei)�������(chanhui)��
LONG
        );
        	 
        set("exits", ([
               "south" : __DIR__"shilu4",               
        ]));

        setup();
	replace_program(ROOM);
}

void init()
{
	add_action("do_chanhui","chanhui");
}

int do_chanhui(string arg)
{
	object me = this_player();
	if(arg != "lingwei")
		return 0;

	write("����������������ڵ���λ����ʼ����Լ���ǰ�����������Ķ��õ��˾�����\n");
	if( me->query("bellicosity") > 0)
		me->add("bellicosity",-((me->query_int())*2+random(me->query_int())) );
	return 1;
}
