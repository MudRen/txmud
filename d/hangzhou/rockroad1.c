// Room: /d/hangzhou/rockroad1.c

inherit ROOM;

void create()
{
	set("short", "��ʯ·");
	set("long", @LONG
��������һ����ʯ�̾͵�С·�ϣ�·�����������񣬷�����
���������������ԣ�������Զ����Ϳ������������������յ���
��
��·����һ��СС��Ժ�䡣
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"sudi3",
  "south" : __DIR__"rockroad2",
  "east" : __DIR__"wanghouse",
  "north" : __DIR__"cross1",
]));


        set("objects",([
        __DIR__"npc/beggar" : 1,
        NPC_DIR"xunpu" : 1,
]));

	setup();
	replace_program(ROOM);
}
