// Room: /wiz/louth/a/road6.c

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
  "west" : __DIR__"yaxinroom",
  "northeast" : __DIR__"road5",
]));
       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
