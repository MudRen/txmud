// Room: /wiz/louth/k/kai20.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ����ͨ����ӣ����ڵĳ���ǳ����ӣ������Ĵ�����
ʰ�Ľ������䣬�ɼ���������һλ�����ܸ�֮�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai19",
]));
        set("objects",([
        __DIR__"npc/laohan": 1,
]));

	setup();
	replace_program(ROOM);
}
