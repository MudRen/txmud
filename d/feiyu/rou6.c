// Room: /wiz/louth/a/rou6.c

inherit ROOM;

void create()
{
	set("short", "ľ��");
	set("long", @LONG
����һ���ª��Сľ�ݣ��Ĵ���ʰ�øɸɾ�����������û��
ʲô���裬ֻ�п�ǽ��ľ����ڷ��ż����顣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"rou5",
  "north" : __DIR__"rou7",
]));

	setup();
	replace_program(ROOM);
}
