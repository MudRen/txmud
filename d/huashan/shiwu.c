// Room: /d/huashan/shiwu.c

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ��ʯ�ݣ��������һ�����ӣ����Ƿ������ܣ�����
���Ѿ�ʲô��û���ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dongtian",
]));

	setup();
	replace_program(ROOM);
}
