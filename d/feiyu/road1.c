// Room: /wiz/louth/a/road1.c

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
  "west" : __DIR__"road2",
  "east" : __DIR__"yu58",
]));
 
       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
