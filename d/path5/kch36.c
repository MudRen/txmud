// Room: /d/path5/kch36.c

inherit ROOM;

void create()
{
	set("short", "«��");
	set("long", @LONG
����һ����״��ɽ·���������ɽʯ���������Ŷ���Գ���
ণ���ʱ��������һ�����Ǻ���Х���㲻�ɵô�����־���ǧ
������ʲô���⡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"kch37",
  "eastup" : __DIR__"kch35",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "��ǰ��ĵ��Σ���ͽ�����ܹ�ȥ��������ûϷ�ˡ�");
	setup();
	replace_program(ROOM);
}