// Room: /wiz/louth/c/haozhai.c

inherit ROOM;

void create()
{
	set("short", "���Ҵ�լ");
	set("long", @LONG
���������������Ĵ������ǧ���լԺ����˵���ҵĵ���ǧ
�꣬�軧�������Զ�������ǧ�꣬��������ûʲô��֪���ˡ�
լ�������������������ۼ����˵������ĵ���һ������ʹ���
������Ƶġ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wmlu8",
]));
        set("objects",([
        __DIR__"npc/dizhu_wang" : 1,
]));

	setup();
	replace_program(ROOM);
}
