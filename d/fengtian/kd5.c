// Room: /d/fengtian/kd5.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����·�Ƿ����ϳǵ���Ҫ�ֵ�������·�ᴮ�����Ƿ���ǵ�
һ���Ͻ֣��ֵ�����ʯ�������ߵ���ͷ���˶�����ֻ���������
�������в���С�̵꣬��Ӫ������ʳס���Լ����ӵĻ��
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"kd6",
  "south" : __DIR__"rou",
  "east" : __DIR__"lukou",
  "north" : __DIR__"yao",
]));
        set("outdoors", "fengtian");

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_2" : 3,
]));

	setup();
	replace_program(ROOM);
}
