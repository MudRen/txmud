// Room: /u/w/wangs/b/kai21.c

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
������һ�������С������Ǿ����������ĸ߸ߵ���ש
Ժǽ�������ɫ��Ժǽ�ϼ���ż��Ƚ��յĴ��š����������
�������⣬���Ը���һ������ɭɭ�ĸо������洫������������
ͷһ����ԭ��������һ��СС�Ĳ�ݡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"kai22",
  "west" : __DIR__"kai19",
  "east" : __DIR__"kai23",
]));

        set("objects",([
	NPC_DIR"stdnpc/stdnpc_1" : 3,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
