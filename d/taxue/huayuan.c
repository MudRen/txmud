// huayuan.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","��԰");
        set("long",@LONG
������̤ѩɽׯ����Ļ�԰������̤ѩɽׯ�����ڶ࣬�������ﲻ��
���ص��滨��ݣ��ļ����������涷����������������̤ѩɽׯ�Ĵ�����
������ȥֻ���Ʒ���ɢ����Ŀ�����ƺ���
LONG);

	set("outdoors","taxue");

	set("exits",([
                "out" : __DIR__"menfang",
		"north" : __DIR__"dating",
		"west" : __DIR__"zaofang",
		"southwest" : __DIR__"jiashan",
	]));

	setup();
	replace_program(ROOM);
}
