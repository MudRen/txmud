// jiaoshi.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����");
        set("long",@LONG
�������̤ѩɽׯ������ң�������ƵĹ������̺ܸ��ӡ���������
�ֹ���ϸ����Ҳ�ر��Щ�����Ǵ�æµ���ֳ����������Ǿ������ֲ�����
������������̤ѩɽׯ����֮�ڣ�����ʱ���ر����
LONG);

	set("exits",([
		"out" : __DIR__"zaofang",
	]));
        set("objects",([
                
        ]));
	setup();
	replace_program(ROOM);
}
