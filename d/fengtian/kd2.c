// Room: /d/fengtian/kd2.c

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

	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"kd3",
  "south" : __DIR__"midian",
  "east" : __DIR__"kd1",
]));
        set("outdoors", "fengtian");

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_3" : 2,
]));

	setup();
	replace_program(ROOM);
}
