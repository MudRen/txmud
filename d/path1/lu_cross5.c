// Room: /d/path1/lu_cross5.c

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
����һƬ�����֣��ߵͲ��ȵ������β�룬ʱ��һö�ɹ�
���������ߣ����������ۡ������졣������ϸ�۲죬���ѷ���
·�ںη���
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tch_ft4",
  "southeast" : __DIR__"lu_cross4",
]));
	set("outdoors", "path1");

	set("objects",([
	__DIR__"npc/tufei" : 2,
]));

	setup();
	replace_program(ROOM);
}
