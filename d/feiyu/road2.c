// Room: /wiz/louth/a/road2.c

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
  "southwest" : __DIR__"road3",
  "east" : __DIR__"road1",
]));
       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
