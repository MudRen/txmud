// Room: /d/hangzhou/hotell2.c

inherit ROOM;

void create()
{
	set("short", "��԰��¥");
	set("long", @LONG
��������԰��¥�Ķ�¥��������¥�´������������������
������࣬װ��Ҳ��������࣬�������ϵĲ���Ҳ�������ľ���
���մš��������Ǯ�˳����������������������䡣
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"hotel",
]));

	setup();
	replace_program(ROOM);
}
