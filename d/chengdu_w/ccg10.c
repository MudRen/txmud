// Room: /d/path5/ccg10.c

inherit ROOM;

void create()
{
	set("short", "ɽ�ִ��");
	set("long", @LONG
������һ��ɽ�ִ�·�ϣ�ֻ�����������де�ȫ�ǲ��������
����ɽ���������ʱ���д���������������У��㲻�ɵüӿ���
ǰ���Ĳ�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"ccg11",
  "northeast" : __DIR__"ccg09",
]));
        set("outdoors", "chengdu_w");
        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
