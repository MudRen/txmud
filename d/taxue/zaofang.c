// zaofang.c  �㷻
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�㷻");
        set("long",@LONG
��һ������һ��Ũ�ҵľ����˱Ƕ�����̤ѩɽׯ������ɽ֮��ȴ����
�������������������̤ѩɽׯ��Ƶĵط����㷻��Ϊ��Ҥ�ͽ��ң���Ϊ
����������֮�á���ʱ��ֵ���֮�ڣ����������ر�æµ��
LONG);

	set("exits",([
		"east"  : __DIR__"huayuan",
		"down" : __DIR__"gangyao",
		"enter"  : __DIR__"jiaoshi",
	]));
	setup();
	replace_program(ROOM);
}
