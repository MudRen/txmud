// Room: /u/w/wangs/a/yu20.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����������Ľ����ң�������ĵ��ӷ����ʱ��
������ǹ����������˼���������Ѿ��þ�û���ù��ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"yu19",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
