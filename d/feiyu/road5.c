// Room: /wiz/louth/a/road5.c

inherit ROOM;

void create()
{
	set("short", "��ʯ·");
	set("long", @LONG
���Ǵ�÷��԰������һ����ʯ�̾͵�С·����ɫ����ʯƴ��
��ͼ�������Լ���������˲���Ѱ��֮����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"road6",
  "north" : __DIR__"road4",
]));
       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
