// Room: /wiz/louth/a/road3.c

inherit ROOM;

void create()
{
	set("short", "��ʯ·");
	set("long", @LONG
���Ǵ�÷��԰������һ����ʯ�̾͵�С·����ɫ����ʯƴ��
��ͼ�������Լ���������˲���Ѱ��֮����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"road2",
  "southeast" : __DIR__"road4",
  "south" : __DIR__"qge",
	"north" : __DIR__"rukou",
]));
       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
