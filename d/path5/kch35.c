// Room: /d/path5/kch35.c

inherit ROOM;

void create()
{
	set("short", "����ɽ·");
	set("long", @LONG
����һ����᫵�ɽ·�������������������Ŷ���Գ���
ণ���ʱ��������һ�����Ǻ���Х���㲻�ɵô�����־���ǧ
������ʲô���⡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"kch36",
  "northup" : __DIR__"kch34",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "��ǰ��ĵ��Σ���ͽ�����ܹ�ȥ��������ûϷ�ˡ�");
	setup();
	replace_program(ROOM);
}
