// Room: /d/tangmen/lcd03.c

inherit ROOM;

void create()
{
	set("short", "��ŢС·");
	set("long", @LONG
����һ����С��·��������������¹���һ����Ţ��������
��һЩ���õĿ�֦��Ҷ������Ѭ�졣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"lcd02",
  "southwest" : __DIR__"lcd04",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
