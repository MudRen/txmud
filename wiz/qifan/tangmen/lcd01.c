// Room: /d/tangmen/lcd01.c

inherit ROOM;

void create()
{
	set("short", "��ŢС·");
	set("long", @LONG
����һ����С��·��������������¹���һ����Ţ��������
��һЩ���õĿ�֦��Ҷ������Ѭ�졣
LONG
	);
	set("exits", ([
  "southwest" : __DIR__"lcd02",
  "northeast" : "/d/chengdu/scd04",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
