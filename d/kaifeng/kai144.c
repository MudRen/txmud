// Room: /u/w/wangs/b/kai144.c

inherit ROOM;

void create()
{
	set("short", "���ⶫ��");
	set("long", @LONG
������ֺ�ᶫ�����ѿ���Ƿֳ����롣·����������������
�ܶ������Ǻ�«�ġ���ζС�Ե�С�̷����ؽֽ���������������
�ϣ������и��ܵ��������ķ�����������·������һ�ҿ�ջ����
������һ����Ӫ�����򶫲�Զ���ǿ��ⶫ���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kai146",
  "north" : __DIR__"kai145",
  "west" : __DIR__"kai141",
  "east" : __DIR__"kai147",
]));
        set("objects",([
	NPC_DIR"stdnpc/stdnpc_1" : 2,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
