// Room: /wiz/louth/c/jguanlu8.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
���ǳɶ��Ľ���·���򱱾��Ǹ����֡��򶫾����ҷ���Ժ��
��������ͨ����������·.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"jguanlu7",
  "north" : __DIR__"fdjie1",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
